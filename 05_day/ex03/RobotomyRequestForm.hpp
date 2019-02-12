/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 19:39:54 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/14 20:48:53 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_CLASS_HPP
# define ROBOTOMY_REQUEST_FORM_CLASS_HPP

#include <iostream>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		RobotomyRequestForm(void);
		std::string	_target;

	protected:


	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		~RobotomyRequestForm(void);

		std::string const &		getTarget(void) const;
		void 					execute(Bureaucrat const &bur) const;


		RobotomyRequestForm &	operator=(RobotomyRequestForm const &rhs);
};


#endif
