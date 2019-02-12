/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:04:34 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/14 17:56:16 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		std::size_t const	_gradeToSign;
		std::size_t const	_gradeToExec;
		Form(void);

	protected:


	public:
		Form(std::string name, std::size_t gradeToSign, std::size_t gradeToExec);
		Form(Form const &src);
		~Form(void);

		Form &	operator=(Form const &rhs);

		std::string const &		getName(void) const;
		std::size_t				getGradeToSign(void) const;
		std::size_t				getGradeToExec(void) const;
		bool					getSignedBool(void) const;

		void					beSigned(Bureaucrat const & peon);


		class GradeTooHighException : public std::exception
		{
			private:
				GradeTooHighException &	operator=(GradeTooHighException const &rhs);

			public:
				GradeTooHighException(void){};
				GradeTooHighException(GradeTooHighException const &src) : std::exception(src){};
				~GradeTooHighException(void) throw(){};

				virtual const char* what() const throw() {
					return ("Form Grade Level Too High");
				}
		};


		class GradeTooLowException : public std::exception
		{
			private:
				GradeTooLowException &	operator=(GradeTooLowException const &rhs);

			public:
				GradeTooLowException(void){};
				GradeTooLowException(GradeTooLowException const &src) : std::exception(src){};
				~GradeTooLowException(void) throw(){};

				virtual const char* what() const throw() {
					return ("Form Grade Level Too Low");
				}
		};

};

std::ostream &	operator<<(std::ostream &o, Form const &rhs);

#endif
