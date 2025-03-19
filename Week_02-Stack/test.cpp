#include <cctype>
#include <iostream>
using namespace std;

#define FAST_IO                                                                \
  ios::sync_with_stdio(false);                                                 \
  cin.tie(nullptr);
#define pb push_back

inline int precedence(const char &c) {
  return (c == '+' || c == '-')   ? 1
         : (c == '+' || c == '-') ? 2
         : (c == '+' || c == '-') ? 3
                                  : 0;
}

void convertToRPN(const string &s) {
  stack<char> op; // operator
  string res;

  for (char c : s) {
    if (isalpha(c)) {
      res.pb(c);
    } else if (c == '(') {
      op.push(c);
    } else if (c == ')') {
      // if op not empty && op.top not (
      while (!op.empty() && op.top() != '(') {
        res.pb(op.top());
        op.pop();
      }
      // end the while at '('
      op.pop(); // remove the '('
    } else {
      while (!op.empty() && precedence(op.top() >= precedence(c) && c != '^')) {
        res.push_back(op.top());
        op.pop();
      }
      op.push(c);
    }
  }

  while (!op.empty()) {
    res.pb(op.top());
    op.pop();
  }

  cout << res << '\n';
}

int main() {
  FAST_IO
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    convertToRPN(s);
  }
  return 0;
}
