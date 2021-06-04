#ifndef node_hpp
#define node_hpp
#include <iostream>
#include <stdio.h>
template<typename TV, typename TK>
struct node
{
    TK key;
    TV val;
    node<TV,TK>* r_child;
    node<TV,TK>* l_child;
    node<TV,TK>* parent;
    unsigned char heigt;
};

template<typename TV, typename TK>
class Tree{
    private:
    node<TV,TK>* root;

    public:
    unsigned char height_tree(){
        return root->heigt;
    }

    Tree(){
        root = nullptr;
    }

    node<TV,TK>* find(TK key){
        return findnoderec(key, root);
    }

    ~Tree(){
        delete_Tree(root);
    }

    void printTree(){
        printTreerev(root, 1);
    }
    TV Get(TK key){
        node<TV,TK>* a = find(key);
        return a->val;
    }

    void insert(TK key,TV vall){ //Добавление элемента
        if(root == nullptr){
        node<TV,TK>* new_node = new node<TV,TK>;
        new_node->parent = nullptr;
        new_node->r_child = nullptr;
        new_node->l_child = nullptr;
        new_node->key = key;
        new_node->val = vall;
        new_node->heigt = 1;
        root = new_node;
        } else{
            insertat(key,vall,root);
        }
    }

    void delete_node(TK key){
        node<TV,TK>* now = find(key);
        delete_node_rec(now);
    }

    void map( void (*funk)(TV* element)){
        node<TV,TK>* curr = root;
        node<TV,TK>* prev = nullptr;
        do{
            if((!curr->l_child) && (!curr->r_child) && (!curr->parent)){// если только 1 элемент
                funk(&(curr->val));
                return;
            } else if ((curr->l_child) && (curr->r_child != prev) && (curr->l_child != prev)){ //down left
                prev = curr;
                curr = curr->l_child;
            } else if ((curr->r_child) && (curr->r_child != prev) && ((curr->l_child == prev) || (!(curr->l_child)))){// right down
                prev = curr;
                curr = curr->r_child;
            } else if ((!curr->l_child) && (!curr->r_child)){  //last 
                funk(&(curr->val));
                prev = curr;
                curr = curr->parent;
            } else if ((curr->r_child == prev) || ((!curr->r_child) && (prev == curr->l_child))){
                funk(&(curr->val));
                prev = curr;
                curr = curr->parent;
            }
        } while(!((curr->parent == nullptr) && (curr->r_child == prev)));
    }

    Tree<TV,TK> * where(bool(*f)(TV elem)){
        node<TV,TK> * curr = root;
        node<TV,TK> * lastNode = nullptr;
        Tree<TV,TK> * newtree = new Tree();
        while(curr != nullptr){
            if(lastNode == curr->parent){
                if(curr->l_child){
                    lastNode = curr;
                    curr = curr->l_child;
                } else if (curr->r_child){
                    lastNode = curr;
                    curr = curr->r_child;
                } else {
                    if(f(curr->val)){
                        newtree->insert(curr->key, curr->val);
                    }
                    lastNode = curr;
                    curr = curr->parent;
                }
            } else if(lastNode == curr->l_child){
                if(curr->r_child){
                    lastNode = curr;
                    curr = curr->r_child;
                } else {
                    if(f(curr->val)){
                        newtree->insert(curr->key,curr->val);
                    }
                    lastNode = curr;
                    curr = curr->parent;
                }
            } else if(lastNode == curr->r_child){
                if(f(curr->val)){
                    newtree->insert(curr->key,curr->val);
                }
                lastNode = curr;
                curr = curr->parent;
            }
        }
        return newtree;
    }

