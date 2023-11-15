///���� ����� �������� ���-22 (������)
///��������� ���� - ������ ��� ������ ���������� ������                
#include <iostream>                                                                                 //����������� ���������� ��� ����� � ������
#include <fstream>                                                                                  //����������� ���������� ��� ����� � ������, � ����� ������ � ������
#include <clocale>                                                                                  //����������� ���������� ��� ��������� ��������� ������
#include "DynamicMatrix.h"                                                                          //����������� ������������� ������������� �����~������ ��� ������ � �����  

DynamicMatrix::DynamicMatrix() : rows(0), cols(0), matrix(nullptr) {}                               ///����� ������������� �������

DynamicMatrix::DynamicMatrix(int rows, int cols) : rows(rows), cols(cols) {                         ///����� ������������� ������ �������
    matrix = new double*[rows];                                                                     //��������� ������ ��� ������� �� ��������
    for (int i = 0; i < rows; i++) {                                                                //������ �� �������
        matrix[i] = new double[cols];                                                               //��������� ������ ��� ������� �� ��������
    }
    for (int i = 0; i < rows; i++) {                                                                //������ �� �������
        for (int j = 0; j < cols; j++) {                                                            //������ �� ��������
            matrix[i][j] = 0;                                                                       //������������� ������
        }
    }
}

DynamicMatrix::DynamicMatrix(const DynamicMatrix& other) : rows(other.rows), cols(other.cols) {     ///����� ������������� ������������� ������������ �������
    matrix = new double*[rows];                                                                     //��������� ������ ��� ������� �� ��������
    for (int i = 0; i < rows; i++) {                                                                //������ �� �������
        matrix[i] = new double[cols];                                                               //��������� ������ ��� ������� �� ��������
    }
    for (int i = 0; i < rows; i++) {                                                                //������ �� �������
        for (int j = 0; j < cols; j++) {                                                            //������ �� ��������
            matrix[i][j] = other.matrix[i][j];                                                      //������������� ������
        }
    }
}

DynamicMatrix& DynamicMatrix::operator=(const DynamicMatrix& other) {                               ///����� ���������� �������
    if (this != &other) {                                                                           //���� ������ ������� �����������
        for (int i = 0; i < rows; i++) {                                                            //������ �� �������
            delete[] matrix[i];                                                                     //������������ ������� �� ��������
        }
        delete[] matrix;                                                                            //������������ �������
        rows = other.rows;                                                                          //���������� ���-�� ����� ������ �������
        cols = other.cols;                                                                          //���������� ���-�� ����� ������� �������
        matrix = new double*[rows];                                                                 //������������� ������ �� �������
        for (int i = 0; i < rows; i++) {                                                            //������ �� ��������
            matrix[i] = new double[cols];                                                           //������������� ������ �� ��������
        }
        for (int i = 0; i < rows; i++) {                                                            //������ �� �������
            for (int j = 0; j < cols; j++) {                                                        //������ �� ��������
                matrix[i][j] = other.matrix[i][j];                                                  //������������� ������
            }
        }
    }
    return *this;                                                                                   //������� ����� - �������
}

void DynamicMatrix::setElement(int row, int col, int value)                             ///����� ������ ���������� ����� � �������
{
    if (row >= 0 && row < rows && col >= 0 && col < cols) {                             //�������� �� ���������� �������� ������� � ���������
        matrix[row][col] = value;                                                       //���������� ��������
    } 
    else {
        std::cout << "����������� ��������� ���-�� ����� ��� ��������" << std::endl;    //����� ������ "����������� ��������� ���-�� ����� ��� ��������"
    }
}

int DynamicMatrix::getElement(int row, int col)                                         ///����� ��������� �������� �� �������
{
    if (row >= 0 && row < rows && col >= 0 && col < cols) {                             //�������� �� ���������� �������� ������� � ���������
        return matrix[row][col];                                                        //������� ��������
    } 
    else {
        std::cout << "����������� ��������� ���-�� ����� ��� ��������" << std::endl;    //����� ������ "����������� ��������� ���-�� ����� ��� ��������"
        return 0;                                                                       //������� 0 - �.�. ������� ��������� �������� int
    }
}

