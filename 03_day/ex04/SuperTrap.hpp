/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 21:31:53 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/11 23:39:49 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPER_TRAP_CLASS_HPP
# define SUPER_TRAP_CLASS_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
	private:
		SuperTrap(void);

	protected:


	public:
		SuperTrap(std::string name);
		SuperTrap(SuperTrap const &src);
		~SuperTrap(void);


		SuperTrap &	operator=(SuperTrap const &rhs);
};

#endif
