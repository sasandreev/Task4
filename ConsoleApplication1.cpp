// Задача№1 sin(x)/x = 1-(x^2/3!)+(x^4/5!)-(x^6/7!)+...  (R=oo)
#include <conio.h>
#include <locale>
#include <iostream>

using namespace std;

double rez1(double, int, double&);
double rez2(double, double, int&);

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Вычисление значений функции sin(x)/x\n\n";
	double x; // Значение аргумента
	double func; // Точное значение функции
	double sum; // Значение частичной суммы
	int n; // Число слагаемых в частичной сумме
	int m = 1, num;
	while (m == 1)
	{
		cout << "Задание 1" << endl;
		cout << "Введите значение аргумента > ";
		cin >> x;
		cout << "Введите число слагаемых > ";
		cin >> n;
		func = sin(x) / x;// Вычисление "точного" значения
		double last;
		sum = rez1(x, n, last);
		cout << "Точное значение функции равно " << func << endl;
		cout << "Частичная сумма ряда равна " << sum << endl;
		cout << "Абсолютная погрешность равна " << fabs(func - sum) << endl;
		cout << "Последнее слагаемое равно " << last << endl;

		cout << "\nЗадание 2" << endl;
		double E;
		cout << "Введите значение аргумента > ";
		cin >> x;
		cout << "Задайте точность вычислений > ";
		cin >> E;
		func = sin(x) / x;// Вычисление "точного" значения
		sum = rez2(x, E, n);
		cout << "Точное значение функции равно " << func << endl;
		cout << "Частичная сумма ряда c заданной точностью равна " << sum << endl;
		cout << "Учтено " << n << " членов ряда" << endl;
		sum = rez2(x, E / 10, n);
		cout << "Частичная сумма ряда c точностью, большей в 10 раз, равна " << sum << endl;
		cout << "Учтено " << n << " членов ряда" << endl;
		_getch();
		cout << "Выполнить задачу с новыми значениями? (1-Да)\n"; // меню продолжения
		cin >> m;
	}
	return 0;
}

double rez1(double x, int n, double& last)
{
	last = 1; // Инициализация переменной last
	double sum = last;
	for (int i = 1; i < n; ++i)
	{
		double r; // Отношение i-го слагаемлого к (i - 1)-му
		r = -x * x / (2 * i) / (2 * i + 1); // Вычисление значения r
		last *= r; // новое слагаемое 
		sum += last; // суммирование слагаемых
	}
	return sum;
}

double rez2(double x, double E, int& n)
{
	double last;
	last = 1; // Инициализация переменной last
	double sum = last;
	for (n = 1; fabs(last) > E; ++n)
	{
		double r; // Отношение n-го слагаемлого к (n - 1)-му
	    r = -x * x / (2 * n) / (2 * n + 1); // Вычисление значения r
		last *= r; // новое слагаемое 
		sum += last; // суммирование слагаемых
	}
	return sum;
}

