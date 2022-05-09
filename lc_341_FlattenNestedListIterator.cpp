#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>

#include "utils.h"
using namespace std;

// DFS
// TC: O(n) need to iterate once
// SC: O(n) need a queue to store all elements

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator
{
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        helper(nestedList);
    }

    int next()
    {
        if (hasNext())
        {
            int val = iq.front();
            iq.pop();
            return val;
        }
        return 0;
    }

    bool hasNext()
    {
        return iq.size();
    }

private:
    void helper(vector<NestedInteger> &nestedList)
    {
        for (int i = 0; i < nestedList.size(); ++i)
        {
            NestedInteger &ni = nestedList[i];
            if (ni.isInteger())
                iq.push(ni.getInteger());
            else
                helper(ni.getList());
        }
    }
    queue<int> iq;
};