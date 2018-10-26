#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXM 1000010
#define MAXN 1010
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

bool prime[MAXN];
vi primes;

// Time Complexity: O(loglog(n))
void sieve (int n) {
    memset(prime, 1, sizeof(prime));
    prime[1] = 0;
    for (int i=2; i*i<=n; i++){
        if (prime[i]) {
            for (int j=i*i; j<=n; j+=i) prime[j] = 0;
        }
    }
}

int main () {
	sieve(MAXM);
	for (int i=1; i<=MAXN; i++) {
		if (prime[i]) primes.pb(i);
	}
	for (int i : primes) cout << i << "\n";
	return 0;
}