/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 19:01:24 by anri              #+#    #+#             */
/*   Updated: 2019/10/24 12:50:06 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Factory.hpp"

IOperand const * Factory::createInt8( std::string const & value ) const {
	Operand<int8_t>*	ret = nullptr;
	try {
		long pre = std::stoll(value);

		if ( pre < std::numeric_limits<int8_t>::min() )
			throw UnderflowException();
		if ( pre > std::numeric_limits<int8_t>::max() )
			throw OverflowException();
		ret = new Operand<int8_t>(static_cast<int8_t>(pre));
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	return ret;
}

IOperand const * Factory::createInt16( std::string const & value ) const {
	try {
		long pre = std::stoll(value);

		if ( pre < std::numeric_limits<int16_t>::min() )
			throw UnderflowException();
		if ( pre > std::numeric_limits<int16_t>::max() )
			throw OverflowException();
		return (new Operand<int16_t>(static_cast<int16_t>(pre)));
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	return nullptr;
}

IOperand const * Factory::createInt32( std::string const & value ) const {
	try {
		long pre = std::stoll(value);

		if ( pre < std::numeric_limits<int32_t>::min() )
			throw UnderflowException();
		if ( pre > std::numeric_limits<int32_t>::max() )
			throw OverflowException();
		return (new Operand<int32_t>(static_cast<int32_t>(pre)));
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	return nullptr;
}

IOperand const * Factory::createFloat( std::string const & value ) const {
	try {
		double pre = std::stod(value);
		
		if ( pre < std::numeric_limits<float>::min() )
			throw UnderflowException();
		if ( pre > std::numeric_limits<float>::max() )
			throw OverflowException();
		return (new Operand<float>(static_cast<float>(pre)));
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	return nullptr;
}

IOperand const * Factory::createDouble( std::string const & value ) const {
	try {
		double pre = std::stod(value);
		
		if ( pre < std::numeric_limits<double>::min() )
			throw UnderflowException();
		if ( pre > std::numeric_limits<double>::max() )
			throw OverflowException();
		return (new Operand<double>(pre));
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}
	return nullptr;
}

IOperand const * Factory::createOperand( eOperandType type, std::string const & value ) const {
	return (this->*(_v.at(type)))( value );
}

std::vector<Factory::createValue> Factory::_v = { &Factory::createInt8, \
												&Factory::createInt16, \
												&Factory::createInt32, \
												&Factory::createFloat, \
												&Factory::createDouble };