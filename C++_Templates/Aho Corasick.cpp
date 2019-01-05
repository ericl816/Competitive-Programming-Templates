#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
// #include <bits/stdc++.h>
#include "/Users/ericliu/Desktop/Competitive-Programming-Templates/stdc++.h"
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 200010
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
// #define NOT_DMOJ 0
#ifdef DEBUG
    #define D(x...) printf(x)
#else
    #define D(x...)
#endif
using namespace std;

inline int GCD (int a, int b) { return b == 0 ? a : GCD(b, a % b); }
inline int LCM (int a, int b) { return a * b / GCD(a, b); }
inline ll PowMod (ll a, ll b, ll MOD) { ll val = 1; while (b) { if (b & 1) val = (val * a) % MOD; a = (a * a) % MOD; b >>= 1; } return val; }

int N;
int M; // number of states in the automation
int g[MAXN][26]; // the normal edges in the trie
int f[MAXN]; // failure function
ll out[MAXN]; // output function
ll ans;
string s;
vector<string> dict;

vi KMP (string S, string K) {
    vi T(K.size() + 1, -1);
    vi matches;
    if (K.empty()) {
        matches.pb(0);
        return matches;
    }
    for (size_t i=1; i<=K.size(); i++) {
        int pos = T[i - 1];
        while (~pos && K[pos] != K[i - 1]) pos = T[pos];
        T[i] = pos + 1;
    }
    int sp = 0, kp = 0;
    while (sp < S.size()) {
        while (~kp && (kp == K.size() || K[kp] != S[sp])) kp = T[kp];
        kp++, sp++;
        if (kp == K.size()) matches.pb(sp - K.size());
    }
    return matches;
}

int aho_corasick() {
    memset(g, -1, sizeof g);
    memset(out, 0, sizeof out);

    int nodes = 1;

    // build the trie
    for (auto &s : dict) {
        int cur = 0;
        for (int j = 0; j < s.size(); j++) {
            if (g[cur][s[j] - 'a'] == -1) {
                g[cur][s[j] - 'a'] = nodes++;
            }
            cur = g[cur][s[j] - 'a'];
        }
        out[cur]++;
    }

    for (int ch = 0; ch < 26; ch++) {
        if (g[0][ch] == -1) {
            g[0][ch] = 0;
        }
    }

    // BFS to calculate out and failure functions
    memset(f, -1, sizeof f);
    queue<int> q;
    for (int ch = 0; ch < 26; ch++) {
        if (g[0][ch] != 0) {
            f[g[0][ch]] = 0;
            q.push(g[0][ch]);
        }
    }

    while (!q.empty()) {
        int state = q.front();
        q.pop();

        for (int ch = 0; ch < 26; ch++) {
            if (g[state][ch] == -1) continue;

            int fail = f[state];
            while (g[fail][ch] == -1) {
                fail = f[fail];
            }

            f[g[state][ch]] = g[fail][ch];
            out[g[state][ch]] += out[g[fail][ch]];

            q.push(g[state][ch]);
        }
    }

    return nodes;
}

inline ll search () {
    // Using the Aho-Corasick automation, search the text.
    int state = 0;
    ll ret = 0LL;
    for (char c : s) {
        while (g[state][c - 'a'] == -1) {
            state = f[state];
        }
        state = g[state][c - 'a'];
        D("%lld\n", out[state]);
        ret += out[state];
    }
    // It's that simple!
    return ret;
}

int main (int argc, char const *argv[]) {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> s;
    for (int i=1; i<=N; i++) {
        string ss1 = s.substr(0, i), ss2 = s.substr(N - i, i);
        if (ss1 == ss2) dict.pb(ss1);
    }
    dict.erase(unique(dict.begin(), dict.end()), dict.end());
    // for (auto i : dict) cout << i << " ";
    M = aho_corasick();
    ans = search();
    cout << ans << endl;
    return 0;
}

/*
6
aabaaa
Ans: 9
*/

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */