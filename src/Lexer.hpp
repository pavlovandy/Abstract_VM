/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:16:14 by anri              #+#    #+#             */
/*   Updated: 2019/10/26 14:38:43 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACT_VM_LEXER_HPP
# define ABSTRACT_VM_LEXER_HPP

# include <vector>
# include <regex>
# include "MyExceptions.hpp"
# include <iostream>
# include <fstream>
# include <ios>

class Lexer {
public:
	bool check_line( std::string );
	void checkAll( std::istream & );
};

#endif