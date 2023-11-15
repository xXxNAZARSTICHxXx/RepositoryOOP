#include <iostream>
#include <string>
#include "DynamicMatrix.h"

int main() {
    setlocale(LC_ALL, "Russian");                                                                   //��������� ���������
    const std::string fname = "matrix.txt";                                                         //�������� ����������� ����� �����
    const std::string ffname = "matrix2.txt"; 
    int rowsA, colsA, rowsB, colsB;                                                                                 //rows - ������/cols - �������
    int contr = 0;
    DynamicMatrix matrixA, matrixB;

    
    do {
        if (contr == 1) {
            std::cout << "������� �������� ����� ������� A: ";
            std::cin >> rowsA;
            std::cout << "������� �������� �������� ������� A: ";
            std::cin >> colsA;
            matrixA = DynamicMatrix(rowsA, colsA);
            for (int i = 0; i < rowsA; ++i) {
                for (int j = 0; j < colsA; ++j) {
                    int value;
                    std::cout << "������� �������� ��� matrixA[" << i << "][" << j << "]: ";
                    std::cin >> value;
                    matrixA.setElement(i, j, value);
                }
            }
            std::cout << "������� ����� ��� ������������� �������" << std::endl;
            std::cin >> contr;
        }


        if (contr == 2) {
            std::cout << "������� �������� ����� ������� A: ";
            std::cin >> rowsB;
            std::cout << "������� �������� �������� ������� A: ";
            std::cin >> colsB;
            matrixB = DynamicMatrix(rowsB, colsB);
            for (int i = 0; i < rowsB; ++i) {
                for (int j = 0; j < colsB; ++j) {
                    int value;
                    std::cout << "������� �������� ��� matrixA[" << i << "][" << j << "]: ";
                    std::cin >> value;
                    matrixB.setElement(i, j, value);
                }
            }
            std::cout << "������� ����� ��� ������������� �������" << std::endl;
            std::cin >> contr;
        }

    if (contr == 3){

    std::cout << "������� ����� ��� ������������� �������" << std::endl;
    std::cin >> contr;
    }

    if (contr == 4){

    std::cout << "������� ����� ��� ������������� �������" << std::endl;
    std::cin >> contr;
    }

    if (contr == 5){
    matrixA.printMatrix();
    std::cout << "������� ����� ��� ������������� �������" << std::endl;
    std::cin >> contr;
    }

    if (contr == 6){
    matrixB.printMatrix();
    std::cout << "������� ����� ��� ������������� �������" << std::endl;
    std::cin >> contr;
    }

    if (contr == 0){

    std::cout << "������� ����� ��� ������������� �������" << std::endl;
    std::cin >> contr;
    }

    }while(contr!=999);
    std::cout << "��������� ��������� ������!" << std::endl;
    return 0;
}