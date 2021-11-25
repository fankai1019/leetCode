#include <iostream>
#include <map>
#include <vector>
using namespace std;

// TC: O(n)
// SC: O(map size), O(n)
class Solution
{
public:
    enum direct
    {
        right,
        left,
        up,
        down
    };
    void langtonsAton(int k)
    {
        map<pair<int, int>, int> grid;
        grid[make_pair(0, 0)] = 0;
        size_t m = 0, n = 0;
        direct d = right;
        for (size_t i = 0; i < k; ++i)
        {
            pair<int, int> pos(m, n);
            if (grid[pos]) // black
            {
                grid[pos] = 0; // white
                d = nextDirect(1, d);
                if (d == right)
                    m++;
                else if (d == left)
                    m--;
                else if (d == up)
                    n++;
                else
                    n--;
            }
            else // white
            {
                grid[pos] = 1; // black
                d = nextDirect(0, d);
                if (d == right)
                    m++;
                else if (d == left)
                    m--;
                else if (d == up)
                    n++;
                else
                    n--;
            }
            grid[make_pair(m, n)];
        }
        int grid_left = INT_MAX;
        int grid_right = -INT_MAX;
        int grid_down = INT_MAX;
        int grid_up = -INT_MAX;
        for (map<pair<int, int>, int>::iterator iter = grid.begin(); iter != grid.end(); ++iter)
        {
            int i = iter->first.first;
            int j = iter->first.second;
            if (i < grid_left)
                grid_left = i;
            if (i > grid_right)
                grid_right = i;
            if (j < grid_down)
                grid_down = j;
            if (j > grid_up)
                grid_up = j;
        }

        int shift_right = grid_left < 0 ? -grid_left : 0;
        int shift_up = grid_down < 0 ? -grid_down : 0;
        int row_length = grid_up - grid_down + 1;
        int col_length = grid_right - grid_left + 1;

        vector<vector<int>> imatrix(row_length, vector<int>(col_length, 0));
        for (map<pair<int, int>, int>::iterator iter = grid.begin(); iter != grid.end(); ++iter)
        {
            int i = iter->first.first;
            int j = iter->first.second;
            if (iter->second == 1)
                imatrix[j + shift_up][i + shift_right] = 1;
        }
        cout << "grid: " << endl;

        for (size_t i = imatrix.size() - 1; i < imatrix.size(); --i)
            printVec(imatrix[i]);
    }

private:
    direct nextDirect(int color, direct current_direct)
    {
        if (color == 0) // white
        {
            if (current_direct == right)
                return down;
            if (current_direct == down)
                return left;
            if (current_direct == left)
                return up;
            return right;
        }
        else // black
        {
            if (current_direct == right)
                return up;
            if (current_direct == up)
                return left;
            if (current_direct == left)
                return down;
            return right;
        }
    }

    void printVec(const vector<int> &ivec)
    {
        for (size_t i = 0; i < ivec.size(); ++i)
            cout << ivec[i] << " ";
        cout << endl;
    }
};

int main()
{
    int k;
    cout << "Input num of steps: " << endl;
    cin >> k;
    Solution s;
    s.langtonsAton(k);
    return 0;
}