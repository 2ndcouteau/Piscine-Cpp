/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:02:52 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/08 16:33:24 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"

int main(void)
{
	std::cout << "Call Heap Function" << std::endl;
	Pony::ponyOnTheHeap();
	std::cout << "Heap Function Done" << std::endl << std::endl;


	std::cout << "Call Stack Function" << std::endl;
	Pony::ponyOnTheStack();
	std::cout << "Stack Function Done" << std::endl;

	return (0);
}
