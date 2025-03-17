/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewu <ewu@student.42heilbronn.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:36:04 by ewu               #+#    #+#             */
/*   Updated: 2025/03/17 21:44:06 by ewu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime> //for std::time()
#include <iostream>

Base* generate(void)
{
	static bool flag = false;
	if (!flag)
	{
		std::srand(std::time(0));
		flag = true;
	}
	int nbr = std::rand() % 3; //0, 1, 2
	switch (nbr)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return nullptr;
}

/**
 * logic: p can Point to any of A/B/C (bc inheritance)
 * DYNAMIC CAST: *try* to convert!
 * if 'p' POINTS to A*, then dynamic_cast<A*>(p) will success, otherwise return NULL
*/
void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << "\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << "\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << "\n";
	else
		std::cout << "Error type!\n";//the case when switch() return nullptr
}

/**
 * for references, dynamic_cast works different
 * PTR: return nullptr is fail
 * REF: if fails, throw exception 'std::bad_cast'. REF cannot be NULL!!, so no NULL
 * to indicate a failure in dynamic_cast
 */
void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);//(void) to avoid complier complain about result not used
		std::cout << "A" << "\n";
		return ;
	}
	catch(const std::bad_cast& e)
	{}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << "\n";
		return ;
	}
	catch(const std::bad_cast& e)
	{}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << "\n";
		return ;
	}
	catch(const std::bad_cast& e)
	{}
	std::cout << "Error type!\n";//reach here mean non above casting work
}
