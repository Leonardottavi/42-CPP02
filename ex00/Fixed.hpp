/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lottavi <lottavi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:20:59 by lottavi           #+#    #+#             */
/*   Updated: 2024/11/21 16:10:09 by lottavi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _value;
	static const int _fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed& operator=(const Fixed &other);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif // FIXED_HPP
