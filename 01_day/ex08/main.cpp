/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 07:45:10 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/10 09:25:00 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

int main(void)
{
	Human	CRS("CRS");
	Human	GJ("GJ");
	Human	FRSD("French Sans-Dents");

	CRS.action("intimidating", FRSD.getName());
	GJ.action("melee", CRS.getName());
	CRS.action("ranged", GJ.getName());

	CRS.action("kiss", GJ.getName());

	return (0);
}
