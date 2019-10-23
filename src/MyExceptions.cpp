/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyExceptions.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:31:11 by anri              #+#    #+#             */
/*   Updated: 2019/10/23 20:57:55 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyExceptions.hpp"

LexicalError::LexicalError() : _raw(0) {}
LexicalError::LexicalError( int raw ) : _raw(raw) {}
LexicalError::~LexicalError() {}
LexicalError::LexicalError( LexicalError const & e ) : _raw(e._raw) {}
LexicalError &	LexicalError::operator=( LexicalError const & e ) {
	_raw = e._raw;
	return (*this);
}

const char *	LexicalError::what() const noexcept(true){
	std::string str("Lexical error at line : ");
	str += std::to_string(_raw);
	return str.c_str();
}

const char *	UnderflowException::what() const noexcept(true){
	return "Underflow exception";
}

const char *	OverflowException::what() const noexcept(true){
	return "Overflow exception";
}

const char *	DivisionByZero::what() const noexcept(true){
	return "Division by zero";
}

const char *	OutputException::what() const noexcept(true){
	return "Can not output";
}

const char *	TypesException::what() const noexcept(true){
	return "Types exception";
}

const char *	NoExitException::what() const noexcept(true){
	return "There is no exit!!!!";
}

UnknownInstructionError::UnknownInstructionError() : _raw(0) {}

UnknownInstructionError::UnknownInstructionError( int raw ) : _raw(raw) {}

UnknownInstructionError::UnknownInstructionError( UnknownInstructionError const & e ) : _raw(e._raw) {}

UnknownInstructionError &	UnknownInstructionError::operator=( UnknownInstructionError const & e ) {
	_raw = e._raw;
	return *this;
}

UnknownInstructionError::~UnknownInstructionError() {}

const char *	UnknownInstructionError::what() const noexcept(true){
	std::string str("Unknown instruction at line : ");
	str += std::to_string(_raw);
	return str.c_str();
}

const char *	StackIsTooSmall::what() const noexcept(true){
	return "Stack is too small";
}

const char *	AssertException::what() const noexcept(true){
	return "Can't assert";
}

const char *	NotAnInteger::what() const noexcept(true){
	return "Not an Integer";	
}
