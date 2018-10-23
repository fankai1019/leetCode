#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

class Solution{
public:
    int majorityElement(std::vector<int>& nums){
        std::map<int, int> mymap;
        int max = 0;
        for(int i = 0; i < nums.size(); ++i){
            mymap[nums[i]]++;
            max = std::max(max, mymap[i]);
        }

        for(auto& i : mymap)
            if(i.second == max)
                return i.first;
        return 0;
    }
};

int main(){

    std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    Solution a;
    std::cout << a.majorityElement(nums);
    return 0;
}
