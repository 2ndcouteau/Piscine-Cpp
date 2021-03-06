/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 21:11:49 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/15 12:36:09 by qrosa            ###   ########.fr       */
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
		Form * ptr = new RobotomyRequestForm(target);
		std::cout	<< "Intern creates Robotomy Request Form (s.grade "\
					<< ptr->getGradeToSign() << ", ex.grade "\
					<< ptr->getGradeToExec()\
			 		<< ") targeted on " << target << " (" << ptr->signed_str(*ptr) << ")" << std::endl;
		return (ptr);
	}
	else if (!form.compare("shrubbery creation"))
	{
		Form * ptr = new ShrubberyCreationForm(target);
		std::cout	<< "Intern creates Shrubbery Creation Form (s.grade "\
					<< ptr->getGradeToSign() << ", ex.grade "\
					<< ptr->getGradeToExec()\
			 		<< ") targeted on " << target << " (" << ptr->signed_str(*ptr) << ")" << std::endl;
		return (ptr);	}
	else if (!form.compare("presidential pardon"))
	{
		Form * ptr = new PresidentialPardonForm(target);
		std::cout	<< "Intern creates Presidential Pardon Form (s.grade "\
					<< ptr->getGradeToSign() << ", ex.grade "\
					<< ptr->getGradeToExec()\
			 		<< ") targeted on " << target << " (" << ptr->signed_str(*ptr) << ")" << std::endl;
		return (ptr);	}
	else
		std::cout << "Intern can not create " << form << std::endl;
	return (NULL);
}



std::ostream&	operator<<(std::ostream& o, Intern const & rhs)
{
	o << "I am an intern. I have no soul.\n";
	return (o);
}
