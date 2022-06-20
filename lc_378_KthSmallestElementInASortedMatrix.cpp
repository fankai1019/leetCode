#include "utils.h"
using namespace std;

// TC: O(mnlogk) loop over every elements in the matrix and pq size is k
// SC: O(k) pq size is k
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        priority_queue<int> max_queue;
        int count = 0;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                if (count < k)
                {
                    max_queue.push(matrix[i][j]);
                    count++;
                }
                else
                {
                    max_queue.push(matrix[i][j]);
                    max_queue.pop();
                }
            }
        }
        return max_queue.top();
    }
};

// TC: O(klogk) only k elements are needed and pq size is k
// SC: O(k) pq size is k
class Solution2
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> min_queue;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int r = 0; r < min(k, m); ++r)
            min_queue.push({matrix[r][0], r, 0});

        int result = 0;
        for (int i = 1; i <= k; ++i)
        {
            auto top = min_queue.top();
            int r = top[1];
            int c = top[2];
            result = top[0];

            min_queue.pop();
            if (c + 1 < n)
                min_queue.push({matrix[r][c + 1], r, c + 1});
        }
        return result;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    printVecVec(matrix);
    int k = 8;
    Solution2 s;
    int result = s.kthSmallest(matrix, k);
    cout << result << endl;
    return 0;
}