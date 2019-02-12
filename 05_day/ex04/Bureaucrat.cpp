/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:07:16 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/15 13:22:33 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(void)
{
//	std::cout << " Bureaucrat Default Constructor " << std::endl;
	return;
}

Bureaucrat::Bureaucrat(std::string name, size_t grade) : _name(name), _grade(grade)
{
	if (grade < 1 || grade > 150)
		(grade < 1) ? throw GradeTooLowException() : throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
//	std::cout << " Bureaucrat Copy Constructor " << std::endl;
	*this = src;
	return;
}

Bureaucrat::~Bureaucrat(void)
{
//	std::cout << " Bureaucrat Destructor " << std::endl;
	return;
}

void			Bureaucrat::inc_grade()
{
	if ((this->_grade - 1) < 1)
		throw GradeTooHighException();
	else
		this->_grade -= 1;
}

void			Bureaucrat::dec_grade()
{
	if ((this->_grade + 1) > 150)
		throw GradeTooLowException();
	else
		this->_grade += 1;
}

void					Bureaucrat::signForm(Form& form)
{
	form.beSigned(*this);
	std::cout	<< "Bureaucrat " << this->_name << " (" << this->_grade\
				<< ") signs " << form.getName() << " Form (s_grade " << form.getGradeToSign()\
				<< ", ex.grade " << form.getGradeToExec() << ")"\
				<< " (" << form.signed_str(form) << ")" << std::endl;
}

// void					Bureaucrat::signForm(ShrubberyCreationForm& form)
// {
// 	try {
// 		form.beSigned(*this);
// 	}
// 	catch (std::exception const &e) {
// 		std::cout	<< "Bureaucrat " << this->_name << " cannot sign " << form.getName()\
// 		 			<< " because " << e.what() << std::endl;
// 		return;
// 	}
// 	std::cout	<< "Bureaucrat " << this->_name << "(" << this->_grade\
// 				<< ") signs " << form.getName() << " Form (s_grade " << form.getGradeToSign()\
// 				<< form.getGradeToSign() << ") targeted on " << form.getTarget()\
// 				<< " (" << form.signed_str(form) << ")" << std::endl;
// }
//
// void					Bureaucrat::signForm(RobotomyRequestForm& form)
// {
// 	try {
// 		form.beSigned(*this);
// 	}
// 	catch (std::exception const &e) {
// 		std::cout	<< "Bureaucrat " << this->_name << " cannot sign " << form.getName()\
// 		 			<< " because " << e.what() << std::endl;
// 		return;
// 	}
// 	std::cout	<< "Bureaucrat " << this->_name << "(" << this->_grade\
// 				<< ") signs " << form.getName() << " Form (s_grade " << form.getGradeToSign()\
// 				<< form.getGradeToSign() << ") targeted on " << form.getTarget()\
// 				<< " (" << form.signed_str(form) << ")" << std::endl;
// }
//
// void					Bureaucrat::signForm(PresidentialPardonForm& form)
// {
// 	try {
// 		form.beSigned(*this);
// 	}
// 	catch (std::exception const &e) {
// 		std::cout	<< "Bureaucrat " << this->_name << " cannot sign " << form.getName()\
// 		 			<< " because " << e.what() << std::endl;
// 		return;
// 	}
// 	std::cout	<< "Bureaucrat " << this->_name << "(" << this->_grade\
// 				<< ") signs " << form.getName() << " Form (s_grade " << form.getGradeToSign()\
// 				<< form.getGradeToSign() << ") targeted on " << form.getTarget()\
// 				<< " (" << form.signed_str(form) << ")" << std::endl;
// }




// GET SET

std::string const &		Bureaucrat::getName(void) const
{
	return (this->_name);
}

std::size_t				Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}


// Overload Operator
Bureaucrat &	Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return (*this);
}

std::ostream&	operator<<(std::ostream& o, Bureaucrat const & rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "." << std::endl;
	return (o);
}
