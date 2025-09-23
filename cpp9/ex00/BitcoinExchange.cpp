#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        this->_exchangeRates = other._exchangeRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static int string_to_int(const std::string &s){
    int i;
    std::stringstream(s) >> i;
    return i;
}

static bool isLeapYear(int year) {
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
}

static bool isValidDateFormat(std::string &date) {
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (int i = 0; i < 10; i++) {
        if ((i != 4 && i != 7) && !std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }
    int year = string_to_int(date.substr(0, 4));
    int month = string_to_int(date.substr(5, 2));
    int day = string_to_int(date.substr(8, 2));
    int febDays = isLeapYear(year) ? 29 : 28;
    int dayInMonth[] = {0, 31, febDays, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (year < 2009 || year > 2025)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > dayInMonth[month])
        return false;
    return true;
}

BitcoinExchange::BitcoinExchange(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file) {
        std::cerr << "Error: could not open file." << std::endl; 
    }

    std::string line;
    std::getline(file, line);
    if (line != "date,exchange_rate")
        throw std::runtime_error("Error: file is corrupted.");
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;

        double rate;
        if (std::getline(ss, date, ',') && ss >> rate)
        {
            if (!isValidDateFormat(date))
                throw std::runtime_error("Error: file is corrupted.");
            _exchangeRates[date] = rate;
        } else {
            throw std::runtime_error("Error: file is corrupted.");
        }
    }
    file.close();
}

double BitcoinExchange::convert(const std::string &date, double amount) const {
    std::map<std::string, double>::const_iterator it = _exchangeRates.lower_bound(date);

    if (it == _exchangeRates.end())
        it--;
    else if (it->first != date && it != _exchangeRates.begin())
        it--;
    if (it == _exchangeRates.begin() && it->first != date)
        return (-1);
    return amount * it->second;   
}

void BitcoinExchange::processInputFile(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file) {
        std::cerr << "Error: could not open file." << std::endl; 
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;
        double amount;
        double result;

        if (std::getline(ss, date, '|') && ss >> amount) {
            date.erase(date.size() - 1);
            if (!isValidDateFormat(date))
                std::cerr << "Error: invalid date => " << date << std::endl;
            else if (amount < 0)
                std::cerr << "Error: not a positive number." << std::endl;
            else if (amount > 1000)
                std::cerr << "Error: too large a number." << std::endl;
            else {
                result = convert(date, amount);
                if (result == -1)
                    std::cerr << "Error: no matching dates." << std::endl;
                else 
                    std::cout << date << " => " << amount << " = " << result << std::endl;
            }
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }
}