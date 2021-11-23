#include <iostream>
#include <vector>
using namespace std;

// Assume matrix is not empty matrix
// TC: O(n^2), this is the best we can do for an n by n matrix(traverse all elements)
// SC: O(m + n), we need one vector with size m and one vector with size n to track row and column index of the zero elements
class Solution1
{
public:
    void zeroMatrix(vector<vector<int>> &matrix)
    {
        size_t m = matrix.size();
        if (m == 0)
            return;
        size_t n = matrix[0].size();
        vector<size_t> rows(m, 0);
        vector<size_t> cols(n, 0);
        for (size_t i = 0; i < m; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }

        for (size_t i = 0; i < rows.size(); ++i)
            if (rows[i])
                nullifyRow(matrix, i, m, n);

        for (size_t j = 0; j < cols.size(); ++j)
            if (cols[j])
                nullifyColumn(matrix, j, m, n);
    }

private:
    void nullifyRow(vector<vector<int>> &matrix, size_t r, size_t m, size_t n)
    {
        for (size_t i = 0; i < n; ++i)
            matrix[r][i] = 0;
    }

    void nullifyColumn(vector<vector<int>> &matrix, size_t c, size_t m, size_t n)
    {
        for (size_t i = 0; i < m; ++i)
            matrix[i][c] = 0;
    }
};

// assume m <= 32 and n <= 32
// reduce the SP to O(1), using bit vector
class Solution2
{
public:
    void zeroMatrix(vector<vector<int>> &matrix)
    {
        size_t m = matrix.size();
        if (m == 0)
            return;
        size_t n = matrix[0].size();
        int32_t row_bit_vec = 0;
        int32_t col_bit_vec = 0;
        for (size_t i = 0; i < m; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    int32_t r = 1 << i;
                    int32_t c = 1 << j;
                    row_bit_vec |= r;
                    col_bit_vec |= c;
                }
            }
        }

        for (size_t i = 0; i < m; ++i)
        {
            int32_t bit_vec = 1 << i;
            if (bit_vec & row_bit_vec)
                nullifyRow(matrix, i, m, n);
        }

        for (size_t j = 0; j < n; ++j)
        {
            int32_t bit_vec = 1 << j;
            if (bit_vec & col_bit_vec)
                nullifyColumn(matrix, j, m, n);
        }
    }

private:
    void nullifyRow(vector<vector<int>> &matrix, size_t r, size_t m, size_t n)
    {
        for (size_t i = 0; i < n; ++i)
            matrix[r][i] = 0;
    }

    void nullifyColumn(vector<vector<int>> &matrix, size_t c, size_t m, size_t n)
    {
        for (size_t i = 0; i < m; ++i)
            matrix[i][c] = 0;
    }
};

// reduce SP to O(1) by using the original matrix for data storage
// we use the row and column of first found zero for data storage
// we can also use the first row and column, which is the solution on cc189
class Solution3
{
public:
    void zeroMatrix(vector<vector<int>> &matrix)
    {
        size_t m = matrix.size();
        if (m == 0)
            return;
        size_t n = matrix[0].size();

        bool found_first_zero = false;
        size_t first_row = 0;
        size_t first_col = 0;
        for (size_t i = 0; i < m; ++i)
        {
            for (size_t j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    if (!found_first_zero)
                    {
                        first_row = i;
                        first_col = j;
                        found_first_zero = true;
                    }
                    else
                    {
                        matrix[i][first_col] = 0;
                        matrix[first_row][j] = 0;
                    }
                }
            }
        }

        if (!found_first_zero)
            return;

        for (size_t i = 0; i < m; ++i)
            if (matrix[i][first_col] == 0 && i != first_row)
                nullifyRow(matrix, i, m, n);

        for (size_t j = 0; j < n; ++j)
            if (matrix[first_row][j] == 0 && j != first_col)
                nullifyColumn(matrix, j, m, n);

        nullifyRow(matrix, first_row, m, n);
        nullifyColumn(matrix, first_col, m, n);
    }

private:
    void nullifyRow(vector<vector<int>> &matrix, size_t r, size_t m, size_t n)
    {
        for (size_t i = 0; i < n; ++i)
            matrix[r][i] = 0;
    }

    void nullifyColumn(vector<vector<int>> &matrix, size_t c, size_t m, size_t n)
    {
        for (size_t i = 0; i < m; ++i)
            matrix[i][c] = 0;
    }
};

void printMatrix(const vector<vector<int>> &matrix)
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

int main()
{
    vector<vector<int>> matrix{
        {1, 2, 3, 2, 5},
        {4, 0, 0, 3, 7},
        {7, 8, 9, 5, 9},
        {1, 3, 3, 0, 9},
        {6, 1, 4, 8, 0}};
    printMatrix(matrix);
    // Solution1 s;
    // Solution2 s;
    Solution3 s;
    s.zeroMatrix(matrix);
    printMatrix(matrix);
    return 0;
}