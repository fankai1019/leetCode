#include <algorithm>
#include <iostream>
#include <memory>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

class Trie
{
public:
    struct Node
    {
        Node() : children(26, nullptr), is_word(false) {}
        vector<Node *> children;
        int is_word;
        string word;
    };

    Trie() : root_(new Node()) {}

    void insert(const string &str)
    {
        Node *p = root_.get();
        for (const char c : str)
        {
            int pos = c - 'a';

            // stop at the shortest root
            Node *&child = p->children[pos];
            if (child && child->is_word)
                return;
            if (!child)
                child = new Node();
            p = child;
        }
        p->is_word = true;
        p->word = str;
    }

    void replace(string &str) const
    {
        const Node *p = root_.get();
        for (const char c : str)
        {
            p = p->children[c - 'a'];
            if (p && p->is_word)
            {
                str = p->word;
                break;
            }
            else if (!p)
                break;
        }
    }

private:
    unique_ptr<Node> root_;
};

// TC: O(mn) m is number words, n is average word length
// SC: linear
class Solution
{
public:
    string replaceWords(vector<string> &dictionary, const string &sentence)
    {
        Trie trie;
        for (const string &str : dictionary)
            trie.insert(str);
        stringstream ss(sentence);
        string str;
        string result;
        while (getline(ss, str, ' '))
        {
            trie.replace(str);
            result += str;
            result.push_back(' ');
        }
        if (result.size())
            result.pop_back();
        return result;
    }
};

int main()
{
    vector<string> dictionary = {"cat", "bat", "rat"};
    const string sentence = "the cattle was rattled by the battery";
    Solution s;
    string result = s.replaceWords(dictionary, sentence);
    cout << result << endl;
    return 0;
}