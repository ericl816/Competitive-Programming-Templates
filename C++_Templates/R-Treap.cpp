#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define ull unsigned long long
#define MAXN 100010
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
#define println cout << "\n";
#ifdef DEBUG
    #define D(x...) printf(x)
#else
    #define D(x...)
#endif
using namespace std;

/*
Treap supports two basic (and very powerful) operations : split and merge , both in 𝑂(𝐻) where H is height of treap i.e 𝑂(𝑙𝑜𝑔𝑁) .
split(T,X) :  It splits a given treap T into two different treaps L and R such that L contains all the nodes with 𝐵𝑘<=𝑋 and R contains all the nodes with 𝐵𝑘>𝑋 . The original treap T is destroyed/doesn't exist anymore after the split operation.
(The equality can be put on either side depending on your choice wlg. I prefer equality on the left side and so shall be used further in the blog)

merge(L,R) : The merge operation merges two given treaps L and R into a single treap T and L and R are destroyed after the operation. A very important assumption of the merge operation is that the largest value of L is less than the smallest value of R (where value refers to the 𝐵𝑘 values of the particular node).

Hence we observe that two treaps obtained after a split operation can always be merged to give back the original treap.
*/

// Using solution to Binary Search Tree Test as code for template

int N, M, a, x, ans;
char c;

struct node {
    int val,p,sz;
    node *ch[2];
    node (int i) : val(i), p(rand()), sz(1) {
        ch[0] = ch[1] = NULL;
    }
} *root;

inline int sz (node *n) {
    return n ? n->sz : 0;
}

inline void upd_sz (node *n) {
    if (n) n->sz = sz(n->ch[0]) + 1 + sz(n->ch[1]);
}

inline void rot (node *&n, bool b) {
    node *tmp = n->ch[b];
    n->ch[b] = tmp->ch[b ^ 1];
    tmp->ch[b ^ 1] = n;
    upd_sz(n);
    upd_sz(tmp);
    n = tmp;
}

inline void ins (node *&n, node *i) {
    if (!n) n = i;
    else {
        bool b = n->val < i->val;
        ins(n->ch[b], i);
        if (n->ch[b]->p > n->p) rot(n, b);
    }
    upd_sz(n);
}

inline void del (node *&n, int i) {
    if (!n) return;
    if(n->val == i) {
        if (!n->ch[0] || !n->ch[1]) n = n->ch[0] ? n->ch[0] : n->ch[1];
        else {
            bool b = n->ch[1]->p > n->ch[0]->p;
            rot(n, b);
            del(n->ch[b ^ 1], i);
        }
    }
    else del(n->ch[n->val < i], i);
    upd_sz(n);
}

int sel (node *n, int i) {
    if (sz(n->ch[0]) + 1 == i) return n->val;
    else if (sz(n->ch[0]) + 1 < i) return sel(n->ch[1], i - sz(n->ch[0]) - 1);
    else return sel(n->ch[0], i);
}

int rnk (node *n, int i, int s = 0) {
    if (!n) return -1;
    if (n->val == i) {
        int tmp = rnk(n->ch[0], i, s);
        return ~tmp ? tmp : s + sz(n->ch[0]) + 1;
    }
    else if (n->val < i) return rnk(n->ch[1], i, s + 1 + sz(n->ch[0]));
    else return rnk(n->ch[0], i, s);
}

void display (node *n) {
    if (!n) return;
    display(n->ch[0]);
    printf("%d ",n->val);
    display(n->ch[1]);
}

int main (int argc, char const *argv[]) {
    #ifdef NOT_DMOJ
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif // NOT_DMOJ
    scanf("%d %d", &N, &M);
    for (int i=0, a; i<N; i++) {
        scanf("%d", &a);
        ins(root, new node(a));
    }
    for (int i=0, x; i<M; i++) {
        scanf(" %c %d", &c, &x);
        x ^= ans;
        switch (c) {
            case 'I':
                ins(root, new node(x));
                break;
            case 'R':
                del(root,x);
                break;
            case 'S':
                printf("%d\n", ans = sel(root,x));
                break;
            case 'L':
                printf("%d\n", ans = rnk(root,x));
                break;
        }
    }
    display(root);
    return 0;
}

/* 
 * Look for:
 * the exact constraints (multiple sets are too slow for n=10^6 :( ) 
 * special cases (n=1?)
 * overflow (ll vs int?)
 * array bounds
 */