void DynamicMatrix::saveToFile(const std::string& filename)                             ///����� �������� ������� � ����
{
    std::ofstream file(filename);                                                       //�������� ����� �� ������
    if (file.is_open()) {                                                               //���� ���� ������
        file << rows << " " << cols << "\n";                                            //������ ���-�� ����� � ��������
        for (int i = 0; i < rows; i++) {                                                //������ �� �������
            for (int j = 0; j < cols; j++) {                                            //������ �� ��������
                file << matrix[i][j] << " ";                                            //������ �������
            }
            file << "\n";                                                               //������� �� ��������� ������
        }
        file.close();                                                                   //�������� �����
    } 
    else {
        std::cout << "���� �� ����� ���� ������" << std::endl;                          //����� ������ "���� �� ����� ���� ������"
    }
}

void DynamicMatrix::loadFromFile(const std::string& filename, int& rows, int& cols) {   ///����� �������� ������� �� �����
    std::ifstream file(filename);                                                       //�������� ����� �� ������
    if (!file.is_open()) {                                                              //���� ���� �� ������
        std::cout << "������ �������� �����" << std::endl;                              //����� ������ "������ �������� �����"
        return;                                                                         //����� �� ������
    }
    if (!(file >> rows >> cols)) {                                                      //���� ������ ����������� �� �������
        std::cout << "������ ���������� ����������� �������" << std::endl;              //����� ������ "������ ���������� ����������� �������"
        file.close();                                                                   //�������� �����
        return;                                                                         //����� �� ������
    }
    matrix = new double*[rows];                                                         //������������� ������ �� �������
    for (int i = 0; i < rows; i++) {                                                    //������ �� �������
        matrix[i] = new double[cols];                                                   //������������� ������ �� ��������
        for (int j = 0; j < cols; j++) {                                                //������ �� ��������
            if (!(file >> matrix[i][j])) {                                              //���� ������ �������� ������� �� �������
                std::cout << "������ ���������� �������� �������" << std::endl;         //����� ������ "������ ���������� �������� �������"
                file.close();                                                           //�������� �����
                return;                                                                 //����� �� ������
            }
        }
    }
    file.close();                                                                       //�������� �����
    std::cout << "������� ������� ��������� �� �����" << std::endl;                     //����� ������ 
}

DynamicMatrix DynamicMatrix::add(const DynamicMatrix& other) const {                    ///����� �������� ������� �� �������
    if (rows != other.rows || cols != other.cols) {                                     //���� ����������� �� ���������
        std::cout << "���������� ������� ������� ������ ������������" << std::endl;     //����� ������ "���������� ������� ������� ������ ������������"
        return DynamicMatrix(0, 0);                                                     //������� ������� �������
    }
    DynamicMatrix result(rows, cols);                                                   //���������� ���-�� ����� � �������� � �������
    for (int i = 0; i < rows; i++) {                                                    //������ �� �������
        for (int j = 0; j < cols; j++) {                                                //������ �� ��������
            result.setElement(i, j, matrix[i][j] + other.matrix[i][j]);                 //��������� � �������� ��������� �������
        }
    }
    return result;                                                                      //������� ��������� �������
}

DynamicMatrix DynamicMatrix::subtract(const DynamicMatrix& other) const {               ///����� �������� ������� �� �������
    if (rows != other.rows || cols != other.cols) {                                     //���� ����������� �� ���������
        std::cout << "���������� ������� ������� ������ ������������" << std::endl;     //����� ������ "���������� ������� ������� ������ ������������"
        return DynamicMatrix(0, 0);                                                     //������� ������� �������
    }
    DynamicMatrix result(rows, cols);                                                   //���������� ���-�� ����� � �������� � �������
    for (int i = 0; i < rows; i++) {                                                    //������ �� �������
        for (int j = 0; j < cols; j++) {                                                //������ �� ��������
            result.setElement(i, j, matrix[i][j] + other.matrix[i][j]);                 //��������� � ��������� ��������� �������
        }
    }
    return result;                                                                      //������� �������� ������
}

void DynamicMatrix::multiplyByScalar(int scalar) {                                      ///����� ��������� ������� �� �����
    for (int i = 0; i < rows; i++) {                                                    //������ �� �������
        for (int j = 0; j < cols; j++) {                                                //������ �� ��������
            matrix[i][j] *= scalar;                                                     //��������� ������ ������ �� �����
        }
    }
}

