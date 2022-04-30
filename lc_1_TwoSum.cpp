#include <iostream>
#include <unordered_map>
#include <vector>
#include "utils.h"

using namespace std;

// TC: O(n) loop over nums twice
// SP: O(n) a map is needed
class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    vector<int> results;
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); ++i)
      mp[nums[i]] = i;

    for (int i = 0; i < nums.size(); ++i)
    {
      int the_other = target - nums[i];
      if (mp.count(the_other) && mp[the_other] != i)
      {
        results.push_back(i);
        results.push_back(mp[target - nums[i]]);
        break; // exactly one solution exists
      }
    }
    return results;
  }
};

int main()
{
  vector<int> ivec = {2, 7, 11, 15};
  int target = 9;
  Solution s;
  vector<int> results = s.twoSum(ivec, 9);
  printVec(results);
  return 0;
}
