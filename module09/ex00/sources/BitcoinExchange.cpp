#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& other) : _database(other._database) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& other) {
    if (this != &other)
        _database = other._database;
    return *this;
}

std::string BitcoinExchange::trim(std::string const& s) const {
    size_t start = s.find_first_not_of(" \t\r\n");
    if (start == std::string::npos)
        return "";
    size_t end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

void BitcoinExchange::loadDatabase(std::string const& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("could not open file.");
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        size_t comma = line.find(',');
        if (comma == std::string::npos)
            continue;
        std::string date = trim(line.substr(0, comma));
        std::string rateStr = trim(line.substr(comma + 1));
        float rate = static_cast<float>(std::atof(rateStr.c_str()));
        _database[date] = rate;
    }
}

bool BitcoinExchange::isValidDate(std::string const& date) const {
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 10; i++) {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return false;
    }
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    if (isLeap)
        daysInMonth[1] = 29;
    if (day > daysInMonth[month - 1])
        return false;
    return true;
}

float BitcoinExchange::getRate(std::string const& date) const {
    std::map<std::string, float>::const_iterator it = _database.lower_bound(date);
    if (it == _database.end() || it->first != date) {
        if (it == _database.begin())
            throw std::runtime_error("date too early.");
        --it;
    }
    return it->second;
}

void BitcoinExchange::processInput(std::string const& filename) const {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("could not open file.");
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        size_t sep = line.find(" | ");
        if (sep == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = trim(line.substr(0, sep));
        std::string valueStr = trim(line.substr(sep + 3));
        if (!isValidDate(date)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (valueStr.empty()) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        bool negative = false;
        size_t start = 0;
        if (valueStr[0] == '-') {
            negative = true;
            start = 1;
        }
        bool hasDot = false;
        bool invalid = false;
        for (size_t i = start; i < valueStr.size(); i++) {
            if (valueStr[i] == '.') {
                if (hasDot) { invalid = true; break; }
                hasDot = true;
            } else if (valueStr[i] < '0' || valueStr[i] > '9') {
                invalid = true;
                break;
            }
        }
        if (invalid || (negative && start >= valueStr.size())) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        float value = static_cast<float>(std::atof(valueStr.c_str()));
        if (value < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        try {
            float rate = getRate(date);
            std::cout << date << " => " << value << " = " << value * rate << std::endl;
        } catch (std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
}
