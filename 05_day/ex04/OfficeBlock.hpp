/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OfficeBlock.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 10:29:15 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/15 12:29:29 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFICE_BLOCK_CLASS_HPP
# define OFFICE_BLOCK_CLASS_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

class OfficeBlock
{
	private:
		Intern		*_pt_intern;
		Bureaucrat	*_pt_sign;
		Bureaucrat	*_pt_exec;

		OfficeBlock(OfficeBlock const &src);
		OfficeBlock &	operator=(OfficeBlock const &rhs);

	protected:

	public:
		OfficeBlock(void);
		OfficeBlock(Intern * intern, Bureaucrat * signer, Bureaucrat * executor);

		~OfficeBlock(void);

		void			doBureaucracy(std::string form, std::string target);

		void			setIntern(Intern & intern);
		void			setSigner(Bureaucrat & signer);
		void			setExecutor(Bureaucrat & exec);

		Intern *		getIntern() const ;
		Bureaucrat *	getSigner() const ;
		Bureaucrat *	getExecutor() const ;


};

//std::ostream &	operator<<(std::ostream &o, OfficeBlock const &rhs);

#endif
