/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:41:30 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/14 21:08:59 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form()
{
//	std::cout << " RobotomyRequestForm Default Constructor " << std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
Form("Robotomy Request", 72, 45)
{
	this->_target = target;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
{
//	std::cout << " RobotomyRequestForm Copy Constructor " << std::endl;
	*this = src;
	return;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
//	std::cout << " RobotomyRequestForm Destructor " << std::endl;
	return;
}

std::string const & 	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}


RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	Form::operator=(rhs);
	this->_target = rhs.getTarget();
	return *this;
}


void 			RobotomyRequestForm::execute(Bureaucrat const &bur) const
{
	if (this->getSignedBool() == false)
		throw NoSignedException();
	else if (bur.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	else
	{
		if (rand() % 2)
			std::cout << this->_target << " has been robotomized successfully." << std::endl;
		else
			std::cout << "It’s a failure." << std::endl;
	}
	return;
}
