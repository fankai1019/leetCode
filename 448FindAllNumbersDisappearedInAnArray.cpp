#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

//Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.
//Find all the elements of [1, n] inclusive that do not appear in this array.
//Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
//Example:

//Input:
//[4,3,2,7,8,2,3,1]

//Output:
//[5,6]

class Solution{
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums){
        std::vector<int> result;
        for(int i = 0; i < nums.size(); ++i){
            int m = std::abs(nums[i]) - 1;
            nums[m] = nums[m] > 0 ? -nums[m] : nums[m];
        }

        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] > 0)
                result.push_back(i + 1);
        return result;
    }
};

int main(){

    std::vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    Solution a;
    auto result = a.findDisappearedNumbers(nums);
    for(auto i : result) std::cout << i << ' ';
    std::cout << std::endl;
    return 0;
}
