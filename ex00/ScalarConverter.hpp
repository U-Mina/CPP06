/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:29:55 by ewu               #+#    #+#             */
/*   Updated: 2025/03/17 11:18:20 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <cmath>
# include <climits>
# include <iostream>
# include <iomanip>
# include <exception>

// possible input: char, int, floar, double, pseudo-litral
class ScalarConverter
{
private:
	ScalarConverter(); // make cons private to prevent instantiation
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);

public:
	static void convert(const std::string& input);
};

enum			inputType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO_F,
	PSEUDO_D,
	INVALID
};

struct	getInput
{
	inputType	type;
	double		val;
	std::string pseudo_val;
};

bool			is_psedo(const std::string& input, const std::string pse_d_f[],	int volum);
inputType		check_input1(const std::string& input, getInput& getinput);
inputType		check_input2(const std::string& input, getInput& getinput);
inputType		check_input3(const std::string& input, getInput& getinput);
void			convertChar(const getInput& getinput);
void			convertInt(const getInput& getinput);
void			convertFloat(const getInput& getinput);
void			convertDouble(const getInput& getinput);

#endif