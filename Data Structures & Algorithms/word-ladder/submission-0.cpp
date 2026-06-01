class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> patternMap;
        int L = beginWord.size();

        // Preprocessing
        for (auto& word : wordList) {
            for (int i = 0; i < L; i++) {
                string pattern = word;
                pattern[i] = '*';
                patternMap[pattern].push_back(word);
            }
        }

        queue<pair<string, int>> q;
        unordered_set<string> visited;

        q.push({beginWord, 1});
        visited.insert(beginWord);

        while (!q.empty()) {
            auto [word, level] = q.front();
            q.pop();

            if (word == endWord) return level;

            for (int i = 0; i < L; i++) {
                string pattern = word;
                pattern[i] = '*';

                for (auto& nei : patternMap[pattern]) {
                    if (!visited.count(nei)) {
                        visited.insert(nei);
                        q.push({nei, level + 1});
                    }
                }
            }
        }

        return 0;
    }
};
