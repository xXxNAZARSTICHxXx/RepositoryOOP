///Стич Назар Иванович ИВТ-22 (КЛАССЫ)
///Модульный файл - хранит все методы реализации класса                
#include <iostream>                                                                     //Подключение библиотеки для ввода и вывода
#include <fstream>                                                                      //Подключение библиотеки для ввода и вывода, а также работы с файлом
#include <clocale>                                                                      //Подключение библиотеки для изменения кодировки текста
#include "DynamicMatrix.h"                                                              //Подключение собственноого заголовочного файла~Класса для работы с кодом  

DynamicMatrix::DynamicMatrix(int rows, int cols) : rows(rows), cols(cols)               ///Метод инициализации матрицы
{ 
    matrix = new int*[rows];                                                            //Выделение памяти на строки
    for (int i = 0; i < rows; i++) {                                                    //Проход по строкам
        matrix[i] = new int[cols];                                                      //Выделение памяти на столбцы
        for (int j = 0; j < cols; j++) {                                                //Проход по столбцам
            matrix[i][j] = 0;                                                           //Заполнение матрицы
        }
    }
}

void DynamicMatrix::setElement(int row, int col, int value)                             ///Метод замены отдельного числа в матрице
{
    if (row >= 0 && row < rows && col >= 0 && col < cols) {                             //Проверка на правильное введение позиций в диапазоне
        matrix[row][col] = value;                                                       //Присвоение значения
    } 
    else {
        std::cout << "Неправильно введенное кол-во строк или столбцов" << std::endl;    //Вывод строки "Неправильно введенное кол-во строк или столбцов"
    }
}

int DynamicMatrix::getElement(int row, int col)                                         ///Метод получения элемента из матрицы
{
    if (row >= 0 && row < rows && col >= 0 && col < cols) {                             //Проверка на правильное введение позиций в диапазоне
        return matrix[row][col];                                                        //Возврат значения
    } 
    else {
        std::cout << "Неправильно введенное кол-во строк или столбцов" << std::endl;    //Вывод строки "Неправильно введенное кол-во строк или столбцов"
        return 0;                                                                       //Возврат 0 - т.к. функция принимает значение int
    }
}

void DynamicMatrix::saveToFile(const std::string& filename)                             ///Метод загрузки матрицы из файла
{
    std::ofstream file(filename);                                                       //Открытие файла на запись
    if (file.is_open()) {                                                               //Если файл открыт
        file << rows << " " << cols << "\n";                                            //Запись кол-во строк и столбцов
        for (int i = 0; i < rows; i++) {                                                //Проход по строкам
            for (int j = 0; j < cols; j++) {                                            //Проход по столбцам
                file << matrix[i][j] << " ";                                            //Запись матрицы
            }
            file << "\n";                                                               //Переход на следующую строку
        }
        file.close();                                                                   //Закрытие файла
    } 
    else {
        std::cout << "Файл не может быть открыт" << std::endl;                          //Вывод строки "Файл не может быть открыт"
    }
}

void DynamicMatrix::loadFromFile(const std::string& filename)                           ///Метод загрузки матрицы в файл
{
    std::ifstream file(filename);                                                       //Открытие файла на чтение
    if (file.is_open()) {                                                               //Если файл открыт
        file >> rows >> cols;                                                           //Считывание кол-во строк и столбцов
        matrix = new int*[rows];                                                        //Создание матрицы ~ выделение памяти
        for (int i = 0; i < rows; i++) {                                                //Проход по строкам
            matrix[i] = new int[cols];                                                  //Создание матрицы ~ выделение памяти
            for (int j = 0; j < cols; j++) {                                            //Проход по столбцам
                file >> matrix[i][j];                                                   //Чтение матрицы
            }
        }
        file.close();                                                                   //Закрытие файла
    } 
    else {
        std::cout << "Файл не может быть открыт" << std::endl;                          //Вывод строки "Файл не может быть открыт"
    }
}

DynamicMatrix::~DynamicMatrix()                                                         //Деструктор матрицы
{
    for (int i = 0; i < rows; i++) {                                                    //Проход по строкам
        delete[] matrix[i];                                                             //Освобождение памяти по строкам
    }
    delete[] matrix;                                                                    //Освобождение памяти
}   