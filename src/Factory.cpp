/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:01:24 by anri              #+#    #+#             */
/*   Updated: 2019/10/21 21:18:54 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"

IOperand const * Factory::createInt8( std::string const & value ) const {
	try {
		long pre = std::stoll(value);

		if ( pre < INT8_MIN || pre > INT8_MAX)
			throw MyExceptions("Int8 overflow at creation");
		return (new Operand<int8_t>(static_cast<int8_t>(pre)));
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}

IOperand const * Factory::createInt16( std::string const & value ) const {
	try {
		long pre = std::stoll(value);

		if ( pre < INT16_MIN || pre > INT16_MAX)
			throw MyExceptions("Int16 overflow at creation");
		return (new Operand<int16_t>(static_cast<int16_t>(pre)));
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}

IOperand const * Factory::createInt32( std::string const & value ) const {
	try {
		long pre = std::stoll(value);

		if ( pre < INT32_MIN || pre > INT32_MAX)
			throw MyExceptions("Int32 overflow at creation");
		return (new Operand<int32_t>(static_cast<int32_t>(pre)));
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}

IOperand const * Factory::createFloat( std::string const & value ) const {
	try {
		double pre = std::stod(value);
		
		if ( pre < FLT_MIN || pre > FLT_MAX)
			throw MyExceptions("Float overflow at creation");
		return (new Operand<float>(static_cast<float>(pre)));
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}

IOperand const * Factory::createDouble( std::string const & value ) const {
	try {
		double pre = std::stod(value);
		
		if ( pre < DBL_MIN || pre > DBL_MAX)
			throw MyExceptions("Double overflow at creation");
		return (new Operand<double>(pre));
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
}

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const {
	return (this->*(_v.at(type)))( value );
}

std::vector<Factory::createValue> Factory::_v = { &createInt8, \
												&createInt16, \
												&createInt32, \
												&createFloat, \
												&createDouble };