# FT_CONTAINERS 42
---
## Index
1. [Index](#index)
2. [File Hierarchy ](#file-hierarchy-)
3. [Mandatory ](#mandatory-)
4. [Enable_if](#using-enable_if)
4. [Bibliography ](#bibliography-)
5. [License](#license)
---
## To-Do List <a name="todo"></a>

- Vector
	- constructors 
		- alloc constructor
		- iterator constructor
	- Basic
		- assign (all)
	- Modifiers
		- insert (all)
		- erase (all)
		- pop_back

-	stack
-	binary tree
-	map

---
## File Hierarchy <a name="files"></a>
```
.
├─ 📁srcs
├─ Makefile
├─ main.cpp
└─ README.md
```
---
##  Mandatory <a name="mandatory"></a>

Implement the following containers and turn in the necessary files <container>.hpp
• You must also provide a main.cpp which tests everything for your evaluations. (you
need to go further than the example!)
• You must produce one binary with only your containers and one with the same
testing with STL containers.
• Compare outputs and timing (you can be up to 20 times slower).
• member functions, Non-member and overloads are expected.
• respect the naming, take care to details.
• You must use std::allocator.
• You must justify your inner data structure for each container (using a simple array
for a map is not ok).
• If the container has an iterator system, you must implement it.
• iterators_traits, reverse_iterator, enable_if, is_integral, equal/lexicographical compare, std::pair, std::make_pair, must be reimplemented.
• You can use https://www.cplusplus.com/ and https://cppreference.com/ as
references.
• You cannot implement more public functions than the ones offered in the standard
containers. Everything else must be private or protected. Each public function/-
variable must be justified.
• For non-member overloads, the keyword friend is allowed. Each use of friend
must be justified and will be checked during evaluation.
You must turn in the following containers and their associated functions:
• Vector
• Map
5
ft_containers C++ containers, easy mode
• Stack
For your vector implementation, it is not mandatory to code the vector<bool> specialization.
Your stack will use your vector class as default underlaying container, it must still be
compatible with others containers like the STL one.
STL containers are forbidden.
You are allowed to use the STD library.

---
## Using Enable_if <a name="Enable_if"></a>
How the fuck am I supossed to use enable if and what the fuck it is? Well those are some questions that Im to lazy to respond so Im gonna give some links so you can undestand it. My iterator constructor is:
```c++
template <class InputIt >
		vector(InputIt first, InputIt last, const Allocator &alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIt>::value>::type * = 0) {
```
Some Links I used are:
1.	[How to use SFINAE to restrict overload to input iterators][How to use SFINAE to restrict overload to input iterators]
2.	[std::enable_if to conditionally compile a member function][std::enable_if to conditionally compile a member function]
3.	[select class constructor using enable_if][select class constructor using enable_if]
4.	[An enable if medium really cool post][enableifmedium]

## Lexicographical Compare

This is well explained and documented in both cppreference and cplusplus pages, it is basically a strcmplike templated function
[CPPREFERENCE][lexicographicalcomparecpp]
[CPLUSPLUS][lexicographicalcomparecplusplus]

--
## Bibliography <a name="biblio"></a>
-	[cplusplus][cplusplus]
-	[cppreference][cppreference]
-	[what is enable_if][what is enable_if]
-	[std::enable_if to conditionally compile a member function][std::enable_if to conditionally compile a member function]
-	[select class constructor using enable_if][select class constructor using enable_if]
-	[How to use SFINAE to restrict overload to input iterators][How to use SFINAE to restrict overload to input iterators]
---
## License <a name="license"></a>

Comeme el culo

## Terroristas

- YO
- <a href="https://www.github.com/AingeruAlvarezSanchez>HELECHO</a>

[//]: #
	[Test]: <localhost:8080>
	[cplusplus]: <https://www.cplusplus.com/>
	[cppreference]: <https://cppreference.com/>
	[what is enable_if]: <https://medium.com/@sidbhasin82/c-templates-what-is-std-enable-if-and-how-to-use-it-fd76d3abbabe>
	[std::enable_if to conditionally compile a member function]: <https://stackoverflow.com/questions/6972368/stdenable-if-to-conditionally-compile-a-member-function>
	[select class constructor using enable_if]: <https://stackoverflow.com/questions/17842478/select-class-constructor-using-enable-if>
	[How to use SFINAE to restrict overload to input iterators]: <https://stackoverflow.com/questions/25668966/how-to-use-sfinae-to-restrict-overload-to-input-iterators>
	[lexicographicalcomparecpp]: <https://en.cppreference.com/w/cpp/algorithm/lexicographical_compare>
	[lexicographicalcomparecplusplus]: <https://cplusplus.com/reference/algorithm/lexicographical_compare/>
	[enableifmedium]: <https://medium.com/@sidbhasin82/c-templates-what-is-std-enable-if-and-how-to-use-it-fd76d3abbabe>