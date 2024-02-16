#include <iostream>                                                                         
#include <fstream>                                                                                 
#include <clocale>                                                                                 
#include <time.h>                                                                                
#include <stdlib.h>                                                                               
#include <cstdlib>
#include <fstream> 
#include <ctime>
#include <algorithm>
#include <cassert>

#include "T1Names.h"


using namespace std;

// ГЛАВНАЯ ФУНКЦИЯ
int main()
{
	setlocale(LC_ALL, "russian");												//Преобразование русского языка
	assert_run();																//Функция проверки сортировок через assert
	const string first_array= "before_array.txt";								//Имя файла для сохранения массива до сортировок
	const string second_array = "after_array.txt";								//Имя файла для сохранения массива после сортировок
	srand(time(nullptr));														//Создание генератора псевдослучайных чисел
	int n;																		//n - длина массива
	n = array_size();															//определение длины массива
	int min = 1, max = 10000;													//min, max - минимальный и максимальный диапазоны случайных чисел
	int* arr = new int[n];														//Создание массива
	//random_diaposon(min, max);													//Указание диапазонов случайных чисел
	time_t t0 = time(nullptr);													//Определение t0 или его обнуление (таймер)
	filling_array<int>(n, min, max, arr);										//Создание массива и его заполнение 
	//cout << "Время создания массива: " << time(nullptr) - t0 << "\n";			//Вывод времени в секундах создания массива
	t0 = time(nullptr);															//Обнуление таймера

	try {
		save_in_file<int>(n, arr, first_array);									//Сохранение первичного массива в файл
	}
	catch (const exception& e) {
		cerr << e.what() << endl;
	}
														
	//cout << "Время сохранения массива: " << time(nullptr) - t0 << "\n";			//Вывод времени в секундах сохранения массива
	cout << "Введите запрашиваемое число для поиска его в массиве: ";			//Вывод: "Введите запрашиваемое число для поиска его в массиве: "
	int x;																		//Инициализация X - числа для поиска его в массиве
	cin >> x;																	//Ввод числа X

	//t1 = time(nullptr);															//Обнуление таймера
	cout << seek_run<int>(n, arr, x) << endl;													//Поиск числа X в массиве													
	//cout << "Время поиска числа: " << time(nullptr) - t1 << "\n";				//Вывод времени в секундах поиска числа

	//t2 = time(nullptr);															//Обнуление таймера
	algoritm_sort_array<int>(n, arr);												//Сортировка в ставками													
	//cout << "Время сортировки массива: " << time(nullptr) - t2 << "\n";			//Вывод времени в секундах сортировки числел массива

	//t3 = time(nullptr);															//Обнуление таймера
	cout << seek_run<int>(n, arr, x) << endl;													//Поиск числа X в массиве
	//cout << "Время поиска числа: " << time(nullptr) - t3 << "\n";				//Вывод времени в секундах поиска числа

	try {
		save_in_file<int>(n, arr, second_array);								//Сохранение отсортированного массива в файл
	}
	catch (const exception& e) {
		cerr << e.what() << endl;
	}
	cout << "Время работы программы при четырехзначных числах и размером в "<<  n <<" чисел: " << time(nullptr) - t0 << "\n";				//Вывод времени в секундах поиска числа
	cout << "Программа завершилась" << "\n";									//Вывод: "Программа завершилась"
}
