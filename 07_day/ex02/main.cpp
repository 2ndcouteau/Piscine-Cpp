/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:54:17 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/17 17:56:26 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	Array<int> test;
	Array<double> answer(42);
	Array<double> answer_bis(answer);
	Array<double> answer_ter = answer;


	std::cout << "Answer should be 0 --> " << answer[24] << std::endl;
	std::cout << "Answer_bis should be 0 --> " << answer_bis[12] << std::endl;
	std::cout << "Answer_ter should be 0 --> " << answer_ter[41] << std::endl;

	std::cout << "size test: 0 --> " << test.size() << std::endl;
	std::cout << "size answer: 42 --> " << answer.size() << std::endl;
	std::cout << "size answer_bis: 42 --> " << answer_bis.size() << std::endl;
	std::cout << "size answer_ter: 42 -->" << answer_ter.size() << std::endl;

	std::cout << std::endl;

	answer[4] = 4242424242424242;
	answer_bis[5] = static_cast<double>(42);
	answer_ter[6] = 21;
	std::cout	<< "Arrays content :" << std::endl\
				<< "Answer : " << answer[4] << std::endl\
				<< "Answer_bis : " << answer_bis[5] << std::endl\
				<< "Answer_ter : " << answer_ter[6] << std::endl;


	Array<std::string> str(42);
	str[11] = "On en a gros !";
	std::cout << str[11] << std::endl;

	try {
		std::cout << str[1] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "exception found : " << e.what() << std::endl;
	}

	try {
		std::cout << str[-11] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "exception found : " << e.what() << std::endl;
	}

	try {
		std::cout << str[11] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "exception found : " << e.what() << std::endl;
	}

	return (0);
}
