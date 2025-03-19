#include <cctype>
#include <iostream>
using namespace std;

#define FAST_IO                                                                \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(nullptr);
/*
 * Problem: Mass of Molecule
 *
 * The chemical compound consists of only the elements C, H, O,
 * with atomic masses: C = 12, H = 1, O = 16.
 *
 * The formula is given in a "compressed" format. Examples:
 *   - COOHHH is written as CO2H3
 *   - CH(CO2H)(CO2H) is written as CH(CO2H)2
 *
 * If a subformula is repeated, the repetition count is always between 2 and 9.
 *
 * Task: Calculate the molecular mass of the given formula.
 *
 * Input:
 * - A single string representing the molecule (length ≤ 100).
 * - The string contains only characters C, H, O, (, ), and digits 2-9.
 *
 * Output:
 * - The molecular mass (always ≤ 10000).
 */
// having number -> char -> ascii
// assign components with its values directly
// using stack to manage the group of values, caring abt its order
// ( ) C H O number

void helper(const string &s) {
  stack<int> numb;

  for (int i = 0; i < (int)s.size(); i++) {
    if (s[i] == '(') {
      numb.push(0);
    } else if (s[i] == 'C') {
      numb.push(12);
    } else if (s[i] == 'O') {
      numb.push(16);
    } else if (s[i] == 'H') {
      numb.push(1);
    } else if (s[i] == ')') {
      int sumOfGroup = 0;
      while (numb.top() != '0') {
        numb.pop();
        sumOfGroup += numb.top();
      }
      numb.push(sumOfGroup);
    } else {
      int ans = numb.top();
      numb.pop();
      ans *= s[i] - '0'; // convert from ascii
      numb.push(ans);
    }
  }
  // Make a sum of all elements in stack
  int res = 0;
  while (!numb.empty()) {
    res += numb.top();
    numb.pop();
  }
  cout << res;
}

int main() {
  FAST_IO
  string s;
  cin >> s;
  helper(s);

  return 0;
}
