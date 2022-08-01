//
//双向链表+哈希
//
class LRUCache {
public:
    struct Node{
        int key,value;
        Node *left,*right;
        Node(int a,int b):key(a),value(b),left(nullptr),right(nullptr){}
    };
    int n;
    unordered_map<int,Node*> hash;
    Node *LL,*RR;

    void remove(Node *p){       // 删除p节点需要知道它的前驱节点，所以得用双向链表
        p->left->right=p->right;
        p->right->left=p->left;
    }

    void insert(Node *p){
        p->right=LL->right;
        p->left=LL;
        LL->right->left=p;
        LL->right=p;
    }

    LRUCache(int capacity) {
        n=capacity;
        LL=new Node(-1,-1);
        RR=new Node(-1,-1);
        LL->right=RR;
        RR->left=LL;
    }
    
    int get(int key) {
        if(hash.count(key)){
            remove(hash[key]);
            insert(hash[key]);
            return hash[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(hash.count(key)){
            hash[key]->value=value;
            remove(hash[key]);
            insert(hash[key]);
        }
        else{
            if(hash.size()==n){
                auto p=RR->left;    // 需要用临时变量p，因为remove之后RR->left的结果已经发生变化
                remove(p);
                hash.erase(p->key);
                delete p;
            }
            auto p=new Node(key,value);
            insert(p);
            hash[key]=p;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
