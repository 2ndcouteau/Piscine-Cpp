/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:53:00 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/17 17:13:21 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_CLASS_HPP
# define ARRAY_CLASS_HPP

#include <iostream>
#include <exception>

template < typename T >
class Array
{
private:
		T*				_array;
		unsigned int	_length;

protected:


public:
	Array<T>(void): _array(NULL), _length(0) {};
	Array<T>(unsigned int n): _array(new T[n]()), _length(n) {};


	Array<T>(Array<T> const & src): _array(NULL), _length(0)
	{
		*this = src;
		return;
	};


	~Array<T>(void)
	{
		if (_array)
		{
			delete [] _array;
			_array = NULL;
		}
	};

	unsigned int const size(void) const
	{
		return (_length);
	};

	Array<T>&	operator=(Array<T> const & rhs)
	{
		unsigned int i = 0;

		if (this != &rhs)
		{
			if (this->_array)
				delete [] this->_array;
			this->_length = rhs.size();
			this->_array = new T[this->_length];

			while (i < this->_length)
			{
				this->_array[i] = rhs[i];
				i++;
			}
		}
		return (*this);
	};

	T&		operator[](unsigned int index) const
	{
		if (index > _length || index < 0)
			throw std::out_of_range("Index out of range.");
		else
			return (_array[index]);
	};
};

#endif
