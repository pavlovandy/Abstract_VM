/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyExceptions.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:31:11 by anri              #+#    #+#             */
/*   Updated: 2019/10/21 20:35:51 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MyExceptions.hpp"

MyExceptions::MyExceptions( const std::string & s ) : _mess(s) {}

MyExceptions::MyExceptions( MyExceptions const & e ) : _mess(e._mess) {}

MyExceptions::~MyExceptions() {}

const char*	MyExceptions::what( void ) const noexcept {
	return (_mess.c_str());
}
