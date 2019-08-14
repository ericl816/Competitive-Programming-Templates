#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
// #include <bits/stdc++.h>
#include "/Users/ericliu/Desktop/Competitive-Programming-Templates/stdc++.h"
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXM 1010
#define MAXN 5010
#define INF 0x3f3f3f3f
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
#define DEBUG 1
#ifdef DEBUG
	#define D(x...) printf(x)
#else
	#define D(x...)
#endif
using namespace std;

/*
 * Source: https://codeforces.com/blog/entry/22276
 
 * This is so named , since it works on graphs with edge weights 0 and 1.
 * Let's take a point of execution of BFS when you are at an arbitrary vertex
 * "u" having edges with weight 0 and 1. Similar to Dijkstra,
 * we only put a vertex in the queue if it has been relaxed by a
 * previous vertex (distance is reduced by travelling on this edge)
 * and we also keep the queue sorted by distance from source at every point of time.

 * Now, when we are at "u", we know one thing for sure: Travelling an edge (u,v)
 * would make sure that v is either in the same level as u or at the next
 * successive level. This is because the edge weights are 0 and 1.
 * An edge weight of 0 would mean that they lie on the same level,
 * whereas an edge weight of 1 means they lie on the level below.
 * We also know that during BFS our queue holds vertices of two
 * successive levels at max. So, when we are at vertex "u",
 * our queue contains elements of level L[u] or L[u] + 1.
 * And we also know that for an edge (u,v), L[v] is either L[u] or L[u] + 1.
 * Thus , if the vertex "v" is relaxed and has the same level,
 * we can push it to the front of our queue and if it has the very
 * next level, we can push it to the end of the queue. This helps
 * us keep the queue sorted by level for the BFS to work properly.

 * But, using a normal queue data structure, we cannot insert
 * and keep it sorted in O(1). Using priority queue cost us O(logN)
 * to keep it sorted. The problem with the normal queue is the
 * absence of methods which helps us to perform all of these functions:

 * Remove Top Element (To get vertex for BFS)
 * Insert At the beginning (To push a vertex with same level)
 * Insert At the end (To push a vertex on next level)
 */

int N, Q;
int dist[MAXN];
deque<int> dq;
bool vis[MAXN];
vector<pii> adj[MAXN];

inline void BFS (int src) {
	memset(dist, INF, sizeof(dist));
	dist[src] = 0;
	dq.push_front(src);
	while (!dq.empty()) {
		int curr = dq.front();
		dq.pop_front();
		for (auto i : adj[src]) {
			if (dist[i.f] > dist[curr] + i.s) {
				dist[i.f] = dist[curr] + i.s;
				if (i.s == 1) dq.pb(i.f);
				else dq.push_front(i.f);
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
	cin >> N;
	for (int i=1, u, v, w; i<N; i++) {
		cin >> u >> v >> w;
		adj[u].pb(mp(v, w));
		adj[v].pb(mp(u, w));
	}
	BFS(1);
	cin >> Q;
	for (int i=0, v; i<Q; i++) {
		cin >> v;
		cout << dist[v] << "\n";
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