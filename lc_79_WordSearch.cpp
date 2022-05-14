#include "utils.h"

using namespace std;

// Backtracking
// TC: O(m*n*L^4) there are 2^n possible subsets and each time we need to copy path into results
// SC: O(L) stack frame size is L, path size is L, regardless of collecting results
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        result = false;
        int m = board.size() - 1;
        int n = board[0].size() - 1;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        string path;
        for (int i = 0; i <= m; ++i)
            for (int j = 0; j <= n; ++j)
                backtracking(board, i, j, m, n, path, visited, word);
        return result;
    }

private:
    bool backtracking(vector<vector<char>> &board, int i, int j,
                      int m, int n, string &path, vector<vector<bool>> &visited, const string &word)
    {
        if (result)
            return true;

        if (path.size() && path.back() != word[path.size() - 1])
            return result = false;

        if (path.size() == word.size())
            return result = true;

        if (i < 0 || i > m || j < 0 || j > n)
            return result = false;

        if (visited[i][j])
            return result = false;

        path.push_back(board[i][j]);
        visited[i][j] = true;
        backtracking(board, i, j + 1, m, n, path, visited, word);
        backtracking(board, i, j - 1, m, n, path, visited, word);
        backtracking(board, i + 1, j, m, n, path, visited, word);
        backtracking(board, i - 1, j, m, n, path, visited, word);
        path.pop_back();
        visited[i][j] = false;
        return result;
    }
    bool result;
};

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    Solution s;
    bool result = s.exist(board, word);
    cout << result << endl;
    return 0;
}
