#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;

class UF
{
public:
    UF()
    {
        for (size_t i = 0; i < 26; ++i)
        {
            parents_.push_back(i);
            ranks_.push_back(0);
        }
    }

    int find(int x)
    {
        if (x != parents_[x])
            parents_[x] = find(parents_[x]);
        return parents_[x];
    }

    bool merge(int x, int y)
    {
        int parent1 = parents_[x];
        int parent2 = parents_[y];
        if (parent1 == parent2)
            return false;
        int rank1 = ranks_[parent1];
        int rank2 = ranks_[parent2];
        if (rank1 < rank2)
            parents_[parent1] = parent2;
        else if (rank1 > rank2)
            parents_[parent2] = parent1;
        else
        {
            parents_[parent1] = parent2;
            ranks_[parent2]++;
        }
        return true;
    }

private:
    vector<int> parents_;
    vector<int> ranks_;
};

// TC: O(n), we need to traverse all equations
// SC: O(n), we need to store those equations
class Solution
{
public:
    bool satisfiabilityOfEqualityEquations(const vector<string> &equations)
    {
        vector<string> not_equals;
        for (const auto &equation : equations)
        {
            if (equation[1] == '!')
                not_equals.push_back(equation);
        }
        if (!not_equals.size())
            return true;

        UF uf;
        for (const auto &equation : equations)
        {
            if (equation[1] == '=')
            {
                int lhs = equation[0] - 'a';
                int rhs = equation[3] - 'a';
                uf.merge(lhs, rhs);
            }
        }

        for (size_t i = 0; i < not_equals.size(); ++i)
        {
            int lhs = not_equals[i][0] - 'a';
            int rhs = not_equals[i][3] - 'a';
            if (uf.find(lhs) == uf.find(rhs))
                return false;
        }
        return true;
    }
};

int main()
{
    vector<string> equations = {"a==b", "b!=c", "c==a"};
    // vector<string> equations = {"c==c", "b==d", "x!=z"};
    // vector<string> equations = {"a==b", "b==c", "d==e", "e==f", "d==a", "f!=a"};
    Solution s;
    bool result = s.satisfiabilityOfEqualityEquations(equations);
    cout << result << endl;
    return 0;
}