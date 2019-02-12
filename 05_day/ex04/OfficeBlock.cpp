/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:29:17 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/15 13:28:51 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OfficeBlock.hpp"


OfficeBlock::OfficeBlock(void)
{
//	std::cout << " OfficeBlock Default Constructor " << std::endl;
	return;
}

OfficeBlock::OfficeBlock(Intern * intern, Bureaucrat * signer, Bureaucrat * executor) :
_pt_intern(intern),
_pt_sign(signer),
_pt_exec(executor)
{
	return;
}

OfficeBlock::OfficeBlock(OfficeBlock const &src)
{
//	std::cout << " OfficeBlock Copy Constructor " << std::endl;
	*this = src;
	return;
}

OfficeBlock::~OfficeBlock(void)
{
//	std::cout << " OfficeBlock Destructor " << std::endl;
	return;
}

OfficeBlock &	OfficeBlock::operator=(OfficeBlock const &rhs)
{
//	std::cout << " OfficeBlock Assignement Operator " << std::endl;

	// if (this != &rhs)
//		this->_foo = rhs.getFoo();

	return *this;
}


void 			OfficeBlock::doBureaucracy(std::string form, std::string target)
{
	Form*   rrf;

	rrf = this->_pt_intern->makeForm(form, target);
	if (rrf != NULL)
	{
		this->_pt_sign->signForm(*rrf);

		if (rrf->getSignedBool() == true)
			rrf->execute(*this->_pt_exec);
	}
	return;
}

void			OfficeBlock::setIntern(Intern & intern)
{
	this->_pt_intern = &intern;
	return;
}

void			OfficeBlock::setSigner(Bureaucrat & signer)
{
	this->_pt_sign = &signer;
	return;
}

void			OfficeBlock::setExecutor(Bureaucrat & exec)
{
	this->_pt_exec = &exec;
	return;
}


Intern *		OfficeBlock::getIntern() const
{
	return (this->_pt_intern);
}

Bureaucrat *	OfficeBlock::getSigner() const
{
	return (this->_pt_sign);
}

Bureaucrat *	OfficeBlock::getExecutor() const
{
	return (this->_pt_exec);
}
