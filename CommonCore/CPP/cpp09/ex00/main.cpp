#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: " << av[0] << " <input file>" << std::endl;
        return 1;
    }

    const std::string inputFile = av[1];
    try 
    {
        BitcoinExchange exchange;
        exchange.loadDatabase("data.csv");

        std::ifstream input(inputFile.c_str());
        if (!input.is_open())
            throw std::runtime_error("Error: Unable to open input file.");
        
        std::string line; 
        std::getline(input, line); 

        while (std::getline(input, line))
        {
            try
            {
                line.erase(line.find_last_not_of(" \t\r\n") + 1);  // Suppression des espaces à la fin
                line.erase(0, line.find_first_not_of(" \t\r\n"));   // Suppression des espaces au début

                std::istringstream ss(line);
                std::string date;
                double amount;

                if (std::getline(ss, date, '|') && ss >> amount)
                {
                    // Nettoyer la date après extraction
                    date.erase(date.find_last_not_of(" \t\r\n") + 1);
                    date.erase(0, date.find_first_not_of(" \t\r\n"));

                    // Valider la datem
                    if (!exchange.isValidDate(date))
                        throw std::invalid_argument("Error : bad input");

                    // Traiter la requête
                    double result = exchange.processQuery(date, amount);
                    std::cout << date << " => " << amount << " = " << result << std::endl;
                }
                else
                {
                    throw std::runtime_error("Error: bad input => ");
                }
            }
            catch (const std::invalid_argument &e)
            {
                std::cerr << e.what() << std::endl;
            }
            catch (const std::runtime_error &e)
            {
                std::cerr << e.what() << line << std::endl;
            }
            catch (const std::exception &e)
            {
                std::cerr << "Unexpected error on line: '" << line << "' - " << e.what() << std::endl;
            }
        }
        input.close();
    } 
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return (0);
}
