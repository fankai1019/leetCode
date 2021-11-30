#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

struct TrieNode
{
    TrieNode() : children(26, nullptr), is_word(false) {}
    ~TrieNode()
    {
        for (const TrieNode *child : children)
        {
            if (child)
                delete child;
        }
    }

    vector<TrieNode *> children;
    bool is_word;
};

// TC:
//  insert: O(m), m is the word length
//  search & startsWith O(m)
// SC"
//  insert: O(m), l is the word length
//  search & startsWith O(1)
class Trie
{
public:
    Trie() : root_(new TrieNode()) {}

    void insert(const string &str)
    {
        TrieNode *p = root_.get();
        for (const char c : str)
        {
            int pos = c - 'a';
            if (!p->children[pos])
                p->children[pos] = new TrieNode();
            p = p->children[pos];
        }
        p->is_word = true;
    }

    bool search(const string &word) const
    {
        const TrieNode *p = find(word);
        return p && p->is_word;
    }

    bool startsWith(const string &prefix) const
    {
        return find(prefix);
    }

private:
    const TrieNode *find(const string &str) const
    {
        TrieNode *p = root_.get();
        for (const char c : str)
        {
            int pos = c - 'a';
            p = p->children[pos];
            if (!p)
                break;
        }
        return p;
    }

    unique_ptr<TrieNode> root_;
};

int main()
{
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple") << endl;
    cout << trie.search("app") << endl;
    cout << trie.startsWith("app") << endl;
    trie.insert("app");
    cout << trie.search("app") << endl;
    return 0;
}