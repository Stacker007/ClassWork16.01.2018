/*
1. Напишите программу сортировки одномерного массива целых чисел по
невозрастанию (убыванию) методом выбора максимального элемента
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
	int k = 0;
	for (int i = 0; i < SIZE; i++)
		ourArr[i] = rand() % 22 - 10; //Инициализируем числами от -10 до 10
	cout << "Исходный массив:\n";
	printOurArr(ourArr); // Вызов функции вывода массива
	for (int k = 0; k < SIZE -1; k++) // к - левая граница подмассива
	{
		int imin = k; 
		for (int i = k + 1; i < SIZE; i++) 
			if (ourArr[i]>ourArr[imin]) imin = i; //Находим максимальный элемент в части массива от k до SIZE 
		int tmp = ourArr[k];
		ourArr[k] = ourArr[imin];
		ourArr[imin] = tmp;
	}
	cout << endl;
	cout << "Итоговый массив:\n";
	printOurArr(ourArr); // Вызов функции вывода массива
	system("pause");
}
