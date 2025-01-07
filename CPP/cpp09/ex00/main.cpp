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
        std::cout << "Database loaded successfully!" << std::endl;
        
        std::string line; 
        while (std::getline(input, line))
        {
            try
            {
                // Nettoyer la ligne pour éviter les espaces indésirables
                line.erase(line.find_last_not_of(" \t\r\n") + 1);  // Suppression des espaces à la fin
                line.erase(0, line.find_first_not_of(" \t\r\n"));   // Suppression des espaces au début

                // Afficher la ligne pour débogage
                std::cout << "Processing line: '" << line << "'" << std::endl;

                // Maintenant, on suppose que la ligne est au format "date | amount"
                std::istringstream ss(line);
                std::string date;
                double amount;

                // Utilisation de la barre verticale comme séparateur
                if (std::getline(ss, date, '|') && ss >> amount)
                {
                    // On vérifie que les deux parties ont bien été extraites
                    if (ss.fail())
                        throw std::runtime_error("Error: Invalid input format");

                    // Affichage de la ligne correctement traitée
                    double result = exchange.processQuery(date, amount);
                    std::cout << date << " => " << amount << " = " << result << std::endl;
                }
                else
                {
                    throw std::runtime_error("Error: Invalid input format");
                }
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << std::endl;
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