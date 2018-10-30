#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

class Solution {
   public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        std::vector<int> result;
        int i = 0, j = numbers.size() - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] == target)
                return {i + 1, j + 1};
            else if (numbers[i] + numbers[j] > target)
                --j;
            else
                ++i;
        }
        return result;
    }
};

class Solution2 {
   public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        std::vector<int> result;
        for (auto iter1 = numbers.begin(); iter1 != numbers.end() - 1;
             ++iter1) {
            int a = *iter1;
            auto iter2 = std::find(iter1 + 1, numbers.end(), target - a);
            if (iter2 != numbers.end()) {
                result.push_back(std::distance(numbers.begin(), iter1) + 1);
                result.push_back(std::distance(numbers.begin(), iter2) + 1);
                break;
            }
        }
        return result;
    }
};

int main() {
    std::vector<int> inputs = {2, 7, 11, 15};
    Solution a;
    auto result = a.twoSum(inputs, 9);
    for (auto i : result) std::cout << i << ' ' << ' ';
    std::cout << std::endl;
    return 0;
}
