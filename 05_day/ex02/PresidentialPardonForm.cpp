/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:42:12 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/14 21:09:05 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(void) : Form()
{
//	std::cout << " PresidentialPardonForm Default Constructor " << std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
Form("Presidential Pardon", 25, 5)
{
	this->_target = target;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src)
{
//	std::cout << " PresidentialPardonForm Copy Constructor " << std::endl;
	*this = src;
	return;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
//	std::cout << " PresidentialPardonForm Destructor " << std::endl;
	return;
}

std::string const & 	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	Form::operator=(rhs);
	this->_target = rhs.getTarget();
	return *this;
}

void 			PresidentialPardonForm::execute(Bureaucrat const &bur) const
{
	if (this->getSignedBool() == false)
		throw NoSignedException();
	else if (bur.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	else
		std::cout << this->_target << " as been pardoned by Zaphod Beeblebrox" << std::endl;
	return;
}
