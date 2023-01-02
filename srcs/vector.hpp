#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

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
            typedef size_t size_type;
        public:

        //constructors
            vector(void): allocate()
            {
                array = (T *)allocate(0 * sizeof(T));
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



        
    };  
};

#endif