#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include "Node.h"
#include "Queue.cpp"
#include "functions.cpp"

using namespace std;

int main()
{
	char menu_choice,sub_m;
	bool exit = true;
	bool exit_1 = true;
	int i = 0, size = 0, Num_q = 0;
	int *int_mass = new int[size];
	float *float_mass = new float[size];
	double *double_mass = new double[size];
	char *char_mass = new char[size];

	Queue<int> *int_Q = nullptr;
	Queue<char> *char_Q = nullptr;
	Queue<float> *float_Q = nullptr;
	Queue<double> *double_Q = nullptr;


	do
	{
		system("cls");
		cout << " Choose type:" << endl;
		cout << "First task" << endl;
		cout << " 1.INT." << endl;
		cout << " 2.FLOAT." << endl;
		cout << " 3.DOUBLE." << endl;
		cout << " 4.CHAR" << endl;
		cout << "Second task" << endl;
		cout << " 5.INT." << endl;
		cout << " 6.FLOAT." << endl;
		cout << " 7.DOUBLE." << endl;
		cout << " 8.CHAR" << endl;
		cout << " 9.Exit." << endl;
		cout << "> ";
		cin >> menu_choice;

		switch (menu_choice) {
		case '1':
			cout << "Enter the size of array: ";
			cin >> size;
			for (int i = 0; i < size; i++)
				int_mass[i] = rand() % 1000 + 1;
			cout << "Your array: " << endl;
			try {
				print(int_mass, size);
				mergeSort(int_mass, 0, size - 1,size);
			}
			catch (int myException){
				cout << "Array has one element!" << endl;
				delete[] int_mass;
				break;
			}
			cout << "Sorted array:" << endl;
			print(int_mass, size);
			system("Pause");
			break;
		case '2':
			cout << "Enter the size of array: ";
			cin >> size;
			for (int i = 0; i < size; i++)
				float_mass[i] = float(rand() % 50 + 50) / float(rand() % 50 + 50);
			cout << "Your array:" << endl;
			try {
				print(float_mass, size);
				mergeSort(float_mass, 0, size - 1, size);
			}
			catch (int myException) {
				cout << "Array has one element!" << endl;
				delete[] float_mass;
				break;
			}
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
			try {
				print(double_mass, size);
				mergeSort(double_mass, 0, size - 1,size);
			}
			catch (int myException) {
				cout << "Array has one element!" << endl;
				delete[] double_mass;
				break;
			}
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
			try {
				print(char_mass, size);
				mergeSort(char_mass, 0, size - 1,size);
			}
			catch (int myException) {
				cout << "Array has one element!" << endl;
				delete[] char_mass;
				break;
			}
			cout << "Sorted array:" << endl;
			print(char_mass, size);
			system("Pause");
			break;
		case '5': 
			system("cls");
			cout << "1.Add element." << endl;
			cout << "2.Delete element." << endl;
			cout << "3.Check for emptiness." << endl;
			cout << "Exit - any button." << endl;
			cout << "> ";
			cin >> sub_m;
			switch (sub_m) {
			case '1':
				int_Q = new Queue<int>(rand() % 20 + 5);
				int_Q->print();
				+*int_Q;
				int_Q->print();
				system("Pause");
				break;
			case '2':
				int_Q = new Queue<int>(rand() % 20 + 5);
				int_Q->print();
				try
				{
					-*int_Q;
				}
				catch (int myException)
				{
					cout << "Queue is empty!" << endl;
				}
				int_Q->print();
				system("Pause");
				break;
			case'3':
				int_Q = new Queue<int>(rand() % 20 + 5);
				if (!int_Q)
				{
					cout << "Queue is empty!" << endl;
				}
				else
				{
					int_Q->print();
					cout << "Queue isn't empty, it has " << int_Q->getNum() << " elements" << endl;
				}
				system("Pause");
				break;
			default:
				break;
			}
			break;

		case '6':
			system("cls");
			cout << "1.Add element." << endl;
			cout << "2.Delete element." << endl;
			cout << "3.Check for emptiness." << endl;
			cout << "Exit - any button." << endl;
			cout << "> ";
			cin >> sub_m;
			switch (sub_m) {
			case '1':
				float_Q = new Queue<float>(rand() % 20 + 5);
				float_Q->print();
				+*float_Q;
				float_Q->print();
				system("Pause");
				break;
			case '2':
				float_Q = new Queue<float>(rand() % 20 + 5);
				int_Q->print();
				try
				{
					-*float_Q;
				}
				catch (int myException)
				{
					cout << "Queue is empty!" << endl;
				}
				float_Q->print();
				system("Pause");
				break;
			case'3':
				float_Q = new Queue<float>(rand() % 20 + 5);
				if (!float_Q)
				{
					cout << "Queue is empty!" << endl;
				}
				else
				{
					float_Q->print();
					cout << "Queue isn't empty, it has " << float_Q->getNum() << " elements" << endl;
				}
				system("Pause");
				break;
			default:
				break;
			}
			break;

		case '7':
			system("cls");
			cout << "1.Add element." << endl;
			cout << "2.Delete element." << endl;
			cout << "3.Check for emptiness." << endl;
			cout << "Exit - any button." << endl;
			cout << "> ";
			cin >> sub_m;
			switch (sub_m) {
			case '1':
				double_Q = new Queue<double>(rand() % 20 + 5);
				double_Q->print();
				+*double_Q;
				double_Q->print();
				system("Pause");
				break;
			case '2':
				double_Q = new Queue<double>(rand() % 20 + 5);
				double_Q->print();
				try
				{
					-*double_Q;
				}
				catch (int myException)
				{
					cout << "Queue is empty!" << endl;
				}
				double_Q->print();
				system("Pause");
				break;
			case'3':
				double_Q = new Queue<double>(rand() % 20 + 5);
				if (!double_Q)
				{
					cout << "Queue is empty!" << endl;
				}
				else
				{
					double_Q->print();
					cout << "Queue isn't empty, it has " << double_Q->getNum() << " elements" << endl;
				}
				system("Pause");
				break;
			default:
				break;
			}
			break;

		case '8':
			system("cls");
			cout << "1.Add element." << endl;
			cout << "2.Delete element." << endl;
			cout << "3.Check for emptiness." << endl;
			cout << "Exit - any button." << endl;
			cout << "> ";
			cin >> sub_m;
			switch (sub_m) {
			case '1':
				char_Q = new Queue<char>(rand() % 20 + 5);
				char_Q->print();
				+*char_Q;
				char_Q->print();
				system("Pause");
				break;
			case '2':
				char_Q = new Queue<char>(rand() % 20 + 5);
				char_Q->print();
				try
				{
					-*char_Q;
				}
				catch (int myException)
				{
					cout << "Queue is empty!" << endl;
				}
				char_Q->print();
				system("Pause");
				break;
			case'3':
				char_Q = new Queue<char>(rand() % 20 + 5);
				if (!char_Q)
				{
					cout << "Queue is empty!" << endl;
				}
				else
				{
					char_Q->print();
					cout << "Queue isn't empty, it has " << char_Q->getNum() << " elements" << endl;
				}
				system("Pause");
				break;
			default:
				break;
			}
			break;

		case '9':
			exit = false;
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