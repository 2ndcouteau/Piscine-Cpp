/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:23:49 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/12 21:16:14 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPER_MUTANT_CLASS_HPP
# define SUPER_MUTANT_CLASS_HPP

#include <iostream>
#include "Enemy.hpp"

class SuperMutant : public Enemy
{
	private:

	protected:
		int		_armor;

	public:
		SuperMutant(void);
		SuperMutant(SuperMutant const &src);
		SuperMutant &	operator=(SuperMutant const &rhs);
		~SuperMutant(void);

		void	takeDamage(int);

		int		getArmor() const;
};

#endif
