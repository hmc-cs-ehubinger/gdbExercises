#include <cassert>
#include <iostream>

int main() {
  int foo = 0;
  int array[5];
  int bar = 42;

  for (unsigned int i = 3; i >= 0; --i) {
    array[i] = i * 10;
  }

  std::cout << foo << std::endl;
  std::cout << bar << std::endl;

  return 0;
}
