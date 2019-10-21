/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MyExceptions.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anri <anri@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 20:26:48 by anri              #+#    #+#             */
/*   Updated: 2019/10/21 20:35:22 by anri             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ABSTRACT_VM_MY_EXCEPTIONS_HPP
# define ABSTRACT_VM_MY_EXCEPTIONS_HPP

# include <string>
# include <stdexcept>

class MyExceptions : public std::exception {
private:
	std::string const  _mess;
	
public:
	MyExceptions( const std::string & );
	MyExceptions( ) = delete;
	MyExceptions( MyExceptions const & );
	MyExceptions &	operator=( MyExceptions const & ) = delete ;
	~ MyExceptions();
	const char*	what( void ) const noexcept;
};

#endif