#include "utils.h"

using namespace std;

// TC: O(logn) worse case, its prime factors are all 2
// SC: O(1)
class Solution
{
public:
    bool isUgly(int n)
    {
        if (n == 0)
            return false;
        if (n == 1)
            return true;

        while (n % 2 == 0)
            n /= 2;
        while (n % 3 == 0)
            n /= 3;
        while (n % 5 == 0)
            n /= 5;
        return n == 1;
    }
};

int main()
{
    int n = 10;
    Solution s;
    bool result = s.isUgly(n);
    cout << result << endl;
    return 0;
}
