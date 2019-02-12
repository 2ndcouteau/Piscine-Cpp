/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrosa <qrosa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 08:39:53 by qrosa             #+#    #+#             */
/*   Updated: 2019/01/22 16:48:59 by qrosa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename Type>
void 	swap(Type &elem1, Type &elem2)
{
	Type 	elem_tmp(elem1);

	elem_tmp = elem1;
	elem1 = elem2;
	elem2 = elem_tmp;
}


template <typename Type>
Type const & min(Type const &elem1, Type const &elem2)
{
	return (elem1 < elem2 ? elem1 : elem2);
}


template <typename Type>
Type const & max(Type const &elem1, Type const &elem2)
{
	return (elem1 > elem2 ? elem1 : elem2);
}
