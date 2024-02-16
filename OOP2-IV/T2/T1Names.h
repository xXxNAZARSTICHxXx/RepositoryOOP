#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <clocale> 
using namespace std;

// Функция вывода массива на экран
//template <typename A> требуется для того, чтобы запускать функцию в другом режиме
//n - размер массива; arr - массив;
template <typename A>
void show_array(int n, A arr[]) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

// Функция создание массива м заполнения его случайными числами
//template <typename A> требуется для того, чтобы запускать функцию в другом режиме
//n - размер массива; arr - массив;
template <typename A>
double filling_array(int n, int min, int max, A arr[]) {
	for (int i = 0; i < n; i++) {
		arr[i] = 1.0 * rand() / RAND_MAX * (max - min) + min;
	}
	return *arr;
}

// Функция ввода размерности массива
int array_size() {
	int n;
	cout << "Введите размерность массива: ";
	cin >> n;
	return n;
}

// Функция ввода диапазона случайных чисел
//template <typename A> требуется для того, чтобы запускать функцию в другом режиме
//min - минимальный диапазон случайных чисел; max - максимальный диапазон случайных чисел ;
void random_diaposon(int& min, int& max) {
	cout << "Введите диапазон случайных чисел для заполнения массива MIN, MAX: ";
	cin >> min;
	cin >> max;
}

// Функция сохранения массива в файл
//template <typename A> требуется для того, чтобы запускать функцию в другом режиме
//n - размер массива; arr - массив;Название файла - constant переменная fname
template <typename A>
void save_in_file(int n, A arr[], const string& filename) {
	ofstream outfile(filename);
	if (!outfile.is_open()) {
		throw runtime_error("Ошибка открытия файла для записи");
	}

	for (int i = 0; i < n; i++) {
		if (i % 21 == 20) {
			outfile << "\n";
		}
		outfile << arr[i] << " ";
	}
	outfile.close();
	cout << "\nМассив успешно записан в файл" << endl;
}