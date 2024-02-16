﻿//Стич Назар Иванович ИВТ-22
// Напишите программу, которая по данному списку чисел и среднему значению этих чисел определяет, 
// превышает ли число элементов списка, больших среднего значения, число элементов, меньших этого значения, 
// или наоборот.Опишите группы, на которые распадаются возможные наборы входных данных.Какой случай для 
// алгоритма является наилучшим ? Наихудшим ? Средним ? (Если наилучший и наихудший случаи совпадают, 
// то перепишите Ваш алгоритм так, чтобы он останавливался, как только ответ на поставленный вопрос 
// становится известным, делая наилучший случай лучше наихудшего.) Результаты тестирования вывести в текстовый файл.

#include <iostream>
#include <vector>
#include <fstream>
#include <time.h> 
#include <ctime>

#include "T1Names.h"

using namespace std; // Для использования пространства имен std

// Функция для определения того, превышает ли количество элементов, больших среднего; количество элементов, меньших среднего, или наоборот
void compareCounts(int* arr, int n, double average, const string& filename) {
    int aboveCount = 0;                                                         //Переменная для хранения кол-ва чисел превышающих среднее число
    int belowCount = 0;                                                         //Переменная для хранения кол-ва чисел не превышающих среднее число

    for (int i = 0; i < n; i++) {                                               //Подсчет сравнений
        if (arr[i] > average) {
            aboveCount++;
        }
        else if (arr[i] < average) {
            belowCount++;
        }
    }

    ofstream outFile(filename);
    if (!outFile.is_open()) {
        throw runtime_error("Unable to open output file!");                     // Бросаем исключение в случае ошибки открытия файла
    }                                                                           // И выводим результат с последующим серединным числом и массивом

    if (aboveCount > belowCount) {
        outFile << ">>> Число элементов, превышающих среднее, больше числа элементов, меньших среднего" << endl;
        outFile << ">>> Серединное число: " << average << endl;
        if (!outFile.is_open()) {
            throw runtime_error("Ошибка открытия файла для записи");
        }
        for (int i = 0; i < n; i++) {
            outFile << arr[i] << " ";
        }
    }
    else if (aboveCount < belowCount) {
        outFile << ">>> Число элементов, превышающих среднее, меньше числа элементов, меньших среднего" << endl;
        outFile << ">>> Серединное число: " << average << endl;
        if (!outFile.is_open()) {
            throw runtime_error("Ошибка открытия файла для записи");
        }
        for (int i = 0; i < n; i++) {
            outFile << arr[i] << " ";
        }
    }
    else {
        outFile << ">>> Число элементов, превышающих среднее, равно числу элементов, меньших среднего" << endl;
        outFile << ">>> Серединное число: " << average << endl;
        if (!outFile.is_open()) {
            throw runtime_error("Ошибка открытия файла для записи");
        }
        for (int i = 0; i < n; i++) {
            outFile << arr[i] << " ";
        }
    }

    outFile.close();
}

int main() {
    setlocale(LC_ALL, "russian");
    const string fname = "result.txt";                                          //Название файла - constant переменная fname
    int n, min, max;															//n - длина массива,min - минимальный диапазон случайных чисел,max - максимальный диапазон случайных чисел
    n = array_size();															//Определение длины массива
    random_diaposon(min, max);													//min, max - минимальный и максимальный диапазоны случайных чисел (Функция указывает диапазоны)
    int* arr = new int[n];														//Создание массива
    filling_array(n, min, max, arr);                                            //Заполнение массива

    float sum = 0;                                                              //Переменная для подсчета суммы для нахождения среднего числа
    for (int i = 0; i < n; i++) {                                               //Вычисление среднего значения
        sum += arr[i];
    }
    float average = sum / n;                                                    //Переменная для нахождения среднего числа 

    try {
        compareCounts(arr, n, average, fname);                                  //Сравнение количества элементов больших и меньших среднего значения
    }
    catch (const exception& e) {
        cerr << e.what() << endl;                                               //Выводим сообщение об ошибке если файл не открылся
    }

    delete[n] arr;                                                              //Освобождаем выделенную память

    return 0;
}
