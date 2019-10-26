/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:05:32 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/10/26 14:58:28 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"

void	Lexer::checkAll( std::istream & i ) {
	static std::regex	exit_regex("(\\s)*(exit|;;)(\\s)*(;(.+))*");
	int		line = 1;
	bool	exit_flag = false;
	bool	err = false;

	for (std::string str; std::getline(i, str); line++)
	{
		if (std::regex_match(str, exit_regex))
		{
			exit_flag = true;
			break ;
		}
		if (check_line( str ))
		{
			err = true;
			std::cerr << "Lexical error on line " << line << std::endl;
		}
	}
	if (err)
		throw LexicalError();
	if (!exit_flag)
		throw NoExitException();
}

bool	Lexer::check_line( std::string str ) {
	static std::vector<std::regex> regex_vector = { std::regex("(\\s)*dump(\\s)*(;(.+))*"), \
													std::regex("(\\s)*pop(\\s)*(;(.+))*"), \
													std::regex("(\\s)*add(\\s)*(;(.+))*"), \
													std::regex("(\\s)*sub(\\s)*(;(.+))*"), \
													std::regex("(\\s)*mul(\\s)*(;(.+))*"), \
													std::regex("(\\s)*div(\\s)*(;(.+))*"), \
													std::regex("(\\s)*mod(\\s)*(;(.+))*"), \
													std::regex("(\\s)*print(\\s)*(;(.+))*"), \
													std::regex("(\\s)*"), \
													std::regex("\\s*(;(.+))*"), \
													std::regex("\\s*push\\s+"
																"(int8|int16|int32|float|double)"
																"\\((\\+|-)?[\\d]+(\\.[\\d]+)?\\)"
																"\\s*(;(.+))*"), \
													std::regex("(\\s)*assert(\\s)*"
																"(int8|int16|int32|float|double)"
																"\\((\\+|-)?[\\d]+(\\.[\\d]+)?\\)"
																"\\s*(;(.+))*")};
	bool isMatch = false;

	for ( const auto& reg : regex_vector )
		if (std::regex_match(str, reg))
		{
			isMatch = true;
			break ;
		}
	return (isMatch);
}