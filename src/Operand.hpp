/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apavlov <apavlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:10:15 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/20 18:04:22 by apavlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACT_VM_OPERAND_HPP
# define ABSTRACT_VM_OPERAND_HPP

# include "IOperand.hpp"
# include <cstdint>

template < typename T >
class Operand : public IOperand {
	private:
		int &	_type;
		T &		value;
		
		IOperand const * createInt8( std::string const & value ) const;
		IOperand const * createInt16( std::string const & value ) const;
		IOperand const * createInt32( std::string const & value ) const;
		IOperand const * createFloat( std::string const & value ) const;
		IOperand const * createDouble( std::string const & value ) const;

		typedef IOperand const (Operand::*createValue)( std::string const & value ) const ;

		static createValue funArray[5];
		static std::string operandNamesArray[5];
		
	public:
		int		getPrecision() const ;
		eOperandType	getType() const { return (_type); }

		IOperand const *	operator+( IOperand const & rhs ) const ;
		IOperand const *	operator-( IOperand const & rhs ) const ;
		IOperand const *	operator*( IOperand const & rhs ) const ;
		IOperand const *	operator/( IOperand const & rhs ) const ;
		IOperand const *	operator%( IOperand const & rhs ) const ;

		std::string const &	toString() const ;

		~IOperand() {}
		IOperand const * createOperand( eOperandType type, std::string const & value ) const ;
};

#endif