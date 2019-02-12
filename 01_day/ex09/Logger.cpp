/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 10:01:33 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/10 11:04:29 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Logger.hpp"
#include <fstream>

typedef void (Logger::*t_dest)(std::string const &);

std::string Logger::makeLogEntry(std::string const &message)
{
	std::string	logline;

	char date[20] = { 0 };
	time_t time = std::time(NULL);

	std::strftime(date, 15, "%Y/%m/%d_%H:%M:%S" , std::localtime(&time));

	logline = "[" + std::string (date) + "] " + message + "\n";

	return (logline);
}

void		Logger::logToConsole(std::string const &str)
{
	std::string logline = this->makeLogEntry(str);

	std::cout << logline << std::endl;
}

void		Logger::logToFile(std::string const &str)
{
	std::ofstream	ofs;
	std::string logline = this->makeLogEntry(str);

	ofs.open(this->_logfile.data(), std::ios::app|std::ios::ate);
	if (ofs.is_open())
	{
		ofs << logline;
		ofs.close();
		return;
	}
	else
		std::cerr << "Can not write in the file" << std::endl;
}

void	Logger::log(std::string const & dest, std::string const & message)
{
	std::string	dest_name[2] = {"file", "console"};
	t_dest dest_fn[2] = {\
		&Logger::logToFile,
		&Logger::logToConsole,
	};

	std::size_t i = 0;
	while (i < (sizeof(dest_fn) / sizeof(dest_fn[0])))
	{
		if (!dest.compare(dest_name[i]))
		{
			(this->*dest_fn[i])(message);
			return;
		}
		i++;
	}
	std::cerr << "Error: Unknown Destination." << std::endl;
}


Logger::Logger(std::string logfile) : _logfile(logfile)
{
//	std::cout << " Logger Constructor " << std::endl;
	return;
}

Logger::~Logger(void)
{
//	std::cout << " Logger Destructor " << std::endl;
	return;
}
