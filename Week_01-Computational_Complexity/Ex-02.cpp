#include <iostream>
#include <vector>
int n;
int height;
int counter;
std::vector<int> a;

int main() {
  std::cin >> n >> height;
  counter = 0;
  a.resize(n);

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    if (a[i] <= height) {
      counter++;
    } else {
      counter += 2;
    }
  }

  std::cout << counter;

  return 0;
}
