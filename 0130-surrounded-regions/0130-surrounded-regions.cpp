class Solution {
public:
    int rows, cols;
    vector<vector<int>> vis;

    void dfs(vector<vector<char>>& board, int row, int col, bool &can, vector<pair<int, int>> &region) {
        vis[row][col] = 1;
        region.push_back({row, col});

        if (row == 0 || row == rows - 1 || col == 0 || col == cols - 1) {
            can = false;
        }

        vector<int> dr = {-1, 0, 0, 1};
        vector<int> dc = {0, -1, 1, 0};

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                if (board[nr][nc] == 'O' && vis[nr][nc] == -1) {
                    dfs(board, nr, nc, can, region);
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();

        vis.assign(rows, vector<int>(cols, -1));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O' && vis[i][j] == -1) {
                    bool canSurround = true;
                    vector<pair<int, int>> region;
                    dfs(board, i, j, canSurround, region);

                    if (canSurround) {
                        for (auto [r, c] : region) {
                            board[r][c] = 'X';
                        }
                    }
                }
            }
        }
    }
};
