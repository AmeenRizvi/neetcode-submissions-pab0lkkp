class Node{
    public:
        char c;
        bool isWord;
        Node* children[26];

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
class WordDictionary {
    Node *root;
    
    bool searchHelper(int index, string word, Node *curr)
    {
        if(index == word.size())
            return curr &&  curr->isWord;
        
        char c = word[index];
        if(c == '.')
        {
            for(int i = 0; i < 26; i++)
            {
                if(curr->children[i] != NULL)
                {
                    if(searchHelper(index+1, word, curr->children[i]))
                        return true;
                }
            }
            return false;
        }
        else
        {
            if(curr->children[c-'a'] == NULL)
                return false;
            return searchHelper(index+1, word, curr->children[c-'a']);
        }
    }
public:
    WordDictionary() {
        root = new Node('\0');
    }
    
    void addWord(string word) {
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
        
    }
    
    bool search(string word) {
        return searchHelper(0, word, root);
        
    }
};
