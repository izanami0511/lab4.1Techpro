#include "Node.h"
#include<random>
#include<ctime>
#include <iostream>

using namespace std;
template <typename T>
class Queue 
{
	Node<T> *Head;
	Node<T> *Tail;
	int Num;

public:
	Queue() :Head(nullptr), Tail(nullptr), Num(0) {};
	Queue(int op1);
	~Queue();

	Node<T>* gethead() { return Head; }
	Node<T>* gettail() { return Tail; }
	int getNum() { return Num; }

	void sethead(Node<T>* op1) { Head = op1; };
	void settail(Node<T>* op1) { Tail = op1; };
	void setnum(int op1) { Num = op1; };

	Queue& operator+();
	Queue& operator-();
	bool operator!();

	void print();
};

template <typename T>
Queue<T>::Queue(int op1)
{
	for (int i = 0; i < op1; ++i)
	{
		Node<T> *tmp = new Node<T>;
		tmp->setValue(static_cast<T>(rand()));
		if (Num == 0)
		{
			tmp->setPrev(nullptr);
			Head = tmp;
			Tail = Head;
		}
		else
		{
			tmp->setPrev(Tail);
			Tail = tmp;
		}
		Num++;
	}
}

template <typename T>
Queue<T>::~Queue()
{
	Node<T> *temp = Tail;
	while (temp != nullptr) {
		temp = Tail->getPrev();
		delete Tail;
		Tail = temp;
	}
}

template <typename T>
Queue<T>& Queue<T>::operator+()
{
	Node<T> *tmp = new Node<T>;
	tmp->setValue(static_cast<T>(rand()));
	if (Num == 0)
	{
		tmp->setPrev(nullptr);
		Head = tmp;
		Tail = Head;
	}
	else
	{
		tmp->setPrev(Tail);
		Tail = tmp;
	}
	Num++;
	return *this;
}

template <typename T>
Queue<T>& Queue<T>::operator-()
{
	if (!this)
		throw 666;
	Node<T> *tmp;
	tmp = Tail;
	while (tmp->getPrev() != Head)
		tmp = tmp->getPrev();
	delete Head;
	Head = tmp;
	tmp = Tail;
	Num--;
	return *this;
}

template <typename T>
bool Queue<T>::operator!()
{
	if (Num == 0)
		return false;
	else
		return true;
}

template <typename T>
void Queue<T>::print()
{
	Node<T> *tmp = Tail;
	T *mas = new T[Num];
	int k = Num - 1;
	for (int i = 0; i < Num; ++i)
	{
		mas[k--] = tmp->getValue();
		tmp = tmp->getPrev();
	}

	for (k = 0; k < Num; ++k)
		k == Num - 1 ? cout << mas[k] : cout << mas[k] << " << ";
	cout << endl;
	delete[] mas;
}