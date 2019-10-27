/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:15:32 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/10/27 19:38:16 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

void Parser::getMatches( std::istream & i, std::string & command, eOperandType & type, std::string &value ) {
	static std::vector<std::regex> regex_vector = { std::regex("(dump)"), \
													std::regex("(pop)"), \
													std::regex("(add)"), \
													std::regex("(sub)"), \
													std::regex("(mul)"), \
													std::regex("(div)"), \
													std::regex("(mod)"), \
													std::regex("(print)"), \
													std::regex("(\\s)*"), \
													std::regex("\\s*(;(.+))*"), \
													std::regex("\\s*(push)\\s+"
																"(int8|int16|int32|float|double)"
																"\\(((\\+|-)?[\\d]+(\\.[\\d]+)?)\\)"
																"\\s*(;(.+))*"), \
													std::regex("\\s*(assert)\\s*"
																"(int8|int16|int32|float|double)"
																"\\(((\\+|-)?[\\d]+(\\.[\\d]+)?)\\)"
																"\\s*(;(.+))*")};

	std::string str;
	std::smatch sm;
	std::getline(i, str);
	for ( const auto& reg : regex_vector )
		if (std::regex_match(str, sm, reg))
			break ;
			
	command = sm.str(1);
	if (command == "push" || command == "assert")
	{ 
		type = strToEnum(sm.str(2));
		value = sm.str(3);
	}
}

eOperandType Parser::strToEnum( const std::string m ) {
	if ( m == "int8" )
		return (Int8);
	else if ( m == "int16" )
		return (Int16);
	else if ( m == "int32" )
		return (Int32);
	else if ( m == "float" )
		return (Float);
	else
		return (Double);
}

