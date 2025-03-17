/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_input.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:18:18 by ewu               #+#    #+#             */
/*   Updated: 2025/03/17 12:40:13 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
// #include <cmath>
// #include <climits>
// #include <iostream>
// #include <exception>

void	convertChar(const getInput& getinput)
{
	inputType type = getinput.type;
	if (type == PSEUDO_D || type == PSEUDO_F)
		std::cout << "char: impossibl\n";
	else
	{
		double nbr_v = getinput.val;
		if (nbr_v > 127 || nbr_v < -128)//CHAR_MIN -128; CHAR_MAX +127
			std::cout << "char: impossible\n";
		else
		{
			char result = static_cast<unsigned char>(nbr_v);
			if (result > 31 && result < 127)
				std::cout << "char: '" << result << "'\n";
			else
				std::cout << "char: Non displayable\n";
		}	
	}
}

void	convertInt(const getInput &getinput)
{
	inputType type = getinput.type;
	if (type == PSEUDO_D || type == PSEUDO_F)
		std::cout << "int: impossibl\n";
	else
	{
		double nbr_v = getinput.val;
		if (nbr_v > INT_MAX || nbr_v < INT_MIN)
			std::cout << "int: impossibl\n";
		else
			std::cout << "int: " << static_cast<int>(nbr_v) << "\n";
	}
}

//precison is: 0.*f, namely (1)
void	convertFloat(const getInput &getinput)
{
	inputType type = getinput.type;
	if (type == PSEUDO_F)
		std::cout << "float: " << getinput.pseudo_val << "\n";
	else if (type == PSEUDO_D)
		std::cout << "float: " << getinput.pseudo_val << "f\n";
	else
	{
		float nbr_v = static_cast<float>(getinput.val);
		std::cout << "float: " << std::fixed << std::setprecision(1) << nbr_v << "f\n";	
	}
}

void convertDouble(const getInput &getinput)
{
	inputType type = getinput.type;
	if (type == PSEUDO_D)
		std::cout << "double: " << getinput.pseudo_val << "\n";
	else if (type == PSEUDO_F)
	{
		std::string s = getinput.pseudo_val.substr(0, getinput.pseudo_val.size() - 1);
		std::cout << "double: " << s << "\n";
	}
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << getinput.val << "\n";
}
