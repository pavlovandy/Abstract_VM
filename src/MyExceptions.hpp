/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyExceptions.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Andrii Pavlov <apavlov@student.unit.ua>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:26:48 by anri              #+#    #+#             */
/*   Updated: 2019/11/02 15:56:01 by Andrii Pavl      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACT_VM_MY_EXCEPTIONS_HPP
# define ABSTRACT_VM_MY_EXCEPTIONS_HPP

# include <string>
# include <stdexcept>

class LexicalError : public std::exception {
public:
	virtual const char *	what() const noexcept(true);
};

class UnderflowException : public std::exception {
public:
	virtual const char *	what() const noexcept(true);
};

class OverflowException : public std::exception {
public:
	virtual const char *	what() const noexcept(true);
};

class DivisionByZero : public std::exception {
public:
	virtual const char *	what() const noexcept(true);
};

class OutputException : public std::exception {
public:
	virtual const char *	what() const noexcept(true);
};

class TypesException : public std::exception {
public:
	virtual const char *	what() const noexcept(true);
};

class NoExitException : public std::exception {
public:
	virtual const char *	what() const noexcept(true);
};

class StackIsTooSmall : public std::exception {
public:
	virtual const char *	what() const noexcept(true);
};

class AssertException : public std::exception {
public:
	virtual const char *	what() const noexcept(true);
};

class NotAnInteger : public std::exception {
public:
	virtual const char *	what() const noexcept(true);
};

class AllocationException : public std::exception {
public:
	virtual const char *	what() const noexcept(true);	
};

class NoSuchFile : public std::exception {
public:
	virtual const char *	what() const noexcept(true);	
};

#endif