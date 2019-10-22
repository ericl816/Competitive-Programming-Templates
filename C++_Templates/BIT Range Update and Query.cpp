// Can use BIT range updates and queries, or Seg Tree with Lazy Propagation instead
struct BIT {
private:
    int N;
    vector<ll> bit1, bit2;

public:
    BIT(int N) : N(N), bit1(N + 1), bit2(N + 1) { }

    void Update (vector<ll> &bit, int idx, int val) {
        for (; idx<=N; idx += idx & -idx) bit[idx] += val;
    }

    void Update (int x, int y, int val) {
        Update(bit1, x, val);
        Update(bit1, y + 1, -val);
        Update(bit2, x, val * (x - 1));
        Update(bit2, y + 1, -val * y);
    }

    ll Query (vector<ll> &bit, int idx) {
        ll sum = 0;
        for (; idx; idx -= idx & -idx) sum += bit[idx];
        return sum;
    }

    ll Query (int x) {
        return Query(bit1, x) * x - Query(bit2, x);
    }

    ll Query (int x, int y) {
        return Query(y) - Query(x - 1);
    }
};