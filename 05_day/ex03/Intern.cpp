/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 21:11:49 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/14 21:36:37 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
//	std::cout << " Intern Default Constructor " << std::endl;
	return;
}

Intern::Intern(Intern const &src)
{
//	std::cout << " Intern Copy Constructor " << std::endl;
	*this = src;
	return;
}

Intern::~Intern(void)
{
//	std::cout << " Intern Destructor " << std::endl;
	return;
}

Intern &	Intern::operator=(Intern const &rhs)
{
	return *this;
}

Form * Intern::makeForm(std::string form, std::string target)
{
	if (!form.compare("robotomy request"))
	{
		std::cout << "Intern creates " << form << " form." << std::endl;
		return (new RobotomyRequestForm(target));
	}
	else if (!form.compare("shrubbery creation"))
	{
		std::cout << "Intern creates " << form << " form." << std::endl;
		return (new ShrubberyCreationForm(target));
	}
	else if (!form.compare("presidential pardon"))
	{
		std::cout << "Intern creates " << form << " form." << std::endl;
		return (new PresidentialPardonForm(target));
	}
	else
		std::cout << "Intern can not create " << form << std::endl;
	return (NULL);
}



std::ostream&	operator<<(std::ostream& o, Intern const & rhs)
{
	o << "I am an intern. I have no soul.";
	return (o);
}
