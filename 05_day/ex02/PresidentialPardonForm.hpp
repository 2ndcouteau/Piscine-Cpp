/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:41:40 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/14 20:47:33 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_CLASS_HPP
# define PRESIDENTIAL_PARDON_FORM_CLASS_HPP

#include <iostream>
#include "Form.hpp"

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
