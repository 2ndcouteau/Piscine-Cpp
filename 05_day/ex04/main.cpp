/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:07:12 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/15 13:31:24 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "OfficeBlock.hpp"

int main(void)
{
	std::cout << "\n* BUREAUCRACY PART *\n" << std::endl;

	Intern 			idiotOne;
	Bureaucrat  	jesus = Bureaucrat("Jesus Christ", 1);
	Bureaucrat  	hermes = Bureaucrat("Hermes Conrad", 24);
	Bureaucrat  	bob = Bureaucrat("Bobby Bobson", 123);
	OfficeBlock 	ob1;
	OfficeBlock 	ob2(&idiotOne, &hermes, &jesus);


	ob1.setIntern(idiotOne);
	ob1.setSigner(bob);
	ob1.setExecutor(hermes);

	std::cout	<< idiotOne << std::endl\
				<< jesus << std::endl\
				<< hermes << std::endl\
				<< bob << std::endl\
	<< std::endl;

	std::cout << std::endl;

	try
	{
		ob1.doBureaucracy("robotomy request", "Pigley");
	}
	catch (Form::GradeTooHighException & e)
	{
		std::cout << "Office 1 : " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cout << "Office 1 : " << e.what() << std::endl;
	}
	catch (Form::NoSignedException & e)
	{
		std::cout << "Office 1 : " << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Office 1 : Shutdown administration... THIS IS AMERICA !!!" << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		ob2.doBureaucracy("presidential pardon", "Pigley");
		std::cout << std::endl;
		ob2.doBureaucracy("shrubbery creation", "Pigley");
	}
	catch (Form::GradeTooHighException & e)
	{
		std::cout << "Office 1 : " << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException & e)
	{
		std::cout << "Office 1 : " << e.what() << std::endl;
	}
	catch (Form::NoSignedException & e)
	{
		std::cout << "Office 1 : " << e.what() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Office 1 : Shutdown administration... THIS IS AMERICA !!!" << e.what() << std::endl;
	}

	std::cout << std::endl;

	return (0);
}
