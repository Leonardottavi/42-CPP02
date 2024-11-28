/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:10:43 by lottavi           #+#    #+#             */
/*   Updated: 2024/11/28 14:40:57 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Function to check if a string is a valid float
bool isValidFloat(const std::string& str) {
	std::istringstream iss(str);
	float f;
	iss >> std::noskipws >> f; // noskipws considers leading whitespace invalid
	return iss.eof() && !iss.fail(); // Check if the entire string was consumed and if the conversion was successful
}

int main(int argc, char **argv)
{
	float arg1, arg2, arg3, arg4;

	if (argc < 2)
	{
		std::string response;
		std::cout << "No arguments provided. Do you want to use default parameters (10, 42.42, 10, 1234.4321)? (y/n): ";
		std::cin >> response;

		if (response == "y" || response == "Y")
		{
			// Use default parameters
			arg1 = 10;
			arg2 = 42.42;
			arg3 = 10;
			arg4 = 1234.4321;
		}
		else
		{
			// Ask the user to input four float values
			std::string input1, input2, input3, input4;
			std::cout << "Please enter four float values: ";
			std::cin >> input1 >> input2 >> input3 >> input4;

			if (!isValidFloat(input1) || !isValidFloat(input2) || !isValidFloat(input3) || !isValidFloat(input4))
			{
				std::cerr << "\033[1;31mError: Invalid float values provided.\033[0m" << std::endl;
				return 1;
			}
			arg1 = std::atof(argv[1]);
			arg2 = std::atof(argv[2]);
			arg3 = std::atof(argv[3]);
			arg4 = std::atof(argv[4]);
		}
	}
	else if (argc < 5)
	{
		// If the number of arguments is insufficient, display an error message
		std::cerr << "Usage: " << argv[0] << " <float1> <float2> <float3> <float4>" << std::endl;
		return 1;
	}
	else
	{
		// Check if the provided arguments are valid float values
		if (!isValidFloat(argv[1]) || !isValidFloat(argv[2]) || !isValidFloat(argv[3]) || !isValidFloat(argv[4]))
		{
			std::cerr << "\033[1;31mError: Invalid float values provided.\033[0m" << std::endl;
			return 1;
		}
		// Convert the arguments to float
		arg1 = std::atof(argv[1]);
		arg2 = std::atof(argv[2]);
		arg3 = std::atof(argv[3]);
		arg4 = std::atof(argv[4]);
	}

	// Create Fixed objects with the provided values
	Fixed a;
	Fixed const b(arg1);
	Fixed const c(arg2);
	Fixed const d(arg3);
	a = Fixed(arg4);

	// Print the values of the Fixed objects
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	return 0;
}

/*
int main( void ) {
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}
*/
