/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 09:17:26 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/09 11:40:13 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_CLASS_HPP
# define HUMAN_CLASS_HPP

#include "Brain.hpp"

class Human
{

	public:
		Human(void);
		~Human(void);


		std::string	identify(void) const;
		Brain		&getBrain(void) const;

	private:
		Brain const _brain;
};

#endif
