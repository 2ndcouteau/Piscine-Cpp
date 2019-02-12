/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 07:37:46 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/10 09:23:51 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"

// typedef "return type" (*name_ptr)(args type only)
// typedef int (*foo_ptr_t)( int );
// foo_ptr_t foo_ptr_array[2];

typedef void (Human::*t_attacks)(std::string const &);

static void	print_action
(std::string name, std::string attack_name, std::string const target)
{
	std::cout	<< name\
				<< " use "\
				<< attack_name\
				<< " on "\
				<< target\
				<< std::endl;

}

void Human::meleeAttack(std::string const & target)
{
	print_action(this->_name, "Melee Attack", target);
}

void Human::rangedAttack(std::string const & target)
{
	print_action(this->_name, "Ranged Attack", target);
}

void Human::intimidatingShout(std::string const & target)
{
	print_action(this->_name, "Intimidating Shout", target);
}


void Human::action(std::string const & action_name, std::string const & target)
{
	std::string	attack_names[3] = {"melee", "ranged", "intimidating"};
	t_attacks attacks_arr[3] = {\
			&Human::meleeAttack,
			&Human::rangedAttack,
			&Human::intimidatingShout,
	};


	std::size_t i = 0;
	while (i < (sizeof(attack_names) / sizeof(attack_names[0])))
	{
		if (!action_name.compare(attack_names[i]))
		{
			(this->*attacks_arr[i])(target);
			return;
		}
		i++;
	}
	std::cerr << "Error: Bad action." << std::endl;
}


std::string		Human::getName() const
{
	return (this->_name);
}

Human::Human(std::string name) : _name(name)
{
//	std::cout << " Human Constructor " << std::endl;
	return;
}

Human::~Human(void)
{
//	std::cout << " Human Destructor " << std::endl;
	return;
}
