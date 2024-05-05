#include <iostream>

using namespace std;

template <class T> 
void PrintInfo(T &obj)
{
	obj->PrintInfo();
}

template <typename T>
class Comparer {
public:
	Comparer(const T& value) {
		this->value_ = value;
	}
	bool operator()(const T& other) const {
		return value_ < other;
	}
	T value_;
};

template <typename T>
class Array {
public:
	void AddElement(T element) {
        array.push_back(element);
	}
	void printArray() {
		for (int i = 0; i < array.size(); i++)
			cout << array[i] << ", ";
		cout << endl;
	}
	vector<T> array;
	int i = 0;
};

