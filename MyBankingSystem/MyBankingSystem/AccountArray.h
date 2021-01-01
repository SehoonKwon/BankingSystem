/**
*@file AccountArray.h
*Account 배열 관리
*/
#pragma once

///@brief 계좌 관리를 위한 배열 클래스.
///@details 아래와 같이 함수 템플릿을 헤더와 소스파일로 분리하면 main에서 square 호출 시 실제 Lib.h 헤더파일만 참고하므로 
/// 템플릿을 기반으로 실제 int형 함수 생성이 필요한데 생성할 구현부 확인이 불가능하여 에러 발생
/// 따라서 .h에 구현부를 넣거나, 구현부를 include 해줘야 한다
template <typename T>
class BoundCheckArray
{
private:

	T* arr;
	int arrlen;
	BoundCheckArray(const BoundCheckArray& arr) {}
	BoundCheckArray& operator=(const BoundCheckArray& arr){}

public:
	BoundCheckArray(int len = 100);
	T& operator[](int idx);
	T operator[] (int idx) const;
	int GetArrLen() const;
	~BoundCheckArray();
};

template <typename T>
BoundCheckArray<T>::BoundCheckArray(int len) : arrlen(len)
{
	arr = new T[len];
}

template <typename T>
T& BoundCheckArray<T>::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound expetion" << endl;
		exit(1);
	}
	return arr[idx];
}

template <typename T>
T BoundCheckArray<T>::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound expetion" << endl;
		exit(1);
	}
	return arr[idx];
}

template <typename T>
int BoundCheckArray<T>::GetArrLen() const
{
	return arrlen;
}

template <typename T>
BoundCheckArray<T>::~BoundCheckArray()
{
	delete[]arr;
}