#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> imageSmoother(
        std::vector<std::vector<int>>& M) {
        if (M.size() == 0 && M[0].size() == 0) return {{}};

        int m = M.size();
        int n = M[0].size();
        std::vector<std::vector<int>> N(M.size(),
                                        std::vector<int>(M[0].size(), 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int count = 0;
                int sum = 0;
                for (int k = i - 1; k <= i + 1; ++k)
                    for (int l = j - 1; l <= j + 1; ++l) {
                        if (k > -1 && k < m && l > -1 && l < n) {
                            count++;
                            sum += M[k][l];
                        }
                    }
                N[i][j] = sum / count;
            }
        }
        return N;
    }
};

int main() {
    //    std::vector<std::vector<int>> input = {{1, 1, 1}, {1, 0, 1}, {1, 1,
    //    1}};
    std::vector<std::vector<int>> input = {
        {2, 3, 4}, {5, 6, 7}, {8, 9, 10}, {11, 12, 13}, {14, 15, 16}};
    Solution a;
    auto result = a.imageSmoother(input);
    for (auto row : result) {
        for (auto i : row) std::cout << i << ' ';
        std::cout << std::endl;
    }
    return 0;
}
