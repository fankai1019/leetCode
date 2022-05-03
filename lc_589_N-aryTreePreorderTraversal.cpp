#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

#include "utils.h"
using namespace std;

// Iterative
// TC: O(n) each node is pushed and poped once
// SC: O(n) worst stack frame size is n
class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> result;
        if (!root)
            return result;
        stack<Node *> ns;
        ns.push(root);
        while (ns.size())
        {
            Node *node = ns.top();
            ns.pop();
            result.push_back(node->val);
            for (int i = node->children.size() - 1; i >= 0; --i)
            {
                Node *child = node->children[i];
                if (child)
                    ns.push(child);
            }
        }
        return result;
    }
};