class Solution {
    bool backtrack(int i, int j, vector<vector<char>>& board, string word, int idx)
    {
        if(idx == word.size())
            return true;
        
        if(i >= board.size() || j >= board[i].size() || i < 0 || j < 0 || 
        board[i][j] == '#' || board[i][j] != word[idx])
            return false;

        board[i][j] = '#';

        
        bool ans = backtrack(i+1, j, board, word, idx+1 ) || 
                backtrack(i, j+1, board, word, idx+1 )    || 
                backtrack(i-1, j, board, word, idx+1 )    || 
                backtrack(i, j-1, board, word, idx+1 );
            
        
        board[i][j] = word[idx];
        return ans;

        

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                bool ans = backtrack(i, j, board, word, 0);
                if(ans)
                    return true;
            }
        }
        return false;
        
        
    }
};
