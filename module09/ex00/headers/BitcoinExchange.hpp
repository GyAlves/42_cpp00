/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 19:15:47 by galves-a          #+#    #+#             */
/*   Updated: 2026/04/15 19:48:34 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        std::string trim(std::string const& s) const;
        bool isValidDate(std::string const& date) const;
        bool isValidValueFormat(std::string const& valueStr) const;
        bool parseInputLine(std::string const& line, std::string& date, float& value) const;
        void printExchangeValue(std::string const& date, float value) const;
        float getRate(std::string const& date) const;
};

#endif
