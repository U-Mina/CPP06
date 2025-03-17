/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:23:18 by ewu               #+#    #+#             */
/*   Updated: 2025/03/17 11:54:31 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Invalid parameter number! ONE parameter needed!\n";
		return (1);
	}
	ScalarConverter::convert(av[1]);
	// getInput r;
	// inputType t = check_input1(av[1], r);
	// std::cout << t << "\n";
	return (0);
}


// int main() {
//     getInput result;
//     std::string test = "'a'";
//     inputType type = check_input1(test, result);

//     if (type == CHAR) {
//         std::cout << "It's a char: " << static_cast<char>(result.val) << std::endl;
//     } else {
//         std::cout << "It's not a char" << std::endl;
//     }
//     return 0;
// }