void DynamicMatrix::multiplyByMatrix(const DynamicMatrix& otherMatrix) {                ///����� ��������� ������� �� �������
    if (cols != otherMatrix.rows) {                                                     //���� ���� ������������ ����� ������ ������� � �������� ������ �������
        std::cout << "���������� �������� �������: ����� �������� ������ ������� �� ����� ����� ����� ������ �������" << std::endl;         //����� ������ "���������� �������� �������: ����� �������� ������ ������� �� ����� ����� ����� ������ �������"
        return;                                                                         //����� �� ������
    }
    DynamicMatrix result(rows, otherMatrix.cols);                                       //���������� ����� ������ ������� � �������� ������ �������
    for (int i = 0; i < rows; i++) {                                                    //������ �� ������� �������
        for (int j = 0; j < otherMatrix.cols; j++) {                                    //������ �� �������� ������ �������
            for (int k = 0; k < cols; k++) {                                            //������ �� �������� �������
                result.matrix[i][j] += matrix[i][k] * otherMatrix.matrix[k][j];         //��������� �������
            }
        }
    }
    *this = result;                                                                     //������� �������
}

void DynamicMatrix::transpose() {                                                       ///����� ���������������� �������
    DynamicMatrix result(cols, rows);                                                   //���������� ���-�� ����� � �������� � �������
    for (int i = 0; i < rows; i++) {                                                    //������ �� �������
        for (int j = 0; j < cols; j++) {                                                //������ �� ��������
            result.matrix[j][i] = matrix[i][j];                                         //�������������� �������� ������
        }
    }
    *this = result;                                                                     //������� �������
}

int DynamicMatrix::Determinant() {                                                      ///����� ���������� ������������
    if (rows == cols) {                                                                 //���� ������� ����������
        DynamicMatrix temp(*this);                                                      //����������� �������

        //���������� ������������
        int det = 1;                                                                    //������� 1 ��� ������������ ��� ���������         
        for (int i = 0; i < rows - 1; i++) {                                        
            for (int j = i + 1; j < rows; j++) {                                    
                int factor = temp.matrix[j][i] / temp.matrix[i][i];                 
                for (int k = 0; k < cols; k++) {                                     
                    temp.matrix[j][k] -= factor * temp.matrix[i][k];                   
                }
            }
        }
        for (int i = 0; i < rows; i++) {                                              
            det *= temp.matrix[i][i];                                                  
        }

        return det;                                                                     //������� ������������                                                              
    } else {
        std::cout << "���������� ��������� ������������: ������� �� ����������" << std::endl;      //����� ������ ���������� ��������� ������������: ������� �� ����������
        return 0;                                                                       //����� �� ������
    }
}

void DynamicMatrix::invertToDiagonal() {                                                ///����� ���������� ������������ �������
    // ���������, ��� ������� ���������� (����� ����� ����� ����� ��������)
    if (rows != cols) {
        std::cerr << "������: ������� �� ����������. ���������� ������������� � ������������" << std::endl;
        return;
    }

    // ��������� ����� ������
    for (int i = 0; i < rows; i++) {
        //������� ������������ ������� � ������� �������
        int maxRowIndex = i;
        for (int k = i + 1; k < rows; k++) {
            if (abs(matrix[k][i]) > abs(matrix[maxRowIndex][i])) {
                maxRowIndex = k;
            }
        }

        //���������� ������� ������ � �������, ���������� ������������ �������
        for (int k = 0; k < cols; k++) {
            std::swap(matrix[i][k], matrix[maxRowIndex][k]);
        }

        //�������� ������� ������ � ���������� ����
        double divisor = matrix[i][i];
        for (int k = 0; k < cols; k++) {
            matrix[i][k] /= divisor;
        }

        //�������� ��� ��������, ����������� ���� � ���� ������� ������
        for (int k = 0; k < rows; k++) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = 0; j < cols; ++j) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }


    //���������� ������� � ������������� ����
    for (int i = rows - 1; i > 0; i--) {
        for (int j = i - 1; j >= 0; j--) {
            int factor = matrix[j][i] / matrix[i][i];
            for (int k = 0; k < cols; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }

    //������������ ���������
    for (int i = 0; i < rows; i++) {
        int factor = matrix[i][i];
        for (int j = 0; j < cols; j++) {
            matrix[i][j] /= factor;
        }
    }
}

DynamicMatrix::~DynamicMatrix()                                                         //���������� �������
{
    for (int i = 0; i < rows; i++) {                                                    //������ �� �������
        delete[] matrix[i];                                                             //������������ ������ �� �������
    }
    delete[] matrix;                                                                    //������������ ������
}  

void DynamicMatrix::printMatrix() const {                                               ///����� ������ �������
    for (int i = 0; i < rows; i++) {                                                    //������ �� �������
        for (int j = 0; j < cols; j++) {                                                //������ �� ��������
            std::cout << matrix[i][j] << " ";                                           //����� �������� �������
        }
        std::cout << std::endl;                                                         //������� �� ��������� ������
    }
}
