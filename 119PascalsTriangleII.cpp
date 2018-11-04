#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> row(rowIndex + 1, 0);
        row[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            row[rowIndex] = 1;
            for (int j = rowIndex - 1; j > 0; --j) {
                row[j] = row[j] + row[j - 1];
            }
        }
        return row;
    }
};

class Solution2 {
   public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> row(rowIndex + 1, 0);
        row[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            row[rowIndex] = 1;
            for (int j = rowIndex / 2; j > 0; --j) {
                int temp = row[j] + row[j - 1];
                row[j] = temp;
                row[rowIndex - j] = temp;
            }
        }
        return row;
    }
};

int main() {
    Solution a;
    auto result = a.getRow(3);
    for (auto i : result) std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}
