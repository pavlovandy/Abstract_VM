/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Program.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:11:10 by anri              #+#    #+#             */
/*   Updated: 2019/10/26 17:14:17 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Program.hpp"

Program::Program() : 
	_factory( new Factory ), 
	_lexer( new Lexer ), 
	_parser( new Parser ) {
	if (_factory == nullptr || _lexer == nullptr || _parser == nullptr)
		throw AllocationException();
}

Program::~Program() {
	delete _factory;
	delete _lexer;
	delete _parser;
	while (!_stack.empty())
		_stack.pop();
}

void	Program::run() {
	_lexer->checkAll(std::cin);
}

void	Program::run( char * file ) {
	std::ifstream	ifile(file);
	//lex it
	_lexer->checkAll(ifile);
	//go to the start of the file
	ifile.clear( );
	ifile.seekg( 0, std::ios::beg );
	//start the program
	std::smatch m;
	while (!ifile.eof())
	{
		_parser->getMatches( ifile, m );
		if (m.str(1) == "push")
			_push(_factory->createOperand(_parser->strToEnum(m.str(2)), m.str(3)));
		else if (m.str(1) == "pop")
			_pop();
		else if (m.str(1) == "dump")
			_dump();
		else if (m.str(1) == "assert")
			_assert(_factory->createOperand(_parser->strToEnum(m.str(2)), m.str(3)));
		else if (m.str(1) == "add")
			_add();
		else if (m.str(1) == "sub")
			_sub();
		else if (m.str(1) == "mul")
			_mul();
		else if (m.str(1) == "div")
			_div();
		else if (m.str(1) == "mod")
			_mod();
		else if (m.str(1) == "print")
			_print();
		else if (m.str(1) == "exit" || m.str(1) == ";;")
			break ;
	}
	ifile.close();
}

void	Program::_push( const IOperand* value ) {

}

void	Program::_pop() {

}

void	Program::_dump() const {

}

void	Program::_assert( const IOperand* value ) {
	//need to delete pointer to value
}

void	Program::_add() {

}

void	Program::_sub() {

}

void	Program::_mul() {

}

void	Program::_div() {

}

void	Program::_mod() {

}

void	Program::_print() const {

}
