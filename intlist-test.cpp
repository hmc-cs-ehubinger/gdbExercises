/**
 * \file intlist-test.cpp
 * \authors YOUR NAME HERE
 * \brief The program unit tests the IntList class.
 */

/* Note: In testing, it's always a good idea to #include the header you're
 * testing without including anything else beforehand.  That way, if your header
 * refers to strings or vectors or size_t without including the necessary header
 * files, you'll know.
 */
#include "intlist.hpp"

#include <cassert>
#include <iostream>

/** \brief Test default constructor for IntLists
 */
void defaultConstructorTest()
{
  IntList myList;

  assert(myList.size() == 0);

  return;
}

/** \brief Test push_front
 *  \detail Does 1000 inserts at the front of the list.
 *
 */
void pushFrontTest()
{
  IntList myList;

  myList.push_front(99999);
  assert(myList.size() == 1);

  for (size_t i = 0; i != 1000; ++i) {
    myList.push_front(i);
  }

  assert(myList.size() == 1001);
}

/** \brief Test pop_front
 *  \detail Pops the front of the list 1,000 times.
 *
 */
void popFrontTest()
{
  IntList myList;

  for (size_t i = 0; i != 1001; ++i) {
    myList.push_front(i);
  }

  myList.pop_front();

  assert(myList.size() == 1000);

  for (size_t i = 0; i != 1000; ++i)
    {
      myList.pop_front();
    }

  assert(myList.size() == 0);
}

/** \brief Test push_back
 *  \detail inserts values to the back of 1,000 times.
 *
 *
 */
void pushBackTest()
{
  IntList myList;

  myList.push_back(99999);
  assert(myList.size() == 1);
  for (size_t i = 0; i != 1000; ++i)
    {

      myList.push_back(i);
    }

  assert(myList.size() == 1001);
}

/** \brief Test copy constructor for IntLists
 *  \detail creates a 1000-element list.
 *      copies the elements into a new list
 *      increase the old list and checks the size of each
 */
void copyConstructorTest()
{
  IntList myList;
  for (size_t i = 0; i != 1000; ++i) {
    myList.push_front(i);
  }

  // Redundant, but better safe than sorry.
  assert(myList.size() == 1000);
  // Copy the list
  IntList copyList = myList;
  // Add more to the original list
  for (size_t i = 0; i != 1000; ++i) {
    myList.push_front(i);

  }
  // Check that the copy hasn't changed,
  // and that both lists have the correct size.
  assert(copyList.size() == 1000);
  assert(myList.size() == 2000);
}

/** \brief Test operator++ for iterators
 *  \detail creates a 75 element list
 *     iterates through by using ++
 *     pops the front of the list
 */
void operatorPlusPlusTest()
{
  IntList myList;
  for (size_t i = 0; i != 75; ++i) {
    myList.push_front(i);
  }

  assert(myList.size() == 75);

  for (IntList::iterator j = myList.begin(); j != myList.end(); ++j) {
    if (myList.size() != 0) {
      myList.pop_front();
    }
  }
  assert(myList.size() == 0);
}

/** \brief Tests the insert after function
 *  \detail creates a 200 element list
 *     iterates over and adds an element
 *     after each element that already exists
 */
void insertAfterTest()
{
  IntList myList;
  for (size_t i = 0; i != 200; ++i) {
    myList.push_front(i);
  }
  assert (myList.size() == 200);

  for (IntList::iterator j = myList.begin(); j != myList.end(); ++j) {
    myList.insert_after(j, 3);
    ++j;
  }
  assert (myList.size() == 400 );
}

int main() {
  defaultConstructorTest();
  pushFrontTest();
  popFrontTest();
  pushBackTest();
  copyConstructorTest();
  operatorPlusPlusTest();
  insertAfterTest();
  return 0;
}
