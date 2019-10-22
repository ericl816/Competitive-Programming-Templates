struct BIT {
private:
    int N;
    vector<ll> bit;

public:
    BIT(int N) : N(N), bit(N + 1) { }

    void Update (int idx, int val) {
        for (; idx<=N; idx += idx & -idx) bit[idx] += val;
    }

    void Update (int x, int y, int val) {
        Update(x, val);
        Update(y + 1, -val);
    }

    ll Query (int idx) {
        ll sum = 0;
        for (; idx; idx -= idx & -idx) sum += bit[idx];
        return sum;
    }

    ll Query (int x, int y) {
        return Query(y) - Query(x - 1);
    }
};