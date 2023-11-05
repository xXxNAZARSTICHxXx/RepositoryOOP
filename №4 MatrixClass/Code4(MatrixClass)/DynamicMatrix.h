 ///Стич Назар Иванович ИВТ-22 (КЛАССЫ)
///Заголовочный файл - файл хранящий класс МАТРИЦЫ
#include <string>                                               //Подключение библиотеки для работы с строками

class DynamicMatrix                                             //Класс матрицы
{                                           
public:
    int rows;                                                   //Открытое поле для доступа к числу строк
    int cols;                                                   //Открытое поле для доступа к числу столбцов
    DynamicMatrix(int rows, int cols);                          ///Метод инициализации матрицы
    void setElement(int row, int col, int value);               ///Метод замены отдельного числа в матрице
    int getElement(int row, int col);                           ///Метод получения элемента из матрицы
    void saveToFile(const std::string& filename);               ///Метод загрузки матрицы из файла
    void loadFromFile(const std::string& filename);             ///Метод загрузки матрицы в файл
    ~DynamicMatrix();                                           ///Деструктор матрицы

private:
    int **matrix;                                               //Матрица, которую нельзя напрямую изменить
};