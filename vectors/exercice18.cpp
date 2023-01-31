// is_integral example
#include <iostream>
#include <type_traits>

int main() {
  std::cout << std::boolalpha;
  std::cout << "is_integral:" << std::endl;
  
  std::cout << "char: " << std::is_integral<char>::value << std::endl;
  std::cout << "int: " << std::is_integral<int>::value << std::endl;
  std::cout << "float: " << std::is_integral<float>::value << std::endl;
  return 0;
}