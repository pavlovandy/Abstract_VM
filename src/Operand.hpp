/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:10:15 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/21 22:30:29 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACT_VM_OPERAND_HPP
# define ABSTRACT_VM_OPERAND_HPP

# include "IOperand.hpp"
# include <cstdint>
# include "MyExceptions.hpp"

template < typename T >
class Operand : public IOperand {
	private:
		T &		_value;
		eOperandType const & _type;

		eOperandType const	_setType() const ;
		// void	checkOverFlow() const noexcept(false);
		// void	checkDivisionZero( IOperand const & rhs ) const noexcept(false);

	public:

		Operand<T>( T const & v );
		Operand<T>( ) = delete ;
		Operand<T>( Operand<T> const & o );
		Operand<T> &	operator=( Operand<T> const & o );
		~IOperand() = default ;

		int		getPrecision() const ;
		eOperandType	getType() const ;

		IOperand const *	operator+( IOperand const & rhs ) const ;
		IOperand const *	operator-( IOperand const & rhs ) const ;
		IOperand const *	operator*( IOperand const & rhs ) const ;
		IOperand const *	operator/( IOperand const & rhs ) const ;
		IOperand const *	operator%( IOperand const & rhs ) const ;

		std::string const &	toString() const ;
};

#endif