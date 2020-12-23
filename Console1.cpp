#include <iostream>
#include <fstream>
#include <conio.h>
#include <Windows.h>
using namespace std;
class Worker {
	char fio[30];
	char dol[30];
	int year;
	double wage;
public:
	void set() {
		cout << "Введите ФИО работника: "; cin >> fio;
		cout << "Введите должность работника: "; cin >> dol;
		cout << "Введите заработную плату работника: "; cin >> wage;
		cout << "Введите год поступления на работу: "; cin >> year; cout << endl;
	};
	void get() {
		cout << "ФИО работника: " << fio << endl;
		cout << "Должность работника: " << dol << endl;
		cout << "Заработная плата работника: " << wage << endl;
		cout << "Год поступления на работу: " << year << endl;
	};
	void getfio() {
		cout << "ФИО работника: " << fio << endl;
	};
	int Year() { return year; };
	double Wage() { return wage; };
	char* Dol() { return dol; };
};
void main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Лабораторная работа №1" << endl;
	cout << "Выполнить задание №1? (Если да, то введите - 1)" << endl;
	if (_getch() == '1')
	{
		Worker* List;
		int n, k, a = 0;
		cout << "Введите количество работников: "; cin >> n;
		cout << "Введите заданное число лет: "; cin >> k;
		List = new Worker[n];
		for (int i = 0;i < n;i++) {
			cout << "Данные о работнике № " << i + 1 << endl;
			List[i].set();
		}
		cout << "Список работников, стаж работы которых на данном предприятии превышает заданное число лет: " << endl;
		for (int i = 0;i < n;i++) {
			if (2020 - List[i].Year() > k) {
				List[i].getfio();
			}
		}
		delete[] List;
	}
	cout << "Выполнить задание №2? (Если да, то введите - 2)" << endl;
	if (_getch() == '2')
	{
		Worker* List;
		int n, a = 0;
		double k;
		cout << "Введите количество работников: "; cin >> n;
		cout << "Введите зарплату: "; cin >> k;
		List = new Worker[n];
		for (int i = 0;i < n;i++) {
			cout << "Данные о работнике № " << i + 1 << endl;
			List[i].set();
		}
		cout << "Список работников, зарплата которых больше заданной: " << endl;
		for (int i = 0;i < n;i++) {
			if (List[i].Wage() > k) {
				List[i].getfio();
			}
		}
		delete[] List;
	}
	cout << "Выполнить задание №3? (Если да, то введите - 3)" << endl;
	if (_getch() == '3')
	{
		Worker* List;
		char A[30];
		int n, a = 0;
		cout << "Введите количество работников: "; cin >> n;
		cout << "Введите заданную должность: "; cin >> A;
		List = new Worker[n];
		for (int i = 0;i < n;i++) {
			cout << "Данные о работнике № " << i + 1 << endl;
			List[i].set();
		}
		cout << "Список работников, занимающих заданную должность: " << endl;
		for (int i = 0;i < n;i++) {
			if (strcmp(List[i].Dol(), A) == 0) {
				List[i].getfio();
			}
		}
		delete[] List;
	}
	system("pause");
};

