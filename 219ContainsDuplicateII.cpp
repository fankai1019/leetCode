#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

class Solution {
   public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        k = k + 1;
        if (nums.size() < k) {
            std::set<int> temp(nums.begin(), nums.end());
            if (temp.size() != nums.size()) return true;
            return false;
        } else {
            std::set<int> kset(nums.begin(), nums.begin() + k);
            if (kset.size() < k) return true;
            int i = k;
            while (i != nums.size()) {
                kset.erase(kset.find(nums[i - k]));
                kset.insert(nums[i]);
                if (kset.size() < k) return true;
                i++;
            }
            return false;
        }
    }
};

int main() {
    std::vector<int> inputs{1, 2, 3, 1};
    Solution a;
    std::cout << a.containsNearbyDuplicate(inputs, 3) << std::endl;
    return 0;
}
