/*
2. Написать программу, выполняющую сортировку одномерного массива целых
чисел по возрастанию методом пузырька. Направление просмотров – слева
направо, минимизировать число просмотров.
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
	int countOfNull = 0;
	int k = SIZE-1;
	bool flag = true;
	for (int i = 0; i < SIZE; i++)
		ourArr[i] = rand() % 202 - 100; //Инициализируем массив
	cout << "Исходный массив:\n";
	printOurArr(ourArr); // Вызов функции вывода массива
	while (k > 0 && flag)// к - левая граница подмассива
	{
		int endI = -1;
		flag = false;
		for (int i = 0; i < k; i++) 
			if (ourArr[i] > ourArr[i + 1]) {
				 //Находим максимальный элемент в части массива от k до SIZE 
				int tmp = ourArr[i];
				ourArr[i] = ourArr[i+1];
				ourArr[i+1] = tmp;
				flag = true;
				endI = i;
			}
		k=endI;		
	}	
	cout << "Итоговый массив:\n";
	printOurArr(ourArr); // Вызов функции вывода массива
	system("pause");
}
