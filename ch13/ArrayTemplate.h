#ifndef __ARRAY_TEMPLATE_H_
#define __ARRAY_TEMPLATE_H_

#include <iostream>
#include <cstdlib>
using namespace std;

template<typename T>
class BoundCheckArray
{
private:
	T* arr;
	int arrlen;
	BoundCheckArray(const BoundCheckArray& arr) {}
	BoundCheckArray = (const BoundCheckArray & arr){}
public:
	BoundCheckArray(int len);
	T& operator[](int idx);
	T operator[](int idx) const;
	int GetArrLen() const;
	~BoundCheckArr();
};

template<typename T>
BoundCheckArray<T>::BoundCheckArr(int len)
{
	arr = new T[len];
}

template<typename T>
T& BoundCheckArray<T>::operator[] (int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template<typename T>
T BoundCheckArray<T>::operator[] (int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array idx out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

template<typename T>
int BoundaryCheckArray<T>::GetArrLen() const
{
	return arrlen;
}

template<typename T>
BoundaryCheckArray<T>::~BoundaryCheckArray()
{
	delete[] arr;
}

#endif
