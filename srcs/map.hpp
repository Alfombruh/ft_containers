#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include "pair.hpp"
#include <iterator>

#define	RED		true;
#define BLACK	false;

namespace ft
{
	template <class map>
	class iterator : public Iterator<std::bidirectional_iterator_tag, typename map::value_type>
	{

	};
	template < class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			typedef				Key							key_type;
			typedef				T							mapped_type;
			typedef	typename	ft::pair<const Key, T>		value_type;
			typedef	typename	std::size_t					size_type;
			typedef	typename	std::ptrdiff_t				difference_type;
			typedef				Compare						key_compare;
			typedef				Allocator					allocator_type;
			typedef				const value_type&			const_reference;
			typedef	typename	Allocator::pointer			pointer;
			typedef	typename	Allocator::const_pointer	pointer;
			// ITERATOR THINGS TODO
			// LegacyBidirectionalIterator to value_type iterator
			// LegacyBidirectionalIterator to const value_type
			//typedef typename ft::reverse_iterator<iterator> reverse_iterator;
			//typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
		private:
			allocator_type	alloc;
			size_type		_size;
			value_type		pair;
			key_compare		compare;
			Node<Key, T>	*node;
		public:
			map();
			explicit map( const Compare& comp,
              const Allocator& alloc = Allocator() );
			template< class InputIt >
			  map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );
	};

}

#endif