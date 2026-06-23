class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> buckets;
        for (const auto& word : wordList) {
            for (size_t i = 0; i < word.length(); ++i) {
                string pattern = word;
                pattern[i] = '*';
                buckets[pattern].push_back(word);
            }
        }

        queue<pair<string, int>> q;
        unordered_set<string> visited;
        q.push({beginWord, 1});
        visited.insert(beginWord);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            string word = node.first;
            int dist = node.second;

            for (int i = 0; i < word.size(); i++) {
                string pattern = word;
                pattern[i] = '*';

                for (const string& next : buckets[pattern]) {
                    if (next == endWord) return dist + 1;
                    if (visited.count(next)) continue;

                    visited.insert(next);
                    q.push({next, dist + 1});
                }
            }
        }

        return 0;
    }
};
