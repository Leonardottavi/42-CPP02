/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:42:50 by lottavi           #+#    #+#             */
/*   Updated: 2024/11/22 15:34:45 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointValue(0) {}

Fixed::Fixed(const int value) {
	fixedPointValue = value << fractionalBits;
}

Fixed::Fixed(const float value) {
	fixedPointValue = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other) {
		fixedPointValue = other.fixedPointValue;
	}
	return *this;
}

bool Fixed::operator>(const Fixed &other) const {
	return fixedPointValue > other.fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const {
	return fixedPointValue < other.fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const {
	return fixedPointValue >= other.fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const {
	return fixedPointValue <= other.fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const {
	return fixedPointValue == other.fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const {
	return fixedPointValue != other.fixedPointValue;
}

Fixed Fixed::operator+(const Fixed &other) const {
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++() {
	fixedPointValue++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++(*this);
	return temp;
}

Fixed &Fixed::operator--() {
	fixedPointValue--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--(*this);
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}

int Fixed::getRawBits() const {
	return fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	fixedPointValue = raw;
}

float Fixed::toFloat() const {
	return (float)fixedPointValue / (1 << fractionalBits);
}

int Fixed::toInt() const {
	return fixedPointValue >> fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
	out << value.toFloat();
	return out;
}
