/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//Выполнил Стич Назар ИВТ-22
#include <iostream>                         //Подключение базовой библиотеки для вывода в командную строку строк
#include <cstdlib>                          //Подключение библиотеки для понимания ifфов
#include <clocale>                          //Подключение библиотеки, которая распознает русский язык при кодировке кирилицей
#include <cassert>                          //Подключение библиотеки assert, которая в будущем будет сбрасывать команду, если будет введена фантасмогория, не соответствующая ожидаемому значению.
#include <fstream>                          //Подключение библиотеки для работы с файлами
#include <string>                           //Подключение библиотеки time для будущего рандомайзера
#include <time.h>                           //Подключение бибственного СПИСКА модулей

#include "ArrayNAMEMODULE.h"                //Подключение соблиотеки string, для работы с путем хранения файла

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//136a Даны натуральное число n, действительные числа a1,..., an. Вычислить: а) a1 + ... + an;

using namespace std;                        //Подключение пространства std, чтобы сократить код
using namespace ArrayFuncs;                 //Подключение собственного пространства имен 

int main(int argc, char *argv[]) {          //ГЛАВНЫЙ МОДУЛЬ с принимаемыми аргументами

    string filename = "data.dat";                           //Название файла
    int t;                                                  //Число для "Ввода вопросов на ответы, задаваемые позже"
    size_t n;                                               //Целые числа - размер массива
    float testarr1[]={50, 100, 150, 200, 250};              //Тестовый массив для assert №1
    float testarr2[]={-50, 50, -50, 50, -50, 50};           //Тестовый массив для assert №2
    float testarr3[]={1.5, 2.25, 1.25, -6.25, -7.5, 10.5};  //Тестовый массив для assert №3
    int a;                                                  //максимальный диапазон для рандома
    int b;                                                  //минимальный диапазон для рандома
    float* arr;                                             //создание массива


    assert ( SumArray(5, testarr1)== 750 );         //заведомо ввожу числа так, чтобы сумма была 750;
    assert ( SumArray(6, testarr2)== 0 );           //заведомо ввожу числа так, чтобы сумма была 0;
    assert ( SumArray(6, testarr3)== 1.75 );        //заведомо ввожу числа так, чтобы сумма была 1.75;


    srand( time(nullptr) );                 //Инициализация генератора случайных чисел
    setlocale(LC_ALL, "Russian");           //изменение кодировки для распознавания русского языка     
    t = atoi(argv[1]);                      //присвоение введенного числа - аргумента - из командной строки

    if (t == 1){                            //если на входе 1
    try {
        arr=readBinaryFile(filename,n);     //открытие файла на чтение
    }
    catch (const runtime_error&e) {         //если срабатывает throw runtime_error
        cerr << e.what() << endl;  //обработка ошибки
       
    }
    }

    if (t == 2){                            //если на входе 2

        cout << "Введите количество элементов: ";       //вывод строчки "Введите количество элементов: "

        do{                                 //проверка на дурака (feat. Владимир Александрович Соловьев)
        cin >> n;                           //ввод размерности массива (почему не input(t), потому что тут другое условие))
        }while(n<1);                        //проверка, что введено => 1

        arr = new float[n];                 //выделение памяти для массива
        cout << "Вы хотите заполнить случайно массив или руками, введите 1 или 2 соответственно: ";     //вывод строчки "Вы хотите заполнить случайно массив или руками, введите 1 или 2 соответственно: "
        
        t=input();                          //проверка на дурака (feat. Владимир Александрович Соловьев)
        if (t == 1){                        //если на входе 1
            cout << "Первое число - MAXимальный диапазон, второе число MINимальный диапазон, введите диапазоны, но " << endl;       //вывод строчки "Первое число - MAXимальный диапазон, второе число MINимальный диапазон, введите диапазоны, но "
            cout << "один из диапазонов ОБЯЗАН БЫТЬ НЕ НУЛЕВЫМ: " << endl;                              //вывод строчки "один из диапазонов ОБЯЗАН БЫТЬ НЕ НУЛЕВЫМ: "
            do{                             //цикл с постусловием
            cin >> a;                       //ввод максимального диапазона
            cin >> b;                       //ввод минимального диапазона
        }while(a==0 && b==0);               //если оба значения были нулевыми
            FillArrayRandom(n, a, b, arr);  //заполнение массива случаными числами
        };
        if (t == 2){                        //если на входе 2
            FillArrayWithHands(n, arr);     //заполнение массива ручным способом
        }
    }

    cout << "Вы хотите увидеть массив, 1 или 2 - да или нет соответственно : ";                         //вывод строчки "Вы хотите увидеть массив, 1 или 2 - да или нет соответственно : "
    
    t=input();                              //проверка на дурака (feat. Владимир Александрович Соловьев)
    if (t == 1){                            //если на входе 1
        cout << "Массив: ";
        ShowArrayOfNumbers(n, arr);         //выовд массива в командную строку
        cout << endl;
    }

    cout << "Вы хотите узнать сумму элементов массива, 1 или 2 - да или нет соответственно : ";     //вывод строчки "Вы хотите узнать сумму элементов массива, 1 или 2 - да или нет соответственно : "
    
    t=input();                              //проверка на дурака (feat. Владимир Александрович Соловьев)
    if (t == 1){                            //если на входе 1
        cout << "Сумма все элементов массива: " << SumArray(n, arr) << endl;                        //суммирование всех элементов массива и вывод значения на экран
    }



    cout << "Вы хотите записать массив в файл, 1 или 2 - да или нет соответственно : "; //вывод строчки "Вы хотите записать массив в файл, 1 или 2 - да или нет соответственно : "

    t=input();                              //проверка на дурака (feat. Владимир Александрович Соловьев)
    if (t == 1){                            //если на входе 1

    try {
        clearBinaryFile(filename);          //очистка файла
    }
    catch (const runtime_error& e) {        //если срабатывает throw runtime_error
        cerr << e.what() << endl;  //обработка ошибки
       
    }


    try {
        writeBinaryFile(filename,arr, n);   //запись массива в файл
    }
    catch (const runtime_error& e) {        //если срабатывает throw runtime_error
        cerr << e.what() << endl;  //обработка ошибки
       
    }


    }
    cout << "Работа завершена, массив стерт";   //вывод строчки "Работа завершена, массив стерт"
    delete[] arr;                               //освобождение памяти после использования массива

    return 0;                               //завершение главной функции - возвратом 0 в командную строку
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/