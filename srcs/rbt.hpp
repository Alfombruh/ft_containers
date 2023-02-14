#ifndef RBT_HPP
#define RBT_HPP

#include "pair.hpp"
#include <iostream>
#include <memory>

#define RED		false
#define BLACK	true

template <class Key, class T>
struct Node
{
	T							value;
	Key							key;
	Node						*left;
	Node						*right;
	Node						*parent;
	bool						color;
};



template<class Key, class T>
class RBT
{
	public:
		typedef typename	ft::pair<Key, T>				value_type;
		typedef	typename	std::allocator<Node<Key, T> >	allocator_type;
		typedef 			Node<Key, T>					Node;
		typedef				Node<Key, T>					*pointer;
				
	//private:
		Node					*list;
		allocator_type			alloc;
		Node					*current;

		void firstNode(Node *firstNode)
		{
			firstNode->color = BLACK;
			list = firstNode;
			current = list;
		}

	public:
		RBT(): list(NULL), current(NULL) {};
		~RBT()
		{

		};//LIBERAR MEMORIA TODO
		Node *createNode(value_type const &value)
		{
			Node *node = alloc.allocate(1);
			node->value = value;
			node->parent = NULL;
			node->left = NULL;
			node->right = NULL;
			node->color = RED;
			return (node);
		}
		void	insertNode(const &value_type value, Node *ptr = NULL )
		{
			Node *node = createNode(key, value);
			if (list == NULL)
			{
				firstNode(node);
				return ;
			}
			if (value >= current->value.second)
			{
				if (ptr == NULL)
				{
					ptr = node;
					current->left = ptr;
					current = current->left;
				}
				else
					return insertNode(key, value, current->left);
			}
			if (value < current->value.second)
			{
				if (ptr == NULL)
				{
					ptr = node;
					current->right = ptr;
					current = current->right;
				}
				else	
					return insertNode(key, value, current->right);
			}
		}
		void printRBT(const std::string& prefix, const Node* node, bool isLeft)//AINGERU'S FUNCTION
		{
			if( node != nullptr )
			{
				std::cout << prefix;

				std::cout << (isLeft ? "├──" : "└──" );

				// print the value of the node
				std::cout << node->value.second << std::endl;

				// enter the next tree level - left and right branch
				printRBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
				printRBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
			}
			
		}
		void printTree()
		{
			if (list)
				printHelper(list, 0);
		}
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
			std::cout << root->key << (root->color == RED ? " (RED)" : " (BLACK)") << "\n";

			// Process left child
			printHelper(root->left, space);
		}
};
#endif	
