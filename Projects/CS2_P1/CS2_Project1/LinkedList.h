#pragma once
#include <iostream>
#include <vector>
using namespace std;

/*==== LinkedList Class =====*/
template <typename T>
class LinkedList
{
public:
	class Node
	{
	public:
		T data;
		Node* next;
		Node* prev;
		Node();
		Node(T data, Node* next = nullptr, Node* prev = nullptr);
	};
private:
	Node* _head;
	Node* _tail;
	unsigned int _nodeCount;
public:
	/*==== Behaviros ====*/
	void PrintForward() const;
	void PrintReverse() const;
	void PrintForwardRecursive(const Node* node) const;
	void PrintReverseRecursive(const Node* node) const;

	/*==== Accessors ====*/
	unsigned int NodeCount() const;
	void FindAll(vector<Node*>& outData, const T& value) const;
	const Node* Find(const T& data) const;
	Node* Find(const T& data);
	Node* GetNode(unsigned int index);
	const Node* GetNode(unsigned int index) const;
	Node* Head();
	const Node* Head() const;
	Node* Tail();
	const Node* Tail() const;

	/*==== Insertion ====*/
	void AddHead(const T& data);
	void AddTail(const T& data);
	void AddNodesHead(const T* data, unsigned int count);
	void AddNodesTail(const T* data, unsigned int count);
	void InsertAfter(Node* node, const T& data);
	void InsertBefore(Node* node, const T& data);
	void InsertAt(const T& data, unsigned int index);

	/*==== Removal ====*/
	bool RemoveHead();
	bool RemoveTail();
	unsigned int Remove(const T& data);
	bool RemoveAt(unsigned int index);
	void Clear();

	/*==== Operators ====*/
	const T& operator[](unsigned int index) const;
	T& operator[](unsigned int index);
	bool operator==(const LinkedList<T>& rhs) const;
	LinkedList<T>& operator=(const LinkedList<T>& rhs);

	/*==== Construction / Destruction ====*/
	LinkedList();
	LinkedList(const LinkedList<T>& list);
	~LinkedList();
};

/*==== Behaviros ====*/
template <typename T>
void LinkedList<T>::PrintForward() const
{
	if (NodeCount() > 0)
	{
		Node* ptr = _head;

		while (ptr != nullptr)
		{
			cout << ptr->data << endl;

			ptr = ptr->next;
		}
	}
}

template <typename T>
void LinkedList<T>::PrintReverse() const
{
	if (NodeCount() > 0)
	{
		Node* ptr = _tail;

		while (ptr != nullptr)
		{
			cout << ptr->data << endl;

			ptr = ptr->prev;
		}
	}
}

template <typename T>
void LinkedList<T>::PrintForwardRecursive(const Node* node) const
{
	if (node == nullptr)
	{
		return;
	}
	else // Node is not a nullptr
	{
		cout << node->data << endl;

		PrintForwardRecursive(node->next);
	}
}

template <typename T>
void LinkedList<T>::PrintReverseRecursive(const Node* node) const
{
	if (node == nullptr)
	{
		return;
	}
	else // Node is not a nullptr
	{
		cout << node->data << endl;

		PrintReverseRecursive(node->prev);
	}
}

/*==== Accessors ====*/
template <typename T>
unsigned int LinkedList<T>::NodeCount() const
{
	return _nodeCount;
}

