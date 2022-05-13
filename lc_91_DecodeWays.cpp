#include <iostream>
#include <vector>

#include "utils.h"

using namespace std;

// DP
// define dp[i] as the number of ways with i being the first char
// TC: O(n) iterate onces
// SC: O(n) an array is needed for dp
class Solution1
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        vector<int> dp(n, 0);
        for (int i = n - 1; i >= 0; --i)
        {
            if (s[i] == '0')
            {
                dp[i] = 0;
                continue;
            }
            if (i == n - 1)
                dp[i] = 1;
            else
            {
                bool valid = (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'));
                if (i == n - 2)
                    dp[i] = dp[i + 1] + (valid ? 1 : 0);
                else
                    dp[i] = dp[i + 1] + (valid ? dp[i + 2] : 0);
            }
        }
        return dp[0];
    }
};

// DP
// define dp[i] as the number of ways with i being the first char
// TC: O(n) iterate once
// SC: O(1) 3 pointers
class Solution2
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        int curr = 0;
        int next = 0;
        int next_next = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if (s[i] == '0')
            {
                curr = 0;
            }
            else
            {
                if (i == n - 1)
                    curr = 1;
                else
                {
                    bool valid = (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'));
                    if (i == n - 2)
                        curr = next + (valid ? 1 : 0);
                    else
                        curr = next + (valid ? next_next : 0);
                }
            }
            next_next = next;
            next = curr;
        }
        return next;
    }
};

int main()
{
    string str = "11106";
    cout << str << endl;
    // Solution1 s;
    Solution2 s;
    int result = s.numDecodings(str);
    cout << result << endl;
    return 0;
}
