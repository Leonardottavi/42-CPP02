/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:21:06 by lottavi           #+#    #+#             */
/*   Updated: 2024/11/21 16:10:14 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed &other) : _value(other._value)
{
	std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		_value = other._value;
	}
	return *this;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// Get raw bits
int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

// Set raw bits
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}