template <typename T>
void LinkedList<T>::FindAll(vector<LinkedList<T>::Node*>& outData, const T& value) const
{
	if (NodeCount() > 0)
	{
		Node* ptr = _head;

		while (ptr != nullptr)
		{
			if ((ptr->data) == value)
			{
				outData.push_back(ptr);
			}

			ptr = ptr->next;
		}
	}
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const
{
	if (NodeCount() > 0)
	{
		Node* ptr = _head;

		while (ptr != nullptr)
		{
			if ((ptr->data) == data)
			{
				return ptr;
			}

			ptr = ptr->next;
		}

		return nullptr;
	}
	else
	{
		return nullptr;
	}

}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data)
{
	if (NodeCount() > 0)
	{
		Node* ptr = _head;

		while (ptr != nullptr)
		{
			if ((ptr->data) == data)
			{
				return ptr;
			}

			ptr = ptr->next;
		}

		return nullptr;
	}
	else
	{
		return nullptr;
	}
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index)
{
	if (NodeCount() > 0)
	{
		Node* ptr = _head;
		unsigned int ptr2 = 0;

		while (ptr2 != index)
		{
			if (ptr == nullptr)
			{
				throw out_of_range("Index out of range.");

				return nullptr;
			}

			ptr = ptr->next;
			ptr2++;
		}

		return ptr;
	}
	else
	{
		throw out_of_range("List has 0 nodes.");
		
		return nullptr;
	}
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const
{
	if (NodeCount() > 0)
	{
		Node* ptr = _head;
		unsigned int ptr2 = 0;

		while (ptr2 != index)
		{
			if (ptr == nullptr)
			{
				throw out_of_range("Index out of range.");

				return nullptr;
			}

			ptr = ptr->next;
			ptr2++;
		}

		return ptr;
	}
	else
	{
		throw out_of_range("List has 0 nodes.");

		return nullptr;
	}
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head()
{
	return _head;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Head() const
{
	return _head;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail()
{
	return _tail;
}

template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Tail() const
{
	return _tail;
}

/*==== Insertion ====*/
template <typename T>
void LinkedList<T>::AddHead(const T& data)
{
	if (_head != nullptr)
	{
		Node* currHead = _head;
		Node* newHead = new Node(data, currHead, nullptr);

		currHead->prev = newHead;

		_head = newHead;
	}
	else // The head does not exist.
	{
		Node* firstNode = new Node(data, nullptr, nullptr);
		_head = firstNode;
		_tail = firstNode;
	}
	
	_nodeCount++;
}

template <typename T>
void LinkedList<T>::AddTail(const T& data)
{
	if (NodeCount() > 0)
	{
		Node* ptr = new Node(data, nullptr, _tail);

		Node* ptr2 = _tail;

		ptr2->next = ptr;

		_tail = ptr;
	}
	else // Tail does not exist.
	{
		_tail = new Node(data, nullptr, nullptr);
		_head = _tail;
	}

	_nodeCount++;
}

template <typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count)
{
	unsigned int ptr = count;

	while (ptr != 0)
	{
		AddHead(data[ptr - 1]);
		ptr--;
	}
}

template <typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count)
{
	unsigned int ptr = 0;

	while (ptr != count)
	{
		AddTail(data[ptr]);
		ptr++;
	}
}

template <typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& data)
{
	Node* ptr = node;

	Node* insertNode = new Node(data, ptr->next, ptr);

	ptr->next = insertNode;

	if (insertNode->next != nullptr)
	{
		ptr = insertNode->next;
		ptr->prev = insertNode;

	}

	_nodeCount++;
}

template <typename T>
void LinkedList<T>::InsertBefore(Node* node, const T& data)
{
	Node* ptr = node;

	Node* insertNode = new Node(data, ptr, ptr->prev);

	ptr->prev = insertNode;

	if (insertNode->prev != nullptr)
	{
		ptr = insertNode->prev;
		ptr->next = insertNode;
	}

	_nodeCount++;
}

template <typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index)
{
	if (index == 0)
	{
		AddHead(data);
	}
	else if (index >= _nodeCount)
	{
		AddTail(data);
	}
	else if (index < _nodeCount)
	{
		Node* indexNode = GetNode(index);

		Node* insertNode = new Node(data, indexNode, indexNode->prev);

		indexNode->prev = insertNode;

		if (insertNode->prev != nullptr)
		{
			Node* ptr = insertNode->prev;

			ptr->next = insertNode;
		}

		_nodeCount++;
	}
}

/*==== Removal ====*/
template <typename T>
bool LinkedList<T>::RemoveHead()
{
	if (_head != nullptr)
	{
		Node* ptr = _head->next;

		delete _head;

		_head = ptr;

		if (_head != nullptr)
			_head->prev = nullptr;

		_nodeCount--;

		return true;
	}
	else // The head does not exist.
	{
		return false;
	}
}

template <typename T>
bool LinkedList<T>::RemoveTail()
{
	if (_tail != nullptr)
	{
		Node* ptr = _tail->prev;

		delete _tail;

		_tail = ptr;

		if (_tail != nullptr)
			_tail->next = nullptr;

		_nodeCount--;

		return true;
	}
	else // The tail does not exist.
	{
		return false;
	}
}

template <typename T>
unsigned int LinkedList<T>::Remove(const T& data)
{
	unsigned int removeCount = 0;

	if (NodeCount() > 0)
	{
		Node* ptr = _head;

		while (ptr != nullptr)
		{
			if ((ptr->data) == data)
			{
				Node* rmNode = ptr;
				Node* next = ptr->next;
				Node* prev = ptr->prev;

				ptr = ptr->next;

				if (next != nullptr)
				{
					next->prev = prev;
				}
				if (prev != nullptr)
				{
					prev->next = next;
				}

				delete rmNode;
				removeCount++;
			}
			else
			{
				ptr = ptr->next;
			}
		}
	}
	_nodeCount -= removeCount;
	return removeCount;
}

template <typename T>
bool LinkedList<T>::RemoveAt(unsigned int index)
{
	bool status = false;

	if (index == 0)
	{
		status = RemoveHead();
	}
	else if (index >= _nodeCount)
	{
		status = false;

	}
	else if (index < _nodeCount)
	{
		Node* rmPtr = GetNode(index);
		Node* prev = rmPtr->prev;
		Node* next = rmPtr->next;

		if (next != nullptr)
		{
			next->prev = prev;
		}
		if (prev != nullptr)
		{
			prev->next = next;
		}

		delete rmPtr;
		_nodeCount--;
		status = true;
	}

	return status;
}

