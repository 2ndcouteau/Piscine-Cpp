/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 21:11:36 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/14 21:30:37 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP

#include <iostream>
#include "Form.hpp"

class Intern
{
	private:

	protected:


	public:
		Intern(void);
		Intern(Intern const &src);
		~Intern(void);

		Intern &	operator=(Intern const &rhs);

		Form * makeForm(std::string form, std::string target);
};

std::ostream &	operator<<(std::ostream &o, Intern const &rhs);

#endif
