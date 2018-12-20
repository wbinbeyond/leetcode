class Trie {
public:
    /** Initialize your data structure here. */
    Trie(): root(new TrieNode()) {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root.get();
        for (const auto& c : word) {
            if (!cur->children.count(c)) {
                cur->children[c] = make_unique<TrieNode>();
            }
            cur = cur->children[c].get();
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        const TrieNode* n = find(word);
        return n && n->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
    
private:
    struct TrieNode {
        bool isWord;
        unordered_map<char, unique_ptr<TrieNode>> children;
        TrieNode() : isWord(false) {}
    };
    
    unique_ptr<TrieNode> root;
    
    const TrieNode* find(string prefix) {
        const TrieNode* cur = root.get();
        for (const auto& c : prefix) {
            if (!cur->children.count(c)) {
                return nullptr;
            }
            cur = cur->children.at(c).get();
        }
        return cur;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
