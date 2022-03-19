#include "SetIterator.h"
#include "Set.h"
#include <exception>
using namespace std;
SetIterator::SetIterator(const Set& m) : set(m)
{
	this->currentElemet = m.head;
}//theta(1)



void SetIterator::first() {
	this->currentElemet = set.head;
}//theta(1)



void SetIterator::next() {
	if (this->currentElemet == nullptr)
		throw exception();
	this->currentElemet = this->currentElemet->link;
}//theta(1)



TElem SetIterator::getCurrent()
{
	if (this->currentElemet == nullptr)
		throw exception();
	TElem e;
    e = this->currentElemet->info;
	return e;

}//theta(1)

bool SetIterator::valid() const {
	if (this->currentElemet != nullptr)
		return true;
	else
		return false;
}//theta(1)



