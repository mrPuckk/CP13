#include <iostream>
#include <vector>
int n;
std::vector<int> a;

int main() {
  std::cin >> n;
  int isnt_fastened = 0;
  a.resize(n);

  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    if (a[i] == 0) {
      isnt_fastened++;
    }
  }

  if ((isnt_fastened == 1 && n > 1) || (isnt_fastened == 0 && n == 1)) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }

  return 0;
}
