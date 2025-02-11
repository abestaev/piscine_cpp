#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const & src) {
    (void)src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const & src) {
    (void)src;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

enum Type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID,
	SPECIAL
};

Type detectType(const std::string& input) 
{
    if (input.length() == 1 && std::isprint(input[0])  && !isdigit(input[0]))
        return CHAR;

    bool isInt = true;
	size_t i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (i < input.length()) {
		if (!isdigit(input[i])){
			isInt = false;
			break;
		}
		i++;
	}
	long n = atol(input.c_str());
	if (isInt &&  n <= 2147483647 && n >= -2147483648)
		return INT;

	bool hasDot = false;
	bool hasF = false;
	bool isNumeric = true;
	i = 0;
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (i < input.length()) {
		if (input[i] == '.') {
			if (hasDot)
				return INVALID;
			hasDot = true;
		}
		else if (input[i] == 'f') {
			if (hasF || i != input.length() - 1)
				return INVALID;
			hasF = true;
		}
		else if (!isdigit(input[i])) {
			isNumeric = false;
			break;
		}
		i++;
	}

	if (isNumeric && hasDot) {
		return DOUBLE;
	} else if (isNumeric) {
		return FLOAT;
	}

    if (input == "nan" || input == "-inf" || input == "+inf"
		|| input == "nanf" || input == "-inff" || input == "+inff")
        return SPECIAL;

    return INVALID;
}

void displayResults(char c, size_t n, float f, double d)
{
	std::cout << "char: ";
	if (n < 0 || n > 127 || !std::isprint(n))
		std::cout << "Non affichable" << std::endl;
	else
		std::cout << "'" << c << "'" << std::endl;

	std::cout << "int: ";
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else 
		std::cout << n << std::endl;

	if (f - static_cast<int>(f) == 0)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;

	if (d - static_cast<int>(d) == 0)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: "<< d << std::endl;
}

void ScalarConverter::convert(std::string const &input) {
	Type type = detectType(input);
	// std::cout << "Type: ";
	// switch (type) {
	// 	case CHAR:
	// 		std::cout << "char" << std::endl;
	// 		break ;
	// 	case INT:
	// 		std::cout << "int" << std::endl;
	// 		break ;
	// 	case FLOAT:
	// 		std::cout << "float" << std::endl;
	// 		break ;
	// 	case DOUBLE:
	// 		std::cout << "double" << std::endl;
	// 		break ;
	// 	case INVALID:
	// 		std::cout << "Invalid input" << std::endl;
	// 		return;
	// 	case SPECIAL:
	// 		std::cout << "Special" << std::endl;
	// 		break ;
	// }
	if (type == SPECIAL) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " + input + "f" << std::endl;
		std::cout << "double: " << input << std::endl;
		return;
	}
	char c;
	int n;
	float f;
	double d;

	switch (type) {
		case CHAR:
			c = input[0];
			n = static_cast<int>(c);
			f = static_cast<float>(c);
			d = static_cast<double>(c);
			break ;
		case INT:
			n = atoi(input.c_str());
			c = static_cast<char>(n);
			f = static_cast<float>(n);
			d = static_cast<double>(n);
			break ;
		case FLOAT:
			f = atof(input.c_str());
			c = static_cast<char>(f);
			n = static_cast<int>(f);
			d = static_cast<double>(f);
			break ;
		case DOUBLE:
			d = strtod(input.c_str(), NULL);
			c = static_cast<char>(d);
			n = static_cast<int>(d);
			f = static_cast<float>(d);
			break ;
		default:
			std::cout << "Conversion impossible." << std::endl;
			return;
	}

	displayResults(c, n, f, d);
}
