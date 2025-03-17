/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 10:13:58 by ewu               #+#    #+#             */
/*   Updated: 2025/03/17 12:55:14 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
// #include <cmath>
// #include <climits>
// #include <iostream>
// #include <exception>

//possible input: char, int, floar, double, pseudo-litral
// enum inputType
// {
// 	CHAR,
// 	INT,
// 	FLOAT,
// 	DOUBLE,
// 	PSEUDO_F,
// 	PSEUDO_D,
// 	INVALID
// };

// struct getInput
// {
// 	inputType type;
// 	double val;
// 	std::string pseudo_val;
// };

bool is_psedo(const std::string& input, const std::string pse_d_f[], int volum)
{
	for (int i = 0; i < volum; ++i)
	{
		if (input == pse_d_f[i])
			return true;
	}
	return false;
}

inputType check_input3(const std::string& input, getInput& getinput)
{
	try
	{
		double nbr_val = std::stod(input);
		if (std::isnan(nbr_val) || std::isinf(nbr_val))
			return INVALID;
		if (input.find('.') != std::string::npos || input.find('e') != std::string::npos
			|| input.find('E') != std::string::npos)//has e/E or '.' in the str
		{
			getinput.type = DOUBLE;
			getinput.val = nbr_val;
			return DOUBLE;
		}
		else //its an INT!
		{
			getinput.type = INT;
			getinput.val = nbr_val;
			return INT;
		}
	}
	catch(const std::exception& e)
	{
		// std::cout << "debug msg3.\n";
		return INVALID;
	}
}

/**
 * NOTE: stod() in std c++ lib, use try-catch() to catch if any exception being thrown
 * difference with strtod(s, &end), std c lib function, track &end of str
*/
inputType check_input2(const std::string& input, getInput& getinput)
{
	if (input.back() == 'f' || input.back() == 'F')//string.back() return REF to last CHAR
	{
		std::string nbr;
		double nbr_val;
		nbr = input.substr(0, (input.size() - 1));
		try
		{
			nbr_val = std::stod(nbr);
			if (std::isnan(nbr_val) || std::isinf(nbr_val))
				return INVALID;
			getinput.type = FLOAT;
			getinput.val = nbr_val;
			return FLOAT;
		}
		catch(const std::exception& e)
		{
			// std::cout << "debug msg22.\n";
			return INVALID;
		}
	}
	else
		return (check_input3(input, getinput));
}

inputType check_input1(const std::string& input, getInput& getinput)
{
	if (input.empty())
		return INVALID;
	//get CHAR; char literal: 'a', 'c' (with single quote)
	// std::cout << "Debug: Checking input1: " << input << "\n";
    // std::cout << "Input size: " << input.size() << "\n";
	if (input.size() == 3 && input[0] == '\'' && input[2] == '\'')//'a', 'b', 'c'
	{
		// std::cout << "Debug: CHAR\n" << input << "\n";
		getinput.type = CHAR;
		getinput.val = static_cast<unsigned char>(input[1]);//unsigned char here to ensure get insigne int depiste complier or platforms
		return CHAR;
	}
	//get PSEUDO_D/F: pseudo literal, non_official: -infinity; +infinity; Not-A-Number
	const std::string pse_d[] = {"-inf", "+inf", "nan"};
	const std::string pse_f[] = {"-inff", "+inff", "nanf"};
	if (is_psedo(input, pse_d, 3))
	{
		getinput.type = PSEUDO_D;
		getinput.pseudo_val = input;
		return PSEUDO_D;
	}
	else if (is_psedo(input, pse_f, 4))
		return (getinput.type = PSEUDO_F, getinput.pseudo_val = input, PSEUDO_F);
	else
		return (check_input2(input, getinput));
}
