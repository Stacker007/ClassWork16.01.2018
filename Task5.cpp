/*
5. Дан массив случайных чисел от 0 до 20. Пользователь вводит число. Необходимо
найти самую левую позицию этого числа в массиве. Отсортировать элементы
справа от найденного по возрастанию, а слева – по убыванию.
*/

#include <iostream>
#include <ctime>
#define SIZE 10

using namespace std;
// ФУНКЦИЯ ДЛЯ ВЫВОДА МАССИВА :
void printOurArr(int a[], int column){
	for (int i = 0; i < column; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int ourArr[SIZE];
	int choice;
	int indexOfChoice;
	bool flag = true;
	for (int i = 0; i < SIZE; i++)
		ourArr[i] = rand() % 21; //Инициализируем массив
	cout << "Исходный массив:\n";
	printOurArr(ourArr,SIZE); // Вызов функции вывода массива
	do {
		flag = true;
		cout << "Выберите число из массива ";
		cin >> choice;
		int i;
		for (i = 0; i < SIZE; i++)
			if (ourArr[i] == choice) break;
		indexOfChoice = i;
		if (i == SIZE) {
			cout << "Такого числа нет в массиве!!!\n";
			flag = false;
		}
	} while (!flag); // Ввод числа с проверкой

	int k = indexOfChoice-1; //сортировка до слева от числа (по убыванию)
	while (k > 0 && flag) // к - левая граница подмассива (
	{
	int endI = -1;
	flag = false;
	for (int i = 0; i < k; i++)
	if (ourArr[i] < ourArr[i + 1]) {
	//Находим максимальный элемент в части массива от k до SIZE
	int tmp = ourArr[i];
	ourArr[i] = ourArr[i + 1];
	ourArr[i + 1] = tmp;
	flag = true;
	endI = i;
	}
	k = endI;
	}
	flag = true;
	k = SIZE-1; //сортировка справа от числа (по возрастанию)
	while (k > indexOfChoice+1 && flag) // к - левая граница подмассива (
	{
		int endI = -1;
		flag = false;
		for (int i = indexOfChoice+1 ; i < k; i++)
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
	printOurArr(ourArr, SIZE); // Вызов функции вывода массива
	
	system("pause");
	return 0;
}
