#include "utils.h"
using namespace std;

// TC: O(nlogn), heap operations nlogk, sort nlogn
// SC: O(n)
class Solution
{
public:
    struct Compare
    {
        Compare(int x) : x_(x) {}
        bool operator()(int a, int b)
        {
            if (abs(a - x_) < abs(b - x_) || (abs(a - x_) == abs(b - x_) && a < b))
                return true;
            return false;
        }
        int x_;
    };

    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        typedef priority_queue<int, vector<int>, Compare> myPq;
        myPq pq(x);
        for (int i = 0; i < arr.size(); ++i)
        {
            pq.push(arr[i]);
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> result;
        while (pq.size())
        {
            result.push_back(pq.top());
            pq.pop();
        }
        sort(result.begin(), result.end());
        return result;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    int x = 3;
    printVec(arr);
    Solution s;
    vector<int> result = s.findClosestElements(arr, k, x);
    printVec(result);
    return 0;
}