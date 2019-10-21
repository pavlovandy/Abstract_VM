/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 22:22:20 by anri              #+#    #+#             */
/*   Updated: 2019/10/21 22:32:49 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Operand.hpp"

template <typename T>
eOperandType const	Operand<T>::_setType() const {
	switch (typeid(T))
	{
		case typeid(int8_t): return (Int8); break;
		case typeid(int16_t): return (Int16); break;
		case typeid(int32_t): return (Int32); break;
		case typeid(float): return (Float); break;
		case typeid(double): return (Double); break;
		default: return (Kappa); break;
	}
}

template < typename T >
Operand<T>::Operand<T>( T const & v ) : _value(v), _type(_setType()) {}

template < typename T >
Operand<T>::Operand<T>( Operand<T> const & o ) : _value(o._value) {}

template < typename T >
Operand<T> &	Operand<T>::operator=( Operand<T> const & o ) {
	_value = o._value;
	return *this;
}

template < typename T >
IOperand const *	Operand<T>::operator+( IOperand const & rhs ) const {}

template < typename T >
IOperand const *	Operand<T>::operator-( IOperand const & rhs ) const {}

template < typename T >
IOperand const *	Operand<T>::operator*( IOperand const & rhs ) const {}

template < typename T >
IOperand const *	Operand<T>::operator/( IOperand const & rhs ) const {}

template < typename T >
IOperand const *	Operand<T>::operator%( IOperand const & rhs ) const {}

template < typename T >
std::string const &	Operand<T>::toString() const { return std::to_string(_value); }

/*	Чи можна переписати лише функцію Operand<float>::toString \
		без декларації специфікації для окремого класу Operand<float>
*/
template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<float>;
template class Operand<double>;