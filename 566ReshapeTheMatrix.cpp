#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> matrixReshape(
        std::vector<std::vector<int>>& nums, int r, int c) {
        int row = nums.size();
        int column = nums[0].size();
        if (row * column != r * c) {
            return nums;
        }

        std::vector<std::vector<int>> matrix(r, std::vector<int>(c, 0));
        int m = 0;
        int n = 0;

        for (int i = 0; i < row * column; ++i) {
            matrix[i / c][i % c] = nums[i / column][i % column];
        }

        return matrix;
    }
};

class Solution2 {
   public:
    std::vector<std::vector<int>> matrixReshape(
        std::vector<std::vector<int>>& nums, int r, int c) {
        int row = nums.size();
        int column = nums[0].size();
        if (row * column != r * c) {
            return nums;
        }

        std::vector<std::vector<int>> matrix(r, std::vector<int>(c, 0));
        int m = 0;
        int n = 0;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j) {
                if (n < column)
                    matrix[i][j] = nums[m][n++];
                else {
                    n = 0;
                    matrix[i][j] = nums[++m][n++];
                }
            }

        return matrix;
    }
};

int main() {
    std::vector<std::vector<int>> matrix = {{1, 2}, {3, 4}};
    Solution a;
    auto result = a.matrixReshape(matrix, 1, 4);
    for (auto& row : result) {
        for (auto i : row) std::cout << i << ' ';
        std::cout << std::endl;
    }

    return 0;
}
