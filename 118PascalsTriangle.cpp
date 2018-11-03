#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> results;
        if (numRows != 0) {
            results.push_back({1});
            for (int i = 1; i < numRows; ++i) {
                std::vector<int> temp(i + 1, 0);
                temp[0] = 1;
                temp[temp.size() - 1] = 1;
                for (int j = 1; j < temp.size() - 1; ++j) {
                    temp[j] = results.back()[j - 1] + results.back()[j];
                }
                results.push_back(temp);
            }
            return results;
        } else {
            return {};
        }
    }
};

int main() {
    int input = 5;
    Solution a;
    auto result = a.generate(input);
    for (auto& row : result) {
        for (auto i : row) std::cout << i << ' ';
        std::cout << std::endl;
    }

    return 0;
}

