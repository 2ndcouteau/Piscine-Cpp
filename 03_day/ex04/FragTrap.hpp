/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 09:54:16 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/11 21:35:56 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_CLASS_HPP
# define FRAG_TRAP_CLASS_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
	private:

	protected:


	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const &src);
		~FragTrap(void);

		FragTrap &	operator=(FragTrap const &rhs);

		void 	vaulthunter_dot_exe(std::string const & target);
};

// std::ostream &	operator<<(std::ostream &o, FragTrap const &i);

#endif
