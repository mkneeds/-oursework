#pragma once
#include <iostream>

using namespace std;

template <class T>
struct Status {
	T* ptr;
	int counter;
};
template <class T>
class SmartPointer {
	Status<T>* smartPtr;
public:
	SmartPointer(T* ptr);
	SmartPointer(const SmartPointer& obj);
	~SmartPointer();//деструктор
	SmartPointer& operator=(const SmartPointer& obj);
	T* operator->() const;
	void showCounter() {
		cout << "Значение счетчика для объекта " << smartPtr << " равно: " << smartPtr->counter << endl;
	}
};
