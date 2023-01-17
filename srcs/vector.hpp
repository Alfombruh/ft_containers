#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "reverse_iterator.hpp"


#include <memory>
#include <iostream>
#include <cstddef> //justo en caso

/// member functions, non-member and overloads are expected
/// respect the naming
/// integrate the iterator
/// iterators_traits, reverse_iterator, enable_if, is_integral, equal/lexicographical compare, std::pair, std::make_pair, must be reimplemented
namespace ft
{
	template <class vector>
	class iterator : public Iterator<std::random_access_iterator_tag, typename vector::value_type >
	{
	public:
		typedef typename vector::value_type value_type;
		typedef typename vector::difference_type	difference_type;
		typedef typename std::random_access_iterator_tag	iterator_category;
		typedef value_type  *pointer;
		typedef value_type  &reference;

	private:
		pointer array;

	public:
		//https://youtu.be/F9eDv-YIOQ0?t=711 crear un costructor default y crear operador ++
		iterator()
		{
			this->array = NULL;
		};
		iterator(pointer pos)
		{
			this->array = pos;
		};

		//operator
		bool	operator==(const iterator &r){return (array == r.array? true : false);};
		bool		operator!=(const iterator &r){return (array == r.array? false : true);};
		reference  operator*()const {return(*array);};
		iterator	&operator=(const iterator &r)
		{
			array = r.array;
			return (*this);
		};
		iterator	&operator++(void)
		{
			++array;
			return (*this);
		}
		iterator	operator++(int)
		{
			iterator temp = *this;
			array++;
			return (temp);
		};
		iterator	&operator--(void)
		{
			--array;
			return (*this);
		};
		iterator	operator--(int)
		{
			iterator	temp = *this ;
			array--;
			return (temp);
		};
		difference_type operator+(iterator const &r){return (r.array + array);};
		difference_type operator-(iterator const &r){return (r.array - array);};
		iterator &operator+(difference_type const &r)
		{
			iterator temp = *this;
			temp.array += r;
			return (temp);
		};
		iterator &operator-(difference_type const &r)
		{
			iterator temp = *this;
			temp.array -= r;
			return (temp);
		};
		bool	operator<(iterator const &r){return (array < r.array? true : false);};
		bool	operator>(iterator const &r){return (array > r.array? true : false);};
		bool	operator<=(iterator const &r){return (array <= r.array? true : false);};
		bool	operator>=(iterator const &r){return (array >= r.array? true : false);};
		iterator &operator+=(difference_type const &r)
		{
			iterator	temp = *this;
			temp.array += r;
			return(temp);
		};
		iterator &operator-=(difference_type const &r)
		{
			iterator	temp = *this;
			temp.array -= r;
			return(temp);
		};
		reference	operator[](difference_type n){return(array[n]);};
	};

	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
	private:
		T *array;
		Allocator allocate;
		int size;

	public: // typedef's
		typedef T value_type;
		typedef typename std::allocator<T> allocator_type;
		typedef typename allocator_type::size_type size_type;
		typedef typename allocator_type::difference_type difference_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef typename ft::iterator<vector> iterator;
		typedef typename ft::iterator<const vector> const_iterator;
		typedef typename ft::reverse_iterator<iterator>	reverse_iterator;
		typedef	typename ft::reverse_iterator<const iterator>  const_reverse_iterator;

	public:
		// constructors (https://en.cppreference.com/w/cpp/container/vector/vector)
		vector(void)
		{
			array = (T *)allocate.allocate(sizeof(T) * 0);
			size = 0;
			std::cout << "Just Allocated\n";
		};
		explicit vector(const Allocator &alloc){
			allocate(alloc);
		};
		explicit vector(size_type count, const T &value, const Allocator &alloc = Allocator())
		{
			array = (T *)allocate.allocate(sizeof(T) * count);
			size = count;
			for (int i = 0; i < count; i++){
				array[i] = value;
			}
		};
		template <class InputIt >
		vector(InputIt first, InputIt last, const Allocator &alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIt>::value>::type * = 0) {
			std::cout << "sexo" << '\n';
		};
		vector(const vector &other);
		// destructors (https://en.cppreference.com/w/cpp/container/vector/~vector)
		~vector(void)
		{
			allocate.deallocate(array, size);
			std::cout << "Just Deleted\n";
		};
		// operators
		vector &operator=(const vector &other) //(https://en.cppreference.com/w/cpp/container/vector/operator%3D)
		{
			other.array = array;
			other.allocate = allocate;
			other.size = size;
			return (*this);
		};
		// member fucntions-methods
		// assing (https://cplusplus.com/reference/vector/vector/assign/)
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last){

		};
		void assign(size_type n, const value_type &val){

		};
		// at (https://cplusplus.com/reference/vector/vector/at/)
		reference at(size_type n)
		{
		}
		const reference at(size_type n) const {

		};
		//Iterator methods
		iterator begin()
		{
			return (iterator(this->array));
		};
		const_iterator cbegin() const
		{
			return (const_iterator(this->array));
		};
		iterator end()
		{
			return (iterator(this->array + this->size));
		};
		const_iterator cend() const
		{
			return (const_iterator(this->array + this->size));
		};
		//reverse_iterator methods
		reverse_iterator rbegin()
		{
			return (reverse_iterator(this->array + this->size));
		};
		const_reverse_iterator crbegin() const
		{
			return (const_reverse_iterator(this->array + this->size));
		};
		reverse_iterator rend()
		{
			return (reverse_iterator(this->array));
		};
		const_reverse_iterator crend() const
		{
			return (const_reverse_iterator(this->array));
		};
	};
};

#endif
