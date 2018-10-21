#include <iostream>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& A) {
        std::vector<std::vector<int>> B(A[0].size(),
                                        std::vector<int>(A.size(), 0));

        for (int i = 0; i < A.size(); ++i)
            for (int j = 0; j < A[i].size(); ++j) B[j][i] = A[i][j];

        return B;
    }
};

// class Solution {
//   public:
//    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& A)
//    {
//        if (A.empty()) {
//            return A;
//        }
//        std::vector<std::vector<int>> B(A[0].size());
//        for (auto& row : B) row.resize(A.size());

//        for (int i = 0; i < A.size(); ++i)
//            for (int j = 0; j < A[i].size(); ++j) B[j][i] = A[i][j];

//        return B;
//    }
//};

int main() {
    std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution a;
    auto result = a.transpose(matrix);
    for (auto& row : result) {
        for (auto i : row) std::cout << i << ' ';
        std::cout << std::endl;
    }

    return 0;
}
