#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <stdexcept>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const& other);
    ~BitcoinExchange();
    BitcoinExchange& operator=(BitcoinExchange const& other);
    void loadDatabase(std::string const& filename);
    void processInput(std::string const& filename) const;

private:
    std::map<std::string, float> _database;
    bool isValidDate(std::string const& date) const;
    float getRate(std::string const& date) const;
    std::string trim(std::string const& s) const;
};

#endif
