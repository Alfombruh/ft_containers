# FT_CONTAINERS 42
---
## Index
1. [Index](#index)
2. [File Hierarchy ](#file-hierarchy-)
3. [Mandatory ](#mandatory-)
4. [Bibliography ](#bibliography-)
5. [License](#license)
---
## To-Do List <a name="todo"></a>

- Read cplusplus and cppreference
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
## Bibliography <a name="biblio"></a>
- [cplusplus][cplusplus]
- [cppreference][cppreference]

---
## License <a name="license"></a>

Comeme el culo

---
[//]: #
  [Test]: <localhost:8080>
  [cplusplus]: <https://www.cplusplus.com/>
  [cppreference]: <https://cppreference.com/>