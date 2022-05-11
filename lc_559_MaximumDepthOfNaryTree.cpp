#include "utils.h"
using namespace std;

// BFS
// TC: O(n) need to iterate once
// SC: O(n) a queue is needed
class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;
        int depth = 0;
        queue<Node *> nq;
        nq.push(root);
        while (nq.size())
        {
            int size = nq.size();
            for (int i = 0; i < size; ++i)
            {
                Node *node = nq.front();
                nq.pop();
                for (int j = 0; j < node->children.size(); ++j)
                {
                    Node *child = node->children[j];
                    if (child)
                        nq.push(child);
                }
            }
            depth++;
        }
        return depth;
    }
};