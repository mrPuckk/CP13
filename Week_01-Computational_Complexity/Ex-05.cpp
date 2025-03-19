#include <iostream>

int main() {
  int N;
  std::cin >> N;

  for (int i = 0; i < N; i++) {
    long long iii = 0;
    std::cin >> iii;

    while (iii % 2 == 0) {
      iii /= 2;
    }
    if (iii % 2 == 1 && iii > 1) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
      std::cout << sizeof(int);
    }
  }

  return 0;
}
