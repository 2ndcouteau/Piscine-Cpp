/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 09:53:47 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/11 23:36:33 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

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


//----------------------------------------------------------------------------//
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


//----------------------------------------------------------------------------//
	std::cout << "\n##########\n# NINJA PART #\n##########" << std::endl;

	NinjaTrap kin("Kin");
	NinjaTrap buronzu("Buronzu");

	NinjaTrap kami("Kami");

	kin.display_profile();
	buronzu.display_profile();

	kin.rangedAttack("buronzu");
	buronzu.takeDamage(kin.getRangedAttack());
	kin.rangedAttack("buronzu");
	buronzu.takeDamage(kin.getRangedAttack());

	buronzu.meleeAttack("kin");
	kin.takeDamage(buronzu.getMeleeAttack());
	buronzu.meleeAttack("kin");
	kin.takeDamage(buronzu.getMeleeAttack());
	buronzu.meleeAttack("kin");
	kin.takeDamage(buronzu.getMeleeAttack());
	buronzu.meleeAttack("kin");
	kin.takeDamage(buronzu.getMeleeAttack());

	std::cout << "\nBuronzu Hit point = " << buronzu.getHitPoints() << std::endl;
	std::cout << "Kin Hit points = " << kin.getHitPoints() << std::endl << std::endl;

	buronzu.beRepaired(10);
	kin.beRepaired(142);

	std::cout << "\nBuronzu Hit point = " << buronzu.getHitPoints() << std::endl;
	std::cout << "Kin Hit points = " << kin.getHitPoints() << std::endl << std::endl;

	buronzu.ninjaShoebox(blue); // frag
	buronzu.ninjaShoebox(good); // scav
	buronzu.ninjaShoebox(kin); // ninja

	std::cout << std::endl;

	kin.display_profile();
	buronzu.display_profile();

	kami = buronzu;

	std::cout << "\nKami profile:" << std::endl;

	kami.display_profile();


	NinjaTrap random1 = NinjaTrap();
	FragTrap  random2 = FragTrap();
	ScavTrap  random3 = ScavTrap();

	random1.display_profile();
	random2.display_profile();
	random3.display_profile();

	std::cout << "\n##########\n# SUPERTRAP PART #\n##########" << std::endl;

	SuperTrap	superman("Superman");

	superman.display_profile();

	std::cout << std::endl;

	superman.vaulthunter_dot_exe("2Pac");
	superman.ninjaShoebox(kin);

	std::cout << std::endl;
	return (0);
}
