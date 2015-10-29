/*
 * \file intlist.cpp
 * \authors anonymous
 * \brief Implemenation of IntList and its private classes.
 */

#include "intlist.hpp"

#include <cstddef>
#include <cassert>
#include <algorithm>

using namespace std;

//default constructor
IntList::IntList():size_(0)
{

}

//copy constructor
IntList::IntList(const IntList& orig)
{
  IntList newList;
  for (IntList::iterator i = orig.begin(); i != orig.end(); ++i){
    newList.push_back(*i);
  }
  *this=newList;
}

//destructor
IntList::~IntList(){
  while (empty() == false) {
    pop_front();
  }
}

void IntList::swap(IntList& rhs)
{
  // This is the canonical way to swap arbitrary types; this incantation
  // means that we'll use std::swap unless we're swapping a class that
  // provides its own swap function (like we do).  Here we'll be actually
  // just be using std::swap since the swapped parts are primitives.

  std::swap(back_, rhs.back_);
  std::swap(front_, rhs.front_);
  std::swap(size_, rhs.size_);
}

IntList& IntList::operator=(const IntList& rhs)
{
  // Assignment is implemented idiomatically for C++, using "the swap trick"
  IntList copy = rhs;
  swap(copy);
  return *this;
}

size_t IntList::size() const
{
  return size_;
}

bool IntList::empty() const
{
  return size_ == 0;
}


bool IntList::operator==(const IntList& rhs) const
{
  // This doesn't look right...

  return (rhs.size() > 0);
}

bool IntList::operator!=(const IntList& rhs) const
{
  // Idiomatic code: leverage == to implement !=
  return !operator==(rhs);
}

// function to push elements with value pushee to front of intlist
void IntList::push_front(int pushee)
{
  if (empty()) {
    front_ = new Element(pushee, nullptr);
    back_ = front_;
  } else {
    // copies the front_ pointer into oldFront
    Element* oldFront = front_;
    // creates a new elements with the next equal to oldFront
    front_ = new Element(pushee, oldFront);
  }
  ++size_;
}

// function to pop elements from the front of the list
int IntList::pop_front()
{
  assert (empty() == false);

  if (size_ > 1) {
    Element* poppedElement = front_;
    front_= poppedElement->next_;
    delete poppedElement;
    --size_;
    return poppedElement->value_;
  } else {
    delete front_;
    --size_;
    return front_->value_;
  }
}

// function to push elements with value pushee to back of intlist
void IntList::push_back(int pushee)
{
  if (empty() == true) {
    push_front(pushee);
  } else {
    Element* newElement = new Element(pushee, nullptr);
    back_->next_ = newElement;
    back_ = newElement;
    ++size_;
  }
}


void IntList::insert_after(iterator where, int value)
{
  Element* currNext = where.current_->next_;
  Element* inserted = new Element(value, currNext);
  where.current_->next_ = inserted;
  ++size_;
}

//returns head node of the list
IntList::iterator IntList::begin() const
{
  return iterator(front_);
}

//returns a nullpointer
IntList::iterator IntList::end() const
{
  return iterator(nullptr);
}

// --------------------------------------
// Implementation of IntList::Element
// --------------------------------------

IntList::Element::Element(int value, Element* next)
  : value_{value}, next_{next}
{
  // Nothing else to do.
}

// --------------------------------------
// Implementation of IntList::Iterator
// --------------------------------------
//
IntList::Iterator::Iterator(Element* current)
  : current_{current}
{
  // Nothing else to do.
}


IntList::Iterator& IntList::Iterator::operator++()
{
  //go to next element
  current_ = current_->next_;
  return *this;
}


int& IntList::Iterator::operator*() const
{
  //return value stored at the current location
  int& toReturn = current_->value_;
  return toReturn;
}


bool IntList::Iterator::operator==(const Iterator& rhs) const
{
  //return true if they point to same place in memory
  return (rhs.current_ == current_);
}


bool IntList::Iterator::operator!=(const Iterator& rhs) const
{
  // Idiomatic code: leverage == to implement !=
  return !(*this == rhs);
}
