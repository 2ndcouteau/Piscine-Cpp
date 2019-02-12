/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:08:49 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/15 12:06:07 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHUBBRY_CREATION_FORM_CLASS_HPP
# define SHUBBRY_CREATION_FORM_CLASS_HPP

#include <iostream>
#include "Form.hpp"
// #include "Bureaucrat.hpp"

class Form;
// class Bureaucrat;

class ShrubberyCreationForm : public Form
{
	private:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const &rhs);
		std::string	_target;

	protected:


	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		~ShrubberyCreationForm(void);

		std::string const &	getTarget(void) const;
		void				execute(Bureaucrat const &bur) const;
};

#endif
