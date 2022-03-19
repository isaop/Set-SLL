#include "Set.h"
#include "SetITerator.h"
// n = length

Set::Set() {
	this->head = nullptr;
	this->length = 0;
}//theta(1)


bool Set::add(TElem elem) {
	if (search(elem) == true)
		return false;
	else
	{
		if (this->length == 0)
		{
			node* firstNode = new node;
			firstNode->info = elem;
			firstNode->link = nullptr;
			this->head = firstNode;
		}
		else
		{
			node* newNode = new node;
			newNode->info = elem;
			newNode->link = this->head;
			this->head = newNode;
		}
		this->length++;
		return true;
	}
		
	
}//Best case: theta(1)
//Worst case: theta(n)
//Complexity: O(n)


bool Set::remove(TElem elem) {
	if (search(elem) == false){
		return false;
	}
	else
	{
		node* currentNode = new node;
		node* previousNode = new node;
		previousNode = nullptr;
		currentNode = this->head;
		while (currentNode->info != elem && currentNode != nullptr)
		{
			previousNode = currentNode;
			currentNode = currentNode->link;
		}
		if (currentNode != nullptr && previousNode == nullptr) {
			this->head = this->head->link;
			this->length--;

		}
		else
			if (currentNode != nullptr) {
				previousNode->link = currentNode->link;
				currentNode->link = nullptr;
				this->length--;

			}	
		return true;
	}
}//Best case: theta(1)
//Worst case: theta(n)
//Complexity: O(n)

bool Set::search(TElem elem) const {
	node* current = new node;
	current = this->head;
	while (current != nullptr && current->info != elem  )
	{
		current = current->link;
	}
	if (current == nullptr)
		return false;
	else
		if(current->info == elem)
			return true;
}//Best case: theta(1)
//Worst case: theta(n)
//Complexity: O(n)


int Set::size() const {
	return this->length;
}//theta(1)


bool Set::isEmpty() const {
	return this->length == 0;
}//theta(1)


Set::~Set() {
	node* aux = new node;
	node* current = new node;
	current = this->head;
	while (current != nullptr)
	{
		aux = current->link;
		delete current;
		current = aux;
	}
}//theta(n)


SetIterator Set::iterator() const {
	return SetIterator(*this);
}//theta(1)


