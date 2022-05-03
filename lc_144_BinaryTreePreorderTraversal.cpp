#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

#include "utils.h"
using namespace std;

// Recursive
// TC: O(n) each node is pushed and poped once
// SC: O(n) worst case stack frame size is n
class Solution1
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        preorder(root, result);
        return result;
    };

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        inorder(root, result);
        return result;
    };

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        postorder(root, result);
        return result;
    };

private:
    void preorder(TreeNode *root, vector<int> &result)
    {
        if (!root)
            return;
        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
    }

    void inorder(TreeNode *root, vector<int> &result)
    {
        if (!root)
            return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }

    void postorder(TreeNode *root, vector<int> &result)
    {
        if (!root)
            return;
        postorder(root->left, result);
        postorder(root->right, result);
        result.push_back(root->val);
    }
};

// Iterative intuitive
// TC: O(n) each node is pushed and poped once
// SC: O(n) a stack is needed
class Solution2
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        stack<TreeNode *> nstack;
        nstack.push(root);
        while (nstack.size())
        {
            TreeNode *curr = nstack.top();
            nstack.pop();
            result.push_back(curr->val);
            if (curr->right)
                nstack.push(curr->right);
            if (curr->left)
                nstack.push(curr->left);
        }
        return result;
    };

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        TreeNode *curr = root;
        stack<TreeNode *> nstack;
        while (curr || nstack.size())
        {
            while (curr)
            {
                nstack.push(curr);
                curr = curr->left;
            }

            TreeNode *node = nstack.top();
            nstack.pop();
            result.push_back(node->val);
            curr = node->right;
        }

        return result;
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        TreeNode *curr = root;
        TreeNode *prev = nullptr;
        stack<TreeNode *> nstack;

        // prev means last poped node
        while (curr || nstack.size())
        {
            while (curr)
            {
                nstack.push(curr);
                curr = curr->left;
            }
            TreeNode *node = nstack.top();
            if (node->right && prev != node->right)
                curr = node->right;
            else
            {
                result.push_back(node->val);
                prev = node;
                nstack.pop();
            }
        }

        // prev means last time go right
        // while (curr || nstack.size())
        // {
        //     while (curr)
        //     {
        //         nstack.push(curr);
        //         curr = curr->left;
        //     }

        //     TreeNode *node = nstack.top();
        //     if(!node->right || node->right == prev)
        //     {
        //         result.push_back(node->val);
        //         nstack.pop();
        //     }
        //     else
        //     {
        //         curr = node->right;
        //         prev = curr;
        //     }
        // }

        return result;
    }
};

// Iterative templatable
// TC: O(n) each node is pushed and poped once
// SC: O(n) a stack is needed
class Solution3
{
public:
    enum Color
    {
        White,
        Grey
    };
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        stack<pair<TreeNode *, Color>> nstack;
        nstack.push(make_pair(root, White));

        while (nstack.size())
        {
            pair<TreeNode *, Color> node = nstack.top();
            nstack.pop();
            if (node.second == White)
            {
                node.second = Grey;
                if (node.first->right)
                    nstack.push(make_pair(node.first->right, White));
                if (node.first->left)
                    nstack.push(make_pair(node.first->left, White));
                nstack.push(node);
            }
            else
            {
                result.push_back(node.first->val);
            }
        }

        return result;
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        stack<pair<TreeNode *, Color>> nstack;
        nstack.push(make_pair(root, White));

        while (nstack.size())
        {
            pair<TreeNode *, Color> node = nstack.top();
            nstack.pop();
            if (node.second == White)
            {
                node.second = Grey;
                if (node.first->right)
                    nstack.push(make_pair(node.first->right, White));
                nstack.push(node);
                if (node.first->left)
                    nstack.push(make_pair(node.first->left, White));
            }
            else
            {
                result.push_back(node.first->val);
            }
        }

        return result;
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (!root)
            return result;
        stack<pair<TreeNode *, Color>> nstack;
        nstack.push(make_pair(root, White));

        while (nstack.size())
        {
            pair<TreeNode *, Color> node = nstack.top();
            nstack.pop();
            if (node.second == White)
            {
                node.second = Grey;
                nstack.push(node);
                if (node.first->right)
                    nstack.push(make_pair(node.first->right, White));
                if (node.first->left)
                    nstack.push(make_pair(node.first->left, White));
            }
            else
            {
                result.push_back(node.first->val);
            }
        }

        return result;
    }
};

int main()
{
    vector<int> ivec = {1, -1, 2, 3};
    BFS<TreeNode> bfs(ivec);
    bfs.print(bfs.root());
    Solution1 s1;
    Solution2 s2;
    Solution3 s3;
    cout << "pre order: " << endl;
    vector<int> result = s1.preorderTraversal(bfs.root());
    printVec(result);
    result = s2.preorderTraversal(bfs.root());
    printVec(result);
    result = s3.preorderTraversal(bfs.root());
    printVec(result);
    cout << "in order: " << endl;
    result = s1.inorderTraversal(bfs.root());
    printVec(result);
    result = s2.inorderTraversal(bfs.root());
    printVec(result);
    result = s3.inorderTraversal(bfs.root());
    printVec(result);
    cout << "post order: " << endl;
    result = s1.postorderTraversal(bfs.root());
    printVec(result);
    result = s2.postorderTraversal(bfs.root());
    printVec(result);
    result = s3.postorderTraversal(bfs.root());
    printVec(result);
    return 0;
}
