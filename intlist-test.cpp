/**
 * \file intlist-test.cpp
 * \authors Evan Hubinger and Ramy Elminyawi
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
  std::cout << "Testing default constructor" << std::endl;

  IntList myList;

  // Test both size() and empty()
  assert(myList.size() == 0);
  assert(myList.empty());

  return;
}

/** \brief Test push_front
 *  \detail Adds one element, then 1000 elements to the list
 */
void pushFrontTest()
{
  std::cout << "Testing push_front" << std::endl;

  IntList myList;

  myList.push_front(99999);
  assert(myList.size() == 1);
  assert(!myList.empty());

  for (size_t i = 0; i != 1000; ++i) {
     myList.push_front(i);
  }

  assert(myList.size() == 1001);
  assert(!myList.empty());
}

/** \brief Test pop_front for IntLists
 *  \detail Adds 1000 elements to a list and removes each element
 *     one at a time. Checks that all elements are removed in
 *     the right order.
 */
void popFrontTest()
{
  std::cout << "Testing pop_front" << std::endl;
  IntList popList;

  // Put 1000 elements on the list
  for (size_t i = 0; i < 1001; ++i) {
    popList.push_front(i);
  }

  // Remove 1000 elements from the list
  assert(popList.size() == 1001);
  for (int i = 0; i < 1001; ++i) {
    assert(popList.pop_front() == 1000-i);
  }

  // Check end size() and empty()
  assert(popList.size() == 0);
  assert(popList.empty());
}

/** \brief Test push_Back for IntLists
 *  \detail Adds 1000 elements to a list and removes each element
 *     one at a time. Checks if elements are in correct order.
 */
void pushBackTest()
{
  std::cout << "Testing push_back" << std::endl;
  IntList pushList;

  for (size_t i = 0; i < 1001; ++i) {
    pushList.push_back(i);
  }
  assert(pushList.size() == 1001);

  for (int i = 0; i < 1001; ++i) {
    assert(pushList.pop_front() == i);
  }
  assert(pushList.size() == 0);
}

/** \brief Test iterator for IntLists
 *  \detail Adds 1000 elements to a list and checks the size of the
 *      list and the elements after all have been added.
 */
void iteratorTest()
{
  std::cout << "Testing iterator" << std::endl;
  IntList iterList;

  // Tests empty list
  assert(iterList.begin() == iterList.end());

  for (size_t i = 0; i < 1001; ++i) {
    iterList.push_back(i);
  }
  assert(iterList.size() == 1001);

  int i = 0;
  for (IntList::iterator it = iterList.begin();
       it != iterList.end(); ++it) {
    assert(*it == i);
    ++i;
  }
  assert(i == 1001);
  assert(iterList.size() == 1001);
}

/** \brief Test copy constructor for IntLists
 *  \detail Copies a 1000-element list.
 *     Checks whether the resulting list contents are correct.
 */
void copyConstructorTest()
{
  std::cout << "Testing list copy constructor" << std::endl;

  IntList myList;
  for (size_t i = 0; i != 1000; ++i) {
     myList.push_front(i);
  }

  // Redundant, but better safe than sorry.
  assert(myList.size() == 1000);

  // Copy the list
  IntList copyList = myList;

  // Test to make sure list is in proper order
  int i = 0;
  for (IntList::iterator it = copyList.begin();
       it != copyList.end(); ++it) {
    assert(*it == 999 - i);
    ++i;
  }
  assert(i == 1000);

  // Add more to the original list
  for (size_t i = 0; i != 1000; ++i) {
     myList.push_front(i);
  }

  // Check that the copy hasn't changed,
  // and that both lists have the correct size.
  assert(copyList.size() == 1000);
  assert(myList.size() == 2000);
}

/** \brief Test insert_after for IntLists
 *  \detail Adds an element to the list and inserts an element after,
 *      checking the size and elements of the list.
 */
void insertAfterTest()
{
  std::cout << "Testing insert_after" << std::endl;
  IntList insertList;

  insertList.push_front(1);
  assert(insertList.size() == 1);

  insertList.insert_after(insertList.begin(), 2);
  assert(insertList.size() == 2);

  insertList.push_back(3);
  assert(insertList.size() == 3);

  int i = 1;
  for (IntList::iterator it = insertList.begin();
       it != insertList.end(); ++it) {
    assert(*it == i);
    ++i;
  }
  assert(i == 4);
}

/** \brief Test equality and inequality for IntLists
 *  \detail Creates two lists and adds the same elements to the list to
 *      check equality and then adds different elements to both lists
 *      to check inequality.
 */
void comparisonTest()
{
  std::cout << "Testing == and !=" << std::endl;
  IntList compareList1;
  IntList compareList2;

  // compareList1 == [], compareList2 == []
  assert(compareList1 == compareList2);
  assert(!(compareList1 != compareList2));

  // compareList1 == [1], compareList2 == []
  compareList1.push_front(1);
  assert(compareList1 != compareList2);
  assert(!(compareList1 == compareList2));

  // compareList1 == [1], compareList2 == [1]
  compareList2.push_front(1);
  assert(compareList1 == compareList2);

  // compareList1 == [1,2], compareList2 == [1]
  compareList1.push_front(2);
  assert(compareList1 != compareList2);

  // compareList1 == [1,2], compareList2 == [1,3]
  compareList2.push_front(3);
  assert(compareList1 != compareList2);
}

int main(int, const char**)
{
    defaultConstructorTest();
    pushFrontTest();
    popFrontTest();
    pushBackTest();
    iteratorTest();
    copyConstructorTest();
    insertAfterTest();
    comparisonTest();

    // Unix "success" value
    return 0;
}
