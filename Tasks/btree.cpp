#include<iostream>
#include<string>

template<class T>
struct TreeNode {
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode(const T& _data, TreeNode<T>* _left = nullptr, TreeNode<T>* _right = nullptr): data(_data), left(_left), right(_right){}
};
template<class T>
bool findTraceHelper(TreeNode<T>* root, const T& element, std::string& trace) {
    if (!root) {
        return false;
    }
    if (root->data == element) {
        return true;
    }
    trace.push_back('L'); // We start from the left subtree
    if (!findTraceHelper(root->left, element, trace)) { // If the element is not in the left subtree
        trace.pop_back(); // We switch to 
        trace.push_back('R'); // the right subtree
        if (!findTraceHelper(root->right, element, trace)) { // And if the element is not there too
            trace.pop_back(); // We remove the last added direction
            return false;
        }
    }
    return true;
}


template<class T>
std::string findTrace(TreeNode<T>* root, const T& element) {
    std::string trace;
    findTraceHelper(root, element, trace);
    if (trace.empty()) { // If we don't have any trace
        trace.push_back('-'); // We add terminating symbol, whatever it is
    }
    return trace; // And return the trace 
}

int main() {
    TreeNode<int>* root = new TreeNode<int>(2, new TreeNode<int>(12, new TreeNode<int>(19)), new TreeNode<int>(110, new TreeNode<int>(90, new TreeNode<int>(115, new TreeNode<int>(40)))));
    std::string trace = findTrace(root,12345);
    std::cout << trace << std::endl;
    return 0;
}