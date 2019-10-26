/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:15:28 by anri              #+#    #+#             */
/*   Updated: 2019/10/26 17:13:59 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACT_VM_PARSER_HPP
# define ABSTRACT_VM_PARSER_HPP

# include <regex>
# include <string>
# include <vector>
# include <ios>
# include <iostream>
# include "IOperand.hpp"
# include <cstring>

class Parser {
	public:
		void getMatches( std::istream & i, std::smatch & sm );
		eOperandType strToEnum( const std::string m );
};

#endif