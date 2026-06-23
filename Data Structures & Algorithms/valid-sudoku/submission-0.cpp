class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> hash;

        for(auto r : board) {
            for(char c : r) {
                if (c == '.') continue;
                if(hash.count(c)) return false;
                hash.insert(c);
            }
            hash.clear();
        }

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                char c = board[j][i];
                if (c == '.') continue;
                if(hash.count(c)) return false;
                hash.insert(c);
            }
            hash.clear();
        }

        for(int row = 0; row < 3; row++) {
            for(int col = 0; col < 3; col++) {
                
                for(int i = 0; i < 3; i++) {
                    for(int j = 0; j < 3; j++) {
                        char c = board[3 * row + i][3 * col + j];
                        if (c == '.') continue;
                        if(hash.count(c)) return false;
                        hash.insert(c);
                    }
                }
                hash.clear();
            }
        }

        return true;
    }
};
