#ifndef	STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef				Container					container_type;
			typedef	typename	Container::value_type		value_type;
			typedef	typename	Container::size_type		size_type;
		protected:
			container_type container;
		public:
			explicit stack(const Container& cont = Container()) { container = cont; };
			stack(const stack& other) { *this = other; };
			~stack(){};

			stack& operator=( const stack& other )
			{
				container = other.container;
				return (*this);	
			};

			bool				empty() const { return (this->empty()); };

			size_type			size() const { return (this->size()); };

			value_type			&top() { return(container.back()); };
			const value_type	&top() const { return(container.back()); };

			void 				push(const value_type& val) { container.push_back(val); };
			void 				pop() { container.pop_back(); };
			friend bool operator==( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs );
			friend bool operator!=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs );
			friend bool operator< ( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs );
			friend bool operator<=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs );
			friend bool operator> ( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs );
			friend bool operator>=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs );
	};
	template< class T, class Container >
	bool operator==( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ) {lhs == rhs;};
	template< class T, class Container >
	bool operator!=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ) {lhs != rhs;};
	template< class T, class Container >
	bool operator< ( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ) {lhs < rhs;};
	template< class T, class Container >
	bool operator<=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ) {lhs <= rhs;};
	template< class T, class Container >
	bool operator> ( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ) {lhs > rhs;};
	template< class T, class Container >
	bool operator>=( const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs ) {lhs >= rhs;};
}
#endif