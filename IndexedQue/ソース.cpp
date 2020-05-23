#include <iostream>
#include <deque>

template<class T>
class IndexedQue {
public:

	bool Pop() {
		if (!D.size()) { return false; }
		D.pop_front();
		return true;
	}
	bool Push(const T& In) {
		D.push_back(In);

		return true;
	}
	const T& Front() {
		return  D.front();
	}

	const T& operator[](std::size_t In) {
		return D[In];
	}

	typename std::deque<T>::const_iterator begin() {
		return D.cbegin();
	}
	typename std::deque<T>::const_iterator end() {
		return D.cend();
	}

	std::size_t Size() {
		return D.size();
	}
protected:
	std::deque<T> D;
};

int main() {
	IndexedQue<int> IQ;

	for (int i = 0; i < 7; i++) {
		IQ.Push(i);
	}
	for (auto& o : IQ) {
		std::cout << o << ',';
	}
	std::cout << std::endl;

	while (IQ.Size()) {
		for (auto& o : IQ) {
			std::cout << o << ',';
		}
		std::cout << std::endl;
		IQ.Pop();
	}

	for (auto& o : IQ) {
		std::cout << o << ',';
	}
	std::cout << std::endl;
}
