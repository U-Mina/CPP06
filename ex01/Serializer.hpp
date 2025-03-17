/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 12:57:17 by ewu               #+#    #+#             */
/*   Updated: 2025/03/17 13:22:42 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint> //for uintptr_t type
#include <string>

struct Data;

class Serializer
{
private:
	Serializer();//private cons prevent initialize
	~Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other);
	
public:
	//cvrt Data ptr to uintptr_t
	static uintptr_t serialize(Data* ptr);
	//cvrt uintptr_t to Data ptr
	static Data* deserialize(uintptr_t raw);
};

#endif