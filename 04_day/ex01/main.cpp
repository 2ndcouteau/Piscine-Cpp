/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:26:09 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/12 23:00:41 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "Character.hpp"


int main(void)
{
	Character* zaz = new Character("zaz");

	std::cout << *zaz;

	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();

	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz << std::endl << std::endl << std::endl;

	std::cout << "##Custom Part ##" << std::endl << std::endl;

	Enemy* c = new SuperMutant();
	Enemy* d = new RadScorpion();

	std::cout << *pr << *pf << std::endl;


	zaz->attack(c);
	zaz->attack(c);
	zaz->attack(c);
	zaz->attack(c);
	zaz->attack(c);

	zaz->recoverAP();
	zaz->recoverAP();
	zaz->recoverAP();
	zaz->recoverAP();
	zaz->recoverAP();

	std::cout << *zaz << std::endl;

	zaz->equip(pf);
	zaz->attack(c);
	zaz->attack(c);
	zaz->attack(c);

	zaz->equip(NULL);

	std::cout << *zaz << std::endl;
	return (0);
}
