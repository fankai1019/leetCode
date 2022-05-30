#include "utils.h"

using namespace std;

// Prioirty Queue
// TC: O(nlogn) insert to min_q 3n times
// SC: O(n) min_q size 3n
class Solution1
{
public:
    int nthUglyNumber(int n)
    {
        if (n == 1)
            return 1;
        vector<long> ugly;

        priority_queue<long, vector<long>, greater<long>> min_q;
        min_q.push(1);

        int count = 0;
        while (count < n)
        {
            while (count > 1 && min_q.top() == ugly.back())
                min_q.pop();

            long top = min_q.top();
            min_q.pop();

            ugly.push_back(top);
            count++;

            min_q.push(top * 2);
            min_q.push(top * 3);
            min_q.push(top * 5);
        }
        return ugly[n - 1];
    }
};

// Set
// TC: O(nlogn) insert to set 3n times
// SC: O(n) set size 3n
class Solution2
{
public:
    int nthUglyNumber(int n)
    {
        if (n == 1)
            return 1;

        set<long> lset;
        lset.insert(1);

        vector<long> ugly;

        int count = 0;
        while (count < n)
        {
            long top = *lset.begin();
            lset.erase(top); // logarithmic in container size

            ugly.push_back(top);
            count++;

            lset.insert(top * 2);
            lset.insert(top * 3);
            lset.insert(top * 5);
        }
        return ugly[n - 1];
    }
};

int main()
{
    int n = 10;
    // Solution1 s;
    Solution2 s;
    int result = s.nthUglyNumber(n);
    cout << result << endl;
    return 0;
}
