#include <vector>
#include <algorithm>

using namespace std;

class SegmentTree {
    vector<double> tree;
    int n;
public:
    SegmentTree(const vector<double>& arr) {
        n = arr.size();
        tree.assign(2 * n, 0);
        for (int i = 0; i < n; i++) tree[n + i] = arr[i];
        for (int i = n - 1; i > 0; --i) tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
    }
    double query_max(int l, int r) {
        double res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, tree[l++]);
            if (r & 1) res = max(res, tree[--r]);
        }
        return res;
    }
};