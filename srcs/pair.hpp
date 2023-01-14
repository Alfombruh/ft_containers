#ifndef PAIR_HPP
#define PAIR_HPP

#include "lexicographical_compare.hpp"

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		// elements
		typedef T1 first_type;
		typedef T2 second_type;
		first_type first;
		second_type second;

		// constructors
		pair(void) : first(), second(){};
		template <class U, class V>
		pair(const pair<U, V> &pr) : first(pr.first), second(pr.second){};
		pair(const first_type &a, const second_type &b) : first(a), second(b){};

		// operator
		pair &operator=(const pair &r)
		{
			this->first = r.first;
			this->second = r.second;
			return (*this);
		};

	};

	//MAKE PAIR 
	template <class T1, class T2>
	ft::pair<T1, T2> make_pair(T1 t, T2 u)
	{
		//ft::pair<T1, T2> temp(t, u);
		ft::pair<T1, T2> temp = new ft::pair<T1, T2>(t, u);
		return temp;
	};

	//non member operators

	template <class T1, class T2>
	bool operator==(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		if (!((lhs.first != rhs.first) && (lhs.second != rhs.second)))
			return (true);
		return (false);
	};

	template <class T1, class T2>
	bool operator!=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		if (!((lhs.first != rhs.first) && (lhs.second != rhs.second)))
			return (false);
		return (true);
	};

	template <class T1, class T2>
	bool operator<(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		if (!lexicographical_compare<T1, T2>(lhs.first, lhs.second, rhs.first, rhs.second))
			return (false);
		return (true);
	};

	template <class T1, class T2>
	bool operator<=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		if (!lexicographical_compare<T1, T2>(lhs.first, lhs.second, rhs.first, rhs.second))
			return (false);
		return (true);
	};

	template< class T1, class T2 >
	bool operator>( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs )
	{
		if (!lexicographical_compare<T1, T2>(rhs.first, rhs.second, lhs.first, lhs.second))
			return (false);
		return (true);
	};

	template< class T1, class T2 >
	bool operator>=( const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs )
	{
		if (!lexicographical_compare<T1, T2>(rhs.first, rhs.second, lhs.first, lhs.second))
			return (false);
		return (true);
	};
}

#endif