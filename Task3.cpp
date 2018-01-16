/*
3. Написать программу, выполняющую сортировку одномерного массива целых
чисел по возрастанию методом вставок.
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
	int k = SIZE-1;
	for (int i = 0; i < SIZE; i++)
		ourArr[i] = rand() % 202 - 100; //Инициализируем массив
	cout << "Исходный массив:\n";
	printOurArr(ourArr); // Вызов функции вывода массива
	for (int i = 0; i < SIZE - 1; i++)
	{
		int tmp = ourArr[i + 1]; //значение вставляемого элемента
		int j = i; //j- индекс рассматриваемого отсортированного элемента
		while (j >= 0 && ourArr[j] > tmp)
		{
			ourArr[j + 1] = ourArr[j]; //сдвиг элемента вправо
			j--;
		}
		ourArr[j + 1] = tmp;
	}
	cout << "Итоговый массив:\n";
	printOurArr(ourArr); // Вызов функции вывода массива
	system("pause");
}
