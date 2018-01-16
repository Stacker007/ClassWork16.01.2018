/*
4. Дан массив случайных чисел в диапазоне от -20 до 20. Найти позиции самого левого
отрицательного элемента и самого правого отрицательного элемента и отсортировать
элементы между ними по убыванию произвольным методом.
*/

#include <iostream>
#include <ctime>
#define SIZE 10

using namespace std;
// ФУНКЦИЯ ДЛЯ ВЫВОДА МАССИВА :
void printOurArr(int a[SIZE]) {
	for (int i = 0; i < SIZE; i++) 
		cout << a[i] << " ";	
	cout << endl;
}
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int ourArr[SIZE];
	int firstOfNegative = -1;
	int lastOfPositive = -1;
	bool flag = true;
	for (int i = 0; i < SIZE; i++)
		ourArr[i] = rand() % 42 -20; //Инициализируем массив
	cout << "Исходный массив:\n";
	printOurArr(ourArr); // Вызов функции вывода массива
	int i;
	for (i = 0; i<SIZE; i++)
		if (ourArr[i] <0) break;
	if (i == SIZE)
		cout << "Отрицательных чисел нет в массиве\n";
	else {
		firstOfNegative = i;
		for (i = SIZE - 1; i >= 0; i--)
			if (ourArr[i] > 0) break;
		if (i < 0)
			cout << "Положительных чисел нет в массиве\n";
		else lastOfPositive = i;
	}
	if (firstOfNegative != -1 && lastOfPositive != -1) { //Если есть и отрицательный и положительный элементы
		int k = lastOfPositive; //Начинаем сортировку с последнего положительного
		while (k > firstOfNegative && flag) // к - левая граница подмассива (
		{
			int endI = -1;
			flag = false;
			for (int i = firstOfNegative; i < k; i++)
				if (ourArr[i] > ourArr[i + 1]) {
					//Находим максимальный элемент в части массива от k до SIZE 
					int tmp = ourArr[i];
					ourArr[i] = ourArr[i + 1];
					ourArr[i + 1] = tmp;
					flag = true;
					endI = i;
				}
			k = endI;
		}
		cout << "Итоговый массив:\n";
		printOurArr(ourArr); // Вызов функции вывода массива
	}
	system("pause");
}
