struct BIT {
private:
	int N;
	vi tree;

public:
	BIT (int N) : N(N), tree(N + 1) { }

	void Update (int idx, int val) {
		for (; idx<=N; idx += idx & -idx) tree[idx] += val;
	}

	ll Query (int idx) {
		ll sum = 0;
		for (; idx; idx -= idx & -idx) sum += tree[idx];
		return sum;
	}

	ll Query (int l, int r) {
		return Query(r) - Query(l - 1);
	}
};