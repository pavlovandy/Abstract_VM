/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Program.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:55:08 by anri              #+#    #+#             */
/*   Updated: 2019/10/26 16:14:54 by Andrii Pavl      ###   ########.fr       */
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
# include <regex>

class Parser;

class Program {
private:
	Factory *		_factory;
	std::stack< IOperand* >	_stack;
	Lexer *			_lexer;
	Parser *		_parser;

	void	_push( const IOperand* value );
	void	_pop();
	void	_dump() const ;
	void	_assert( const IOperand* value );
	void	_add();
	void	_sub();
	void	_mul();
	void	_div();
	void	_mod();
	void	_print() const ;
	
public:
	Program();
	Program( std::istream & );
	Program( Program const & ) = delete ;
	Program &	operator=( Program const & ) = delete ;
	~Program();

	void	run();
	void	run( char * file );
};

#endif