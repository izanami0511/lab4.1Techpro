#include <iostream>
using namespace std;


template <typename T>
void print(T*op1, int size)
{
	for (int i = 0; i < size; i++) {
		cout << op1[i] << ' ';
	}
	cout << endl;
}

template <typename T>
void mergeSort(T *A, int first, int last, int num)
{
	if (num == 1)
		throw 666;
	int middle, start, final, j;
	T *mas = new T[num];
	middle = (first + last) / 2;
	start = first;
	final = middle + 1;
	{
		if (first < last)
		{
			mergeSort(A, first, (first + last) / 2, num);
			mergeSort(A, (first + last) / 2 + 1, last, num);
			for (j = first; j <= last; j++)
				if ((start <= middle) && ((final > last) || (A[start] < A[final])))
				{
					mas[j] = A[start];
					start++;
				}
				else
				{
					mas[j] = A[final];
					final++; 
				}
			for (j = first; j <= last; j++) A[j] = mas[j];
			delete[]mas;
		}
	}
}