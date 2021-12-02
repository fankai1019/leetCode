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
        ~Node()
        {
            for (const Node *child : children)
                if (child)
                    delete child;
        }
        vector<Node *> children;
        bool is_word;
    };

    Trie() : root_(new Node()) {}

    void insert(const string &word)
    {
        Node *p = root_.get();
        for (const char c : word)
        {
            int pos = c - 'a';
            Node *&child = p->children[pos];
            if (!child)
                child = new Node();
            p = child;
        }
        p->is_word = true;
    }

    bool find(const string &word, size_t pos, vector<int> &memo, int count) const
    {
        if (pos == word.size())
            return count >= 2;

        if (memo[pos] != -1)
            return memo[pos];

        const Node *p = root_.get();
        for (size_t i = pos; i < word.size(); ++i)
        {
            p = p->children[word[i] - 'a'];
            if (!p)
            {
                memo[pos] = 0;
                return false;
            }

            if (p->is_word && find(word, i + 1, memo, count + 1))
            {
                memo[pos] = 1;
                return true;
            }
        }
        memo[pos] = 0;
        return false;
    }

private:
    unique_ptr<Node> root_;
};

// TC: ?
// SC: ?
class Solution
{
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        Trie trie;
        for (const string &word : words)
            trie.insert(word);
        vector<string> result;
        for (const string &word : words)
        {
            vector<int> memo(word.size(), -1);
            if (trie.find(word, 0, memo, 0))
                result.push_back(word);
        }
        return result;
    }
};

int main()
{
    vector<string> str_vec = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratecatdogcat"};
    // vector<string> str_vec = {"cat", "dog", "catdog"};
    // vector<string> str_vec = {"a", "aa", "aaaaaaj"};
    Solution s;
    vector<string> result = s.findAllConcatenatedWordsInADict(str_vec);
    for (const string &str : result)
        cout << str << " ";
    cout << endl;
    return 0;
}