#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
// #include <bits/stdc++.h>
#include "/Users/ericliu/Desktop/Competitive-Programming-Templates/stdc++.h"
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 1010
#define MAXN 5010
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) < (b) ? (b) : (a))
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>w
#define allof(x) x.begin(), x.end()
#define DEBUG 1
// #define NOT_DMOJ 0
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

inline int GCD (int a, int b) { return b == 0 ? a : GCD(b, a % b); }
inline int LCM (int a, int b) { return a * b / GCD(a, b); }
inline ll PowMod (ll a, ll b, ll mod) { ll val = 1; while (b) { if (b & 1) val = (val * a) % mod; a = (a * a) % mod; b >>= 1; } return val; }

inline void LCS (string X, string Y) {
	int n = X.size(), m = Y.size();
	int DP[n + 1][m + 1];
	int len = 0, row = 0, col = 0;
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=m; j++) {
			if (i == 0 || j == 0) DP[i][j] = 0;
			else if (X[i - 1] == Y[i - 1]) {
				DP[i][j] = DP[i - 1][j - 1] + 1;
				if (DP[i][j] > len) {
					len = DP[i][j];
					row = i;
					col = j;
				}
			}
			else DP[i][j] = 0;
		}
	}
	if (len == 0) {
		cout << "No Common Substring!\n";
		return;
	}
	char ans[len + 1];
	while (DP[row][col] != 0) {
		ans[--len] = X[row - 1];
		--row, --col;
	}
	cout << "Longest Common Substring: " << ans << "\n";
	return;
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("DATA.in", "r", stdin);
	freopen("DATA.out", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string X = "Hello, World", Y = "Hello, World!!! 123";
	LCS(X, Y);
	return 0;
}

/* 
 Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 * number of test cases (T = 10)
 * resetting containers, variables, etc
 */