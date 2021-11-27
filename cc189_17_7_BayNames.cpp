#include <cmath>
#include <exception>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

// TC: O(bp), b = num of bay names, p = num of synonyms
//     worst case: num of real names = p (no overlap)
//     This solution basically loops over all synonyms. In each inner loop, it then loops over all real names, the worst case scenario is O(p^2)
//     Then it loops over all names and in each inner loop, it loops over all real names. The TC is O(bp);
// This is a brute force algorithm
// SC: O(b), we need real name vector of sets which includes all baby names but in different sets O(b)
class Solution1
{
public:
    vector<pair<string, int>> babyNames(const vector<pair<string, int>> &names, const vector<pair<string, string>> &synonyms)
    {
        vector<set<string>> real_names;
        for (size_t i = 0; i < synonyms.size(); ++i)
        {
            const pair<string, string> &synonym_pair = synonyms[i];
            const string &first = synonym_pair.first;
            const string &second = synonym_pair.second;

            bool found = false;
            for (size_t j = 0; j < real_names.size(); ++j)
            {
                set<string> &name_set = real_names[j];
                if (name_set.count(first) || name_set.count(second))
                {
                    name_set.insert(first);
                    name_set.insert(second);
                    found = true;
                }
            }

            if (!found)
            {
                set<string> sset;
                sset.insert(first);
                sset.insert(second);
                real_names.push_back(sset);
            }
        }

        vector<pair<string, int>> results;
        for (size_t i = 0; i < real_names.size(); ++i)
        {
            const set<string> &name_set = real_names[i];
            results.push_back(make_pair(*name_set.begin(), 0));
        }

        for (size_t i = 0; i < names.size(); ++i)
        {
            for (size_t j = 0; j < real_names.size(); ++j)
            {
                const set<string> &name_set = real_names[j];
                if (name_set.count(names[i].first))
                    results[j].second += names[i].second;
            }
        }
        return results;
    }
};

// Union find
// TC:
//  starting from an empty data structure, path compression with link by rank
//  performs any intermixed sequence of m >= n make set, union and find operations on a set of n elements takes O(m/alpha(m,n))

//  starting from an empty data structure, path compression with naive linking
//  performs any intermixed sequence of m >= n make set, union and find operations on a set of n elements takes O(mlogn)

//  union or find can O(logn) with rank reduction, n = num of elements
//  union or find can take O(n) with naive linking, n = num of elements
// SP: O(n), need a parent map and vector to track ranks
// Proof of time complexity (https://www.cs.princeton.edu/~wayne/kleinberg-tardos/pdf/UnionFind.pdf)
class Solution2
{
public:
    vector<pair<string, int>> babyNames(const vector<pair<string, int>> &names, const vector<pair<string, string>> &synonyms)
    {
        vector<pair<string, int>> results;
        for (size_t i = 0; i < names.size(); ++i)
        {
            const string &name = names[i].first;
            int freq = names[i].second;
            parents_[name] = name;
            freqs_[name] = freq;
            ranks_[name] = 0;
        }

        for (size_t i = 0; i < synonyms.size(); ++i)
        {
            const string &name1 = synonyms[i].first;
            const string &name2 = synonyms[i].second;
            merge(name1, name2);
        }
        set<string> parents;

        for (size_t i = 0; i < names.size(); ++i)
            parents.insert(find(names[i].first));

        for (const auto &e : parents)
            results.push_back(make_pair(e, freqs_[e]));

        return results;
    }

    string find(const string &name)
    {
        if (name != parents_[name])
            parents_[name] = find(parents_[name]); // path compression
        return parents_[name];
    }

    void merge(const string &name1, const string &name2)
    {
        string parent1 = find(name1);
        string parent2 = find(name2);
        if (parent1 != parent2)
        {
            if (ranks_[parent1] < ranks_[parent2]) // rank reduction
            {
                parents_[parent1] = parent2;
                freqs_[parent2] += freqs_[parent1];
            }
            else if (ranks_[parent2] < ranks_[parent1])
            {
                parents_[parent2] = parent1;
                freqs_[parent1] += freqs_[parent2];
            }
            else
            {
                parents_[parent1] = parent2;
                ranks_[parent2]++;
                freqs_[parent2] += freqs_[parent1];
            }
        }
    }

private:
    unordered_map<string, string> parents_;
    unordered_map<string, int> freqs_;
    unordered_map<string, int> ranks_;
};

// TODO: DFS
// Solution3
// {
// public:
// };

void print(const vector<pair<string, int>> &names)
{
    for (size_t i = 0; i < names.size(); ++i)
    {
        const pair<string, int> &name_pair = names[i];
        cout << name_pair.first << "(" << name_pair.second << ") ";
    }
    cout << endl;
}

int main()
{
    vector<pair<string, int>> names = {
        {"John", 15},
        {"Jon", 12},
        {"Chris", 13},
        {"Kris", 4},
        {"Christopher", 19}};
    print(names);

    vector<pair<string, string>> synonyms{
        {"Jon", "John"},
        {"John", "Johnny"},
        {"Chris", "Kris"},
        {"Chris", "Christopher"}};

    // Solution1 s;
    Solution2 s;
    vector<pair<string, int>> real_names = s.babyNames(names, synonyms);
    print(real_names);
    return 0;
}