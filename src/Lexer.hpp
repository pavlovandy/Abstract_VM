/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 21:16:14 by anri              #+#    #+#             */
/*   Updated: 2019/10/28 16:57:33 by anri             ###   ########.fr       */
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
	bool check_line( const std::string & str );
	void checkAll( std::istream & );
};

#endif