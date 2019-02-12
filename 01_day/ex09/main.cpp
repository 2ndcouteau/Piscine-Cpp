/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 10:01:36 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/10 10:47:31 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"

int main(void)
{
	Logger	Session = Logger("file.log");

	Session.log("console", "Hello !");
	Session.log("console", "What's up ?");
	Session.log("console", "Have a good year !");
	Session.log("console", "2019 is gonna be FUNKY");
	Session.log("console", "\\o/");

	Session.log("file", "Salut !");
	Session.log("file", "Ca va ?");
	Session.log("file", "ASV ?");
	Session.log("file", "19ans");
	Session.log("file", "M");
	Session.log("file", "Paris");
	return (0);
}
