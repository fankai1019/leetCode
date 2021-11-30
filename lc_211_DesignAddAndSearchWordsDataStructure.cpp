#include <algorithm>
#include <iostream>
#include <memory>
#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

// TC:
//  addWord: O(m), m is the length of the word
//  search: O(26m), worst case is 26 times length of the word
// SC: linear
class WordDictionary
{
public:
    struct Node
    {
        Node() : is_word(false), children(26, nullptr) {}
        ~Node()
        {
            for (const Node *child : children)
                if (child)
                    delete child;
        }
        bool is_word;
        vector<Node *> children;
    };

    WordDictionary() : root_(new Node) {}

    void addWord(const string &word)
    {
        Node *p = root_.get();
        for (size_t i = 0; i < word.size(); ++i)
        {
            char c = word[i];
            int pos = c - 'a';
            if (!p->children[pos])
                p->children[pos] = new Node();
            p = p->children[pos];
        }
        p->is_word = true;
    }

    bool search(const string &word)
    {
        return search(word, 0, root_.get());
    }

private:
    bool search(const string &word, int pos, const Node *p)
    {
        for (size_t i = pos; i < word.size() && p; ++i)
        {
            const char c = word[i];
            if (c != '.')
            {
                p = p->children[c - 'a'];
            }
            else
            {
                const Node *tmp = p;
                for (size_t j = 0; j < 26; ++j)
                {
                    p = tmp->children[j];
                    if (search(word, i + 1, p))
                        return true;
                }
            }
        }
        return p && p->is_word;
    }
    unique_ptr<Node> root_;
};

int main()
{
    WordDictionary w_dict;
    w_dict.addWord("bad");
    w_dict.addWord("dad");
    w_dict.addWord("mad");
    cout << w_dict.search("pad") << endl;
    cout << w_dict.search("bad") << endl;
    cout << w_dict.search(".ad") << endl;
    cout << w_dict.search("b..") << endl;
    // w_dict.addWord("a");
    // w_dict.addWord("a");
    // cout << w_dict.search(".") << endl;
    // cout << w_dict.search("a") << endl;
    // cout << w_dict.search("aa") << endl;
    // cout << w_dict.search("a") << endl;
    // cout << w_dict.search(".a") << endl;
    // cout << w_dict.search("a.") << endl;
    return 0;
}