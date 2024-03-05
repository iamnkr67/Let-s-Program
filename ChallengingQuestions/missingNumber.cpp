#include <bits/stdc++.h>
using namespace std;

long long sumUptoN(long long n) {
  return n * (n + 1) / 2;
}

int main() {
    long long Actualsize;
    cin >> Actualsize;
    vector<long long> arr;
    for (long long i = 0; i < Actualsize - 1; i++) {
        long long num;
        cin >> num;
        arr.push_back(num);
    }
    // find smallest element
    long long smallest = *min_element(arr.begin(), arr.end());

    // finding missing number;
    long long ArraySum = accumulate(arr.begin(), arr.end(), 0LL);
    long long ActualSum = sumUptoN(Actualsize);

    // If the smallest number is not 1, the missing number is 1
    if (smallest > 1) {
        cout << 1 << endl;
    } else {
        cout << ActualSum - ArraySum << endl;
    }

    return 0;
}