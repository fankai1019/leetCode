#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> sortArrayByParity(vector<int>& A) {
        std::sort(A.begin(), A.end(), [](int a, int b) {
            if (a % 2 == b % 2)
                return a < b;
            else
                return a % 2 == 0;
        });
        return A;
    }
};

// class Solution {
//   public:
//    vector<int> sortArrayByParity(vector<int>& A) {
//        vector<int> result;
//        for (auto iter = A.begin(); iter != A.end(); ++iter)
//            if (*iter % 2 == 0) result.push_back(*iter);

//        for (auto iter = A.begin(); iter != A.end(); ++iter)
//            if (*iter % 2 != 0) result.push_back(*iter);
//        return result;
//    }
//};

int main() {
    vector<int> input = {3, 1, 2, 4};
    Solution a;
    vector<int> result = a.sortArrayByParity(input);
    for (auto i : result) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
}
