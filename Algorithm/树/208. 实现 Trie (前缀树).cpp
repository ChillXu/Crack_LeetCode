//
//字典树
//
class Trie {
private:
    bool isEnd;
    vector<Trie*> next=vector<Trie*>(26);
//     vector<Trie*> next;
public:
    Trie() {
        isEnd=false;
    }
    
//     Trie(): isEnd(false),next(26) {           // 初始化列表
//     }
      
    
    void insert(string word) {
        Trie *node=this;
        for(char c:word){
            c-='a';
            if(node->next[c]==nullptr){
                node->next[c]=new Trie();
            }
            node=node->next[c];         // ×else
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
        Trie *node=this;
        for(char c:word){
            c-='a';
            node=node->next[c];
            if(node==nullptr) return false;
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie *node=this;
        for(char c:prefix){
            c-='a';
            node=node->next[c];
            if(node==nullptr) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
