#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

#include <iostream>
namespace ft
{
	template <class Iter>
	class reverse_iterator
	{
	public:
		typedef Iter iterator_type;
		typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer pointer;
		typedef typename ft::iterator_traits<Iter>::reference reference;

	private:
		iterator_type array;

	public:
	// constructors https://cplusplus.com/reference/iterator/reverse_iterator/reverse_iterator/
		reverse_iterator() : array(0){};
		explicit reverse_iterator(iterator_type x) : array(x){};
		template <class U>
		reverse_iterator(const reverse_iterator<U> &other) : array(other.array){};
	//methods
		iterator_type base() const { return (this->array); };
	//operators 0
		reference operator*() const
		{
			iterator_type tmp = array;
			return (*(--tmp));
		};
		reference operator[](difference_type n) const // https://cplusplus.com/reference/iterator/reverse_iterator/operator[]/
		{
			return (base() - n - 1);
		};
		pointer operator->() const { return &(operator*()); };
	//operators 1
		reverse_iterator operator+(difference_type n) const { return (base() - n + 1); };
		reverse_iterator operator-(difference_type n) const { return (base() + n + 1); };
		reverse_iterator &operator-=(difference_type n) { return (base() + n); };
		reverse_iterator &operator+=(difference_type n) { return (base() - n); };
	//operators 2
		reverse_iterator &operator--()
		{
			++array;
			return (*this);
		};
		reverse_iterator operator--(int)
		{
			reverse_iterator temp = *this;
			--(*this);
			return temp;
		};
		reverse_iterator &operator++()
		{

			--array;
			return (*this);
		};
		reverse_iterator operator++(int)
		{
			reverse_iterator temp = *this;
			++(*this);
			return temp;
		};
	};
	template <class Iterator1, class Iterator2>
	bool operator==(const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs) { return (rhs.array == lhs.array ? true : false); };
	template <class Iterator1, class Iterator2>
	bool operator!=(const std::reverse_iterator<Iterator1> &lhs, const std::reverse_iterator<Iterator2> &rhs) { return (rhs.array == lhs.array ? false : true); };
	template <class Iterator1, class Iterator2>
	bool operator<(const std::reverse_iterator<Iterator1> &lhs, const std::reverse_iterator<Iterator2> &rhs) { return (rhs.array < lhs.array ? true : false); };
	template <class Iterator1, class Iterator2>
	bool operator<=(const std::reverse_iterator<Iterator1> &lhs, const std::reverse_iterator<Iterator2> &rhs) { return (lhs.array <= rhs.array ? true : false); };
	template <class Iterator1, class Iterator2>
	bool operator>(const std::reverse_iterator<Iterator1> &lhs, const std::reverse_iterator<Iterator2> &rhs) { return (lhs.array > rhs.array ? true : false); };
	template <class Iterator1, class Iterator2>
	bool operator>=(const std::reverse_iterator<Iterator1> &lhs, const std::reverse_iterator<Iterator2> &rhs) { return (lhs.array >= rhs.array ? true : false); };
}

#endif