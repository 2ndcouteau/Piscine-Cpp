/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 10:01:35 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/10 10:53:04 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGER_CLASS_HPP
# define LOGGER_CLASS_HPP

#include <iostream>

class Logger
{
	private:
		void		logToConsole(std::string const &str);
		void 		logToFile(std::string const &str);
		std::string	makeLogEntry(std::string const &str);

		std::string const _logfile;

	public:
		Logger(std::string logfile);
		~Logger(void);

		void	log(std::string const & dest, std::string const & message);
};

#endif
