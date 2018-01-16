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
void printOurArr(int a[SIZE]) {
	for (int i = 0; i < SIZE; i++) 
		cout << a[i] << " ";	
	cout << endl;
}
void main() {
	setlocale(LC_ALL, "rus");
	srand(time(0));
	int ourArr[SIZE];
	int choice ;
	bool flag = true;
	for (int i = 0; i < SIZE; i++)
		ourArr[i] = rand() % 21; //Инициализируем массив
	cout << "Исходный массив:\n";
	printOurArr(ourArr); // Вызов функции вывода массива
	do {
		cout << "Выберите число из массива ";
		cin >> choice;
		int i;
		for (i = 0; i < SIZE; i++)
			if (ourArr[i] == choice ) break;

		if (i == SIZE) {
			cout << "Такого числа нет в массиве!!!\n";
			flag = false;
		}
	} while (!flag);

	/*
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
	*/
	system("pause");
}
