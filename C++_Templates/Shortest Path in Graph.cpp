#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 16
#define MAXN 50010
#define MAXQ 110
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f
#define min(a, b) (a) < (b) ? (a) : (b)
#define max(a, b) (a) < (b) ? (b) : (a)
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair
#define f first
#define s second
#define mii map<int, int>
#define umii unordered_map<int, int>
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

// Using solution to https://codeforces.com/problemset/problem/1051/F

int N, M, Q, a, b, w, s, e, ind, idx;
int in[MAXN], out[MAXN], depth[MAXN];
vector<pair<int, ll> > adj[MAXN];
int par[MAXM][MAXN];
set<pii> edges; // Stores "special" nodes that are incident on non-tree edges
queue<int> q;
ll dist[MAXN];
ll cost[MAXQ][MAXN];
bool vis[MAXN];

inline void DFS (int node, int prev, ll weight) {
	in[node] = idx++;
	par[0][node] = prev;
	dist[node] = weight;
	vis[node] = 1;
	for (int i=1; i<MAXM; i++) {
		par[i][node] = par[i - 1][par[i - 1][node]];
	}
	for (auto i : adj[node]) {
		if (!vis[i.f]) {
			DFS(i.f, node, weight + i.s);
			if (node < i.f) edges.erase(mp(node, i.f));
			else edges.erase(mp(i.f, node));
		}
	}
	out[node] = idx;
}

inline bool Ancestor (int x, int y) {
	return in[x] <= in[y] && out[x] >= out[y];
}

inline int LCA (int x, int y) {
	if (Ancestor(x, y)) return x;
	if (Ancestor(y, x)) return y;
	for (int i=MAXM - 1; i>=0; i--) {
		if (!Ancestor(par[i][x], y)) {
			x = par[i][x];
		}
	}
	return par[0][x];
}

inline void SPFA (int src, ll dist[MAXN]) {
	memset(vis, 0, sizeof(vis));
	vis[src] = 1;
	dist[src] = 0LL;
	q.push(src);
	while (!q.empty()) {
		int curr = q.front(); q.pop();
		vis[curr] = 0;
		for (auto i : adj[curr]) {
			if (dist[i.f] > dist[curr] + i.s) {
				dist[i.f] = dist[curr] + i.s;
				if (!vis[i.f]) {
					vis[i.f] = 1;
					q.push(i.f);
				}
			}
		}
	}
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i=1; i<=M; i++) {
		cin >> a >> b >> w;
		adj[--a].pb(mp(--b, w));
		adj[b].pb(mp(a, w));
	}
	for (int i=0; i<N; i++) {
		for (auto j : adj[i]) {
			if (i < j.f) {
				edges.insert(mp(i, j.f));
			}
		}
	}
	DFS(0, 0, 0LL);
	for (auto i : edges) {
		memset(cost[ind], INF, sizeof(cost[ind]));
		SPFA(i.f, cost[ind++]);
	}
	cin >> Q;
	while (Q--) {
		cin >> s >> e;
		// D("%d\n", LCA(s, e));
		ll ans = dist[--s] + dist[--e] - (dist[LCA(s, e)] << 1);
		for (size_t i=0; i<edges.size(); i++) ans = min(ans, cost[i][s] + cost[i][e]);
		cout << ans << "\n";
	}
	return 0;
}
/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */