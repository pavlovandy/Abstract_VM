/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Program.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:11:10 by anri              #+#    #+#             */
/*   Updated: 2019/11/02 16:12:20 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Program.hpp"

Program::Program(){}

Program::~Program() {
	while (!_stack.empty())
		_stack.pop();
}

void	Program::run() {
	std::smatch m;
	
	eOperandType	type;
	std::string		command;
	bool			exitFlag = 0;
	std::string		value;
	for ( std::string	line; std::getline(std::cin, line); )
	{
		if (_lexer.check_line(line) == false)
			throw LexicalError();
		_parser.getMatches( line, command, type, value );
		if (command == "push")
			_push(_factory.createOperand(type, value));
		else if (command == "pop")
			_pop();
		else if (command == "dump")
			_dump();
		else if (command == "assert")
			_assert(_factory.createOperand(type, value));
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
		{
			exitFlag = true;
			break ;
		}
	}
	if (!exitFlag)
		throw NoExitException();
}

void	Program::run( char * file ) {
	std::ifstream	ifile(file);
	//lex it
	if (!ifile)
		throw NoSuchFile();
	_lexer.checkAll(ifile);
	//go to the start of the file
	ifile.clear( );
	ifile.seekg( 0, std::ios::beg );
	//start the program
	
	eOperandType	type;
	std::string		command;
	std::string		value;
	for (std::string line; std::getline(ifile, line); )
	{	
		_parser.getMatches( line, command, type, value );
		if (command == "push")
			_push(_factory.createOperand(type, value));
		else if (command == "pop")
			_pop();
		else if (command == "dump")
			_dump();
		else if (command == "assert")
			_assert(_factory.createOperand(type, value));
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
	_stack.push(value);
}

void	Program::_pop() {
	if (!_stack.empty())
		_stack.pop();
	else
		throw StackIsTooSmall();
}

void	Program::_dump() const {
	if (_stack.empty())
		std::cout << "Stack is empty" << std::endl;
	else
		for ( auto new_stack = _stack; !new_stack.empty(); new_stack.pop() )
			std::cout << new_stack.top()->toString() << std::endl;
}

void	Program::_assert( const IOperand* value ) {
	if (_stack.empty())
		throw StackIsTooSmall();
	if (std::stod(_stack.top()->toString()) != std::stod(value->toString()))
		throw AssertException();
	delete value;
}

void	Program::_add() {
	if (_stack.size() < 2)
		throw StackIsTooSmall();
	const IOperand* right = _stack.top();
	_stack.pop();
	const IOperand* left = _stack.top();
	_stack.pop();
	_stack.push(*left + *right);
	delete left;
	delete right;
}

void	Program::_sub() {
	if (_stack.size() < 2)
		throw StackIsTooSmall();
	const IOperand* right = _stack.top();
	_stack.pop();
	const IOperand* left = _stack.top();
	_stack.pop();
	_stack.push(*left - *right);
	delete left;
	delete right;
}

void	Program::_mul() {
	if (_stack.size() < 2)
		throw StackIsTooSmall();
	const IOperand* right = _stack.top();
	_stack.pop();
	const IOperand* left = _stack.top();
	_stack.pop();
	_stack.push(*left * *right);
	delete left;
	delete right;
}

void	Program::_div() {
	if (_stack.size() < 2)
		throw StackIsTooSmall();
	const IOperand* right = _stack.top();
	_stack.pop();
	const IOperand* left = _stack.top();
	_stack.pop();
	_stack.push(*left / *right);
	delete left;
	delete right;
}

void	Program::_mod() {
	if (_stack.size() < 2)
		throw StackIsTooSmall();
	const IOperand* right = _stack.top();
	_stack.pop();
	const IOperand* left = _stack.top();
	_stack.pop();
	_stack.push(*left % *right);
	delete left;
	delete right;
}

void	Program::_print() const {
	if (_stack.empty())
		throw StackIsTooSmall();
	if (_stack.top()->getType() == Int8)
		std::cout << static_cast<char>(std::stoi(_stack.top()->toString())) << std::endl;
	else
		throw TypesException();
}
