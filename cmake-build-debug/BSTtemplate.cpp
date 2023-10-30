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
    void remove(node<T>* del){
        if(del->left==nullptr&&del->right==nullptr){ //leaf, can just delete it
            delete del;
            del=nullptr;
        }
        if(del->left==nullptr||del->right==nullptr){ //1 child, swap with child and delete
            delete del;
            del=nullptr;
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
    void printinorder(){inorder(this->root);cout<<endl;}
    void printpreorder(){preorder(this->root);cout<<endl;}
    void printpostorder(){postorder(this->root);cout<<endl;}
    void printlevelorder(){levelorder(this->root);cout<<endl;}
};

int main(){
    vector<int> nums={4,2,6,1,3,5,7};
//    adding these numbers ^ to the tree in that order
//    looks like:
//       4
//     /   \
//     2   6
//    / \ / \
//    1 3 5 7
    BST<int>* tree=new BST<int>();
    for(int x:nums){
        tree->add(new node<int>(x));
    }
    cout<<"DFS - depth first search"<<endl;
    cout<<"In Order: ";tree->printinorder();
    cout<<"Pre-Order: ";tree->printpreorder();
    cout<<"Post-Order: ";tree->printpostorder();
    cout<<endl<<"BFS - breadth first search"<<endl;
    cout<<"Level Order: ";tree->printlevelorder();
    return 0;
}