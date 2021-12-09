#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

// TC: O(26nm^2), the most inner loop has string comparison which takes m, we do it 26 times for each letter of a word (26m^2), worst case needs to loop over all n words
// SC: O(nm), need a queue and unordered_set
class Solution
{
public:
    int ladderLength(string begin_word, string end_word, vector<string> &word_list)
    {
        unordered_set<string> word_set(word_list.begin(), word_list.end());
        int result = 0;
        queue<string> sq;
        sq.push(begin_word);

        while (sq.size())
        {
            result++;
            size_t size = sq.size();
            for (size_t i = 0; i < size; ++i)
            {
                string curr = sq.front();
                sq.pop();
                for (size_t j = 0; j < curr.size(); ++j)
                {
                    char curr_j = curr[j];
                    for (size_t k = 0; k < 26; ++k)
                    {
                        char ch = 'a' + k;
                        if (ch == curr_j)
                            continue;
                        curr[j] = ch;
                        if (word_set.count(curr))
                        {
                            if (curr == end_word)
                                return result + 1;
                            word_set.erase(curr);
                            sq.push(curr);
                        }
                    }
                    curr[j] = curr_j;
                }
            }
        }
        return 0;
    }
};

int main()
{
    string begin_word = "hit";
    string end_word = "cog";
    vector<string> word_list{"hot", "dot", "dog", "lot", "log", "cog"};
    // vector<string> word_list{"hot", "dot", "dog", "lot", "log"};

    Solution s;
    int result = s.ladderLength(begin_word, end_word, word_list);
    cout << result << endl;
    return 0;
}
