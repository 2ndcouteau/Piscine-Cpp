/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:50:11 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/12 15:43:40 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_CLASS_HPP
# define PEON_CLASS_HPP

#include <iostream>
#include "Victim.hpp"

class Peon : public Victim
{
	private:
		Peon(void);

	protected:


	public:
		Peon(std::string name);
		Peon(Peon const &src);
		~Peon(void);

		Peon &	operator=(Peon const &rhs);

		void	getPolymorphed() const;

};

#endif
