class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size(), cnt = n / 2;
        vector<int> root(n, 0);
        for (int i = 0; i < n; ++i) root[i] = i;
        for (int i = 0; i < n; i += 2) {
            //union
            int x = find(root, row[i] / 2);
            int y = find(root, row[i + 1] / 2);
            if (x != y) {
                root[x] = y;
                --cnt;
            }
        }
        return n / 2 - cnt;
    }
    int find(vector<int>& root, int i) {
        return (i == root[i]) ? i : find(root, root[i]);
    }
    //https://mli9502.github.io/2018/10/24/leetcode-765-Couples-Holding-Hands/
};
