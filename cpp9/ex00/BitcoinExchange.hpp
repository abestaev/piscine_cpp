#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>

class BitcoinExchange {
    private:
        std::map<std::string, double> _exchangeRates;
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        
    public:
        BitcoinExchange(const std::string &filename);
        ~BitcoinExchange();
        double convert(const std::string &date, double amount) const;
        void processInputFile(const std::string &filename);
};

#endif
