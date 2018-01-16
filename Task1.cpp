/*
1. *Ввести массив целых чисел. Найти количество нулей в массиве и сумму
элементов, стоящих на нечетных местах.
*/

#include <iostream>
#include <ctime>
#define SIZE 8

using namespace std;
// ФУНКЦИЯ ДЛЯ ВЫВОДА МАССИВА :
void printOurArr(int a[SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		cout << a[i] << " ";		
	}
}

void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int ourArr[SIZE];
	int countOfNull = 0;
	int sum = 0;
	for (int i = 0; i < SIZE; i++)
		ourArr[i] = rand() % 22 - 10; //Инициализируем числами от -10 до 10
	cout << "Исходный массив:\n";
	printOurArr(ourArr); // Вызов функции вывода массива
	cout << endl;
	for (int i = 0; i < SIZE; i++) {
		if (ourArr[i] == 0) countOfNull++;
		if (i % 2 == 0) sum += ourArr[i]; //Нечетная позиция с точки зрения пользователя
	}
	cout << "Количество нулей " << countOfNull << endl;
	cout << "Сумма чисел на нечетных позициях " << sum << endl;

	system("pause");
}
