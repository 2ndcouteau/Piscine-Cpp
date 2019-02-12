/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:50:47 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/12 15:48:03 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_CLASS_HPP
# define SORCERER_CLASS_HPP

#include <iostream>
#include "Victim.hpp"

class Sorcerer
{
	private:
		std::string _name;
		std::string _title;

		Sorcerer(void);
	protected:


	public:
		Sorcerer(std::string name, std::string title);
		Sorcerer(Sorcerer const &src);
		~Sorcerer(void);

		std::string			introduce(void) const;
		void 				polymorph(Victim const &) const;

		std::string const &	getName(void) const;
		std::string const &	getTitle(void) const;

		Sorcerer &	operator=(Sorcerer const &rhs);
};

std::ostream &	operator<<(std::ostream &o, Sorcerer const &rhs);

#endif