    void merger( Tree<TV,TK> tree){
        node<TV,TK>* curr = root;
        node<TV,TK>* prev = nullptr;
        do{
            if((!curr->l_child) && (!curr->r_child) && (!curr->parent)){// если только 1 элемент
                tree.insert(curr);
                return;
            }
            else if((curr->l_child) && (curr->r_child != prev) && (curr->l_child != prev)){ //down left
                prev = curr;
                curr = curr->l_child;
            }
            else if((curr->r_child) && (curr->r_child != prev) && ((curr->l_child == prev) || (!(curr->l_child)))){// right down
                prev = curr;
                curr = curr->r_child;
            }
            else if ((!curr->l_child) && (!curr->r_child)){  //last 
                tree.insert(curr);
                prev = curr;
                curr = curr->parent;
            }
            else if((curr->r_child == prev) || ((!curr->r_child) && (prev == curr->l_child))){
                tree.insert(curr);
                prev = curr;
                curr = curr->parent;
            }
        }while(!((curr->parent == nullptr) && (curr->r_child == prev)));
    }

    Tree<TV,TK> * subTree(int key){
        Tree<TV,TK> newtree = new Tree();
        node<TV,TK> * ptr = find(key);
        if(!ptr){
            throw "subTree not founded";
        }
        node<TV,TK> * curr = ptr;
        node<TV,TK> * lastNode = ptr->parent;
        while(curr != ptr->parent){
            if(lastNode == curr->parent){
                if(curr->left){
                    lastNode = curr;
                    curr = curr->l_child;
                } else if (curr->r_child){
                    lastNode = curr;
                    curr = curr->r_child;
                } else {
                    newtree->insert(curr->key, curr->val);
                    lastNode = curr;
                    curr = curr->parent;
                }
            } else if(lastNode == curr->l_child){
                if(curr->right){
                    lastNode = curr;
                    curr = curr->r_child;
                } else {
                    newtree->insert(curr->key,curr->val);
                    lastNode = curr;
                    curr = curr->parent;
                }
            } else if(lastNode == curr->right){
                newtree->insert(curr->key,curr->val);
                lastNode = curr;
                curr = curr->parent;
            }
        }
        return newtree;
    }

     node<TV,TK> * foundNodels(std::string path){
        node<TV,TK> * curr = root;
        for(int i = 0; i < path.length();i++){
            if(path[i] == 'r'){
                if(curr){
                    curr = curr->r_child;
                }else{
                    return nullptr;
                }
            } else if(path[i] == 'l'){
                if(curr){
                    curr = curr->l_child;
                } else {
                    return nullptr;
                }
            }
        }
        return curr;
    }

    node<TV,TK> * foundNodelsd(std::string path, int key){
        node<TV,TK> * curr = find(key);
        if(!curr){
            return nullptr;
        }
        for(int i = 0; i < path.length();i++){
            if(path[i] == 'r'){
                if(curr){
                    curr = curr->r_child;
                }else{
                    return nullptr;
                }
            } else if(path[i] == 'l'){
                if(curr){
                    curr = curr->l_child;
                } else {
                    return nullptr;
                }
            } else if(path[i] == 'p'){
                if(curr){
                    curr = curr->parent;
                } else {
                    return nullptr;
                }
            }
        }
        return curr;
    }



    protected:
    void delete_node_rec(node<TV,TK>* now) {
        if(now == nullptr) {
            throw "Key doesn't found";
        }
        if(now->r_child == nullptr && now->l_child == nullptr) {
            if(now->parent->r_child == now) {
                now->parent->r_child = nullptr;
            }
            else if(now->parent->l_child == now) {
                now->parent->l_child = nullptr;
            }
            node<TV,TK>* parent = now->parent;
            delete now;
            fix_height(parent);
            while (parent->parent != nullptr) {
                parent = balance(parent);
                fix_height(parent);
                parent = parent->parent;
            }
            root = balance(root);
            fix_height(root);
            return;
        }else{
            if(((now->r_child) && (now->l_child) && (height(now->r_child) < height(now->l_child))) || (!now->r_child)&&(now->l_child)){
                node<TV,TK>* curr = now->l_child;
                while (curr->r_child != nullptr){
                    curr = curr->r_child;
                }
                now->key = curr->key;
                now->val = curr->val;
                delete_node_rec(curr);
            }
            else if(((now->l_child) && (now->r_child) && (height(now->l_child) < height(now->r_child))) || (!now->l_child)&&(now->r_child)){
                node<TV,TK>* curr = now->r_child;
                while (curr->l_child != nullptr){
                    curr=curr->l_child;
                }
                now->key = curr->key;
                now->val = curr->val;
                delete_node_rec(curr);
            }
            else if((now->r_child)&&(now->l_child)&&(height(now->r_child) == height(now->l_child))){
                node<TV,TK>* currR = now->r_child;
                while (currR->l_child != nullptr){
                    currR = currR->l_child;
                }
                node<TV,TK>* currL = now->l_child;
                while (currL->r_child != nullptr){
                    currL = currL->r_child;
                }
                if((now->key - currL->key) < (currR->key - now->key)){
                    now->key = currL->key;
                    now->val = currL->val;
                    delete_node_rec(currL);
                }
                else{
                    now->key = currR->key;
                    now->val = currR->val;
                    delete_node_rec(currR);
                }
            }
        }
    }

