#include<iostream>
#include<vector>
#include<string>
template<class T = int>
struct BinTreeNode {
    T leftNodesCount;
    BinTreeNode<T>* left;
    BinTreeNode<T>* right;
    BinTreeNode(const T _count, BinTreeNode<T>* l = nullptr, BinTreeNode<T>* r = nullptr): leftNodesCount(_count), left(l), right(r) {}
};

template<class T = int>
BinTreeNode<T>* createTree( unsigned int n) {
    if(n == 0) return nullptr;
    int middle = n / 2;
    int leftCount = middle;
    int rightCount = n%2 ==0 ? middle-1 : middle;
    BinTreeNode<T>* root = new BinTreeNode<T>(leftCount);
    root->left = createTree(leftCount);
    root->right = createTree(rightCount);
    return root;
}

template<class T>
void print(BinTreeNode<T>* root) {
    if(!root) return;
    print(root->left);
    std::cout<<root->leftNodesCount;
    print(root->right);
}

using hashfn = size_t (*) (std::string, size_t);

struct HTPair {std::string key; int value;};

struct HTable {hashfn h;  size_t size;  std::vector<std::vector<HTPair>> table;};

void insert(HTable& ht,const std::string& key, int value){
    int hashedIndex = ht.h(key, ht.size);
    
    HTPair forInsert;
    forInsert.key = key;
    forInsert.value = value;
    
    std::vector<HTPair>& currentRow = ht.table[ht.h(key,ht.size)];

    if(ht.table[hashedIndex].empty()){
        ht.table[hashedIndex].push_back(forInsert);
    }else {
        for(auto pair : ht.table[hashedIndex]){
            if(pair.key == key) {
                pair.value = value;
                return;
            }
        }
        ht.table[hashedIndex].push_back(forInsert);
    }
}

size_t howManyKeys(HTable& ht, int value) {
    size_t count = 0;
    for(auto row : ht.table) {
        for(auto pair : row) {
            if(pair.value == value) { // TO DO
                count++;
            }
        }
    }
    return count;
}
struct TreeNodeWrapper{
    char symbol;
    TreeNode* child;
};

struct TreeNode{

    std::vector<TreeNodeWrapper*> children; // std::map<char, TreeNode*> children;
};

bool path(TreeNode* root, const char* text){
    if(!root) return false;
    bool hasPath = false;
    //returns true if text is ''
    char currentSymbol = text[0];
    for(auto currentChild : root->children) {
        if(currentChild->symbol == currentSymbol) hasPath = hasPath || path(currentChild->child, text + 1);
        if(hasPath) return true;
    }
    return false;

}


int main() {
    BinTreeNode<int>* root = createTree<int>(7);
    print(root);
}

