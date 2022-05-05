#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

#include "utils.h"
using namespace std;

// Recursive
// TC: O(n) each node is accessed 3 times
// SC: O(n) worst case stack frame size is n
class Solution1
{
public:
    vector<int> postorder(Node *root)
    {
        vector<int> result;
        if (!root)
            return result;
        post(root, result);
        return result;
    }

private:
    void post(Node *root, vector<int> &result)
    {
        if (!root)
            return;
        for (int i = 0; i < root->children.size(); ++i)
            post(root->children[i], result);
        result.push_back(root->val);
    }
};

// Iterative
// TC: O(n) each node is pushed and poped twice
// SC: O(n) a stack is needed
class Solution2
{
public:
    enum Color
    {
        White,
        Grey
    };
    vector<int> postorder(Node *root)
    {
        vector<int> result;
        if (!root)
            return result;

        stack<pair<Node *, Color>> nstack;
        nstack.push(make_pair(root, White));
        while (nstack.size())
        {
            pair<Node *, Color> node = nstack.top();
            nstack.pop();
            if (node.second == White)
            {
                node.second = Grey;
                nstack.push(node);
                for (int i = node.first->children.size() - 1; i >= 0; --i)
                {
                    Node *child = node.first->children[i];
                    if (child)
                        nstack.push(make_pair(child, White));
                }
            }
            else
                result.push_back(node.first->val);
        }
        return result;
    }

private:
    void post(Node *root, vector<int> &result)
    {
        if (!root)
            return;
        for (int i = 0; i < root->children.size(); ++i)
            post(root->children[i], result);
        result.push_back(root->val);
    }
};