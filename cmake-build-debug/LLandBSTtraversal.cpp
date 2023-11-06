//
// Created by Jacinto Gomez on 6/20/23.
//

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <stack>
#include <queue>
using namespace std;

void printvec(vector<int> v){
    cout<<"printing vector: ";
    for(int i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}

struct LListNode{
    LListNode(int v):val(v){};
    int val;
    LListNode* next=nullptr;
    LListNode* prev=nullptr;
};

struct BSTNode{
    BSTNode(int v):val(v){};
    int val;
    BSTNode* left=nullptr;
    BSTNode* right=nullptr;
    BSTNode* parent=nullptr;
};

class ll{
public:
    LListNode* head;
    LListNode* tail;
    int size;
    ll():head(nullptr),tail(nullptr),size(0){};
    ll(LListNode* i):head(i),tail(i),size(1){};
    void add(LListNode* f){
        f->prev=this->tail;
        this->tail->next=f;
        this->tail=f;
        this->size++;
    }
    void display(){
        LListNode* temp=this->head;
        cout<<"linked list: ";
        while(temp!=nullptr){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

class bst{
public:
    BSTNode* root;
    int size;
    bst():root(nullptr),size(0){};
    bst(BSTNode* i):root(i),size(1){};
    void add(BSTNode* f){
        BSTNode* temp=this->root;
        BSTNode* prev;
        bool r;
        while(temp!=nullptr){
            prev=temp;
            if(temp->val<f->val){temp=temp->right;r=true;}
            else{temp=temp->left;r=false;}
        }
        if(r){prev->right=f;}
        else{prev->left=f;}
        this->size++;
        f->parent=prev;
    }
    void displaydriver(BSTNode* rt){
        if(rt==nullptr){return;}
        displaydriver(rt->left);
        cout<<rt->val<<" ";
        displaydriver(rt->right);
    }
    void display(){
        BSTNode* temp=this->root;
        cout<<"binary search tree: ";
        displaydriver(temp);
        cout<<endl;
    }
};

void inorder(BSTNode* rt,vector<int>& v){
    if(rt==nullptr){return;}
    inorder(rt->left,v);
    v.push_back(rt->val);
    inorder(rt->right,v);
}

// bool compare(BSTNode* b, LListNode* l){
//     vector<int> d;
//     vector<int> e;
//     inorder(b,d);
//     while(l!=nullptr){
//         e.push_back(l->val);
//         l=l->next;
//     }
//     return d==e;
// }

bool compare(BSTNode* root,LListNode*& head){
    if(head==nullptr){return root==nullptr;}
    bool left=true,right=true,center=true;
    if(root!=nullptr){if(root->left!=nullptr){left=compare(root->left,head);}}else{return false;}
    if(head!=nullptr){
        if(root!=nullptr){
            center=root->val==head->val;
            head=head->next;
        }else{return false;}
    }
    else{center=false;}
    if(root->right!=nullptr){right=compare(root->right,head);}//}else{right=false;}
    return left&&right&&center;
}

int main(){
    //linked list
    LListNode start1(1);
    LListNode l1(2);
    LListNode l2(4);
    LListNode l3(7);
    LListNode l4(10);
    ll lst=ll(&start1);
    lst.add(&l1);
    lst.add(&l2);
    lst.add(&l3);
    lst.add(&l4);
    lst.display();

    //linked list copy
    LListNode start1copy(1);
    LListNode l1copy(2);
    LListNode l2copy(4);
    LListNode l3copy(7);
    LListNode l4copy(10);
    ll lstcopy=ll(&start1copy);
    lstcopy.add(&l1copy);
    lstcopy.add(&l2copy);
    lstcopy.add(&l3copy);
    lstcopy.add(&l4copy);
    lstcopy.display();

    //binary search tree
    BSTNode start2(2);
    BSTNode b1(1);
    BSTNode b2(4);
    BSTNode b3(7);
    BSTNode b4(10);
    bst tree=bst(&start2);
    tree.add(&b1);
    tree.add(&b3);
    tree.add(&b2);
    tree.add(&b4);
    tree.display();

    //single linked list
    LListNode start3(100);
    ll badll=ll(&start3);

    //single binary search tree
    BSTNode start4(1000);
    bst badbst(&start4);

    //non matching linked list
    LListNode start5(2);
    LListNode l12(2);
    LListNode l22(4);
    LListNode l32(7);
    LListNode l42(10);
    ll lst5=ll(&start5);
    lst5.add(&l12);
    lst5.add(&l22);
    lst5.add(&l32);
    lst5.add(&l42);

    //linked list
    LListNode longstart1(1);
    LListNode l10(2);
    LListNode l20(4);
    LListNode l30(7);
    LListNode l40(10);
    LListNode l50(11);
    LListNode l60(12);
    ll longlst=ll(&longstart1);
    longlst.add(&l10);
    longlst.add(&l20);
    longlst.add(&l30);
    longlst.add(&l40);
    longlst.add(&l50);
    longlst.add(&l60);
    longlst.display();

    //binary search tree
    BSTNode longstart2(7);
    BSTNode b10(1);
    BSTNode b20(2);
    BSTNode b30(4);
    BSTNode b40(10);
    BSTNode b50(11);
    BSTNode b60(12);
    bst longtree=bst(&longstart2);
    longtree.add(&b20);
    longtree.add(&b50);
    longtree.add(&b10);
    longtree.add(&b30);
    longtree.add(&b40);
    longtree.add(&b60);
    longtree.display();

    LListNode single(1000);
    ll singlell=ll(&single);
    // badll.display();
    // lst5.display();
    // badbst.display();

    ll emptyll=ll();
    bst emptybst=bst();
    LListNode extraa(0);
    ll extra=ll(&extraa);
    cout<<compare(tree.root,lst.head)<<" true "<<endl;//regular ll and bst - pass
    cout<<compare(tree.root,badll.head)<<" false "<<endl;//bad ll and regular bst - fail
    cout<<compare(badbst.root,lstcopy.head)<<" false "<<endl;//regular ll and bad bst - fail
    cout<<compare(tree.root,lst5.head)<<" false "<<endl;//same length ll and bst - fail
    cout<<compare(badbst.root,singlell.head)<<" true "<<endl;//single bst and ll - pass
    cout<<compare(longtree.root,longlst.head)<<" true"<<endl;//another regular example - pass
    cout<<compare(longtree.root,emptyll.head)<<" false"<<endl;//legit bst and null ll - fail
    cout<<compare(emptybst.root,extra.head)<<" false"<<endl;//null bst and legit ll - fail
    cout<<compare(emptybst.root,emptyll.head)<<" true"<<endl;//null bst and ll - pass
    return 0;
}