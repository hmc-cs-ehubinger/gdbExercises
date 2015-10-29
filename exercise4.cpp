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
  for (auto iter = integers.begin(); iter != integers.end(); ++iter) {
    integers.erase(iter);
  }

  std::cout << "final size of integers is " << integers.size() << std::endl;

  return 0;
}
