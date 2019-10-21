/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Factory.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:24:41 by anri              #+#    #+#             */
/*   Updated: 2019/10/21 21:18:48 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACT_VM_FACTORY_HPP
# define ABSTRACT_VM_FACTORY_HPP

# include "IOperand.hpp"
# include <vector>
# include <iostream>
# include <stdexcept>
# include "Operand.hpp"
# include <climits>
# include <cfloat>
# include "MyExceptions.hpp"

class Factory {
private:
	IOperand const * createInt8( std::string const & value ) const;
	IOperand const * createInt16( std::string const & value ) const;
	IOperand const * createInt32( std::string const & value ) const;
	IOperand const * createFloat( std::string const & value ) const;
	IOperand const * createDouble( std::string const & value ) const;

	typedef decltype (createInt8) createValue;
	static std::vector<Factory::createValue> _v;

public:
	Factory() = default ;
	Factory( const Factory & ) = delete ;
	Factory &	operator=( Factory const & ) = delete ;
	~Factory() = default ;

	IOperand const * createOperand( eOperandType type, std::string const & value ) const ;
};

#endif