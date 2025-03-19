#include <iostream>

int main() {
  int numofTest;
  std::cin >> numofTest;

  for (int i = 1; i <= numofTest; i++) {
    int n;
    std::cin >> n;
    std::cout << n - 1 << std::endl;
  }
  return 0;
}
