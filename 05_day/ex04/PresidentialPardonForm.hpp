/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:41:40 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/15 12:06:18 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_CLASS_HPP
# define PRESIDENTIAL_PARDON_FORM_CLASS_HPP

#include <iostream>
#include "Form.hpp"
// #include "Bureaucrat.hpp"

class Form;
// class Bureaucrat;

class PresidentialPardonForm : public Form
{
	private:
		PresidentialPardonForm(void);
		std::string	_target;
	protected:


	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		virtual ~PresidentialPardonForm(void);

		std::string const &		getTarget(void) const;
		void 					execute(Bureaucrat const &bur) const;

		PresidentialPardonForm &	operator=(PresidentialPardonForm const &rhs);
};

//std::ostream &	operator<<(std::ostream &o, PresidentialPardonForm const &rhs);

#endif
