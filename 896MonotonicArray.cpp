#include <iostream>
#include <vector>

class Solution {
   public:
    bool isMonotonic(std::vector<int>& A) {
        bool inc = true;
        bool dec = true;

        for (int i = 0; i < A.size() - 1; ++i) {
            inc &= A[i + 1] >= A[i], dec &= A[i + 1] <= A[i];
        }

        return inc || dec;
    }
};

class Solution2 {
   public:
    bool isMonotonic(std::vector<int>& A) {
        if (A.size() < 3) {
            return true;
        }

        int d = 0;
        int pos = 0;
        for (int i = 0; i < A.size() - 1; ++i) {
            if (A[i + 1] - A[i] > 0) {
                d = 1;
                pos = i + 1;
                break;
            } else if (A[i + 1] - A[i] < 0) {
                d = -1;
                pos = i + 1;
                break;
            } else {
                continue;
            }
        }

        if (d == 0) return true;
        for (int i = pos; i < A.size() - 1; ++i) {
            if ((A[i + 1] - A[i]) * d < 0) return false;
        }

        return true;
    }
};

int main() {
    std::vector<std::vector<int>> input = {
        {1, 2, 2, 3}, {6, 5, 4, 4}, {1, 3, 2}, {1, 2, 4, 5}, {1, 1, 1}};
    Solution a;
    for (auto& i : input) {
        std::cout << a.isMonotonic(i) << std::endl;
    }

    return 0;
}
