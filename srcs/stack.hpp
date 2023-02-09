#ifndef	STACK_HPP
#define STACK_HPP

#include "vector.hpp"
#include "lexicographical_compare.hpp"
#include "is"

namespace ft
{
	template <class T, class Container = ft::vector<T> > class stack
	{
		public:
			Container					container_type;
			Container::value_type		value_type;
			Container::size_type		size_type;
			//These are CPP 11
			// Container::reference		reference;
			// Container::const_reference	const_reference;
		protected:
			container_type container;
		public:
			explicit stack(const Container& cont = Container()) { container = cont; };
			stack(const stack& other) { *this = other; };
			~stack();
			//
			stack& operator=( const stack& other )
			{
				container = other.container;
				return (*this);	
			};
			//

			bool empty() const { return (this->empty()); };

			size_type size() const { return (this->size()); };

			reference top(){ return(container.begin()); };
			const_reference top() const { return(container.begin()); };

			void push (const value_type& val){container.insert(container.begin(), val);};
			void pop() { container.remove(0); };
	};
	template< class T, class Container >
	bool operator==( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ) {return (ft::lexicographical_compare())} ;
}
#endif