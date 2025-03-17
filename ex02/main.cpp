/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 21:34:44 by ewu               #+#    #+#             */
/*   Updated: 2025/03/17 21:51:50 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "Identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

int main()
{
	Base* ami = generate();
	Base* babe = generate();
	Base* car = generate();
	Base* devine = generate();
	std::cout << "call identify() using pointer\n";
	identify(ami);
	identify(babe);
	// std::cout << &babe << "\n";//mem location of of babe PTR
	// std::cout << babe << "\n";//the value of 'babe' itself, bc babe is a PTR, so its an mem address
	identify(car);
	identify(devine);
	std::cout << "call identify() using reference\n";
	identify(*ami);
	identify(*babe);
	// std::cout << &babe << "\n";
	// std::cout << babe << "\n";
	identify(*car);
	identify(*devine);

	delete ami;
	delete babe;
	delete car;
	delete devine;
	return 0;
}

/**
 * NOTE:
 * babe is like a piece of paper with the address of the house written on it.
 * &babe is the address of the drawer where you keep that piece of paper.
 */