#include <cctype>
#include <iostream>
#include <string>
using namespace std;

#define FAST_IO                                                                \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(nullptr);
#define pb push_back

/*
 * Reverse Polish Notation (RPN) Transformation
 *
 * Given an algebraic expression in infix notation with brackets and operators:
 *   Operators: +, -, *, /, ^ (precedence: lowest to highest)
 *   Operands: a, b, ..., z (single-letter variables)
 *
 * The transformation follows these rules:
 * 1. Parentheses dictate operation order.
 * 2. Operator precedence (lowest to highest): +, -, *, /, ^.
 * 3. Left-to-right associativity for +, -, *, /; right-to-left for ^.
 *
 * Example transformations:
 *   Infix:    (a + b) * c
 *   RPN:      a b + c *
 *
 *   Infix:    a + b * c
 *   RPN:      a b c * +
 *
 *   Infix:    a ^ b ^ c
 *   RPN:      a b c ^ ^
 *
 *   Infix:    (a + b) / (c - d) ^ e
 *   RPN:      a b + c d - e ^ /
 *
 */

void RPN_transform(const string &c) {
  stack<char> opr;

  for (char s : c) {
    // Condition 1: If s is the operands
    if (isalpha(s)) {
      cout << s;
    } else if (s == '(') {
      continue;
    } else if (s == ')') {
      cout << opr.top();
      opr.pop();
    } else {
      opr.push(s);
    }
  }
}

int main() {
  FAST_IO;
  int num;
  cin >> num;
  while (num--) {
    string s;
    cin >> s;
    RPN_transform(s);
    cout << endl;
  }
  return 0;
}
