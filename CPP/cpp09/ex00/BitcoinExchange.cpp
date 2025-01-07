#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iomanip>


BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error : cannot open file " + filename);

    std::string line;

    std::getline(file, line);
    
    while(std::getline(file, line))
    {
        std::istringstream ss(line); // Permets de lire chaque partie de la string 
        std::string date;
        std::string priceStr;

        if (std::getline(ss, date, ',') && std::getline(ss, priceStr))
        {
            // Nettoyage de priceStr pour enlever les espaces ou caractères invisibles
            priceStr.erase(priceStr.find_last_not_of(" \t\r\n") + 1);
            priceStr.erase(0, priceStr.find_first_not_of(" \t\r\n"));

            std::cout << "Attempting to convert price: " << priceStr << std::endl;

            
            try
            {
                // Utiliser std::stod pour convertir priceStr en double
                double price = std::stod(priceStr);
                _priceData[date] = price;  // Ajouter le prix à la map
            }
            catch (const std::invalid_argument &)
            {
                std::cerr << "Error: Failed to convert price '" << priceStr << "' to double." << std::endl;
                continue;  // Passer à la ligne suivante en cas d'erreur
            }
            catch (const std::out_of_range &)
            {
                std::cerr << "Error: Price out of range: '" << priceStr << "'" << std::endl;
                continue;
            }
        }
        else 
            throw std::runtime_error("Error : Bad form of line in database file");
    }

    file.close();
}

double BitcoinExchange::processQuery(const std::string &date, double amount)
{
    if (!isValidDate(date))
        throw std::invalid_argument("Error : Invalid date format");
    if (!isValidAmount(amount))
        throw std::invalid_argument("Error : Invalid amount");

    std::map<std::string, double>::iterator it = _priceData.lower_bound(date); // Spécification explicite du type
    if (it == _priceData.end() || it->first != date) // Date plus grande que toutes celles de la map | Date n'existe pas
    {
        if (it == _priceData.begin()) // Aucune date anterieure possible
            throw std::runtime_error("Error: No data available for the date given");
        it--;
    }
    return it->second * amount;         
}


bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    std::istringstream ss(date);
    int year, month, day;
    char dash1, dash2;

    ss >> year >> dash1 >> month >> dash2 >> day;
    if(ss.fail() || dash1 != '-' || dash2 != '-')
        return false; 
    
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false; 

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false; 
    
    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > (isLeap ? 29 : 28))
            return false; 
    }
    return true; 
}

bool BitcoinExchange::isValidAmount(double amount)
{
    return amount > 0;
}