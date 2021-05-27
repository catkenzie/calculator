//Fabiola Belaen (belaenf), Catherine Kenzie (catkenz)
#ifndef LIST_H
#define LIST_H
/* List.h
*
* doubly-linked, double-ended list with Iterator interface
* EECS 280 Project 4
*/

#include <iostream>
#include <cassert> //assert
#include <cstddef> //NULL


template <typename T>
class List {
	//OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:
	//constructor
	List() : first(nullptr) {}

	//destructor
	~List() { pop_all(); }

	//copy constructor
	List(const List<T> &other) : first(0), last(0) { copy_all(other);  }

	//overload =
	List operator =(const List<T> &other) {
		if (this == &other) {
			return *this;
		}
		pop_all();
		copy_all(other);
		return *this;
	}

	//EFFECTS:  returns true if the list is empty
	bool empty() const {
		return first == nullptr;
	}

	//EFFECTS: returns the number of elements in this List
	int size() const {
		int size = 0;
		if(first == nullptr){
			return 0;
		}
		else{
			for (Node *np = first; np; np = np->next) {
				++size;
			}
			return size;
		}
	}

	//REQUIRES: list is not empty
	//EFFECTS: Returns the first element in the list by reference
	T & front() {
		assert(!empty());
		return first->datum;
	}

	//REQUIRES: list is not empty
	//EFFECTS: Returns the last element in the list by reference
	T & back() {
		assert(!empty());
		return last->datum;
	}

	//MODIFIES: this
	//EFFECTS:  inserts datum into the front of the list
	void push_front(const T &datum) {
		Node *holder = new Node;
		holder->datum = datum;
		holder->prev = nullptr;
		if(empty()){
			first = holder;
			last = holder;
			holder->next = nullptr;
		}
		else{
			first->prev = holder;
			holder->next = first;
			first = holder;
		}
	}

	//MODIFIES: this
	//EFFECTS:  inserts datum into the back of the list
	void push_back(const T &datum) {
		Node *holder = new Node;
		holder->datum = datum;
		holder->next = nullptr;
		if(empty()){
			first = holder;
			last = holder;
			holder->prev = nullptr;
		}
		else{
			last->next = holder;
			holder->prev = last;
			last = holder;
		}
	}

	//REQUIRES: list is not empty
	//MODIFIES: this, may invalidate list iterators
	//EFFECTS:  removes the item at the front of the list
	void pop_front() {
		assert(!empty());
		Node *holder = first;
		if(first == last){
			first = nullptr;
			last = nullptr;
		}
		else{
			first = first->next;
			first->prev = nullptr;

		}
		delete holder;
		holder = nullptr;
}

	//REQUIRES: list is not empty
	//MODIFIES: this, may invalidate list iterators
	//EFFECTS:  removes the item at the back of the list
	void pop_back() {
		assert(!empty());
		Node *holder = last;
		if(first == last){
			first = nullptr;
			last = nullptr;
		}
		else{
			last = last->prev;
			last->next = nullptr;
		}
		delete holder;
		holder = nullptr;
	}

	// You should add in a default constructor, destructor, copy constructor,
	// and overloaded assignment operator, if appropriate. If these operations
	// will work correctly without defining these, you can omit them. A user
	// of the class must be able to create, copy, assign, and destroy Lists

private:
	//a private type
	struct Node {
		Node *next;
		Node *prev;
		T datum;
	};

	//MODIFIES: this
	//EFFECTS:  copies all nodes from other to this
	void copy_all(const List<T> &other) {
		for (Node *np = other.first; np; np = np->next) {
			push_back(np->datum);
		}
	}

	//MODIFIES: this, may invalidate list iterators
	//EFFECTS:  removes all nodes
	void pop_all() {
		while (!empty()) {
			pop_front();
		}
	}

	Node *first;   // points to first Node in list, or nullptr if list is empty
	Node *last;    // points to last Node in list, or nullptr if list is empty

public:
	////////////////////////////////////////
	class Iterator {
		//OVERVIEW: Iterator interface to List

		// You should add in a default constructor, destructor, copy constructor,
		// and overloaded assignment operator, if appropriate. If these operations
		// will work correctly without defining these, you can omit them. A user
		// of the class must be able to create, copy, assign, and destroy Iterators.

		// Your iterator should implement the following public operators: *,
		// ++ (prefix), default constructor, == and !=.


	public:
		//default constructor
		Iterator() : node_ptr(nullptr) {}

		//iterator constructed in the middle
		//Iterator(Node *p) : node_ptr(p) {}

		//overload *
	  T &operator *() const {
			return node_ptr->datum;
		}

		//overload ++
		Iterator &operator ++() {
			node_ptr = node_ptr->next;
			return *this; //node_ptr
		}

		//overload ==
		bool operator==(Iterator right) const {
			return node_ptr == right.node_ptr;
		}

		//overload !=
		bool operator!=(Iterator right) const {
			return node_ptr != right.node_ptr;
		}

		//
		// This operator will be used to test your code. Do not modify it.
		// Requires that the current element is dereferenceable.
		Iterator& operator--() {
			assert(node_ptr);
			node_ptr = node_ptr->prev;
			return *this;
		}

	private:
		Node *node_ptr; //current Iterator position is a List node
						// add any additional necessary member variables here

						// add any friend declarations here
		friend class List;
						// construct an Iterator at a specific position
		Iterator(Node *p) : node_ptr(p) {}

	};//List::Iterator
	  ////////////////////////////////////////

	  // return an Iterator pointing to the first element
	Iterator begin() const {
		return Iterator(first);
	}

	// return an Iterator pointing to "past the end"
	Iterator end() const {
		return Iterator();
	}

	//REQUIRES: i is a valid, dereferenceable iterator associated with this list
	//MODIFIES: this, may invalidate other list iterators
	//EFFECTS: Removes a single element from the list container
	void erase(Iterator i) {
		assert(i != end());
		Node *holder = i.node_ptr;
		Node *left = holder->prev;
		Node *right = holder->next;

		//if the list only has one item
		if (!left && !right) {
			pop_front();
		}

		//if want to erase the first item
		else if (!left) {
			pop_front();
		}

		//if we want to erase the last item
		else if (!right) {
			pop_back();
		}

		//if we want to erase something inthe middle of the list
		else {
			left->next = right;
			right->prev = left;
			delete holder;
			holder = nullptr;
			i.node_ptr = nullptr;
		}
	}

	//REQUIRES: i is a valid iterator associated with this list
	//EFFECTS: inserts datum before the element at the specified position.
	void insert(Iterator i, const T &datum) {
		//If the lst is initialized and empty
		if(empty()){
			push_front(datum);
		}
		
		//if i is the first element
		else if (i == begin()) {
			push_front(datum);
		}

		//if i is the "past the end" element
		else if (i == end()) {
			push_back(datum);
		}

		//if i is in the middle of the list
		else {
			Node *np = new Node;
			np->datum = datum;

			Node *holder = i.node_ptr;
			Node *left = holder->prev;

			holder->prev = np;
			left->next = np;
			np->next = holder;
			np->prev = left;
		}
	}

};//List


  ////////////////////////////////////////////////////////////////////////////////
  // Add your member function implementations below or in the class above
  // (your choice). Do not change the public interface of List, although you
  // may add the Big Three if needed.  Do add the public member functions for
  // Iterator.


#endif
