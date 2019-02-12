/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 13:07:42 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/15 11:58:58 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

#include <iostream>
#include <exception>

// #include "ShrubberyCreationForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "PresidentialPardonForm.hpp"
#include "Form.hpp"


class Form;
// class ShrubberyCreationForm;
// class RobotomyRequestForm;
// class PresidentialPardonForm;



class Bureaucrat
{
	private:
		std::string const	_name;
		std::size_t			_grade;
		Bureaucrat(void);

	protected:


	public:
		Bureaucrat(std::string name, size_t grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat(void);

		std::string const &		getName(void) const;
		std::size_t				getGrade(void) const;

		void					inc_grade();
		void					dec_grade();

		void					signForm(Form& form);
		// void					signForm(ShrubberyCreationForm& form);
		// void					signForm(RobotomyRequestForm& form);
		// void					signForm(PresidentialPardonForm& form);

		Bureaucrat &	operator=(Bureaucrat const &rhs);


		class GradeTooHighException : public std::exception
		{
			private:
				GradeTooHighException &	operator=(GradeTooHighException const &rhs);

			public:
				GradeTooHighException(void){};
				GradeTooHighException(GradeTooHighException const &src) : std::exception(src){};
				~GradeTooHighException(void) throw(){};

				virtual const char* what() const throw() {
					return ("Bureaucrat Grade Level Too High");
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
					return ("Bureaucrat Grade Level Too Low");
				}
		};
};

std::ostream &	operator<<(std::ostream &o, Bureaucrat const &rhs);


#endif
