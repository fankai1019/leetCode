#include <iostream>
#include <set>
#include <vector>

class Solution {
   public:
    int numMagicSquaresInside(std::vector<std::vector<int>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 5) {
                    if (i > 0 & i<grid.size() - 1 & j> 0 &
                        j < grid[0].size() - 1) {
                        std::set<int> iset;
                        for (int m = i - 1; m <= i + 1; ++m)
                            for (int n = j - 1; n <= j + 1; ++n)
                                iset.insert(grid[m][n]);
                        if (iset != std::set<int>{1, 2, 3, 4, 5, 6, 7, 8, 9})
                            continue;
                        else {
                            int temp;
                            temp = grid[i - 1][j - 1] + grid[i - 1][j] +
                                   grid[i - 1][j + 1];
                            if (temp != 15) continue;
                            temp = grid[i][j - 1] + grid[i][j] + grid[i][j + 1];
                            if (temp != 15) continue;
                            temp = grid[i + 1][j - 1] + grid[i + 1][j] +
                                   grid[i + 1][j + 1];
                            if (temp != 15) continue;
                            temp = grid[i - 1][j - 1] + grid[i][j - 1] +
                                   grid[i + 1][j - 1];
                            if (temp != 15) continue;
                            temp = grid[i - 1][j] + grid[i][j] + grid[i + 1][j];
                            if (temp != 15) continue;
                            temp = grid[i - 1][j + 1] + grid[i][j + 1] +
                                   grid[i + 1][j + 1];
                            if (temp != 15) continue;
                            temp = grid[i - 1][j - 1] + grid[i][j] +
                                   grid[i + 1][j + 1];
                            if (temp != 15) continue;
                            temp = grid[i - 1][j + 1] + grid[i][j] +
                                   grid[i + 1][j - 1];
                            if (temp != 15) continue;
                            count++;
                        }
                    } else
                        continue;
                } else
                    continue;
            }
        }
        return count;
    }
};

int main() {
    std::vector<std::vector<int>> inputs = {
        {4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}};
    Solution a;
    std::cout << a.numMagicSquaresInside(inputs) << std::endl;
    return 0;
}
