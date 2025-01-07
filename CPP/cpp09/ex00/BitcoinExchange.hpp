#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
private: 
    std::map<std::string, double> _priceData;

public:
    BitcoinExchange();
    ~BitcoinExchange();

    void loadDatabase(const std::string &filename);
    double processQuery(const std::string &date, double amount);
    bool isValidDate(const std::string &date);
    bool isValidAmount(double amount);

};



#endif