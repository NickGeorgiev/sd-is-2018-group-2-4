#include<iostream>
#include<stack>
#include<vector>
#include<cassert>

template<class T>
struct TreeNode {
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
	TreeNode(T _data, TreeNode<T>* _left = nullptr, TreeNode<T>* _right = nullptr) :data(_data), left(_left), right(_right) {}
};

template<class T>
struct Task {
    TreeNode<T>* node;
    bool toPrint;
    Task(TreeNode<T>* _node, bool _toPrint = false): node(_node), toPrint(_toPrint){}
};

template<class T>
class LRoRIterator {
    private:
    std::stack<Task<T>*> tasks;
    void unwind();

    public:
    LRoRIterator()=delete;
    LRoRIterator(TreeNode<T>*);
    void operator++(int=0);
    bool end()const;
    T operator*() const;

};

template<class T>
void LRoRIterator<T>::unwind() {
    while(!tasks.empty() && !tasks.top()->toPrint){
        Task<T>* currentTask = tasks.top();
        tasks.pop();
        if (currentTask->node->right) {
            tasks.push(new Task<T>(currentTask->node->right));
        }
        currentTask->toPrint = true;
        tasks.push(currentTask);
        if (currentTask->node->left) {
            tasks.push(new Task<T>(currentTask->node->left));
        }
    }
}

template<class T>
LRoRIterator<T>::LRoRIterator(TreeNode<T>* root)  {
    tasks.push(new Task<T>(root));
    unwind();
}

template<class T>
bool LRoRIterator<T>::end() const {
    return tasks.empty();
}

template<class T>
T LRoRIterator<T>::operator*() const {
    assert(tasks.top()->toPrint);
    Task<T>* current = tasks.top();
    return current->node->data;
}

template<class T>
void LRoRIterator<T>::operator++(int indx){
    if(tasks.top()->toPrint){
        tasks.pop();
        unwind();
    }

}

template<class T>
class BTree {
	TreeNode<T>* root;
	void printHelp(TreeNode<T>*&);
	void addHelp(TreeNode<T>*&, const T&);
public:
	BTree() :root(nullptr) {}
	void addBOT(const T&);
	void printLRoR();
	LRoRIterator<T> begin();
    LRoRIterator<T> end();
};

template<class T>
void BTree<T>::addHelp(TreeNode<T>*& _root, const T & elem)
{
	if (_root) {
		if (elem <= _root->data) addHelp(_root->left, elem);
		else addHelp(_root->right, elem);
	}
	else {
		_root = new TreeNode<T>(elem);
	}
}

template<class T>
void BTree<T>::printLRoR()
{
	printHelp(root);
}

template<class T>
void BTree<T>::printHelp(TreeNode<T>*& _root)
{
	if (_root) {
		printHelp(_root->left);
		std::cout << _root->data<< " ";
		printHelp(_root->right);
	}
}

template<class T>
LRoRIterator<T> BTree<T>::begin()
{
	return LRoRIterator<T>(root);
}

template<class T>
LRoRIterator<T> BTree<T>::end()
{
	return LRoRIterator<T>(root,true);
}

template<class T>
void BTree<T>::addBOT(const T& elem) {
	addHelp(root, elem);
}


int main() {
    BTree<int> tree;
	tree.addBOT(10);
	tree.addBOT(7);
	tree.addBOT(4);
	tree.addBOT(8);
	tree.addBOT(3);
	tree.addBOT(5);
    tree.addBOT(14);
    tree.addBOT(11);
    tree.addBOT(16);
    tree.addBOT(15);
    tree.addBOT(18);
	tree.printLRoR();
	std::cout << '\n';
   for(auto it = tree.begin(); !it.end(); it++) {
       std::cout<< *it<< " ";
   } 
}