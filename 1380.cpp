*
������������
row[i] ��ʾ �� i �е���Сֵ�ڵ�row[i] ��
col[i] ��ʾ �� i �е����ֵ�ڵ�col[i] ��
һ�� m* n �ı����ҳ� row, col
Ȼ���ҳ�����������λ��
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