#include <iostream>

using namespace std;

int main() {
  int test_case;
  cin >> test_case;

  while(test_case--) {
    long long L, R;
    cin >> L >> R;

    if(L > R) {
      swap(L, R);
    }

    long long sum = sumUptoN(R) - sumUptoN(L - 1);

    cout << sum << endl;
  }
  return 0;