/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:43:31 by lottavi           #+#    #+#             */
/*   Updated: 2024/11/22 16:38:34 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Fixed.hpp
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <sstream>

class Fixed {
private:
	int fixedPointValue;
	static const int fractionalBits = 8;

public:
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &other);
	~Fixed();

	Fixed &operator=(const Fixed &other);

	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	Fixed &operator++();    // Pre-increment
	Fixed operator++(int);  // Post-increment
	Fixed &operator--();    // Pre-decrement
	Fixed operator--(int);  // Post-decrement

	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif
