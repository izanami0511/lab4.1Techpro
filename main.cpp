#include <iostream>
#include <random>
#include <string>

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
void mergeSort(T *a, int l, int r)
{
	if (l == r) return; // границы сомкнулись
	int mid = (l + r) / 2; // определяем середину последовательности
	// и рекурсивно вызываем функцию сортировки для каждой половины
	mergeSort( a, l, mid);
	mergeSort( a, mid + 1, r);
	int i = l;  // начало первого пути
	int j = mid + 1; // начало второго пути
	T *tmp = (T*)malloc(r * sizeof(T)); // дополнительный массив
	for (int step = 0; step < r - l + 1; step++) // для всех элементов дополнительного массива
	{
		// записываем в формируемую последовательность меньший из элементов двух путей
		// или остаток первого пути если j > r
		if ((j > r) || ((i <= mid) && ( a[i] <  a[j])))
		{
			tmp[step] =  a[i];
			i++;
		}
		else
		{
			tmp[step] =  a[j];
			j++;
		}
	}
	// переписываем сформированную последовательность в исходный массив
	for (int step = 0; step < r - l + 1; step++)
		 a[l + step] = tmp[step];
}

int main()
{
	char menu_choice;
	bool exit = true;
	int i = 0, size = 0;
	int *int_mass = new int[size];
	float *float_mass = new float[size];
	double *double_mass = new double[size];
	char *char_mass = new char[size];

	do
	{
		system("cls");
		cout << " Choose type." << endl;
		cout << " 1.INT." << endl;
		cout << " 2.FLOAT." << endl;
		cout << " 3.DOUBLE." << endl;
		cout << " 4.CHAR" << endl;
		cout << " 5.Exit." << endl;
		cout << "> ";
		cin >> menu_choice;

		switch (menu_choice) {
		case '1':
			cout << "Enter the size of array: ";
			cin >> size;
			for (int i = 0; i < size; i++)
				int_mass[i] = rand() % 1000 + 1;
			cout << "Your array:" << endl;
			print(int_mass, size);
			mergeSort(int_mass, 0, size - 1);
			cout << "Sorted array:" << endl;
			print(int_mass, size);
			i = size;
			cout << "====================--Special for Dad--======================" << endl;;
			for (i; i != -1; i--) {
				cout << int_mass[i]<<' ';

			}
			
			system("Pause");
			break;
		case '2':
			cout << "Enter the size of array: ";
			cin >> size;
			for (int i = 0; i < size; i++)
				float_mass[i] = float(rand() % 50 + 50) / float(rand() % 50 + 50);
			cout << "Your array:" << endl;
			print(float_mass, size);
			mergeSort(float_mass, 0, size - 1);
			cout << "Sorted array:" << endl;
			print(float_mass, size);
			system("Pause");
			break;
		case '3':
			cout << "Enter the size of array: ";
			cin >> size;
			for (int i = 0; i < size; i++)
				double_mass[i] = (double(rand() % 50) + 50) / (double(rand() % 50) + 50);
			cout << "Your array:" << endl;
			print(double_mass, size);
			mergeSort(double_mass, 0, size - 1);
			cout << "Sorted array:" << endl;
			print(double_mass, size);
			system("Pause");
			break;
		case '4':
			cout << "Enter the size of array: ";
			cin >> size;
			for (int i = 0; i < size; i++)
				char_mass[i] = rand() % 127 + 33;
			cout << "Your array:" << endl;
			print(char_mass, size);
			mergeSort(char_mass, 0, size - 1);
			cout << "Sorted array:" << endl;
			print(char_mass, size);
			system("Pause");
			break;
		case '5':
			exit = false;;
			break;
		default:
			break;
		}
	} while (exit);
	delete[] int_mass;
	delete[] float_mass;
	delete[] double_mass;
	delete[] char_mass;
	return 0;
}