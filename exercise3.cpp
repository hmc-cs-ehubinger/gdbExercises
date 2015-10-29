#include <cassert>
#include <iostream>
#include <string>
#include <vector>

int main() {

  std::vector<int> integers;
  for (unsigned int i = 0; i < 100; ++i) {
    integers.push_back(i);
  }

  // now empty the integers
  auto iter = integers.begin();
  for (unsigned int i = 0; i < 100; ++i) {
    integers.erase(iter);
    ++iter;
  }

  std::cout << "final size of integers is " << integers.size() << std::endl;

  return 0;
}
