#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft
{
	template <class InputIt1, class InputIt2>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								 InputIt2 first2, InputIt2 last2)
	{
		for (;(first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (*first1 < *first2)
				return (true);
			if (*first1 > *first2)
				return (false);
		}
		return ((first1 == last1) && (first2 != last2));
	};
	template <class InputIt1, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
								 InputIt2 first2, InputIt2 last2, Compare comp)
	{
		for (;(first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (comp(*first1, *first2))
				return (true);
			if (comp(*first2, *first1))
				return (false);
		}
		return ((first1 == last1) && (first2 != last2));
	};
}

// in the lines 10 and 23 of the code you can see that first2 is a parameter thats being casted to void, this seems unnecesary
// but actually is a really good code practice. What it does it that in c++ the ++x operator returns a reference to the object
// thats being incremented, since we dont use that value by casting this to a void type we avoid using the unnecesary use of
// this variable

#endif