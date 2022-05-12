bool print_space; // Wheter you should print a space before the key.
template<typename T>
struct node {
    T key;
    node<T> *l = NULL;
    node<T> *r = NULL;
    int height = 1; // Height of its subtree.
    node() {}
    node(T _key) {key = _key;}
    ~node() {delete l; delete r;}
    void preorder() {
        if(print_space) cout << " ";
        cout << key;
        print_space = true;
        if(l) l->preorder();
        if(r) r->preorder();
    }
    void inorder() { // The elements will be sorted.
        if(l) l->inorder();
        if(print_space) cout << " ";
        cout << key;
        print_space = true;
        if(r) r->inorder();
    }
    void postorder() {
        if(l) l->postorder();
        if(r) r->postorder();
        if(print_space) cout << " ";
        cout << key;
        print_space = true;
    }
};
template<typename T>
class AVL {
    int get_height(node<T> *pn) {
        return pn ? pn->height : 0;
    }
    void update_height(node<T> *pn) {
        pn->height = max(get_height(pn->l), get_height(pn->r)) + 1;
    }
    int get_balance(node<T> *pn) {
        return pn ? get_height(pn->r) - get_height(pn->l) : 0;
    }
    // Return the new root.
    node<T> *right_rotate(node<T> *pn) {
        node<T> *ret = pn->l;
        pn->l = ret->r;
        ret->r = pn;
        update_height(pn);
        update_height(ret);
        return ret;
    }
    node<T> *left_rotate(node<T> *pn) {
        node<T> *ret = pn->r;
        pn->r = ret->l;
        ret->l = pn;
        update_height(pn);
        update_height(ret);
        return ret;
    }
    node<T> *balance(node<T> *pn) {
        if(!pn) return pn;
        update_height(pn);
        int balance = get_balance(pn);
        int balance_l = get_balance(pn->l);
        int balance_r = get_balance(pn->r);
        if(balance < -1 && balance_l <= 0){
            return right_rotate(pn);
        }
        if(balance < -1 && balance_l > 0) {
            pn->l = left_rotate(pn->l);
            return right_rotate(pn);
        }
        if(balance > 1 && balance_r >= 0) {
            return left_rotate(pn);
        }
        if(balance > 1 && balance_r < 0) {
            pn->r = right_rotate(pn->r);
            return left_rotate(pn);
        }
        return pn; // Wasn't unbalanced.
    }
    // We don't insert repeated keys.
    node<T> *insert_key(node<T> *pn, T key) {
        if(!pn) return new node<T> (key);
        if(key < pn->key) pn->l = insert_key(pn->l, key);
        else pn->r = insert_key(pn->r, key);
        return balance(pn);
    }
    node<T> *delete_key(node<T> *pn, T key) {
        if(!pn) return pn;
        if(key < pn->key) pn->l = delete_key(pn->l, key);
        else if(key > pn->key) pn->r = delete_key(pn->r, key);
        else { // Is the node to delete.
            node<T> *temp;
            if(!pn->l) {
                temp = pn;
                pn = pn->r;
                temp->l = NULL; temp->r = NULL;
                delete temp; // Free memory.
            }
            else if(!pn->r) {
                temp = pn;
                pn = pn->l;
                temp->l = NULL; temp->r = NULL;
                delete temp; // Free memory.
            }
            else {
                temp = pn->l;
                while(temp->r) temp = temp->r;
                pn->key = temp->key;
                pn->l = delete_key(pn->l, temp->key);
            }
        }
        return balance(pn);
    }
    public:
    node<T> *root = NULL;
    ~AVL() {delete root;}
    void insert_key(T key) {
        root = insert_key(root, key);
    }
    void delete_key(T key) {
        root = delete_key(root, key);
    }
    void preorder() {
        print_space = false;
        if(root) root->preorder();
        cout << "\n";
    }
    void inorder() {
        print_space = false;
        if(root) root->inorder();
        cout << "\n";
    }
    void postorder() {
        print_space = false;
        if(root) root->postorder();
        cout << "\n";
    }
};

