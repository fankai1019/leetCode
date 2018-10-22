#include <algorithm>
#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>

class Solution {
   public:
    // if Alice swaps candy x and she expects some specific quantity of candy y
    // back; Then, Sa - x + y = Sb - y + x; Then y = x + (Sb - Sa)/2; This
    // method is to tell wheher the lhs of equation above is in set B or not;
    // Thus, set is preferrable here;
    std::vector<int> fairCandySwap(std::vector<int>& A, std::vector<int>& B) {
        std::vector<int> result;

        int SumA = std::accumulate(A.begin(), A.end(), 0);
        int SumB = std::accumulate(B.begin(), B.end(), 0);

        std::unordered_set<int> Bset(B.begin(), B.end());
        for (auto x : A) {
            auto y = x + (SumB - SumA) / 2;
            if (Bset.find(y) != Bset.end()) {
                result.push_back(x);
                result.push_back(y);
                break;
            }
        }

        return result;
    }
};

class Solution2 {
   public:
    std::vector<int> fairCandySwap(std::vector<int>& A, std::vector<int>& B) {
        std::vector<int> result;

        int sumA = std::accumulate(A.begin(), A.end(), 0);
        int sumB = std::accumulate(B.begin(), B.end(), 0);

        bool found = false;
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B.size(); ++j) {
                if (sumB - B[j] + A[i] == sumA - A[i] + B[j]) {
                    result.push_back(A[i]);
                    result.push_back(B[j]);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        return result;
    }
};

int main() {
    std::vector<int> A = {1, 2, 5};
    std::vector<int> B = {2, 4};
    Solution a;
    auto result = a.fairCandySwap(A, B);

    for (auto i : result) std::cout << i << ' ';

    std::cout << std::endl;
    return 0;
}