    void printTreerev(node<TV,TK> *top, int level) {
        if (top) {
            printTreerev(top->l_child, level + 1);
            for (int i = 0; i < level; i++)
                std::cout << "_____";
            std::cout << top->key << "(" << ((top->parent)?(top->parent->key):-1) << ")" << std::endl;
            printTreerev(top->r_child, level + 1);
        } else {
            for (int i = 0; i < level; i++){
                std::cout << "_____";
            }          
            std::cout << "nil" << std::endl;
        }
    }

    void delete_Tree(node<TV,TK>* qwe){
        if(qwe == nullptr){
            return;
        }
        if((qwe->l_child) && (root->r_child)){
            if(qwe->parent){
                if(qwe->parent->r_child == qwe){
                    qwe->parent->r_child = nullptr;
                }
                else if (qwe->parent->l_child == qwe){
                    qwe->parent->l_child == nullptr;
                }
            }
            delete qwe;
        }
        else if(qwe->r_child){
            delete_Tree(qwe->l_child);
            delete_Tree(qwe);

        }
        else if(qwe->l_child){
            delete_Tree(qwe->r_child);
            delete_Tree(qwe);
        }
        else{
            delete_Tree(qwe->l_child);
            delete_Tree(qwe->r_child);
            delete_Tree(qwe);
        }
    }
    
    node<TV,TK>* balance(node<TV,TK>* now_node){
        if(now_node == nullptr){
            return nullptr;
        }
        else if(bfactor(now_node) == 2){
            if(bfactor(now_node->r_child) >= 0){
                now_node = small_left_dance(now_node);
            }
            else if(bfactor(now_node->r_child) < 0){
                now_node = big_left_dance(now_node);
            }
        }
        else if(bfactor(now_node) == -2){
            if(bfactor(now_node->l_child) <= 0){
                now_node = small_right_dance(now_node);
            }
            else if(bfactor(now_node->l_child) > 0){
                now_node = big_right_dance(now_node);
            }
        }
        return now_node;
    }

    char bfactor(node<TV,TK>* now_node){
        return height(now_node->r_child)-height(now_node->l_child);
    }
    
    node<TV,TK>* big_right_dance(node<TV,TK>* a){
        node<TV,TK>* b = a->l_child;
        node<TV,TK>* c = b->r_child;
        c->parent=a->parent;
        if(c->parent){
            if (c->parent->r_child == a){
                c->parent->r_child = c;
            }
            else if(c->parent->l_child == a){
                c->parent->l_child = c; 
            } 
        }
        b->r_child = c->l_child;
        if (c->l_child){
            c->l_child->parent=b;
        }
        c->l_child = b;
        b->parent = c;
        a->l_child = c->r_child;
        if(c->r_child){
            c->r_child->parent = a;
        }
        c->r_child = a;
        a->parent = c;
        fix_height(a);
        fix_height(b);
        fix_height(c);
        return c;
    }

