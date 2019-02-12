/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:07:12 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/14 21:45:57 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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


	Bureaucrat low("Tulipe", 150);
	Bureaucrat mid("John", 100);
	Bureaucrat top("Girst", 1);

	try {
		std::cout	<< std::endl\
					<< low\
					<< mid\
					<< top\
		<< std::endl;
	}
	catch (std::exception & e) {
		std::cerr << "Some error: " << e.what() << std::endl;
	}


	mid.inc_grade();
	std::cout << mid << std::endl;
	mid.dec_grade();
	std::cout << mid << std::endl;

	try {
		low.dec_grade();
	}
	catch (std::exception & e) {
		std::cout << "Tulipe : " << e.what() << std::endl;
	}

	try {
		top.inc_grade();
	}
	catch (std::exception & e) {
		std::cout << "Girst : " << e.what() << std::endl;
	}

	std::cout << "\n* SHRUBBERY_CREATION_FORM PART *\n" << std::endl;

	ShrubberyCreationForm	S_form("Hello");
	RobotomyRequestForm		R_form("H3770");
	PresidentialPardonForm	P_form("Secret");

	std::cout << S_form << R_form << P_form << std::endl;


	try {
		S_form.execute(low);
	}
	catch (std::exception & e) {
		std::cout << "Tulipe : " << e.what() << std::endl;
	}

	low.signForm(S_form);
	top.signForm(S_form);
	top.signForm(R_form);
	top.signForm(P_form);


	try {
		S_form.execute(mid);
	}
	catch (std::exception & e) {
		std::cout << "Toto : " << e.what() << std::endl;
	}

	try {
		R_form.execute(mid);
	}
	catch (std::exception & e) {
		std::cout << "Toto execution: " << e.what() << std::endl;
	}

	try {
		R_form.execute(top);
	}
	catch (std::exception & e) {
		std::cout << "Girst execution: " << e.what() << std::endl;
	}

	try {
		S_form.execute(top);
	}
	catch (std::exception & e) {
		std::cout << "Girst execution: " << e.what() << std::endl;
	}

	try {
		P_form.execute(top);
	}
	catch (std::exception & e) {
		std::cout << "Girst execution: " << e.what() << std::endl;
	}


	std::cout << "\n* SHRUBBERY_CREATION_FORM PART *\n" << std::endl;

	Intern  someRandomIntern;
	Form*   rrf;
	Form*   rrf1;
	Form*   rrf2;
	Form*   rrf3;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	rrf1 = someRandomIntern.makeForm("shrubbery creation", "Marry");
	rrf2 = someRandomIntern.makeForm("presidential pardon", "John");
	rrf3 = someRandomIntern.makeForm("shopping list", "random name");


 	if (rrf != NULL)
		delete rrf;
 	if (rrf1 != NULL)
		delete rrf1;
 	if (rrf2 != NULL)
		delete rrf2;
 	if (rrf3 != NULL)
		delete rrf3;


	return (0);
}
