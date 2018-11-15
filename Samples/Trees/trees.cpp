#include <iostream>
#include <vector>
#include <queue>

template <class T>
struct TreeNode
{
    T data;
    std::vector<TreeNode<T> *> children;
    TreeNode(const T _data) : data(_data) {}
};

template <class T>
class Tree
{
    TreeNode<T> *root;

    void copy(TreeNode<T> *&currentRoot, const TreeNode<T> *otherRoot)
    {
        currentRoot = nullptr;
        if (!otherRoot)
        {
            return;
        }
        currentRoot = new TreeNode<T>(otherRoot->data);
        for (int i = 0; i < otherRoot->children.size(); i++)
        {
            currentRoot->children.push_back(nullptr);
            copy(currentRoot->children[i], otherRoot->children[i]);
        }
    }

    void print_helper( TreeNode<T> *currentRoot)
    {
        if (!currentRoot)
        {
            return;
        }
        if (isLeaf(currentRoot))
        {
            std::cout << currentRoot->data << '\n';
            return;
        }
        std::cout << currentRoot->data << '\n';
        for (auto child : currentRoot->children)
        {
            print_helper(child);
        }
    }

    bool isLeaf(TreeNode<T> *currentRoot)
    {
        if (currentRoot->children.size() == 0)
        {
            return true;
        }
        for (auto child : currentRoot->children)
        {
            if (child)
            {
                return false;
            }
        }
        return true;
    }
    void destroy(TreeNode<T> *&currentRoot)
    {
        if (!currentRoot)
        {
            return;
        }
        for (auto child : currentRoot->children)
        {
            destroy(child);
        }
        delete currentRoot;
        currentRoot = nullptr;
    }
    size_t height_helper(TreeNode<T> *currentRoot)
    {
        if (!currentRoot)
        {
            return 0;
        }
        if (isLeaf(currentRoot))
        {
            return 1;
        }
        size_t maxHeight = 0;
        for (auto child : currentRoot->children)
        {
            size_t currentHeight = height_helper(child);
            if (maxHeight < currentHeight)
            {
                maxHeight = currentHeight;
            }
        }
        return 1 + maxHeight;
    }
    void printBFS_helper(TreeNode<T>* currentRoot){
        std::queue<TreeNode<T>*> q;
        q.push(currentRoot);
        while(!q.empty()){
            TreeNode<T>* current = q.front();
            q.pop();
            std::cout<<current->data<<" ";
            for(TreeNode<T>* child : current->children){
                if (child) {
                    q.push(child);
                }
            }
        }
    }
  public:
    Tree();
    Tree(const Tree<T> &other);
    ~Tree();
    Tree<T> &operator=(const Tree<T> &other);
    size_t height();
    void print();
    void setRoot(TreeNode<T> *other)
    {
        root = other;
    }
    void printBFS();
};

template<class T>
void Tree<T>::printBFS() {
    printBFS_helper(root);
}

template <class T>
Tree<T>::Tree() : root(nullptr) {}

template <class T>
Tree<T>::Tree(const Tree<T> &other)
{
    copy(root, other.root);
}

template <class T>
Tree<T>::~Tree()
{
    destroy(root);
}

template <class T>
Tree<T> &Tree<T>::operator=(const Tree<T> &other)
{
    if (this != &other)
    {
        destroy(this->root);
        copy(this->root, other.root);
    }
    return *this;
}

template <class T>
void Tree<T>::print()
{
    print_helper(root);
}

template <class T>
size_t Tree<T>::height()
{
    return height_helper(root);
}


int main()
{
    TreeNode<int> *t1 = new TreeNode<int>(1);
    t1->children.push_back(new TreeNode<int>(2));
    t1->children.push_back(new TreeNode<int>(3));
    t1->children.push_back(new TreeNode<int>(4));
    t1->children[0]->children.push_back(new TreeNode<int>(22));
    t1->children[1]->children.push_back(new TreeNode<int>(9));
    t1->children[1]->children.push_back(new TreeNode<int>(12));
    Tree<int> t;
    t.setRoot(t1);
    // t.print();
    Tree<int> t3 = t;
    t3.print();
    // std::cout<<t3.height();
    t3.printBFS();
    return 0;
}