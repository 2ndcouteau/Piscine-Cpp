/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 09:53:47 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/11 19:15:58 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
//#include "ClapTrap.hpp"

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

	std::cout << "\n##########\n# SCAV PART #\n##########" << std::endl;

	ScavTrap good("The Good");
	ScavTrap bad("The Bad");

	ScavTrap ugly("The Ugly");

	good.display_profile();
	bad.display_profile();

	good.rangedAttack("bad");
	bad.takeDamage(good.getRangedAttack());
	good.rangedAttack("bad");
	bad.takeDamage(good.getRangedAttack());

	bad.meleeAttack("good");
	good.takeDamage(bad.getMeleeAttack());
	bad.meleeAttack("good");
	good.takeDamage(bad.getMeleeAttack());
	bad.meleeAttack("good");
	good.takeDamage(bad.getMeleeAttack());
	bad.meleeAttack("good");
	good.takeDamage(bad.getMeleeAttack());

	std::cout << "\nBad Hit point = " << bad.getHitPoints() << std::endl;
	std::cout << "Blue Hit points = " << good.getHitPoints() << std::endl << std::endl;

	bad.beRepaired(10);
	good.beRepaired(142);

	std::cout << "\nBad Hit point = " << bad.getHitPoints() << std::endl;
	std::cout << "Blue Hit points = " << good.getHitPoints() << std::endl << std::endl;

	bad.challengeNewcomer("good");
	bad.challengeNewcomer("good");
	bad.challengeNewcomer("good");
	bad.challengeNewcomer("good");
	bad.challengeNewcomer("good");


	good.challengeNewcomer("bad");
	good.challengeNewcomer("bad");
	good.challengeNewcomer("bad");
	good.challengeNewcomer("bad");
	good.challengeNewcomer("bad");

	good.display_profile();
	bad.display_profile();

	ugly = bad;

	std::cout << "\nUgly profile:" << std::endl;

	ugly.display_profile();


	return (0);
}
