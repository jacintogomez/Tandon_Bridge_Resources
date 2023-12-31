//
// Created by Jacinto Gomez on 10/30/23.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <class T>
class node{
public:
    node(T v){ //constructor
        this->val=v;
        this->left=this->right=nullptr;
    }
    T val;
    node<T> *left;
    node<T> *right;
};

template <class T> //regular binary search tree
class BST{
public:
    node<T> *root;
    int size;
    BST(){
        this->root=nullptr;
        this->size=0;
    }
    BST(node<T> *input){ //constructor
        this->root=input;
        this->size=1;
    }
    void add(node<T> *leaf){
        size++;
        if(this->size==1){
            root=leaf;
            return;
        }
        node<T>* rt=root;
        node<T>* parent=nullptr;
        while(rt!=nullptr){
            parent=rt;
            if(leaf->val<rt->val){rt=rt->left;}
            else{rt=rt->right;}
        }
        if(leaf->val<parent->val){parent->left=leaf;}
        else{parent->right=leaf;}
    }
    node<T> *findparent(node<T> *start,node<T> *find){
        if(start==find||start==nullptr){return nullptr;}
        if(start->left==find||start->right==find){return start;}
        if(start->val<find->val){return findparent(start->right,find);}
        else{return findparent(start->left,find);}
    }
    node<T> *findsuccessor(node<T> *st){
        st=st->right;
        while(st->left!=nullptr){
            st=st->left;
        }
        return st;
    }
    node<T> *findpredecessor(node<T> *st){
        st=st->left;
        while(st->right!=nullptr){
            st=st->right;
        }
        return st;
    }
    void remove(node<T>* del){
        node<T> *parent=findparent(this->root,del);
        bool rorl; //is the node to be deleted the right or left child of its parent?
        if(del==nullptr){return;}
        if(del!=root){(parent->right==del)?rorl=true:rorl=false;}
        if(del->left==nullptr&&del->right==nullptr){ //leaf, can just delete it
            if(del!=root){
                if(parent->val<del->val){parent->right=nullptr;}
                else{parent->left=nullptr;}
            }
            delete del;
            size--;
        }
        else if(del->left==nullptr||del->right==nullptr){ //1 child, replace with child
            if(del!=root){
                if(del->left==nullptr){
                    (rorl)?parent->right=del->right:parent->left=del->right;
                }else{
                    (rorl)?parent->right=del->left:parent->left=del->right;
                }
            }
            delete del;
            size--;
        }
        else{ //2 children, replace with in order successor (could also do predecessor)
            node<T> *suc=findsuccessor(del);
            int temp=suc->val;
            remove(suc);
            del->val=temp;
        }
    }
    void inorder(node<T>* rt){ //in-order traversal (most common)
        if(rt==nullptr){return;}
        inorder(rt->left);
        cout<<rt->val<<" ";
        inorder(rt->right);
    }
    void preorder(node<T>* rt){ //pre-order traversal
        if(rt==nullptr){return;}
        cout<<rt->val<<" ";
        preorder(rt->left);
        preorder(rt->right);
    }
    void postorder(node<T>* rt){ //post-order traversal
        if(rt==nullptr){return;}
        postorder(rt->left);
        postorder(rt->right);
        cout<<rt->val<<" ";
    }
    void levelorder(node<T>* rt){ //level-order traversal
        queue<node<T>*> q;
        q.push(rt);
        while(!q.empty()){
            node<T>* temp=q.front();
            q.pop();
            if(temp->left!=nullptr){q.push(temp->left);}
            if(temp->right!=nullptr){q.push(temp->right);}
            cout<<temp->val<<" ";
        }
    }
    //traversal driver functions
    void inorder(){inorder(this->root);cout<<endl;}
    void preorder(){preorder(this->root);cout<<endl;}
    void postorder(){postorder(this->root);cout<<endl;}
    void levelorder(){levelorder(this->root);cout<<endl;}
};

int main(){
    node<int>* four=new node<int>(4);
    node<int>* two=new node<int>(2);
    node<int>* six=new node<int>(6);
    node<int>* one=new node<int>(1);
    node<int>* three=new node<int>(3);
    node<int>* five=new node<int>(5);
    node<int>* seven=new node<int>(7);
    vector<node<int>*> nums={four,two,six,one,three,five,seven};
//    adding these numbers ^ to the tree in order 4,2,6,1,3,5,7
//    looks like:
//       4
//     /   \
//     2   6
//    / \ / \
//    1 3 5 7  = 1,2,3,4,5,6,7
    BST<int>* tree=new BST<int>();
    for(node<int>* x:nums){tree->add(x);} //adding nodes has to be done in a certain order since this is not a self balancing tree
    cout<<"DFS - depth first search"<<endl;
    cout<<"In Order: ";tree->inorder();
    cout<<"Pre-Order: ";tree->preorder();
    cout<<"Post-Order: ";tree->postorder();
    cout<<endl<<"BFS - breadth first search"<<endl;
    cout<<"Level Order: ";tree->levelorder();
    //cout<<endl<<"Delete root node #4: ";tree->remove(four);tree->inorder();
    cout<<endl<<"Delete leaf node #7: ";tree->remove(seven);tree->inorder();
//    now it looks like:
//       4
//     /   \
//     2   6
//    / \ /
//    1 3 5    = 1,2,3,4,5,6
    cout<<"Delete 1-child node #6: ";tree->remove(six);tree->inorder();
//    now it looks like:
//       4
//     /   \
//     2   5
//    / \
//    1 3      = 1,2,3,4,5
    cout<<"Delete 2-child node #2: ";tree->remove(two);tree->inorder();
//    now it looks like:
//       4
//     /   \
//     3   5
//    /
//    1        = 1,3,4,5
    return 0;
}