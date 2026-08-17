class Solution {
public:

    int solve(vector<vector<char>>& matrix, int i, int j, int& Max,
          vector<vector<int>>& dp) {

    if (i >= matrix.size() || j >= matrix[0].size()) {
        return 0;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    int right = solve(matrix, i, j + 1, Max, dp);
    int diagonal = solve(matrix, i + 1, j + 1, Max, dp);
    int bottom = solve(matrix, i + 1, j, Max, dp);

    if (matrix[i][j] == '1') {

        dp[i][j] = 1 + min({right, diagonal, bottom});

        Max = std::max(Max, dp[i][j]);

        return dp[i][j];
    }

    return dp[i][j] = 0;
}

int maximalSquare(vector<vector<char>>& matrix) {

    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }

    int Max = 0;

    int r = matrix.size();
    int c = matrix[0].size();

    vector<vector<int>> dp(r, vector<int>(c, -1));

    solve(matrix, 0, 0, Max, dp);

    return Max * Max;
}
};