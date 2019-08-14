#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define MAXN 70010
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

int N;
ll inv_count;
ll tree[MAXN], A[MAXN], B[MAXN];
 
inline void Update (int idx, int val) {
  for (idx; idx<=MAXN; idx += idx & -idx) tree[idx] += val;
}

inline ll Query (int idx) {
  ll sum = 0;
  for (idx; idx; idx -= idx & -idx) sum += tree[idx];
  return sum;
}

int main () {
  #ifdef NOT_DMOJ
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif // NOT_DMOJ
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  scanf("%d", &N);
  for (int i=0; i<N; i++) {
    scanf("%lld", &A[i]);
    B[i] = A[i];
  }
  sort(B, B + N);
  for (int i=0; i<N; i++) {
    int rank = int(lower_bound(B, B + N, A[i]) - B);
    A[i] = rank + 1;
  }
  for (int i=N - 1; i>=0; i--) {
    ll x = Query(A[i] - 1);
    inv_count += x;
    Update(A[i], 1);
  }
  return !printf("%lld\n", inv_count);
}