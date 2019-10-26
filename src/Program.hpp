/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Program.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:55:08 by anri              #+#    #+#             */
/*   Updated: 2019/10/24 13:43:03 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACT_VM_PROGRAM_HPP
# define ABSTRACT_VM_PROGRAM_HPP

# include <iostream>
# include "MyExceptions.hpp"
# include "Operand.hpp"
# include "Factory.hpp"
# include "IOperand.hpp"
# include "Parser.hpp"
# include "Lexer.hpp"
# include <stack>
# include <fstream>

class Program {
private:
	Factory *		_factory;
	std::stack< IOperand* >	_stack;
	Lexer *			_lexer;
	Parser *		_parser;
	
public:
	Program();
	Program( std::istream & );
	Program( Program const & ) = delete ;
	Program &	operator=( Program const & ) = delete ;
	//Program( std::string flags );
	~Program();

	void	run();
	void	run( char * file );
};

#endif