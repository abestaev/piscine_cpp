#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <iomanip>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const & src);
        ScalarConverter &operator=(ScalarConverter const & src);
        ~ScalarConverter();
    public:
        void convert();
};

#endif