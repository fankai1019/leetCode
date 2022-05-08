#include "utils.h"

using namespace std;

// DFS
// TC: O(n) traverse once
// SC: O(h) stack frame size is height
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        stringstream ss;
        serialize(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream in(data);
        TreeNode *root = nullptr;
        deserialize(root, in);
        return root;
    }

private:
    void deserialize(TreeNode *&root, istringstream &in)
    {
        string str;
        in >> str;
        if (str == "n")
            return;

        root = new TreeNode(stoi(str));
        deserialize(root->left, in);
        deserialize(root->right, in);
    }

    void serialize(TreeNode *root, stringstream &ss)
    {
        if (!root)
        {
            ss << "n ";
            return;
        }

        ss << root->val << ' ';
        serialize(root->left, ss);
        serialize(root->right, ss);
    }
};

int main()
{
    vector<int> ivec = {1, 2, 3, null, null, 4, 5};
    BFS<TreeNode> bfs(ivec);
    TreeNode *root = bfs.root();
    print(root);
    Codec codec;
    string str = codec.serialize(root);
    cout << str << endl
         << endl;
    TreeNode *result = codec.deserialize(str);
    print(result);
    clear(result);
    return 0;
}
