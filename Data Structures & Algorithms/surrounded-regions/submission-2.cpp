class Solution {
    int rows, cols;
    void exploreBoardBfs(queue<pair<int,int>> &q, vector<vector<char>>& board)
    {
        int directions[4][2] = { {-1, 0}, {1, 0}, {0, 1}, {0, -1} }; // traverse horizonatally and vertically
        while(!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            board[x][y] = 'B';

            for(auto &dir : directions)
            {
                int newX = x + dir[0];
                int newY = y + dir[1];

                // new coordinates within matrix and have surrounding O
                if(newX >= 0 && newX < rows && newY >= 0 && newY < cols && board[newX][newY] == 'O' )
                {
                    q.push({newX, newY});
                }
            }
        }
    }

    
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) 
            return;

        rows = board.size();
        cols = board[0].size();
        
        queue<pair<int,int>> q;
        // push O on vertical border into queue
        for(int i = 0; i < rows; i++)
        {
            if(board[i][0] == 'O')
            {
                q.push({i, 0});
            }
            if(board[i][cols-1] == 'O')
            {
                q.push({i, cols-1});
            }
        }

        // push O on horizontal border into queue
        for(int j = 0; j < cols; j++)
        {
            if(board[0][j] == 'O')
            {
                q.push({0, j});
            }
            if(board[rows-1][j] == 'O')
            {
                q.push({rows-1, j});
            }
        }

        exploreBoardBfs(q, board);

        // Traverse board again, if O -> X , if B -> O
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'B')
                {
                    board[i][j] = 'O';
                }
            }
        }


        
    }
};
