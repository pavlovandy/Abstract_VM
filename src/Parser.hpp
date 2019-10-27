/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:15:28 by anri              #+#    #+#             */
/*   Updated: 2019/10/27 19:32:43 by anri             ###   ########.fr       */
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
		void getMatches( std::istream & i, std::string & command, eOperandType & type, std::string &value );
		eOperandType strToEnum( const std::string m );
};

#endif