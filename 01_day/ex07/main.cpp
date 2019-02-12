/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:18:13 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/10 10:18:52 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

// #include <sys/stat.h>


// static bool file_exists(const std::string& name)
// {
// 	struct stat		buffer;
//
// 	return (stat (name.c_str(), &buffer) == 0);
// }

static int		error_params(std::string err_message)
{
	std::cerr	<< err_message << std::endl\
				<< "./replace FILENAME 'STR1' STR2'" << std::endl;
	exit(1);
}


static void		check_args(std::string filename, std::string str1, std::string str2)
{
	if (filename.empty() || str1.empty() || str2.empty())
		error_params("Error: Bad Format Params");
	if (!str1.compare(str2))
		error_params("Error: STR1 and STR2 are equal. Nothing to do.");
}


void	search_and_replace(std::string filename, std::string str1, std::string str2)
{
	std::size_t	pos = 0;

	std::string file, tmp_line = "";

	std::ifstream ifs;
	std::ofstream ofs;


	check_args(filename, str1, str2);


	ifs.open(filename.data());
	if (ifs.is_open())
	{
		// Get all the file
		while (getline(ifs, tmp_line))
		{
			if (!tmp_line.empty())
			{
				file += tmp_line;
				file += "\n";
			}
		}

		// Parse and replace
		while ((pos = file.find(str1)) != std::string::npos)
			file.replace(pos, str1.length(), str2);

		ifs.close();

		// Create and write the FILENAME.replace
		filename += ".replace";
		ofs.open(filename.data());
		if (ofs.is_open())
		{
			ofs << file;
			ofs.close();
			exit(0);
		}
		else
			std::cerr << "Can not write in the file" << std::endl;
	}
	else
	std::cerr << "Can not open the file" << std::endl;
	exit(1);
}

int		main(int argc, char **argv)
{
	if (argc != 4)
		return (error_params("Error: Bad number parameters"));

	search_and_replace(std::string(argv[1]), std::string(argv[2]), std::string(argv[3]));


	return (0);
}
