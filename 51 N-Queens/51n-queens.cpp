class Solution {
public:
    vector<vector<string>> res;
    vector<string> board;
    vector<bool> col, diag1, diag2;

    void backtrack(int row, int n) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int c = 0; c < n; ++c) {
            if (col[c] || diag1[row + c] || diag2[row - c + n - 1]) continue;

            board[row][c] = 'Q';
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = true;

            backtrack(row + 1, n);

            board[row][c] = '.';
            col[c] = diag1[row + c] = diag2[row - c + n - 1] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        board = vector<string>(n, string(n, '.'));
        col = vector<bool>(n, false);
        diag1 = vector<bool>(2 * n - 1, false);
        diag2 = vector<bool>(2 * n - 1, false);

        backtrack(0, n);
        return res;
    }
};
