/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyExceptions.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:31:11 by anri              #+#    #+#             */
/*   Updated: 2019/11/02 15:56:04 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyExceptions.hpp"

const char *	LexicalError::what() const noexcept(true){
	return "Lexical error";
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

const char *	StackIsTooSmall::what() const noexcept(true){
	return "Stack is too small";
}

const char *	AssertException::what() const noexcept(true){
	return "Can't assert";
}

const char *	NotAnInteger::what() const noexcept(true){
	return "Not an Integer";	
}

const char *	AllocationException::what() const noexcept(true) {
	return "Allocaltion trouble";
}	

const char *	NoSuchFile::what() const noexcept(true) {
	return "No such file";
}