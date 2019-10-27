/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Program.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:11:10 by anri              #+#    #+#             */
/*   Updated: 2019/10/27 19:38:27 by anri             ###   ########.fr       */
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
	//copy paste here
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
	eOperandType	type;
	std::string		command;
	std::string		value;
	while (!ifile.eof())
	{
		_parser->getMatches( ifile, command, type, value );
		if (command == "push")
			_push(_factory->createOperand(type, value));
		else if (command == "pop")
			_pop();
		else if (command == "dump")
			_dump();
		else if (command == "assert")
			_assert(_factory->createOperand(type, value));
		else if (command == "add")
			_add();
		else if (command == "sub")
			_sub();
		else if (command == "mul")
			_mul();
		else if (command == "div")
			_div();
		else if (command == "mod")
			_mod();
		else if (command == "print")
			_print();
		else if (command == "exit" || command == ";;")
			break ;
	}
	ifile.close();
}

void	Program::_push( const IOperand* value ) {
	std::cout << "Push " << value->getType() << " " << value->toString() << std::endl;
}

void	Program::_pop() {
	std::cout << "Pop" << std::endl;
}

void	Program::_dump() const {
	std::cout << "Dump" << std::endl;
}

void	Program::_assert( const IOperand* value ) {
	std::cout << "Assert " << value->getType() << " " << value->toString() << std::endl;

	delete value;
	//need to delete pointer to value
}

void	Program::_add() {
	std::cout << "Add" << std::endl;
}

void	Program::_sub() {
	std::cout << "Sub" << std::endl;
}

void	Program::_mul() {
	std::cout << "Mul" << std::endl;
}

void	Program::_div() {
	std::cout << "Div" << std::endl;
}

void	Program::_mod() {
	std::cout << "Mod" << std::endl;
}

void	Program::_print() const {
	std::cout << "Print" << std::endl;
}
