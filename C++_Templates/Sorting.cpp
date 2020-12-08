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

void insertion_sort (vi &a) {
	if (a.empty()) return;
	int len = a.size();
	int idx = 0;
	for (int i=1; i<len; i++) {
		idx = i - 1;
		int val = a[i];
		while (idx >= 0 && a[idx] > val) {
			a[idx + 1] = a[idx];
			idx--;
		}
		a[idx + 1] = val;
	}
}

void selection_sort (vi &a) {
	if (a.empty()) return;
	int len = a.size();
	int min_idx = -1;
	for (int i=0; i<len; i++) {
		min_idx = i;
		for (int j=i + 1; j<len; j++) {
			if (a[j] < a[min_idx]) min_idx = j;
		}
		swap(a[min_idx], a[i]);
	}
}

void bubble_sort (vi &a) {
	if (a.empty()) return;
	int len = a.size();
	for (int i=0; i<len - 1; i++) {
		for (int j=0; j<len - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
}

int partition (int a[], int lo, int hi) {
	int i = lo - 1, pivot = a[hi];
	for (int j=lo; j<hi; j++) {
		if (a[j] <= pivot) {
			swap(a[++i], a[j]);
		}
	}
	swap(a[i + 1], a[hi]);
	return i + 1;
}

void quick_sort (int a[], int lo, int hi) {
	if (lo >= hi) return;
	int idx = partition(a, lo, hi);
	quick_sort(a, lo, idx - 1);
	quick_sort(a, idx + 1, hi);
}

void merge (int n, int a[], int lo, int mid, int hi) {
	int i = lo, j = mid + 1, k = lo;
	int v[n + 1];
	while (i <= mid && j <= hi) {
		if (a[i] < a[j]) v[k++] = a[i++];
		else v[k++] = a[j++];
	}
	while (i <= mid) v[k++] = a[i++];
	while (j <= hi) v[k++] = a[j++];
	for (int idx=lo; idx<k; idx++) a[idx] = v[idx];
}

void merge_sort (int n, int a[], int lo, int hi) {
	if (lo >= hi) return;
	int mid = (lo + hi) >> 1;
	merge_sort(n, a, lo, mid);
	merge_sort(n, a, mid + 1, hi);
	merge(n, a, lo, mid, hi);
}

void merge_sort_iterative (int n, int a[]) {
	for (int curr_size=1; curr_size<n; curr_size *= 2) {
		for (int lo=0; lo<n - 1; lo += curr_size * 2) {
			int mid = min(lo + curr_size - 1, n - 1);
			int hi = min(lo + curr_size * 2 - 1, n - 1);
			merge(n, a, lo, mid, hi);
		}
	}
}

void counting_sort (vi arr) {
	int maxx = *max_element(allof(arr));
	int minn = *min_element(allof(arr));
	int range = maxx - minn + 1;
	vi freq(range), ans(arr.size());
	for (auto i : arr) freq[i - minn]++;
	for (int i=1; i<freq.size(); i++) freq[i] += freq[i - 1];
	for (int i=arr.size() - 1; i>=0; i--) {
		freq[arr[i] - minn]--;
		ans[freq[arr[i] - minn]] = arr[i];
	}
	for (int i=0; i<arr.size(); i++) arr[i] = ans[i];
	for (auto i : arr) cout << i << " ";
	cout << "\n";
}

void print_array (int n, int a[]) {
	for (int i=0; i<n; i++) cout << a[i] << " ";
	cout << "\n";
}

int main (int argc, char const *argv[]) {
	#ifdef NOT_DMOJ
	freopen("DATA.in", "r", stdin);
	freopen("DATA.out", "w", stdout);
	#endif // NOT_DMOJ
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a[4] = {99, 3, 2, 1};
	// merge_sort(4, a, 0, 3);
	// merge_sort_iterative(4, a);
	// selection_sort(a);
	quick_sort(a, 0, 3);
	print_array(4, a);
	vi v;
	v.pb(4), v.pb(3), v.pb(2), v.pb(1);
	counting_sort(v);
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