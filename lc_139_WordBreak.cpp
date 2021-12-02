#include <algorithm>
#include <iostream>
#include <memory>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

// TC: need to do research on trie + dp + memo complexity analysis
// SC: linear
class Solution
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

        int is_word;
        vector<Node *> children;
    };

    Solution() : root_(new Node) {}

    void insert(const string &word)
    {
        Node *p = root_.get();
        for (const char c : word)
        {
            size_t i = c - 'a';
            if (!p->children[i])
                p->children[i] = new Node();
            p = p->children[i];
        }
        p->is_word = true;
    }

    bool wordBreak(const string &sentence, const vector<string> &str_vec)
    {
        for (const string &str : str_vec)
            insert(str);
        vector<string> words;
        // memo is mainly use for memorizing failures
        vector<int> memo(sentence.size(), -1);
        bool result = helper(sentence, 0, memo);
        string new_sentence;
        for (size_t i = words.size() - 1; i < words.size(); --i)
            new_sentence += words[i] + ' ';
        new_sentence.pop_back();
        return result;
    }

private:
    bool helper(const string &sentence, size_t j, vector<int> &memo)
    {
        if (j == sentence.size())
            return true;
        if (memo[j] != -1)
            return memo[j];
        const Node *p = root_.get();
        for (size_t i = j; i < sentence.size(); ++i)
        {
            char c = sentence[i];
            p = p->children[c - 'a'];
            if (!p)
                return memo[j] = false;
            if (p->is_word && helper(sentence, i + 1, memo))
                return memo[j] = true;
        }
        return memo[j] = false;
    }
    unique_ptr<Node> root_;
};

int main()
{
    vector<string> str_vec = {"cats", "dog", "sand", "and", "cat"};
    string str = "catsandog";
    // vector<string> str_vec = {"leet", "code"};
    // string str = "leetcode";
    Solution s;
    cout << s.wordBreak(str, str_vec) << endl;
    return 0;
}
