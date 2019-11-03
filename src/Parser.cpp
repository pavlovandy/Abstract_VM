/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:15:32 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/11/03 15:19:49 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

void Parser::getMatches( const std::string & str, std::string & command, eOperandType & type, std::string &value ) {
	static std::vector<std::regex> regex_vector = { std::regex("(?:\\s)*(dump)(\\s)*(?:;(.*))?"), \
													std::regex("(?:\\s)*(pop)(\\s)*(?:;(.*))?"), \
													std::regex("(?:\\s)*(add)(\\s)*(?:;(.*))?"), \
													std::regex("(?:\\s)*(sub)(\\s)*(?:;(.*))?"), \
													std::regex("(?:\\s)*(mul)(\\s)*(?:;(.*))?"), \
													std::regex("(?:\\s)*(div)(\\s)*(?:;(.*))?"), \
													std::regex("(?:\\s)*(mod)(\\s)*(?:;(.*))?"), \
													std::regex("(?:\\s)*(print)(\\s)*(?:;(.*))?"), \
													std::regex("(?:\\s)*"), \
													std::regex("(?:\\s)*(?:;(.*))?"), \
													std::regex("\\s*(push)\\s+"
																"(int8|int16|int32|float|double)"
																"\\(((\\+|-)?[\\d]+(\\.[\\d]+)?)\\)"
																"(\\s)*(?:;(.*))?"), \
													std::regex("(?:\\s)*(assert)\\s+"
																"(int8|int16|int32|float|double)"
																"\\(((\\+|-)?[\\d]+(\\.[\\d]+)?)\\)"
																"(\\s)*(?:;(.*))?"),
													std::regex("(?:\\s)*(exit|;;)(\\s)*(?:;(.*))?")};


/*
std::regex("\\s*(dump)\\s(?:;(.+))*"), \
													std::regex("\\s*(pop)\\s*(?:;(.+))*"), \
													std::regex("\\s*(add)\\s*(?:;(.+))*"), \
													std::regex("\\s*(sub)\\s*(?:;(.+))*"), \
													std::regex("\\s*(mul)\\s*(?:;(.+))*"), \
													std::regex("\\s*(div)\\s*(?:;(.+))*"), \
													std::regex("\\s*(mod)\\s*(?:;(.+))*"), \
													std::regex("\\s*(print)\\s*(?:;(.+))*"), \
													std::regex("(\\s)*"), \
													std::regex("\\s*(;(.+))*"), \
													std::regex("\\s*(push)\\s+"
																"(int8|int16|int32|float|double)"
																"\\(((\\+|-)?[\\d]+(\\.[\\d]+)?)\\)"
																"\\s*(?:;(.+))*"), \
													std::regex("\\s*(assert)\\s*"
																"(int8|int16|int32|float|double)"
																"\\(((\\+|-)?[\\d]+(\\.[\\d]+)?)\\)"
																"\\s*(;(.+))*"),
													std::regex("\\s*(exit|;;)\\s*(?:;(.+))*")};
*/
	std::smatch sm;
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

