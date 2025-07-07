class Solution {
  public:
    vector<long long int> segtree;

    long long buildsegtree(int i, int l, int r, int arr[]) {
        if (l == r) {
            segtree[i] = arr[l];  // FIXED: assignment added
            return arr[l];
        }
        if (l > r) return 0;
        int mid = l + (r - l) / 2;
        long long le = buildsegtree(2 * i + 1, l, mid, arr);
        long long ri = buildsegtree(2 * i + 2, mid + 1, r, arr);
        segtree[i] = le + ri;
        return segtree[i];
    }

    long long getq(int i, int lq, int rq, int le, int ri) {
        if (le > rq || lq > ri) return 0;
        if (lq <= le && rq >= ri) return segtree[i];
        int mid = le + (ri - le) / 2;
        long long l = getq(2 * i + 1, lq, rq, le, mid);
        long long r = getq(2 * i + 2, lq, rq, mid + 1, ri);
        return l + r;
    }

    vector<int> querySum(int n, int arr[], int q, int queries[]) {
        segtree.resize(4 * n, 0);  // INIT with zeros
        buildsegtree(0, 0, n - 1, arr);
        vector<int> ans(q );
        for (int i = 0; i < 2* q; i += 2) {
            ans[i / 2] = getq(0, queries[i] - 1, queries[i + 1] - 1, 0, n - 1);
        }
        return ans;
    }
};
