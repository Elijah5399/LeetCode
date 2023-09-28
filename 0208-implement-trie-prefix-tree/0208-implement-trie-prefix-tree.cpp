class Trie {
public:
    char val;
    Trie *children[27];
    Trie() {
        for (int i = 0; i < 27; i++) {
            children[i] = nullptr;
        }
    }
    
    void insert(string word) {
        if (word == "") {
            if (children[26] != nullptr) return;
            Trie *newTrie = new Trie();
            newTrie->val = '#';
            children[26] = newTrie;
            return;
        }
        char f = word[0];
        if (children[f - 'a'] == nullptr) {
            Trie *newTrie = new Trie;
            newTrie->val = f;
            children[f - 'a'] = newTrie;
            newTrie->insert(word.substr(1, word.length() - 1));
        } else {
            Trie *next = children[f - 'a'];
            next->insert(word.substr(1, word.length() - 1));
        }
    }
    
    bool search(string word) {
        if (word.length() == 0) {
            if (children[26] == nullptr) {
                return false;
            } else {
                return true;
            }
        }
        char c = word[0];
        if (children[c - 'a'] == nullptr) {
            return false;
        } else {
            return children[c - 'a']->search(word.substr(1, word.length() - 1));
        }
    }
    
    bool startsWith(string prefix) {
        if (prefix.length() == 0) {
            return true;
        }
        char c = prefix[0];
        if (children[c - 'a'] == nullptr) {
            return false;
        } else {
            return children[c - 'a']->startsWith(prefix.substr(1, prefix.length() - 1));
        }
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */