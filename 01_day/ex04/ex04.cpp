/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex04.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 09:09:37 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/09 09:15:22 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string		str = "HI THIS IS BRAIN";

	std::string		*pt_str = &str;
	std::string		&r_str = str;


	std::cout << "pt_str == " << *pt_str << std::endl;
	std::cout << "r_str == " << r_str << std::endl;

	return (0);
}
