/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:40:27 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/22 16:48:32 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iomanip>


class Awesome
{
	public:
		Awesome( int n ) : _n( n ) {}

		bool operator==( Awesome const & rhs ) { return (this->_n == rhs._n); }
		bool operator!=( Awesome const & rhs ) { return (this->_n != rhs._n); }
		bool operator>( Awesome const & rhs ) { return (this->_n > rhs._n); }
		bool operator<( Awesome const & rhs ) { return (this->_n < rhs._n); }
		bool operator>=( Awesome const & rhs ) { return (this->_n >= rhs._n); }
		bool operator<=( Awesome const & rhs ) { return (this->_n <= rhs._n); }
		int _n;

	private:
};



int main(void)
{
	int a = 2;
	int b = 3;
	Awesome  awes(1);
	Awesome  awes2(4);

	::swap( awes, awes2 );
	std::cout << "awes = " << awes._n << ", awes2= " << awes2._n << std::endl;

	std::cout << "min( awes, awes2 ) = " << ::min( &awes, &awes2 )->_n << std::endl;
	std::cout << "max( awes, awes2 ) = " << ::max( &awes, &awes2 )->_n << std::endl;

	std::cout << std::endl;


	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;

	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::cout << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;

	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << std::endl;

	float e = 42.42;
	float f = 43.43;
	std::cout.precision(2);
	std::cout << std::setiosflags(std::ios::fixed);

	::swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;

	std::cout << std::endl;
	std::cout << "min( e, f ) = " << ::min<int>( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max<int>( e, f ) << std::endl;

	std::cout << std::endl;
	std::cout << "min( e, f ) = " << ::min<char>( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max<char>( e, f ) << std::endl;

	std::cout << std::endl;
	std::cout << "min( e, f ) = " << ::min<float>( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max<float>( e, f ) << std::endl;

	std::cout << std::endl;
	std::cout << "min( e, f ) = " << ::min<double>( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max<double>( e, f ) << std::endl;

	return (0);
}
