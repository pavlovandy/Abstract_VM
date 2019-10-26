/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Program.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 13:11:10 by anri              #+#    #+#             */
/*   Updated: 2019/10/24 13:43:41 by anri             ###   ########.fr       */
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
}

void	Program::run() {
	
}

void	Program::run( char * file ) {
	
}
