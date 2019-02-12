/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:07:12 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/14 18:08:52 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "\n* BUREAUCRAT PART *\n" << std::endl;
	try {
		Bureaucrat god("G0d", 0);
	}
	catch (std::exception const &e)	{
		std::cout << "G0d : " << e.what() << std::endl;
	}

	try {
		Bureaucrat henry("Henry", 151);
	}
	catch (std::exception const &e) {
		std::cout << "Henry : " << e.what() << std::endl;
	}


	Bureaucrat tulipe("Tulipe", 150);
	Bureaucrat toto("John", 100);
	Bureaucrat girst("Girst", 1);

	try {
		std::cout	<< std::endl\
					<< tulipe\
					<< toto\
					<< girst\
		<< std::endl;
	}
	catch (std::exception & e) {
		std::cerr << "Some error: " << e.what() << std::endl;
	}


	toto.inc_grade();
	std::cout << toto << std::endl;
	toto.dec_grade();
	std::cout << toto << std::endl;

	try {
		tulipe.dec_grade();
	}
	catch (std::exception & e) {
		std::cout << "Tulipe : " << e.what() << std::endl;
	}

	try {
		girst.inc_grade();
	}
	catch (std::exception & e) {
		std::cout << "Girst : " << e.what() << std::endl;
	}

	std::cout << "\n* FORM PART *\n" << std::endl;

	try {
		Form A37("A37", 151, 151);
	}
	catch (std::exception const &e)	{
		std::cout << "A37 : " << e.what() << std::endl;
	}

	try {
		Form A39("A39", 0, 0);
	}
	catch (std::exception const &e)	{
		std::cout << "A39 : " << e.what() << std::endl;
	}

	Form	A38("A38", 142, 42);

	std::cout << std::endl << A38 << std::endl;

	try {
		tulipe.signForm(A38);
	}
	catch (std::exception const &e)	{
		std::cout << e.what() << std::endl;
	}

	try {
		toto.signForm(A38);
	}
	catch (std::exception const &e)	{
		std::cout << e.what() << std::endl;
	}

	std::cout << A38 << std::endl;

	return (0);
}
