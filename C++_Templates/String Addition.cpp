#include <bits/stdc++.h>
using namespace std;

inline string add (string a[], unsigned int size, unsigned int max) {
  string answer = "";
    int carry = 0;
    for (unsigned int i = 1; i <= max; i ++){
      int sum = carry;
      for (unsigned int j = 0; j < size; j ++){
        unsigned int length = a[j].length();
        if (i <= length){
            sum += a[j][length - i] - 48;
        }
      }
        carry = sum / 10;
        sum = sum % 10;
        answer += (char)(sum + 48);
    }
    reverse(answer.begin(), answer.end());
    if (carry){
        cout << carry;
    }
    return answer;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    unsigned int n;
    cin >> n;
    string c[n];
    unsigned int max = 0;
    for (unsigned int i = 0; i < n; i ++){
        char temp[1000000];
        cin >> temp;
        c[i] = temp;
        unsigned int length = c[i].length();
        max = length > max ? length : max;
    }
    cout << add(c, n, max);
    return 0;
}