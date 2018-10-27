#include<iostream>
#include<cassert>
#include "Stack.cpp"
bool stackTests(bool debug = false) {
	Stack<int> testStack;
	assert(testStack.size() == 0);
	assert(testStack.empty());
	if (debug) std::cout << "Stack is empty!" << std::endl;

	testStack.push(12);
	assert(testStack.size() == 1);
	assert(!testStack.empty());
	assert(testStack.top() == 12);
	if (debug) std::cout << "Successfully pushed element at the top of the stack!" << std::endl;

	testStack.push(24);
	assert(testStack.size() == 2);
	assert(!testStack.empty());
	assert(testStack.top() == 24);
	if (debug) std::cout << "Successfully pushed another element!" << std::endl;

	testStack.pop();
	assert(testStack.size() == 1);
	assert(!testStack.empty());
	assert(testStack.top() == 12);
	if (debug) std::cout << "Successfully popped element from stack!" << std::endl;

	Stack<int> testCopyStack(testStack);
	assert(testCopyStack.size() == 1);
	assert(!testCopyStack.empty());
	assert(testCopyStack.top() == 12);
	if (debug) std::cout << "Successfully copied stack!" << std::endl;

	Stack<int> testAssignedStack;
	testAssignedStack = testStack;
	assert(testAssignedStack.size() == 1);
	assert(!testAssignedStack.empty());
	assert(testAssignedStack.top() == 12);
	if (debug) std::cout << "Successfully assigned stack!" << std::endl;
	return true;
}

//int main() {
//	std::cout << stackTests();
//	return 0;
//}