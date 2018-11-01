#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Solution {
   public:
    std::vector<std::vector<int>> largeGroupPositions(std::string S) {
        std::vector<std::vector<int>> result;
        int i = 0, j = 0;
        int N = S.size();
        while (j < N) {
            while (j < N && S[i] == S[j]) ++j;
            if (j - i > 2) result.push_back({i, j - 1});
            i = j;
        }
        return result;
    }
};

class Solution2 {
   public:
    std::vector<std::vector<int>> largeGroupPositions(std::string S) {
        std::vector<std::vector<int>> result;
        if (S.empty()) return result;
        std::unordered_map<char, int> first;
        std::unordered_map<char, int> counter;
        char curr = S[0];
        char prev = S[0];
        for (int i = 0; i < S.size(); ++i) {
            curr = S[i];
            if (counter[S[i]]++ == 0) first[S[i]] = i;
            if (curr != prev) {
                if (counter[prev] > 2) {
                    result.push_back(
                        {first[prev], first[prev] + counter[prev] - 1});
                }
                counter[prev] = 0;
                first[prev] = 0;
                prev = curr;
            }
            if (i == S.size() - 1)
                if (counter[curr] > 2) {
                    result.push_back(
                        {first[curr], first[curr] + counter[curr] - 1});
                }
        }

        return result;
    }
};

int main() {
    std::string S = "abbxxxxzzy";
    Solution a;
    auto result = a.largeGroupPositions(S);
    for (const auto& row : result) {
        for (auto i : row) std::cout << i << ' ';
        std::cout << std::endl;
    }

    return 0;
}
