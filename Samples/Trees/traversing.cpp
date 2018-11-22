#include<iostream>
#include<queue>
#include<stack>

template<class T>
struct BTreeNode{
    T data;
    BTreeNode<T>* left;
    BTreeNode<T>* right;
    BTreeNode(const T& _data, BTreeNode<T>* _l=nullptr, BTreeNode<T>* _r=nullptr): data(_data), left(_l), right(_r) {}
};

template<class T>
void printBFS(BTreeNode<T>* root){
    std::queue<BTreeNode<T>*> BFSQueue;
    if(!root){
        return;
    }
    BFSQueue.push(root);
    while(!BFSQueue.empty()){
        BTreeNode<T>* current = BFSQueue.front();
        BFSQueue.pop();
        std::cout<<current->data;
        if(current->right){
            BFSQueue.push(current->right);
        }
        if(current->left){
            BFSQueue.push(current->left);
        }
    }
}

template<class T>
void printDFS(BTreeNode<T>* root){
    std::stack<BTreeNode<T>*> DFSStack;
    if(!root){
        return;
    }
    DFSStack.push(root);
    while(!DFSStack.empty()){
        BTreeNode<T>* current = DFSStack.top();
        DFSStack.pop();
        std::cout<<current->data;
        if(current->left) {
            DFSStack.push(current->left);
        }
        if(current->right) {
            DFSStack.push(current->right);
        }
    }
}

int main(){
    BTreeNode<int>* t1 = new BTreeNode<int>(10);
    t1->left = new BTreeNode<int>(8);
    t1->right = new BTreeNode<int>(12);
    t1->left->left = new BTreeNode<int>(6);
    t1->left->right = new BTreeNode<int>(9);
    t1->right->left = new BTreeNode<int>(11);
    t1->right->right = new BTreeNode<int>(14);
    // printBFS(t1);
    printDFS(t1);
}