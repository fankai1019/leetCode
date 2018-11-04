#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            int theOther = target - nums[i];
            if (hash.find(theOther) != hash.end()) return {hash[theOther], i};
            hash[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    std::vector<int> inputs = {2, 7, 11, 15};
    Solution a;
    auto result = a.twoSum(inputs, 9);
    for (auto i : result) std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}
