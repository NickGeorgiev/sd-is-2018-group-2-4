#include<iostream>
template<class T>
struct TreeNode {
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
	TreeNode(T _data, TreeNode<T>* _left = nullptr, TreeNode<T>* _right = nullptr) :data(_data), left(_left), right(_right) {}
};

template<class T>
class BTree {
	TreeNode<T>* root;
	void printHelp(TreeNode<T>*&);
	void addHelp(TreeNode<T>*&, const T&);
    void removeElementHelper(TreeNode<T>*&, const T&);
    TreeNode<T>* findMinInRightSubtree(TreeNode<T>*);
public:
	BTree() :root(nullptr) {}
	void addBOT(const T&);
	void printLRoR();
    void removeElement(const T&);
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
void BTree<T>::addBOT(const T& elem) {
	addHelp(root, elem);
}

template<class T>
void BTree<T>::removeElement(const T& element) {
    removeElementHelper(root,element);
}

template<class T>
TreeNode<T>* BTree<T>::findMinInRightSubtree(TreeNode<T>* _root){
    while(_root->left){
        _root = _root->left;
    }
    return _root;
}

template<class T>
void BTree<T>::removeElementHelper(TreeNode<T>*& _root, const T& element){
    if(!_root) {
        return;
    }
    if(element < _root->data) {
        removeElementHelper(_root->left, element);
    }else if(element > _root->data) {
        removeElementHelper(_root->right, element);
    }else{
        if(!_root->left && !_root->right) {
            delete _root;
            _root = nullptr;
            return;
        }
        if(_root->left && !_root->right){
            TreeNode<T>* save = _root;
            _root = _root->left;
            delete save;
            return;
        }
        if(!_root->left && _root->right){
            TreeNode<T>* save = _root;
            _root = _root->right;
            delete save;
            return;
        }
        TreeNode<T>* minimalElementInRightSubtree = findMinInRightSubtree(_root->right);
        std::cout<<"minElem:"<<minimalElementInRightSubtree->data<<std::endl;
        std::swap(minimalElementInRightSubtree->data, _root->data);
        removeElementHelper(_root->right,element);
    }
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
    std::cout<<std::endl;
    tree.removeElement(14);
    tree.printLRoR();
    std::cout<<std::endl;
    return 0;
}

