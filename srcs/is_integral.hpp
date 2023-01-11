#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

#include <type_traits>

namespace ft
{
	// template < class T >
	// struct is_integral{};
	template < class T >
	struct	is_integral:	std::integral_constant<bool, false>
	{
	};
	template <>
	struct	is_integral<bool>:	std::integral_constant<bool, true>
	{
	};
	template <>
	struct	is_integral<char>:	std::integral_constant<bool, true>
	{
	};
	template <>
	struct	is_integral<char16_t>:	std::integral_constant<bool, true>
	{
	};
	template <>
	struct	is_integral<char32_t>:	std::integral_constant<bool, true>
	{
	};
	template <>
	struct	is_integral<wchar_t>:	std::integral_constant<bool, true>
	{
	};
	template <>
	struct	is_integral<signed char>:	std::integral_constant<bool, true>
	{
	};
	template <>
	struct	is_integral<short int>:	std::integral_constant<bool, true>
	{
	};
	template <>
	struct	is_integral<int>:	std::integral_constant<bool, true>
	{
	};
	template <>
	struct	is_integral<long int>:	std::integral_constant<bool, true>
	{
	};
	template <>
	struct	is_integral<long long int>:	std::integral_constant<bool, true>
	{
	};
	template <>
	struct	is_integral<unsigned char>:	std::integral_constant<bool, true>
	{
	};
	template <>
	struct	is_integral<unsigned short int>:	std::integral_constant<bool, true>
	{
	};
	template <>
	struct	is_integral<unsigned int>:	std::integral_constant<bool, true>
	{
	};
	template <>
	struct	is_integral<unsigned long int>:	std::integral_constant<bool, true>
	{
	};
	template <>
	struct	is_integral<unsigned long long int>:	std::integral_constant<bool, true>
	{
	};
}

#endif