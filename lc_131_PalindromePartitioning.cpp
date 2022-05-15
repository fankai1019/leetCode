#include "utils.h"

using namespace std;

// Backtrakcing
// TC: O(n2^n) worst case, all possible substrings are palindrome. There are 2^n possible substrings.
// SC: O(n) recursion stack size is at most n. Collection results size is not considered here.
class Solution1
{
public:
    vector<vector<string>> partition(string s)
    {
        if (!s.size())
            return results;

        int count = 0;
        vector<string> path;
        backtracking(s, count, path, 0);
        return results;
    }

private:
    void backtracking(const string &s, int &count, vector<string> &path, int begin)
    {
        if (count == s.size())
        {
            results.push_back(path);
            return;
        }

        for (int i = begin; i < s.size(); ++i)
        {
            for (int length = 1; length <= s.size() - i; ++length)
            {
                string sub_str = s.substr(i, length);
                if (isPalindrome(sub_str))
                {
                    path.push_back(sub_str);
                    count += length;
                    backtracking(s, count, path, i + length);
                    path.pop_back();
                    count -= length;
                }
            }
        }
    }

    bool isPalindrome(string s)
    {
        if (!s.size())
            return false;
        if (s.size() == 1)
            return true;
        int left = 0;
        int right = s.size() - 1;
        while (left <= right)
        {
            if (s[left] == s[right])
            {
                left++;
                right--;
            }
            else
                return false;
        }
        return true;
    }

    vector<vector<string>> results;
};

// The problem has a nice structure that backtracking naturally fits in.
// The structure is, given a starting position start, we search from start till the end of the string.
//  Once we reach a position i such that the sub-string from start to i (s.substr(start, i - start + 1)) is a palindrome, we add it to a temporary par.
// Then we recursively call the same function to process the remaining sub-string.
// Once we reach the end of the string, we add par into the result pars of all the possible partitioning.

// Then, backtracking happens.
// Remember that at position i, we find s.substr(start, i - start + 1) to be a palindrome and we immediately add it to par.
// It is obvious that there may be some other position j such that j > i and s.substr(start, j - start + 1) is also a palindrome.
// So we need to recover to the state before adding s.substr(start, i - start + 1) to par and continue to find the next palindrome position after i.
// And we simply need to pop s.substr(start, i - start + 1) out of par to make things work.

// Backtrakcing
// TC: O(n2^n) worst case, all possible substrings are palindrome. There are 2^n possible substrings.
// SC: O(n) recursion stack size is at most n. Collection results size is not considered here.
class Solution2
{
public:
    vector<vector<string>> partition(string s)
    {
        if (!s.size())
            return results;

        vector<string> path;
        backtracking(s, path, 0);

        return results;
    }

private:
    void backtracking(const string &s, vector<string> &path, int start)
    {
        if (start == s.size())
        {
            results.push_back(path);
            return;
        }

        for (int i = start; i < s.size(); ++i)
        {
            if (isPalindrome(s, start, i))
            {
                string sub_str = s.substr(start, i - start + 1);
                path.push_back(sub_str);
                backtracking(s, path, i + 1);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string &s, int start, int end)
    {
        while (start <= end)
            if (s[start++] != s[end--])
                return false;
        return true;
    }
    vector<vector<string>> results;
};

int main()
{
    string str = "aab";
    // Solution1 s;
    Solution2 s;
    vector<vector<string>> results = s.partition(str);
    printVecVec(results);
    return 0;
}
