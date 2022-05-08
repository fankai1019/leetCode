#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

#include "utils.h"

using namespace std;

// DFS
// TC: O(1) next and hasNext is constant
// SC: O(n) all nodes are stored in a queue
class BSTIterator1
{
public:
    BSTIterator1(TreeNode *root)
    {
        // The number of nodes in the tree is in the range [1, 10^5]
        stack<TreeNode *> nstack;
        TreeNode *curr = root;
        while (curr || nstack.size())
        {
            while (curr)
            {
                nstack.push(curr);
                curr = curr->left;
            }

            TreeNode *node = nstack.top();
            nstack.pop();
            nqueue.push(node);
            curr = node->right;
        }
    }

    int next()
    {
        TreeNode *node = nqueue.front();
        nqueue.pop();
        return node->val;
    }

    bool hasNext()
    {
        return nqueue.size() != 0;
    }
    queue<TreeNode *> nqueue;
};

// DFS
// TC: O(1) hasNext is O(1), next is O(1) on average.
//     next can be called n times if there are n nodes in the tree.
//     The number of right nodes in findLeft is at maximal n in a tree which has n nodes
//     So amortized time complexity is O(1)
// SC: O(h) stack only contains left edges
class BSTIterator2
{
public:
    BSTIterator2(TreeNode *root)
    {
        // The number of nodes in the tree is in the range [1, 10^5]
        findLeft(root);
    }

    int next()
    {
        TreeNode *node = nstack.top();
        nstack.pop();
        if (node->right)
            findLeft(node->right);
        return node->val;
    }

    bool hasNext()
    {
        return !nstack.empty();
    }

private:
    void findLeft(TreeNode *root)
    {
        while (root)
        {
            nstack.push(root);
            root = root->left;
        }
    }
    stack<TreeNode *> nstack;
};

int main()
{
    vector<int> ivec{7, 3, 15, null, null, 9, 20};
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    cout << endl;
    // BSTIterator1 BSTIter(bfs.root());
    BSTIterator2 BSTIter(bfs.root());
    cout << BSTIter.next() << endl;
    cout << BSTIter.next() << endl;
    cout << BSTIter.hasNext() << endl;
    cout << BSTIter.next() << endl;
    cout << BSTIter.hasNext() << endl;
    cout << BSTIter.next() << endl;
    cout << BSTIter.hasNext() << endl;
    cout << BSTIter.next() << endl;
    cout << BSTIter.hasNext() << endl;
    return 0;
}
