*
两个辅助数组
row[i] 表示 第 i 行的最小值在第row[i] 列
col[i] 表示 第 i 列的最大值在第col[i] 行
一次 m* n 的遍历找出 row, col
然后找出满足条件的位置
* /
class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        vector<int> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] < matrix[i][row[i]]) {
                    row[i] = j;
                }
                if (matrix[i][j] > matrix[col[j]][j]) {
                    col[j] = i;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if (i == col[row[i]]) {
                res.push_back(matrix[i][row[i]]);
            }
        }
        return res;
    }
};