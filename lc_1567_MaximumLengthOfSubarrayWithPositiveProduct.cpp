#include <iostream>
#include <memory>
#include <vector>

#include "utils.h"
using namespace std;

// TC: O(n) loops over all elements
// SC: O(n) stack size is n
// recursive
#define ll long long int
class Solution1
{
public:
    int getMaxLen(vector<int> &nums)
    {
        global_pos_ = 0;
        ll pos, neg;
        helper(nums, nums.size() - 1, pos, neg);
        return global_pos_;
    }

private:
    void helper(vector<int> &nums, ll i, ll &pos, ll &neg)
    {
        if (i < 0)
        {
            pos = 0;
            neg = 0;
            return;
        }

        ll prev_pos;
        ll prev_neg;
        helper(nums, i - 1, prev_pos, prev_neg);
        if (nums[i] > 0)
        {
            pos = prev_pos + 1;
            neg = prev_neg ? prev_neg + 1 : 0;
        }
        else if (nums[i] < 0)
        {
            pos = prev_neg ? prev_neg + 1 : 0;
            neg = prev_pos + 1;
        }
        else
        {
            pos = 0;
            neg = 0;
        }

        if (global_pos_ < pos)
            global_pos_ = pos;
    }

    ll global_pos_;
};

// TC: O(n) loops over all elements
// SC: O(1) needs to store pos and neg
// iterative
class Solution2
{
public:
    int getMaxLen(vector<int> &nums)
    {
        ll global_pos = 0;
        ll curr_pos = 0;
        ll curr_neg = 0;
        ll prev_pos = 0;
        ll prev_neg = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            ll nums_i = nums[i];
            if (nums_i == 0)
            {
                curr_pos = 0;
                curr_neg = 0;
            }
            else if (nums_i > 0)
            {
                curr_pos = prev_pos + 1;
                curr_neg = prev_neg ? prev_neg + 1 : 0;
            }
            else
            {
                curr_pos = prev_neg ? prev_neg + 1 : 0;
                curr_neg = prev_pos + 1;
            }

            if (curr_pos > global_pos)
                global_pos = curr_pos;

            prev_pos = curr_pos;
            prev_neg = curr_neg;
        }
        return global_pos;
    }
};

int main()
{
    // Solution1 s;
    Solution2 s;
    // vector<int> ivec = {0, 1, -2, -3, -4};
    vector<int> ivec = {-1, -2, -3, 0, 1};
    int result = s.getMaxLen(ivec);
    cout << result << endl;
    return 0;
}
