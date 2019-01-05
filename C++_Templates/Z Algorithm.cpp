// #include <bits/stdc++.h>
#include "/Users/ericliu/Desktop/Competitive-Programming-Templates/stdc++.h"
using namespace std;

/*
For a string str[0..n-1], Z array is of same length as string.
An element Z[i] of Z array stores length of the longest substring starting
from str[i] which is also a prefix of str[0..n-1].
The first entry of Z array is meaning less as complete string is always prefix of itself.
*/

/*
What Z algorithm does, is to evaluate a z-table
where the value of z[i] indicates the longest suffix starting
from index i, which is also a prefix of a string S.
Now to check if the string S="ababa" is palindrome or not
we can reverse the string , add it with the main string and
check every corresponding positions. So, here is the use of z-table. 
*/

bool marked[200010];

vector<int> z_algorithm(string S) {
    int N = S.size(), L = 0, R = 0;
    vector<int> Z(N, 0);
    Z[0] = N;
    for (int i = 1; i < N; i++) {
        if (i < R)
            Z[i] = min(R - i, Z[i - L]);
        while (i + Z[i] < N && S[i + Z[i]] == S[Z[i]])
            ++Z[i];
        if (i + Z[i] > R)
            L = i, R = i + Z[i];
    }
    return Z;
}

vector<int> search(string S, string P) {
    int N = S.size(), M = P.size();
    string combined = P + S;
    vector<int> Z = z_algorithm(combined);
    vector<int> matches;
    for (int i = 0; i < N; i++) {
        if (Z[M + i] >= M) {
            matches.push_back(i);
        }
    }
    return matches;
}

int main() {
    string S = "aabaaa";
    vector<int> Z = z_algorithm(S);
    for (size_t i=0; i<S.size(); i++) {
        if (Z[i] == Z[S.size() - i - 1]) {
            marked[i] = 1;
        }
    }
    for (int i=0; i<S.size(); i++) {
        cout << i << " " << marked[i] << endl;
    }
    for (int i = 0; i < S.size(); i++) {
        cout << "Index " << i << ", Z-value: " << Z[i] << endl;
        cout << S.substr(0, Z[i]) << '|' << S.substr(Z[i]) << endl;
        cout << S.substr(i, Z[i]) << '|' << S.substr(i + Z[i]) << endl;
        cout << endl;
    }
    return 0;
}