    node<TV,TK>* big_left_dance(node<TV,TK>* a){
        node<TV,TK>* b = a->r_child;
        node<TV,TK>* c = b->l_child;
        c->parent = a->parent;
       if(c->parent){
            if (c->parent->r_child == a){
                c->parent->r_child = c;
            }
            else if(c->parent->l_child == a){
                c->parent->l_child = c; 
            } 
        }
        b->l_child = c->r_child;
        if (c->r_child){
            c->r_child->parent = b;
        }
        c->r_child = b;
        b->parent = c;
        a->r_child = c->l_child;
        if(c->l_child){
            c->l_child->parent = a;
        }
        c->l_child = a;
        a->parent = c;
        fix_height(a);
        fix_height(b);
        fix_height(c);
        return c;
    }

    node<TV,TK>* small_right_dance(node<TV,TK>* a){
        node<TV,TK>* b = a->l_child;
        b->parent = a->parent;
        if(b->parent){
            if (b->parent->r_child == a){
                b->parent->r_child = b;
            }
            else if(b->parent->l_child == a){
                b->parent->l_child = b; 
            } 
        }
        a->l_child = b->r_child;
        if(b->r_child){ 
            b->r_child->parent = a;
        }
        b->r_child = a;
        a->parent = b;
        fix_height(a);
        fix_height(b);
        return b;
    }

    node<TV,TK>* small_left_dance(node<TV,TK>* a){
        node<TV,TK>* b = a->r_child;
        b->parent = a->parent;
        if(b->parent){
            if (b->parent->r_child == a){
                b->parent->r_child = b;
            }
            else if(b->parent->l_child == a){
                b->parent->l_child = b; 
            } 
        } 
        a->r_child=b->l_child;
        if (b->l_child){
            b->l_child->parent = a;
        }
        b->l_child = a;
        a->parent = b;
        fix_height(a);
        fix_height(b);
        return b;
    }

    unsigned char height(node<TV,TK>* now_node){
        if(now_node != nullptr){
            return now_node->heigt;
        } 
        else return 0;
    }

    void fix_height(node<TV,TK>* now_node){
        now_node->heigt = 1 + std::max(height(now_node->l_child), height(now_node->r_child));
    }

    void insertat(TK key,TV vall,node<TV,TK>* now_node){
        if(now_node->r_child == nullptr && key > now_node->key){
            node<TV,TK>* new_node = new node<TV,TK>;
            new_node->r_child = nullptr;
            new_node->l_child = nullptr;
            now_node->r_child = new_node;
            new_node->key = key;
            new_node->val = vall;
            new_node->parent = now_node;
            new_node->heigt = 1;
        } else if (now_node->l_child == nullptr && key < now_node->key){
            node<TV,TK>* new_node = new node<TV,TK>;
            new_node->r_child = nullptr;
            new_node->l_child = nullptr;
            now_node->l_child = new_node;
            new_node->key = key;
            new_node->val = vall;
            new_node->parent = now_node;
            new_node->heigt = 1;
        } else if (key < now_node->key){
            insertat(key, vall,now_node->l_child);
            return;
        } else if (key > now_node->key){
            insertat(key, vall,now_node->r_child);
            return;
        } else if (key == now_node->key){
            now_node->val = vall;
            return;
        }
        node<TV,TK>* curr = now_node;
        while ((curr != nullptr)  && (std::abs(bfactor(curr)) != 2)) {
            fix_height(curr);
            curr = curr->parent;
        }
        if (curr) {
            if(curr->parent){
                if (curr->parent->l_child == curr) {
                    curr->parent->l_child = balance(curr);
                } else if(curr->parent->r_child == curr){
                    curr->parent->r_child = balance(curr);
                }   
            } else{
            root = balance(root);
            }
        }
    }

    node<TV,TK>* findnoderec(TK key,node<TV,TK>* now){
        if (key == now->key){
            return now;
        } else if (key > now->key) {
            if(now->r_child == nullptr){
                return nullptr;
            }
            return findnoderec(key, now->r_child);
        } else if (key < now->key) {
            if(now->l_child == nullptr){
                return nullptr;
            }
            return findnoderec(key, now->l_child);
        }
    }

};
#endif