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
        bool rorl;
        if(del==nullptr){return;}
//        if(parent==nullptr){ //deleting the root node
//            delete del;
//            del=nullptr;
//        }
        (parent->right==del)?rorl=true:rorl=false;
        if(del->left==nullptr&&del->right==nullptr){ //leaf, can just delete it
            if(parent->val<del->val){parent->right=nullptr;}
            else{parent->left=nullptr;}
            delete del;
        }
        else if(del->left==nullptr||del->right==nullptr){ //1 child, replace with child
            if(del->left==nullptr){
                (rorl)?parent->right=del->right:parent->left=del->right;
            }else{
                (rorl)?parent->right=del->left:parent->left=del->right;
            }
            delete del;
        }
        else{ //2 children, replace with in order successor (could also do predecessor)
            node<T> *suc=findsuccessor(del);
            del->val=suc->val;
            remove(suc);
        }
//        else { // 2 children, replace with in order successor (or predecessor)
//            node<T> *suc = findsuccessor(del);
//            del->val = suc->val;
//            // Update the parent of suc to point to its child
//            node<T> *suc_parent = findparent(this->root, suc);
//            if (suc_parent->left == suc) {
//                suc_parent->left = nullptr;
//            } else {
//                suc_parent->right = nullptr;
//            }
//            delete suc;
//        }

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
//    cout<<"DFS - depth first search"<<endl;
//    cout<<"In Order: ";tree->printinorder();
//    cout<<"Pre-Order: ";tree->printpreorder();
//    cout<<"Post-Order: ";tree->printpostorder();
//    cout<<endl<<"BFS - breadth first search"<<endl;
//    cout<<"Level Order: ";tree->printlevelorder();
//    cout<<endl<<"Delete Leaf Node #7: ";tree->remove(seven);tree->printinorder();
//    cout<<"Delete Node #6: ";tree->remove(six);tree->printinorder();
    cout<<"Delete Leaf Node of with #2: ";tree->remove(two);tree->printinorder();
    return 0;
}