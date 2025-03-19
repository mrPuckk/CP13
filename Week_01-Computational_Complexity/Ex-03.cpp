#include <iostream>
int weight;

int main() {
  std::cin >> weight;

  if ((weight > 2) && (weight % 2 == 0)) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  };

  return 0;
}
