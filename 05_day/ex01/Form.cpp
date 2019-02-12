/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:04:25 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/14 18:09:54 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) :
_name("Template Form"),
_signed(false),
_gradeToSign(1),
_gradeToExec(1)
{
//	std::cout << " Form Default Constructor " << std::endl;
	return;
}

Form::Form(std::string name, std::size_t gradeToSign, std::size_t gradeToExec) :
_name(name),
_signed(false),
_gradeToSign(gradeToSign),
_gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToSign > 150)
		(gradeToSign < 1) ? throw GradeTooLowException() : throw GradeTooHighException();
	if (gradeToExec < 1 || gradeToExec > 150)
		(gradeToExec < 1) ? throw GradeTooLowException() : throw GradeTooHighException();
	return;
}

Form::Form(Form const &src) :
_name("Template Form"),
_gradeToSign(1),
_gradeToExec(1)
{
//	std::cout << " Form Copy Constructor " << std::endl;
	*this = src;
	return;
}

Form::~Form(void)
{
//	std::cout << " Form Destructor " << std::endl;
	return;
}

// GET SET
std::string const &		Form::getName(void) const
{
	return (this->_name);
}

std::size_t				Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

std::size_t				Form::getGradeToExec(void) const
{
	return (this->_gradeToExec);
}

bool					Form::getSignedBool(void) const
{
	return (this->_signed);
}

void					Form::beSigned(Bureaucrat const & peon)
{
	if (peon.getGrade() > this->_gradeToSign)
		throw GradeTooLowException();
	else
		this->_signed |= true;
}


// OVERLOAD OPERATOR
Form &	Form::operator=(Form const &rhs)
{
	if (this != &rhs)
		this->_signed = rhs.getSignedBool();
	return (*this);
}

static std::string const signed_str(Form const & rhs)
{
	if (rhs.getSignedBool() == true)
		return ("SIGNED.");
	return ("NOT SIGNED.");
}

std::ostream&	operator<<(std::ostream& o, Form const & rhs)
{
	o << rhs.getName()	<< " form needs the level "\
	 					<< rhs.getGradeToSign() << " to be signed and the level "\
						<< rhs.getGradeToExec() << " to be exec." << std::endl;
	o << "Actually, the form is " << signed_str(rhs) << std::endl;
	return (o);
}
