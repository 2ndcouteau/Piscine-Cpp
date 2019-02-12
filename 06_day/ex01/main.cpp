/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 18:40:27 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/16 09:27:53 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

struct Data
{
	std::string s1;
	int n;
	std::string s2;
};


void	*serialize(void)
{
	srand(time(NULL));
	int i = 0;
	char alphnum[37] = "abcdefghijklmnopqrstuvwxyz0123456789";
 	char 	*str = new char[20];
	int		random = rand();

	while (i < 20)
	{
		if (i < 7)
			str[i] = alphnum[rand() % 37];
		else if (i == 7)
			str[i] = 0;
		else if (i == 19)
			str[i] = 0;
		else if (i > 11)
			str[i] = alphnum[rand() % 37];
		else
			str[i] = reinterpret_cast<char*>(&random)[i - 8];
		i++;
	}
	std::cout 	<< "In serialize():\n" << std::endl\
				<< "str1          == " << str << std::endl\
				<< "Random number == " << random << std::endl\
				<< "str2          == " << str + 12 << std::endl;
	return (reinterpret_cast<void*>(str));
}

Data	*deserialize(void *raw)
{
	Data *data = new Data;

	data->s1 = reinterpret_cast<char *>(reinterpret_cast<int *>(raw));
	data->n = *reinterpret_cast<int *>(static_cast<char *>(raw) + 8);
	data->s2 = reinterpret_cast<char *>(reinterpret_cast<int *>(static_cast<char*>(raw) + 12));
	return (data);
}


int main(void)
{
	void *raw;
	struct Data *data;

	raw = serialize();
	data = deserialize(raw);
	std::cout << "\n-------------------------------------" << std::endl;
	std::cout 	<< "\nIn main after deserialize() return: \n" << std::endl\
				<< "S1 = " << data->s1 << std::endl\
				<< "N  = " << data->n << std::endl\
				<< "S2 = " << data->s2 << std::endl;
	return (0);
}
