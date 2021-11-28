#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;

// TC: O(n) we need to loop over all emails and do UF on emails which takes roughly O(1)
// SC: O(n) we need to store all names and accounts
class Solution
{
public:
    vector<vector<string>> accountsMerge(const vector<vector<string>> &accounts)
    {
        for (size_t i = 0; i < accounts.size(); ++i)
        {
            const vector<string> &account = accounts[i];
            const string &name = account[0];
            for (size_t j = 1; j < account.size(); ++j)
            {
                const string &email = account[j];
                owners_[email] = name;
                parents_[email] = email;
            }
        }

        for (const auto &e : parents_)
            ranks_[e.first] = 0;

        for (size_t i = 0; i < accounts.size(); ++i)
        {
            const vector<string> &account = accounts[i];
            for (size_t j = 2; j < account.size(); ++j)
                merge(account[j - 1], account[j]);
        }

        unordered_map<string, set<string>> tmp;
        for (const auto &e : parents_)
            tmp[find(e.first)].insert(e.first);

        vector<vector<string>> results;
        for (const auto &e : tmp)
        {
            const string &name = owners_[e.first];
            vector<string> this_results;
            this_results.push_back(name);
            for (const auto &ee : e.second)
                this_results.push_back(ee);
            results.push_back(this_results);
        }
        return results;
    }

    const string &find(const string &x)
    {
        if (x != parents_[x])
            parents_[x] = find(parents_[x]);
        return parents_[x];
    }

    bool merge(const string &x, const string &y)
    {
        const string &parent1 = find(x);
        const string &parent2 = find(y);
        if (parent1 == parent2)
            return false;
        if (ranks_[parent1] > ranks_[parent2])
            parents_[parent1] = parent2;
        else if (ranks_[parent2] > ranks_[parent1])
            parents_[parent2] = parent1;
        else
        {
            parents_[parent1] = parent2;
            ranks_[parent2]++;
        }
        return true;
    }

private:
    unordered_map<string, string> parents_;
    unordered_map<string, int> ranks_;
    unordered_map<string, string> owners_;
};

void print(const vector<vector<string>> &str_vec_vec)
{
    for (const auto &e : str_vec_vec)
    {
        for (const auto &ee : e)
            cout << ee << " ";
        cout << endl;
    }
}

int main()
{
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}};
    Solution s;
    vector<vector<string>> results = s.accountsMerge(accounts);
    print(results);
    return 0;
}