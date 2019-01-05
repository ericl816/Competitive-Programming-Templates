#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1010
#define MAXN 5010
#define INF 0x3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
using namespace std;

/* 
 * Use DP to get the Longest Common Subsequence
 * Overall Time Complexity: O(N*M)
 */

int DP[MAXN][MAXN];
vi a, b;
int n, m;

inline int LCS () {
	for (size_t i=0; i<=a.size(); i++) {
		for (size_t j=0; j<=b.size(); j++) {
			if (i == 0 || j == 0) DP[i][j] = 0;
			else if (a[i - 1] == b[j - 1]) DP[i][j] = DP[i - 1][j - 1] + 1;
			else DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
		}
	}
	return DP[a.size()][b.size()];
}

int main () {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		a.pb(x);
	}
	for (int i=0; i<m; i++) {
		int x;
		cin >> x;
		b.pb(x);
	}
	cout << LCS(a, b) << endl;
	return 0;
}