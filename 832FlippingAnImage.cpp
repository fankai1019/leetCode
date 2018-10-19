#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> flipAndInvertImage(
        std::vector<std::vector<int>>& A) {
        for (auto& row : A) std::reverse(row.begin(), row.end());

        for (auto& row : A)
            for (auto& i : row) i = 1 - i;

        return A;
    }
};

class Solution2 {
   public:
    std::vector<std::vector<int>> flipAndInvertImage(
        std::vector<std::vector<int>>& A) {
        for (auto& row : A) {
            for (int i = 0; i < row.size() / 2; ++i) {
                int t = row[i];
                row[i] = row[row.size() - i - 1] != 1;
                row[row.size() - i - 1] = t != 1;
            }
        }

        return A;
    }
};

int main() {
    std::vector<std::vector<int>> matrix = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
    Solution a;
    auto result = a.flipAndInvertImage(matrix);

    for (const auto& row : matrix) {
        std::cout << '[';
        for (auto iter = row.cbegin(); iter != row.cend() - 1; ++iter) {
            std::cout << *iter << ',';
        }
        std::cout << row.back() << ']' << std::endl;
    }
}
