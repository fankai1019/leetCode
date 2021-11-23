#include <iostream>
#include <vector>
using namespace std;

// TC: O(n^2), this is the best we can do for an n by n matrix
// SC: O(1), we just use an integer for the swap
class Solution
{
public:
    void rotateMatrix(vector<vector<int>> &matrix)
    {
        size_t n = matrix.size();
        for (size_t i = 0; i < n / 2; ++i)
        {
            size_t left = i;
            size_t right = matrix[i].size() - 1 - i;
            for (size_t j = left; j < right; ++j)
            {
                size_t distance = j - left;
                swap(matrix[left][left + distance], matrix[right - distance][left], matrix[right][right - distance], matrix[left + distance][right]);
            }
        }
    }

    static void printMatrix(const vector<vector<int>> &matrix)
    {
        for (size_t i = 0; i < matrix.size(); ++i)
        {
            for (size_t j = 0; j < matrix[i].size(); ++j)
            {
                cout << matrix[i][j];
                if (j != matrix[i].size() - 1)
                    cout << ", ";
                else
                    cout << endl;
            }
        }
        cout << endl;
    }

private:
    void swap(int &a, int &b, int &c, int &d)
    {
        int e = a;
        a = b;
        b = c;
        c = d;
        d = e;
    }
};

int main()
{
    vector<vector<int>> matrix{
        {1, 2, 3, 2, 5},
        {4, 5, 6, 3, 7},
        {7, 8, 9, 5, 9},
        {1, 3, 3, 6, 9},
        {6, 1, 4, 8, 0}};
    Solution::printMatrix(matrix);
    Solution s;
    s.rotateMatrix(matrix);
    Solution::printMatrix(matrix);
    return 0;
}