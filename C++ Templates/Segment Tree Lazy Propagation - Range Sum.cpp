// Use Segment Tree with Lazy Propagation - Range Sum
struct Node {
    int l, r;
    ll val, lazy;
};

struct Seg {
private:
    int N;
    vector<Node> tree;

public:
    Seg(int N) : N(N), tree(N << 2) { }

    inline void Push_Up (int idx) {
        tree[idx].val = tree[idx << 1].val + tree[idx << 1 | 1].val;
    }

    inline void Push_Down (int idx) {
        if (tree[idx].lazy && tree[idx].l ^ tree[idx].r) {
            tree[idx << 1].val += tree[idx].lazy * (tree[idx << 1].r - tree[idx << 1].l + 1);
            tree[idx << 1].lazy += tree[idx].lazy;
            tree[idx << 1 | 1].val += tree[idx].lazy * (tree[idx << 1 | 1].r - tree[idx << 1 | 1].l + 1);
            tree[idx << 1 | 1].lazy += tree[idx].lazy;
            tree[idx].lazy = 0;
        }
    }

    inline void Build (int idx, int l, int r) {
        tree[idx].l = l, tree[idx].r = r;
        if (l == r) {
            tree[idx].val = spin[l];
            return;
        }
        int mid = (l + r) >> 1;
        Build(idx << 1, l, mid);
        Build(idx << 1 | 1, mid + 1, r);
        Push_Up(idx);
    }

    inline void Update (int idx, int l, int r, int val) {
        Push_Down(idx);
        if (tree[idx].l > r || tree[idx].r < l) return;
        if (tree[idx].l >= l && tree[idx].r <= r) {
            tree[idx].val += val * (tree[idx].r - tree[idx].l + 1);
            tree[idx].lazy += val;
            return;
        }
        Update(idx << 1, l, r, val);
        Update(idx << 1 | 1, l, r, val);
        Push_Up(idx);
    }

    inline ll Query (int idx, int l, int r) {
        Push_Down(idx);
        if (tree[idx].l > r || tree[idx].r < l) return 0;
        if (tree[idx].l >= l && tree[idx].r <= r) return tree[idx].val;
        return Query(idx << 1, l, r) + Query(idx << 1 | 1, l, r);
    }
};