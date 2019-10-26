/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:16:14 by anri              #+#    #+#             */
/*   Updated: 2019/10/25 16:08:52 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACT_VM_LEXER_HPP
# define ABSTRACT_VM_LEXER_HPP

# include <vector>
# include <regex>

class Lexer {
public:
	void check_line( std::string );
};

void Lexer::check_line( std::string str ) {
	static std::vector<std::regex> regex_vector = {	std::regex("(\\s)*dump(\\s)*(;(.+))*"), \
													std::regex("(\\s)*pop(\\s)*(;(.+))*"), \
													std::regex("(\\s)*add(\\s)*(;(.+))*"), \
													std::regex("(\\s)*sub(\\s)*(;(.+))*"), \
													std::regex("(\\s)*mul(\\s)*(;(.+))*"), \
													std::regex("(\\s)*div(\\s)*(;(.+))*"), \
													std::regex("(\\s)*mod(\\s)*(;(.+))*"), \
													std::regex("(\\s)*print(\\s)*(;(.+))*"), \
													std::regex("\\s*push\\s+"
																	"(int8|int16|int32|float|double)"
																	"\\((+|-)?[\\d]+(\\.[\\d]+)?\\)(\\s*)"
																	"(;(.+))*"), \
													std::regex("(\\s)*assert(\\s)*"
																	"(;(.+))*")};
}


#endif