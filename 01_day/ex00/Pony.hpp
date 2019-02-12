/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:02:54 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/08 16:22:22 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_CLASS_HPP
# define PONY_CLASS_HPP

#include <iostream>

class Pony
{
	private:
		std::string _name;


	public:
		Pony(std::string name);
		~Pony(void);


		static void	ponyOnTheHeap(void);
		static void	ponyOnTheStack(void);
};


#endif
