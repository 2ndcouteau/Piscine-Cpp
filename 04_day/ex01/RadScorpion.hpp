/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:57:06 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/12 22:19:31 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAD_SCORPION_CLASS_HPP
# define RAD_SCORPION_CLASS_HPP

#include <iostream>
#include "Enemy.hpp"

class RadScorpion : public Enemy
{
	private:

	protected:


	public:
		RadScorpion(void);
		RadScorpion(RadScorpion const &src);
		~RadScorpion(void);

		RadScorpion &	operator=(RadScorpion const &rhs);
};


#endif
