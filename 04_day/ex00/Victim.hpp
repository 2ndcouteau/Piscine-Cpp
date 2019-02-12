/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:51:18 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/12 18:25:10 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_CLASS_HPP
# define VICTIM_CLASS_HPP

#include <iostream>

class Victim
{
	private:

	protected:
		Victim(void);
		std::string _name;

	public:
		Victim(std::string name);
		Victim(Victim const &src);
		virtual ~Victim(void);

		std::string 	introduce() const;

		virtual void	getPolymorphed() const;

		std::string const &	getName(void) const;

		Victim &	operator=(Victim const &rhs);
};

std::ostream &	operator<<(std::ostream &o, Victim const &rhs);

#endif
