/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyExceptions.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:26:48 by anri              #+#    #+#             */
/*   Updated: 2019/10/24 13:08:23 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACT_VM_MY_EXCEPTIONS_HPP
# define ABSTRACT_VM_MY_EXCEPTIONS_HPP

# include <string>
# include <stdexcept>

class LexicalError : public std::exception {
private:
	int		_raw;
public:
	LexicalError();
	LexicalError( int raw );
	~LexicalError();
	LexicalError( LexicalError const & );
	LexicalError &	operator=( LexicalError const & );
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

class UnknownInstructionError : public std::exception {
private:
	int		_raw;
public:
	UnknownInstructionError();
	UnknownInstructionError( int raw );
	UnknownInstructionError( UnknownInstructionError const & );
	UnknownInstructionError &	operator=( UnknownInstructionError const & );
	~UnknownInstructionError();
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

#endif