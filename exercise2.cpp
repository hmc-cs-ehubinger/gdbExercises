#include <cassert>
#include <iostream>

struct Object {
  int array_[3];
  const int numberOfDoohickies_;
  Object(const int input) :
    numberOfDoohickies_(input) {
  }
};

int main() {

  const int startingNumberOfDoohickies = 42;
  Object object(startingNumberOfDoohickies);

  // Print out the object contents
  std::cout << "starting object array contents:" << std::endl;
  std::cout << object.array_[0] << std::endl;
  std::cout << object.array_[1] << std::endl;
  std::cout << object.array_[2] << std::endl;
  std::cout << "starting object number of doohickies:" << std::endl;
  std::cout << object.numberOfDoohickies_ << std::endl;

  for (unsigned int index = 0; index < 4; ++index) {
    object.array_[index] = index * 10;
  }

  // Print out the object contents
  std::cout << "final object array contents:" << std::endl;
  std::cout << object.array_[0] << std::endl;
  std::cout << object.array_[1] << std::endl;
  std::cout << object.array_[2] << std::endl;
  std::cout << "final object number of doohickies:" << std::endl;
  std::cout << object.numberOfDoohickies_ << std::endl;

  return 0;
}
