#include "slist.cpp"

int main() {
	SList<int> s;
	for (int i = 1; i < 10; i++) {
		s.push(i);
	}
	s.print();
	std::cout << std::endl;
	SList<int> s1(s);
	s1.print();
}