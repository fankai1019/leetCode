#include "utils.h"

using namespace std;

// DP
// TC: O(n) iterated over all nodes in worse case
// SC: O(h) stack frame size is height
class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        istringstream ss(preorder);
        string token;
        vector<string> nodes;
        while (getline(ss, token, ','))
            nodes.push_back(token);
        int n = nodes.size();
        if (n == 0 || (n == 1 && nodes[0] == "#"))
            return true;
        if (n == 2)
            return false;
        if (nodes[n - 1] != "#")
            return false;
        if (nodes[n - 2] != "#")
            return false;
        vector<int> dp(nodes.size(), -1);
        vector<int> length(nodes.size(), 0);
        dp[n - 1] = 0;
        dp[n - 2] = 0;
        for (int i = n - 3; i >= 0; --i)
        {
            if (nodes[i + 1] == "#" && nodes[i + 2] == "#" && nodes[i] != "#")
            {
                dp[i] = 1;
                length[i] = 3;
                continue;
            }
            if (nodes[i + 1] == "#" && dp[i + 2])
            {
                dp[i] = 1;
                length[i] = 2 + length[i + 2];
                continue;
            }
            if (dp[i + 1] && i + length[i + 1] + 1 < n && nodes[i + length[i + 1] + 1] == "#")
            {
                dp[i] = 1;
                length[i] = 2 + length[i + 1];
                continue;
            }
            if (dp[i + 1] && i + length[i + 1] + 1 < n && dp[i + length[i + 1] + 1])
            {
                dp[i] = 1;
                length[i] = 1 + length[i + 1] + length[i + length[i + 1] + 1];
                continue;
            }
        }

        return dp[0] == 1 && length[0] == nodes.size();
    }
};

int main()
{
    // string str = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    string str = "9,#,92,#,#";
    Solution s;
    bool result = s.isValidSerialization(str);
    cout << result << endl;
    return 0;
}
