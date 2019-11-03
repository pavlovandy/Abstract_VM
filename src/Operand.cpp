/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 22:22:20 by anri              #+#    #+#             */
/*   Updated: 2019/11/02 15:17:13 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operand.hpp"

template <typename T>
eOperandType * Operand<T>::_setType() const {
	if (typeid(T) == typeid(int8_t))
		return (new eOperandType(Int8));
	if (typeid(T) == typeid(int16_t))
		return (new eOperandType(Int16));
	if (typeid(T) == typeid(int32_t))
		return (new eOperandType(Int32));
	if (typeid(T) == typeid(float))
		return (new eOperandType(Float));
	return (new eOperandType(Double));
}

template <typename T>
std::string *	Operand<T>::_setString( ) const {
	if (_type < Float)
		return new std::string(std::to_string(_value));
	else
	{
		std::stringstream set;
		set << std::setprecision(_type == Float ? 7 : 14) << _value;
		return new std::string(set.str());
	}
}

template < typename T >
Operand<T>::Operand( T const & v ) : _value(v), _type(*_setType()), _str(*_setString()) {
}

template < typename T >
Operand<T>::Operand( Operand<T> const & o ) : _value(o._value), _type(o._type), _str(o._str) {}

template < typename T >
Operand<T> &	Operand<T>::operator=( Operand<T> const & o ) {
	_value = o._value;
	_type = o._type;
	_str = o._str;
	return *this;
}

template < typename T >
IOperand const *	Operand<T>::operator+( IOperand const & rhs ) const {
	eOperandType highest = std::max(_type, rhs.getType());
	if (highest < Float)
		return (Factory().createOperand(highest, \
			std::to_string(std::stoll(rhs.toString()) + static_cast<long long>(_value))));
	else
		return (Factory().createOperand(highest, \
			std::to_string(std::stod(rhs.toString()) + static_cast<double>(_value))));	
	return (nullptr);
}

template < typename T >
IOperand const *	Operand<T>::operator-( IOperand const & rhs ) const {
	eOperandType highest = std::max(_type, rhs.getType());
	if (highest < Float)
		return (Factory().createOperand(highest, \
			std::to_string(std::stoll(rhs.toString()) - static_cast<long long>(_value))));
	else
		return (Factory().createOperand(highest, \
			std::to_string(std::stod(rhs.toString()) - static_cast<double>(_value))));	
	return (nullptr);
}

template < typename T >
IOperand const *	Operand<T>::operator*( IOperand const & rhs ) const {
	eOperandType highest = std::max(_type, rhs.getType());
	if (highest < Float)
		return (Factory().createOperand(highest, \
			std::to_string(std::stoll(rhs.toString()) * static_cast<long long>(_value))));
	else
		return (Factory().createOperand(highest, \
			std::to_string(std::stod(rhs.toString()) * static_cast<double>(_value))));	
	return (nullptr);
}

template < typename T >
IOperand const *	Operand<T>::operator/( IOperand const & rhs ) const {
	eOperandType highest = std::max(_type, rhs.getType());
	if (highest < Float)
	{
		long long div = std::stoll(rhs.toString());
		if (div == 0)
			throw DivisionByZero();
		return (Factory().createOperand(highest, \
			std::to_string(static_cast<long long>(_value) / div)));
	}
	else
	{
		double div = std::stod(rhs.toString());
		if (div == 0)
			throw DivisionByZero();
		return (Factory().createOperand(highest, \
			std::to_string(static_cast<double>(_value) / div)));
	}	
	return (nullptr);
}

template < typename T >
IOperand const *	Operand<T>::operator%( IOperand const & rhs ) const {
	eOperandType highest = std::max(_type, rhs.getType());
	if (highest < Float)
	{
		long long div = std::stoll(rhs.toString());
		if (div == 0)
			throw DivisionByZero();
		return (Factory().createOperand(highest, \
			std::to_string(static_cast<long long>(_value) % div)));
	}
	else
		throw NotAnInteger();
	return (nullptr);
}

template < typename T >
std::string const &	Operand<T>::toString() const { return _str; }

template < typename T >
int		Operand<T>::getPrecision() const {
	if (_type < Float)
		return (0);
	return ( _type == Float ? 7 : 14);
}

template < typename T >
eOperandType	Operand<T>::getType() const { return _type; }

template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<float>;
template class Operand<double>;
