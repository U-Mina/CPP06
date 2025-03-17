/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:24:12 by ewu               #+#    #+#             */
/*   Updated: 2025/03/17 13:34:00 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	Data* data = new Data;
	data->nbr = 42;
	data->s = "some message to read!";

	uintptr_t cat = Serializer::serialize(data);
	Data* dat = Serializer::deserialize(cat);
	
	if (data == dat)
	{
		std::cout << "Serialize and Deserialize successfully done!\n";
		std::cout << "Original data is: " << data->nbr << " and " << data->s << "\n";
		std::cout << "Deserialized dat is: " << dat->nbr << " and " << dat->s << "\n";
	}
	else
		std::cout << "Serialize and Deserialize not successful!\nAddress not match\n";

	if (data)
		delete data;
	return (0);
}
