/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:40:27 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/16 09:58:49 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>


class Base
{
	public:
		virtual ~Base(void){};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};


Base * generate(void)
{
	int nb = rand();
	switch (nb % 3)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
	}
	return (new A);
}

void identify_from_pointer(Base *p)
{
	if (A* a = dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	if (B* b = dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	if (C* c = dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify_from_reference(Base &p)
{
	try
	{
		A & ref = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast &bc)
	{
		try
		{
			B & ref = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		}
		catch (std::bad_cast &bc)
		{
			try
			{
				C & ref = dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
			}
			catch (std::bad_cast &bc)
			{
				std::cout << "Undefined" << std::endl;
			}
		}
	}
}


int	main(void)
{
	srand(time(NULL));

	Base *ptr;

	ptr = generate();

	std::cout << "Class : ";
	identify_from_pointer(ptr);

	std::cout << "Class : ";
	identify_from_reference(*ptr);

	return (0);
}
