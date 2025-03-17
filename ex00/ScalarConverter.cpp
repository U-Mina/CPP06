/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:36:51 by ewu               #+#    #+#             */
/*   Updated: 2025/03/17 11:22:55 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cmath>
#include <climits>
#include <iostream>
#include <exception>

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

void ScalarConverter::convert(const std::string& input)
{
	getInput getinput;
	inputType type;
	type = check_input1(input, getinput);
	if (type == INVALID)
	{
		std::cout << "Invalid input\n";
		return ;
	}
	convertChar(getinput);
	convertInt(getinput);
	convertFloat(getinput);
	convertDouble(getinput);
}
