/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 19:34:25 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/11 21:36:14 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJA_TRAP_CLASS_HPP
# define NINJA_TRAP_CLASS_HPP

#include <iostream>
#include "ClapTrap.hpp"

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public virtual ClapTrap
{
	private:

	protected:


	public:
		NinjaTrap(void);
		NinjaTrap(std::string name);
		NinjaTrap(NinjaTrap const &src);
		~NinjaTrap(void);

		NinjaTrap &	operator=(NinjaTrap const &rhs);


		void	ninjaShoebox(FragTrap & frag);
		void	ninjaShoebox(ScavTrap & scav);
		void	ninjaShoebox(NinjaTrap & ninja);

};

// std::ostream &	operator<<(std::ostream &o, NinjaTrap const &i);

#endif
