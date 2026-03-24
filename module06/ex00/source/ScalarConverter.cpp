/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 01:40:00 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/12 01:40:00 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ScalarConverter.hpp"

#include <iostream>
#include <string>
#include <limits>
#include <cerrno>
#include <iomanip>
#include <cmath>
#include <cctype>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}

static bool isChar(const std::string &input) {
    return input.length() == 1 && !std::isdigit(input[0]);
}

static bool isInt(const std::string &input) {
    size_t counter = 0;
    if (input[counter] == '+' || input[counter] == '-')
        counter++;
    if (counter >= input.length())
        return false;
    while (counter < input.length()) {
        if (!std::isdigit(input[counter]))
            return false;
        counter++;
    }
    return true;
}

static bool isFloat(const std::string &input) {

    size_t counter = 0;
    bool hasDot = false;

    if (input == "nanf" || input == "+inff" || input == "-inff")
        return true;
    if (input[input.length() - 1] != 'f')
        return false;

    if (input[counter] == '+' || input[counter] == '-')
        counter++;
    while (counter < input.length() - 1) {
        if (input[counter] == '.') {
            if (hasDot)
                return false;
            hasDot = true;
        } else if (!std::isdigit(input[counter]))
            return false;
        counter++;
    }
    return hasDot;
}

static bool isDouble(const std::string &input) {

    size_t counter = 0;
    bool hasDot = false;

    if (input == "nan" || input == "+inf" || input == "-inf")
        return true;
    if (input[counter] == '+' || input[counter] == '-')
        counter++;

    while (counter < input.length()) {
        if (input[counter] == '.') {
            if (hasDot)
                return false;
            hasDot = true;
        } else if (!std::isdigit(input[counter]))
            return false;
        counter++;
    }
    return hasDot;
}

static void printChar(double value, bool impossible) {
    std::cout << "char: ";
    if (impossible || std::isnan(value) || std::isinf(value))
        std::cout << "impossible";
    else if (value < 0 || value > 127)
        std::cout << "impossible";
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "Non displayable";
    else
        std::cout << "'" << static_cast<char>(value) << "'";
    std::cout << std::endl;
}

static void printInt(double value, bool impossible) {
    std::cout << "int: ";
    if (impossible || std::isnan(value) || std::isinf(value))
        std::cout << "impossible";
    else if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "impossible";
    else
        std::cout << static_cast<int>(value);
    std::cout << std::endl;
}

static void printFloat(double value) {
    std::cout << "float: ";
    if (std::isnan(value))
        std::cout << "nanf";
    else if (std::isinf(value))
        std::cout << (value > 0 ? "+inff" : "-inff");
    else {
        std::cout << std::fixed << std::setprecision(1) << static_cast<float>(value) << "f";
    }
    std::cout << std::endl;
}

static void printDouble(double value) {
    std::cout << "double: ";
    if (std::isnan(value))
        std::cout << "nan";
    else if (std::isinf(value))
        std::cout << (value > 0 ? "+inf" : "-inf");
    else
        std::cout << std::fixed << std::setprecision(1) << value;
    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string &input) {

    double value;
    bool impossible = false;

    if (isChar(input)) {
        value = static_cast<double>(input[0]);
    } else if (isInt(input)) {
        char *end;
        long temp = std::strtol(input.c_str(), &end, 10);
        if (*end != '\0' || errno == ERANGE) {
            impossible = true;
            value = 0;
        } else {
            value = static_cast<double>(temp);
        }
    } else if (isFloat(input)) {
        char *end;
        value = std::strtod(input.c_str(), &end);
        if (errno == ERANGE && *end != 'f') {
            impossible = true;
        }
    } else if (isDouble(input)) {
        char *end;
        value = std::strtod(input.c_str(), &end);
        if (errno == ERANGE) {
            impossible = true;
        }
    } else {
        std::cout << "Invalid input" << std::endl;
        return;
    }

    printChar(value, impossible);
    printInt(value, impossible);
    printFloat(value);
    printDouble(value);
}
