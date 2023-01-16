#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
	template <class Iter>
	class reverse_iterator
	{
	public:
		typedef typename Iter iterator_type;
		typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer pointer;
		typedef typename ft::iterator_traits<Iter>::reference reference;

	private:
		pointer array;

	public:
		//constructors https://cplusplus.com/reference/iterator/reverse_iterator/reverse_iterator/
		reverse_iterator(){array = NULL};
		explicit reverse_iterator(iterator_type x)
		{
			
		};
		template <class U>
		reverse_iterator(const reverse_iterator<U> &other)
		{

		};

		iterator_type base() const;
	};
	template <class Iterator1, class Iterator2>
	bool operator==(const ft::reverse_iterator<Iterator1> &lhs, const ft::reverse_iterator<Iterator2> &rhs) { return (rhs.array == lhs.array ? true : false); };
	template <class Iterator1, class Iterator2>
	bool operator!=(const std::reverse_iterator<Iterator1> &lhs, const std::reverse_iterator<Iterator2> &rhs) { return (rhs.array == lhs.array ? false : true); };
	template <class Iterator1, class Iterator2>
	bool operator<(const std::reverse_iterator<Iterator1> &lhs, const std::reverse_iterator<Iterator2> &rhs) { return (rhs.array < rhs.array ? true : false); };
	template <class Iterator1, class Iterator2>
	bool operator<=(const std::reverse_iterator<Iterator1> &lhs, const std::reverse_iterator<Iterator2> &rhs) { return (lhs.array <= rhs.array ? true : false); };
	template <class Iterator1, class Iterator2>
	bool operator>(const std::reverse_iterator<Iterator1> &lhs, const std::reverse_iterator<Iterator2> &rhs) { return (lhs.array > rhs.array ? true : false); };
	template <class Iterator1, class Iterator2>
	bool operator>=(const std::reverse_iterator<Iterator1> &lhs, const std::reverse_iterator<Iterator2> &rhs) { return (lhs.array >= rhs.array ? true : false); };

}

#endif