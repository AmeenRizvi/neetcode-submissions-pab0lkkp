class Node{
    public:
        char c;
        bool isWord;
        Node *children[26];

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
class PrefixTree {
    Node *root;
    Node *getNode(string word)
    {
        Node* curr = root;
        for(int i = 0 ; i < word.size(); i++)
        {
            char c = word[i];
            if(curr->children[c-'a'] == NULL)
                return NULL;
            curr = curr->children[c-'a'];
        }
        return curr;
    }
public:
    PrefixTree() {
        root = new Node('\0');
    }
    
    void insert(string word) {
        Node *curr = root;
        for(int i = 0; i < word.size(); i++)
        {
            char c = word[i];
            if(curr->children[c-'a'] == NULL)
            {
                curr->children[c-'a'] = new Node(c);
            }
            curr = curr->children[c-'a'];
        }
        curr->isWord = true;
        
    }
    
    bool search(string word) {
        Node *node = getNode(word);
        return node != NULL && node->isWord;
        
    }
    
    bool startsWith(string prefix) {
        return getNode(prefix) != NULL;
        
    }
};
