/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:02:14 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/10 19:40:25 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

#include <iostream>

class Fixed
{
	private:
		int					_raw;
		static const int 	_fix;


	public:
		Fixed(void);

		Fixed(int const i_param);
		Fixed(float const f_param);

		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed &	operator=(Fixed const &rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);


		int		toInt(void) const;
		float	toFloat(void) const;

		bool	operator>=(Fixed const &rhs);
		bool	operator==(Fixed const &rhs);
		bool	operator!=(Fixed const &rhs);
		bool	operator< (Fixed const &rhs);
		bool	operator> (Fixed const &rhs);
		bool	operator<=(Fixed const &rhs);

		Fixed	operator+(Fixed const & rhs);
		Fixed	operator-(Fixed const & rhs);
		Fixed	operator*(Fixed const & rhs);
		Fixed	operator/(Fixed const & rhs);

		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);

		static Fixed&	min(Fixed const & f1, Fixed const & f2);
		static Fixed&	min(Fixed & f1, Fixed & f2);
		static Fixed&	max(Fixed const & f1, Fixed const & f2);
		static Fixed&	max(Fixed & f1, Fixed & f2);

};

std::ostream &	operator<<(std::ostream &o, Fixed const &i);


#endif
