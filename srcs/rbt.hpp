#ifndef RBT_HPP
#define RBT_HPP

#include "pair.hpp"
#include <iostream>
#include <memory>

#define CRED	"\033[0;31m"
#define CLOSE	"\033[0;0m"

#define RED		false
#define BLACK	true
#define RIGHT	false;
#define LEFT	true;

template <class Key, class T>
struct Node
{
	ft::pair<Key, T>			pair;
	Node						*left;
	Node						*right;
	Node						*parent;
	bool						color;
};

template<class Key, class T, class Compare = std::less<Key> ,  class Alloc = std::allocator<Node<Key, T> > >
class RBT
{
	///////public definitions///////	
	public:
		typedef				Alloc							allocator_type;
		typedef typename	allocator_type::size_type		size_type;
		typedef typename	ft::pair<Key, T>				value_type;
		typedef 			Node<Key, T>					node;
		typedef				Node<Key, T>					*pointer;
		typedef				Compare							key_compare;
	///////private atributes///////	
	private:
		allocator_type			alloc;
		size_type 				_size; 
		pointer					list;
		key_compare				comp;

		pointer firstNode(node *firstNode)
		{
			firstNode->color = BLACK;
			list = firstNode;
			_size += 1;
			return (firstNode);
		};

	public:
		RBT(): list(NULL), _size(0) {};
		~RBT()
		{
		};//LIBERAR MEMORIA TODO
		pointer	createNode(const Key &key, T const &value)
		{
			pointer	node = alloc.allocate(1);
			node->pair.first = key;
			node->pair.second = value;
			node->parent = NULL;
			node->left = NULL;
			node->right = NULL;
			node->color = RED; 
			return (node);
		};
		pointer	insertNode(const Key &key ,const T &value = 0, pointer ptr = NULL )
		{
			node *node = createNode(key, value);
			if (list == NULL)
				return (firstNode(node));
			if (!comp(key, list->pair.first))
			{
				if (ptr != NULL)
					return (insertNode(key, value, list->left));
				ptr = node;
				list->left = ptr;
				list = list->left;
				_size += 1;
			}
			if (comp(key, list->pair.first))
			{
				if (ptr != NULL)
					return (insertNode(key, value, list->right));
				ptr = node;
				list->right = ptr;
				list = list->right;
				_size += 1;	
			}
			return (node);
		};
		pointer	findNode(pointer node, const Key &key)
		{
			while (list != NULL && list->pair.first != key)
			{
				if (comp(key, list->pair.first))
					return (findNode(list->left, key));
				if (!comp(key, list->pair.first))
					return (findNode(list->right, key));
			}
			return (list);
		};
		pointer	deleteNode(pointer node, const Key &key)
		{
			while (list != NULL && list->pair.first != key)
			{
				if (comp(key, list->pair.first))
					return (findNode(list->left, key));
				if (!comp(key, list->pair.first))
					return (findNode(list->right, key));
			}
			return (list);
		};

		////////////////////////////PRINTF METHODS////////////////////////////
		void	printAing() { printRBT("", list, false) ; };
		void printTree()//IONMI'S FUNCTION
		{
			if (list)
				printHelper(list, 0);
		};
	private:
		void printRBT(const std::string& prefix, const pointer node, bool isLeft)//AINGERU'S FUNCTION
		{
			if( node == nullptr )
				return ;
			std::cout << prefix;
			std::cout << (isLeft ? "├──" : "\033[0;31m└──" );
			// print the value of the node
			std::cout << node->pair.second << CLOSE << std::endl;
			// enter the next tree level - left and right branch
			printRBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
			printRBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
		};
		void printHelper(pointer &root, int space)
		{
			// Base case
			if (root == NULL)
				return;
			// Increase distance between levels
			space += 10;
			// Process right child first
			printHelper(root->right, space);
			// Print current node after space
			// count
			std::cout << "\n";
			for (int i = 10; i < space; i++)
				std::cout << " ";
			std::cout << root->pair.first << (root->color == RED ? " (RED)" : " (BLACK)") << "\n";
			// Process left child
			printHelper(root->left, space);
		};
};
#endif	
