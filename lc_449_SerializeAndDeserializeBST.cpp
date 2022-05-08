#include "utils.h"

using namespace std;

// DFS
// TC: O(n^2) At each level, we need to build a vevtor for left and right:
//     n + (n-1) + (n-2) + ... + 1.
// SC: O(h) stack frame size is height
class Codec1
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream in(data);
        vector<int> inorder;
        string str;
        while (in >> str)
            inorder.push_back(stoi(str));
        return deserialize(inorder);
    }

private:
    void serialize(TreeNode *root, ostringstream &out)
    {
        if (!root)
            return;
        out << root->val << ' ';
        serialize(root->left, out);
        serialize(root->right, out);
    }

    TreeNode *deserialize(vector<int> &inorder)
    {
        if (!inorder.size())
            return nullptr;
        int rootVal = inorder[0];
        TreeNode *root = new TreeNode(rootVal);
        vector<int> left;
        vector<int> right;
        for (int i = 1; i < inorder.size(); ++i)
        {
            if (inorder[i] < rootVal)
                left.push_back(inorder[i]);
            else
                right.push_back(inorder[i]);
        }
        root->left = deserialize(left);
        root->right = deserialize(right);
        return root;
    }
};

// DFS build the tree give inorder and preorder
// TC: O(nlogn) need to sort preorder to get in order
// SC: O(h) stack frame size is height
class Codec2
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream in(data);
        vector<int> preorder;
        string str;
        while (in >> str)
            preorder.push_back(stoi(str));
        vector<int> inorder(preorder);
        sort(inorder.begin(), inorder.end());
        for (int i = 0; i < inorder.size(); ++i)
            mp[inorder[i]] = i;
        return deserialize(inorder, preorder);
    }

private:
    void serialize(TreeNode *root, ostringstream &out)
    {
        if (!root)
            return;
        out << root->val << ' ';
        serialize(root->left, out);
        serialize(root->right, out);
    }

    TreeNode *deserialize(vector<int> &inorder, vector<int> &preorder)
    {
        if (!inorder.size())
            return nullptr;
        return helper(0, inorder.size() - 1, 0, preorder.size() - 1, inorder, preorder);
    }

    TreeNode *helper(int inStart, int inEnd, int preStart, int preEnd, vector<int> &inorder, vector<int> &preorder)
    {
        if (preStart > preEnd)
            return nullptr;
        if (preStart == preEnd)
            return new TreeNode(preorder[preStart]);

        int rootVal = preorder[preStart];
        TreeNode *root = new TreeNode(rootVal);
        int numLeft = mp[rootVal] - inStart;
        root->left = helper(inStart, inStart + numLeft - 1, preStart + 1, preStart + numLeft, inorder, preorder);
        root->right = helper(inStart + numLeft + 1, inEnd, preStart + numLeft + 1, preEnd, inorder, preorder);
        return root;
    }
    unordered_map<int, int> mp;
};

// DFS build the tree give inorder and preorder
// TC: O(n) making use of the property of bst
// SC: O(h) stack frame size is height
class Codec3
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream in(data);
        queue<int> iq;
        string str;
        while (in >> str)
            iq.push(stoi(str));
        return deserialize(iq, INT_MIN, INT_MAX);
    }

private:
    void serialize(TreeNode *root, ostringstream &out)
    {
        if (!root)
            return;
        out << root->val << ' ';
        serialize(root->left, out);
        serialize(root->right, out);
    }

    TreeNode *deserialize(queue<int> &iq, int mn, int mx)
    {
        if (!iq.size())
            return nullptr;
        int val = iq.front();
        if (val < mn || val > mx)
            return nullptr;

        TreeNode *root = new TreeNode(val);
        iq.pop();
        root->left = deserialize(iq, mn, val);
        root->right = deserialize(iq, val, mx);
        return root;
    }
};

int main()
{
    vector<int> ivec = {2, 1, 3};
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    // Codec1 codec;
    // Codec2 codec;
    Codec3 codec;
    string str = codec.serialize(root);
    cout << str << endl
         << endl;
    TreeNode *result = codec.deserialize(str);
    print(result);
    clear(result);
    return 0;
}
