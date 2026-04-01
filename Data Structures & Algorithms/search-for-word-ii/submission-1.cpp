class Node
{
    public:
        char c;
        bool isWord;
        Node* children[26];
        string word;

        Node(char c)
        {
            this->c = c;
            isWord = false;
            for(int i = 0; i < 26; i++)
            {
                children[i] = NULL;
            }
        }
};
class Solution {
    Node *root = new Node('\0');
    void addWord(string word)
    {
        Node *curr = root;
        for(int i = 0; i < word.size(); i++)
        {
            char c = word[i];
            if(curr->children[c-'a'] == NULL)
            {
                curr->children[c-'a'] = new Node(c-'a');
            }
            curr = curr->children[c-'a'];
        }
        curr->isWord = true;
        curr->word = word;
    }



    void dfs(int i, int j, vector<vector<char>>& board, 
    Node *node, vector<string>&ans)
    {
        if(i >= board.size() || i < 0 || j >= board[i].size() || j < 0 || board[i][j] == '#')
            return;
        
        char c = board[i][j];
        if(node->children[c-'a'] == NULL)
            return;
        
        node = node->children[c-'a'];
        if(node->isWord)
        {
            ans.push_back(node->word);
            node->isWord = false;
        }


        board[i][j] = '#';
        
        dfs(i+1, j, board, node, ans);
        dfs(i, j+1, board, node, ans);
        dfs(i-1, j, board, node, ans);
        dfs(i, j-1, board, node, ans);

        board[i][j] = c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto &word : words)
        {
            addWord(word);
        }
        vector<string>ans;
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                dfs(i, j, board, root, ans);
            }
        }
        return ans;
    }
};
