/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:48:51 by apavlov           #+#    #+#             */
/*   Updated: 2019/10/21 22:13:54 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACT_VM_IOPERAND_HPP
# define ABSTRACT_VM_IOPERAND_HPP

# include <string>

enum eOperandType{
		Int8, Int16, Int32, Float, Double, Kappa = 145
};

class IOperand {
public:
	virtual int		getPrecision() const = 0;
	virtual eOperandType	getType() const = 0;

	virtual IOperand const *	operator+( IOperand const & rhs ) const = 0;
	virtual IOperand const *	operator-( IOperand const & rhs ) const = 0;
	virtual IOperand const *	operator*( IOperand const & rhs ) const = 0;
	virtual IOperand const *	operator/( IOperand const & rhs ) const = 0;
	virtual IOperand const *	operator%( IOperand const & rhs ) const = 0;

	virtual std::string const &	toString() const = 0;
	virtual ~IOperand() {}
};

#endif