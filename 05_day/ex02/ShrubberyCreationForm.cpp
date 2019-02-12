/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:09:30 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/14 21:01:17 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form()
{
//	std::cout << " ShrubberyCreationForm Default Constructor " << std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
Form("Shrubbery Creation", 145, 137)
{
	this->_target = target;
	return;
}

std::string const & 	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}


void ShrubberyCreationForm::execute(Bureaucrat const &bur) const
{
	std::ofstream ofs;
	std::string filename;

	std::string str = "\
 .oo689ou.           .oo689ou.\n\
98O9PS9689P         98O9PS9689P\n\
S9968D8O886'        S9968D8O886'\n\
`9O89S9889'         `9O89S9889'\n\
  ``|&|''             ``|&|''\n\
    |%|                 |%|\n\
    |%|                 |%|\n\
   .:%:.               .:%:.\n";

	if (this->getSignedBool() == false)
		throw NoSignedException();
	else if (bur.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	else
	{
		filename = this->_target + "_shubbery";
		ofs.open(filename.data());
		if (ofs.is_open())
		{
			ofs << str;
			ofs.close();
			return;;
		}
		else
			std::cerr << "Can not write in the file" << std::endl;
	}
	return;
}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
{
//	std::cout << " ShrubberyCreationForm Copy Constructor " << std::endl;
	*this = src;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
//	std::cout << " ShrubberyCreationForm Destructor " << std::endl;
	return;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	Form::operator=(rhs);
	this->_target = rhs.getTarget();
	return *this;
}
