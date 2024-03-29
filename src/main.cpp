/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:48:29 by anri              #+#    #+#             */
/*   Updated: 2019/10/24 13:42:34 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Program.hpp"

int		main( int argc, char ** argv) {
	try
	{
		Program program;
		if (argc == 1)
			program.run();
		else
			program.run(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
