class Solution {
    int m, n;
    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int i, int j, vector<vector<char>>& board,
             vector<vector<int>>& safe) {

        if (i < 0 || j < 0 || i >= m || j >= n ||
            safe[i][j] || board[i][j] == 'X')
            return;

        safe[i][j] = 1;

        for (auto d : dir) {
            dfs(i + d.first, j + d.second, board, safe);
        }
    }

public:
    void solve(vector<vector<char>>& board) {

        m = board.size();
        if (m == 0) return;
        n = board[0].size();

        vector<vector<int>> safe(m, vector<int>(n, 0));

        // 1️⃣ Run DFS from all border 'O's
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') dfs(i, 0, board, safe);
            if (board[i][n - 1] == 'O') dfs(i, n - 1, board, safe);
        }

        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') dfs(0, j, board, safe);
            if (board[m - 1][j] == 'O') dfs(m - 1, j, board, safe);
        }

        // 2️⃣ Build replica initialized with 'X'
        vector<vector<char>> replica(m, vector<char>(n, 'X'));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (safe[i][j]) {
                    replica[i][j] = 'O';
                }
            }
        }

        // 3️⃣ Copy replica back to board
        board = replica;
    }
};