template <typename T>
void LinkedList<T>::Clear()
{
	while (_nodeCount > 0)
		RemoveHead();

	_head = nullptr;
	_tail = nullptr;
	_nodeCount = 0;
}

/*==== Operators ====*/
template <typename T>
const T& LinkedList<T>::operator[](unsigned int index) const
{
	Node* ptr = GetNode(index);
	return ptr->data;
}

template <typename T>
T& LinkedList<T>::operator[](unsigned int index)
{
	Node* ptr = GetNode(index);
	return ptr->data;
}

template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T>& rhs) const
{
	if (NodeCount() == rhs.NodeCount())
	{
		Node* lptr = _head;
		Node* rptr = rhs._head;

		while (lptr != nullptr)
		{
			if (lptr->data != rptr->data)
			{
				return false;
			}

			lptr = lptr->next;
			rptr = rptr->next;
		}

		return true;
	}
	else // Node count is not equal.
	{
		return false;
	}
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs) // Assignment Operator.
{
	Clear();

	if (rhs.NodeCount() > 0)
	{
		// Ptr points to head of input list.
		Node* ptr = rhs._head;
		// Create a new node as the head of list.
		_head = new Node;
		// Set head data = to input head data.
		_head->data = ptr->data;
		// Initialize next and prev pointers.
		_head->next = nullptr;
		_head->prev = nullptr;
		// Ptr2 points to head of new list.
		Node* ptr2 = _head;
		// Advance Ptr.
		ptr = ptr->next;

		while (ptr != nullptr)
		{
			// Create the next node.
			ptr2->next = new Node;
			// Store this node in Ptr3.
			Node* ptr3 = ptr2;
			// Advance Ptr2.
			ptr2 = ptr2->next;
			// Copy the data from the input list.
			ptr2->data = ptr->data;
			// Initialize the next pointer.
			ptr2->next = nullptr;
			// Point the prev pointer to the stored node.
			ptr2->prev = ptr3;
			// Advance Ptr.
			ptr = ptr->next;
		}
		// When the loop breaks Ptr->next is nullptr so this is the tail.
		_tail = ptr2;
		// Copy the nodeCount from the input list.
		_nodeCount = rhs.NodeCount();
	}
	else // List is empty
	{
		// Initialize the new list.
		_head = nullptr;
		_tail = nullptr;
		_nodeCount = 0;
	}

	return *this;
}

/*==== Construction / Destruction ====*/
template <typename T>
LinkedList<T>::LinkedList() // Constructor.
{
	_head = nullptr;
	_tail = nullptr;
	_nodeCount = 0;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) // Copy Constructor.
{
	if (list.NodeCount() > 0)
	{
		// Ptr points to head of input list.
		Node* ptr = list._head;
		// Create a new node as the head of list.
		_head = new Node;
		// Set head data = to input head data.
		_head->data = ptr->data;
		// Initialize next and prev pointers.
		_head->next = nullptr;
		_head->prev = nullptr;
		// Ptr2 points to head of new list.
		Node* ptr2 = _head;
		// Advance Ptr.
		ptr = ptr->next;

		while (ptr != nullptr)
		{
			// Create the next node.
			ptr2->next = new Node;
			// Store this node in Ptr3.
			Node* ptr3 = ptr2;
			// Advance Ptr2.
			ptr2 = ptr2->next;
			// Copy the data from the input list.
			ptr2->data = ptr->data;
			// Initialize the next pointer.
			ptr2->next = nullptr;
			// Point the prev pointer to the stored node.
			ptr2->prev = ptr3;
			// Advance Ptr.
			ptr = ptr->next;
		}
		// When the loop breaks Ptr->next is nullptr so this is the tail.
		_tail = ptr2;
		// Copy the nodeCount from the input list.
		_nodeCount = list.NodeCount();
	}
	else // List is empty
	{
		// Initialize the new list.
		_head = nullptr;
		_tail = nullptr;
		_nodeCount = 0;
	}
}

template <typename T>
LinkedList<T>::~LinkedList() // Destructor.
{
	if (_nodeCount > 0)
	{
		Node* ptr = _head;

		while (ptr != nullptr)
		{
			Node* ptr2 = ptr;
			ptr = ptr->next;

			delete ptr2;
		}
	}
}

/*==== Node Class Member Functions ====*/
template <typename T>
LinkedList<T>::Node::Node()
{
	next = nullptr;
	prev = nullptr;
}

template <typename T>
LinkedList<T>::Node::Node(T data, Node* next, Node* prev)
{
	this->data = data;
	this->next = next;
	this->prev = prev;
}
