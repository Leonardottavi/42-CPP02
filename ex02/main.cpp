/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:42:28 by lottavi           #+#    #+#             */
/*   Updated: 2024/11/26 15:07:53 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Function to check if a string can be converted to a float
bool isValidFloat(const std::string& str)
{
	std::istringstream iss(str);
	float f;
	iss >> std::noskipws >> f; // noskipws considers whitespace as part of the input
	return iss.eof() && !iss.fail(); // true if the entire stringstream was consumed and the conversion succeeded
}

int main(int argc, char **argv)
{
	float arg1, arg2;

	// Check if there are less than 3 arguments
	if (argc < 3)
	{
		char response;
		std::cout << "No arguments provided. Do you want to use default values (y/n)? ";
		std::cin >> response;

		// If user does not want to use default values
		if (response != 'y' && response != 'Y')
		{
			std::string input1, input2;
			std::cout << "Please enter the first float value: ";
			std::cin >> input1;
			std::cout << "Please enter the second float value: ";
			std::cin >> input2;

			// Validate the input values
			if (!isValidFloat(input1) || !isValidFloat(input2))
			{
				std::cerr << "\033[1;31mError: Invalid float values provided.\033[0m" << std::endl;
				return 1;
			}

			// Convert strings to floats
			arg1 = std::atof(input1.c_str());
			arg2 = std::atof(input2.c_str());
		}
		else
		{
			// Use default values
			arg1 = 5.05f;
			arg2 = 2.0f;
		}
	}
	else
	{
		// Convert command line arguments to floats
		arg1 = std::atof(argv[1]);
		arg2 = std::atof(argv[2]);
	}

	// Create Fixed objects and perform operations
	Fixed a;
	Fixed const b(Fixed(arg1) * Fixed(arg2));

	// Output results
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;

	return 0;
}

/*
int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}
*/
