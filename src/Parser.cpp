/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 14:15:32 by Andrii Pavl       #+#    #+#             */
/*   Updated: 2019/10/26 17:14:06 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

void Parser::getMatches( std::istream & i, std::smatch & sm ) {
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
																"\\s*(;(.+))*")}; //aint right for parser... atm just copied form lexer

	std::string str;
	std::getline(i, str);
	for ( const auto& reg : regex_vector )
		if (std::regex_match(str, sm, reg))
			break ;
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

