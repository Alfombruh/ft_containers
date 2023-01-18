#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "reverse_iterator.hpp"

#include <memory>
#include <iostream>
#include <cstddef> //justo en caso
#include <exception>

/// member functions, non-member and overloads are expected
/// respect the naming
/// integrate the iterator
/// iterators_traits, reverse_iterator, enable_if, is_integral, equal/lexicographical compare, std::pair, std::make_pair, must be reimplemented
namespace ft
{
	template <class vector>
	class iterator : public Iterator<std::random_access_iterator_tag, typename vector::value_type>
	{
	public:
		typedef typename vector::value_type value_type;
		typedef typename vector::difference_type difference_type;
		typedef typename std::random_access_iterator_tag iterator_category;
		typedef value_type *pointer;
		typedef value_type &reference;

	private:
		pointer array;

	public:
		// https://youtu.be/F9eDv-YIOQ0?t=711 crear un costructor default y crear operador ++
		iterator()
		{
			this->array = NULL;
		};
		iterator(pointer pos)
		{
			this->array = pos;
		};

		// operator
		bool operator==(const iterator &r) { return (array == r.array ? true : false); };
		bool operator!=(const iterator &r) { return (array == r.array ? false : true); };
		reference operator*() const { return (*array); };
		iterator &operator=(const iterator &r)
		{
			array = r.array;
			return (*this);
		};
		iterator &operator++(void)
		{
			++array;
			return (*this);
		}
		iterator operator++(int)
		{
			iterator temp = *this;
			array++;
			return (temp);
		};
		iterator &operator--(void)
		{
			--array;
			return (*this);
		};
		iterator operator--(int)
		{
			iterator temp = *this;
			array--;
			return (temp);
		};
		difference_type operator+(iterator const &r) { return (r.array + array); };
		difference_type operator-(iterator const &r) { return (r.array - array); };
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
		bool operator<(iterator const &r) { return (array < r.array ? true : false); };
		bool operator>(iterator const &r) { return (array > r.array ? true : false); };
		bool operator<=(iterator const &r) { return (array <= r.array ? true : false); };
		bool operator>=(iterator const &r) { return (array >= r.array ? true : false); };
		iterator &operator+=(difference_type const &r)
		{
			iterator temp = *this;
			temp.array += r;
			return (temp);
		};
		iterator &operator-=(difference_type const &r)
		{
			iterator temp = *this;
			temp.array -= r;
			return (temp);
		};
		reference operator[](difference_type n) { return (array[n]); };
	};

	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
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
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const iterator> const_reverse_iterator;

	private:
		T *array;
		Allocator allocate;
		size_type _capacity;
		size_type _size;
		size_type _max_size;

	public:
		// constructors (https://en.cppreference.com/w/cpp/container/vector/vector)
		vector(void)
		{
			array = (T *)allocate.allocate(sizeof(T) * 0);
			_size = 0;
			_capacity = 0;
			_max_size = allocate.max_size();
			std::cout << "max_size: " << _max_size << "\n";
			std::cout << "Just Allocated\n";
		};
		explicit vector(const Allocator &alloc)
		{
			allocate(alloc);
		};
		explicit vector(size_type count, const T &value, const Allocator &alloc = Allocator())
		{
			array = (T *)allocate.allocate(sizeof(T) * count);
			_capacity = count;
			_max_size = allocate.max_size();
			_size = count;
			for (int i = 0; i < count; i++)
				array[i] = value;
		};
		template <class InputIt>
		vector(InputIt first, InputIt last, const Allocator &alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIt>::value>::type * = 0)
		{
			exit(1);
			InputIt temp = first;
			_max_size = allocate.max_size();
			// while(first != last)
			// 	first++

		};
		vector(const vector &other);
		// destructors (https://en.cppreference.com/w/cpp/container/vector/~vector)
		~vector(void)
		{
			allocate.deallocate(array, _capacity);
			std::cout << "Just Deleted\n";
		};
		// operators
		vector &operator=(const vector &other) //(https://en.cppreference.com/w/cpp/container/vector/operator%3D)
		{
			_size = other._size;
			_max_size = other._max_size;
			_capacity = other._capacity;
			allocate = other.allocate;
			array = allocate.allocate(other._capacity);
			for (unsigned long ul = 0; ul < other._size; ul++)
				allocate.construct(array + ul, *(other.array + ul));
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
			//if (n >= _size)
				//throw (std::out_of_range("vector"));
			return (*(array + n));
		}
		const_reference at(size_type n) const {
			//if (n >= _size)
				//throw (std::out_of_range("vector"));
			return (*(array + n));
		};
		// Iterator methods
		iterator begin() { return (iterator(this->array)); };
		const_iterator cbegin() const { return (const_iterator(this->array)); };
		iterator end() { return (iterator(this->array + this->_size)); };
		const_iterator cend() const { return (const_iterator(this->array + this->_size)); };
		// reverse_iterator methods
		reverse_iterator rbegin() { return (reverse_iterator(this->array + this->_size)); };
		const_reverse_iterator crbegin() const { return (const_reverse_iterator(this->array + this->_size)); };
		reverse_iterator rend() { return (reverse_iterator(this->array)); };
		const_reverse_iterator crend() const { return (const_reverse_iterator(this->array)); };

		void push_back(const T &value)
		{
			if ( _size + 1 > _max_size )
				throw(std::out_of_range("max_size_error\n"));
			if (!(_size + 1 > _capacity))
			{
				allocate.construct(_size + 1, array);
				_size += 1;
				return ;
			}
			vector temp = *this;
			if (this->_capacity != 0)
			{
				clear();
				allocate.deallocate(_capacity);
			}
			if (temp._capacity == 0)
			{
				array = allocate.allocate(1);
				_capacity = 1;
			}
			else{
				array = allocate.allocate(temp._capacity * 2);
				for (unsigned long ul; ul < temp._size; ul++)
					allocate.construct(array + ul, *(temp.array + ul));
				allocate.construct(array + temp._size + 1, value);
				_capacity = temp._capacity * 2;
			}
			_size = temp.size + 1;
			//gonna fix and tidy this up
		};

		size_type size() const { return (_size); };
		size_type max_size(void) const { return (sizeof(value_type) == 1 ? (_max_size / 2) : (_max_size)); };
		size_type capacity() const { return (capacity); };
		void clear()
		{
			for (unsigned long ul = 0; ul < _size; ul++)
				allocate.destroy(array + ul);
			_size = 0;
		};
	};
};

#endif
