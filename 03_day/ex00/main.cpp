/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 09:53:47 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/11 15:41:16 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap blue("Blue");
	FragTrap red("Red");

	FragTrap green("Green");

	blue.display_profile();
	red.display_profile();

	blue.rangedAttack("red");
	red.takeDamage(blue.getRangedAttack());
	blue.rangedAttack("red");
	red.takeDamage(blue.getRangedAttack());

	red.meleeAttack("blue");
	blue.takeDamage(red.getMeleeAttack());
	red.meleeAttack("blue");
	blue.takeDamage(red.getMeleeAttack());
	red.meleeAttack("blue");
	blue.takeDamage(red.getMeleeAttack());
	red.meleeAttack("blue");
	blue.takeDamage(red.getMeleeAttack());

	std::cout << "\nRed Hit point = " << red.getHitPoints() << std::endl;
	std::cout << "Blue Hit points = " << blue.getHitPoints() << std::endl << std::endl;

	red.beRepaired(10);
	blue.beRepaired(142);

	std::cout << "\nRed Hit point = " << red.getHitPoints() << std::endl;
	std::cout << "Blue Hit points = " << blue.getHitPoints() << std::endl << std::endl;

	red.vaulthunter_dot_exe("blue");
	red.vaulthunter_dot_exe("blue");
	red.vaulthunter_dot_exe("blue");
	red.vaulthunter_dot_exe("blue");
	red.vaulthunter_dot_exe("blue");


	blue.vaulthunter_dot_exe("red");
	blue.vaulthunter_dot_exe("red");
	blue.vaulthunter_dot_exe("red");
	blue.vaulthunter_dot_exe("red");
	blue.vaulthunter_dot_exe("red");

	blue.display_profile();
	red.display_profile();

	green = red;

	std::cout << "\nGreen profile:" << std::endl;

	green.display_profile();

	return (0);
}
