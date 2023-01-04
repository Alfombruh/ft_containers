#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>

/// member functions, non-member and overloads are expected
/// respect the naming
/// integrate the iterator
/// iterators_traits, reverse_iterator, enable_if, is_integral, equal/lexicographical compare, std::pair, std::make_pair, must be reimplemented
namespace ft
{
    template<class T, class Allocator = std::allocator<T>>
    class vector
    {
        private:
            T *array;
            Allocator allocate;
            int size;
        //typedef's
            typedef T                               value_type;
            typedef std::allocator<T>               allocator_type;
            typedef allocator_type::reference       reference;
            typedef allocator_type::const_reference const_reference;
            typedef allocator_type::pointer         pointer;
            typedef allocator_type::const_pointer   const_pointer;
            //typedef a random access iterator to a value type  iterator; (https://cplusplus.com/reference/vector/vector/)
            //typedef a randon access iterator to a const value_type  const_iterators;
            //typedef a reverse_iterator<iterator>    reverse_iterator;
            //typedef a reverse_iterator<const iterator>  const_reverse_iterator;
            //typedef a iterator_traits<iterator>::diffference_type(same as ptrdiff_t)  difference_type;
            typedef size_t                          size_type;
        public:

        //constructors (https://en.cppreference.com/w/cpp/container/vector/vector)
            vector(void)
            {
                array = (T *)allocate.allocate(sizeof(T) * 0);
                size = 0;
                std::cout << "Just Allocated\n";
            };
            explicit vector( const Allocator &alloc )
            {

            };
            explicit vector( size_type count, const T& value, const Allocator& alloc = Allocator() ) //why tf does it equal alloc to Allocator()
            {

            };
            template< class InputIt >
            vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() )
            {

            };
            vector( const vector& other );
        //destructors (https://en.cppreference.com/w/cpp/container/vector/~vector)
            ~vector(void)
            {
                allocate.deallocate(array, size);
                std::cout << "Just Deleted\n";
            };
        //operators
            vector &operator=(const vector &other) //(https://en.cppreference.com/w/cpp/container/vector/operator%3D)
            {
                other.array = array;
                other.allocate = allocate;
                other.size = size;
                return (*this);
            };
        //member fucntions-methods
            //assing (https://cplusplus.com/reference/vector/vector/assign/)
            template <class InputIterator>
            void assign (InputIterator first, InputIterator last)
            {

            };
            void assign (size_type n, const value_type& val)
            {

            };
            //at (https://cplusplus.com/reference/vector/vector/at/)
            reference at(size_type n)
            {

            }
            const reference at(size_type n)const
            {

            };

    };
};

#endif