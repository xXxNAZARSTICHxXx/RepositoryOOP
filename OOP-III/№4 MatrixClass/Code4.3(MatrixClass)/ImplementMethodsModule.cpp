///���� ����� �������� ���-22 (������)
///��������� ���� - ������ ��� ������ ���������� ������                
#include <iostream>                                                                                 //����������� ���������� ��� ����� � ������
#include <fstream>                                                                                  //����������� ���������� ��� ����� � ������, � ����� ������ � ������
#include <clocale>                                                                                  //����������� ���������� ��� ��������� ��������� ������
#include <cstring>
#include <cassert>
#include <vector>
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

DynamicMatrix::DynamicMatrix(const DynamicMatrix& other) : rows(other.rows), cols(other.cols) {
    matrix = new double*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[cols];
    }

    for (int i = 0; i < rows; i++) {
        // ���������� memcpy ��� ����������� ������ � ������ ������
        std::memcpy(matrix[i], other.matrix[i], cols * sizeof(double));
    }
}


DynamicMatrix& DynamicMatrix::operator=(const DynamicMatrix& other) {
    if (this != &other) {
        // ����������� ������� ������
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;

        // ����������� ����� �������
        rows = other.rows;
        cols = other.cols;

        // �������� ����� ������
        matrix = new double*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new double[cols];
        }

        // ���������� memcpy ��� ����������� ������
        for (int i = 0; i < rows; i++) {
            std::memcpy(matrix[i], other.matrix[i], cols * sizeof(double));
        }
    }
    return *this;
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

// no rows, cols
// this->rows, cols to private
void DynamicMatrix::loadFromFile(const std::string& filename, int& rows, int& cols) {   ///����� �������� ������� �� �����
    std::ifstream file(filename);                                                       //�������� ����� �� ������
    if (!file.is_open()) {                                                              //���� ���� �� ������
        std::cout << "������ �������� �����" << std::endl;                              //����� ������ "������ �������� �����"
        return;                                                                         //����� �� ������
    }
    if (!(file >> this->rows >> cols)) {                                                      //���� ������ ����������� �� �������
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

void DynamicMatrix::AddScalar(int scalar) {                                             ///����� �������� ������� � ������
    for (int i = 0; i < rows; i++) {                                                    //������ �� �������
        for (int j = 0; j < cols; j++) {                                                //������ �� ��������
            matrix[i][j] += scalar;                                                     //�������� ������ ������ �� �����
        }
    }
}

void DynamicMatrix::SubtractScalar(int scalar) {                                        ///����� ��������� ������� �� �����
    for (int i = 0; i < rows; i++) {                                                    //������ �� �������
        for (int j = 0; j < cols; j++) {                                                //������ �� ��������
            matrix[i][j] -= scalar;                                                     //��������� ������ ������ �� �����
        }
    }
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

//todo asserts
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

bool DynamicMatrix::operator==(const DynamicMatrix& other) const {
    // ������� ��������� ������� ������
    if (rows != other.rows || cols != other.cols) {
        return false;
    }

    // ����� ���������� ���������� �������
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != other.matrix[i][j]) {
                return false;
            }
        }
    }

    // ���� ������� � ���������� ���������, ������� �����
    return true;
}

    void DynamicMatrix::invertMatrix() const {
        if (rows != cols) {
            std::cerr << "������: ������� �� ����������. ���������� ������������� � ��������" << std::endl;
            return;
        }

        std::vector<std::vector<double>> augmentedMatrix(rows, std::vector<double>(2 * cols, 0.0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                augmentedMatrix[i][j] = matrix[i][j];
                augmentedMatrix[i][j + cols] = (i == j) ? 1.0 : 0.0;
            }
        }

        for (int i = 0; i < rows; i++) {
            double pivot = augmentedMatrix[i][i];

            for (int j = 0; j < 2 * cols; j++) {
                augmentedMatrix[i][j] /= pivot;
            }

            for (int k = 0; k < rows; k++) {
                if (k != i) {
                    double factor = augmentedMatrix[k][i];
                    for (int j = 0; j < 2 * cols; j++) {
                        augmentedMatrix[k][j] -= factor * augmentedMatrix[i][j];
                    }
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = augmentedMatrix[i][j + cols];
            }
        }
    }


void assertcheck(){
    DynamicMatrix FIRST,SECOND,THIRD,COPY;
    int Inter;
    COPY = DynamicMatrix(3, 3);                                                                                                
    FIRST = DynamicMatrix(3, 3);  
    SECOND = DynamicMatrix(3, 3); 
    THIRD = DynamicMatrix(3, 3); 

    for (int i = 0; i < 3; i++)                                             
        for (int j = 0; j < 3; j++)                                                                                       
            FIRST.setElement(i, j, 1);                             
        
    
    for (int i = 0; i < 3; i++)                                             
        for (int j = 0; j < 3; j++)                                                                                         
            SECOND.setElement(i, j, 3);                              


    for (int i = 0; i < 3; i++)                                           
        for (int j = 0; j < 3; j++)                                                                                       
            THIRD.setElement(i, j, 4);                             

    FIRST = FIRST.add(SECOND);                      //�������� ������ �� �������� ������

    assert(FIRST == THIRD); 



    for (int i = 0; i < 3; i++)                                             
        for (int j = 0; j < 3; j++)                                                                                         
            SECOND.setElement(i, j, 8);

    for (int i = 0; i < 3; i++)                                           
        for (int j = 0; j < 3; j++)                                                                                       
            THIRD.setElement(i, j, 12); 

    FIRST = FIRST.subtract(SECOND);

    assert(FIRST == THIRD);                         //�������� ������ �� ��������� ������



    for (int i = 0; i < 3; i++)                                             
        for (int j = 0; j < 3; j++)                                                                                         
            SECOND.setElement(i, j, 108); 

    FIRST.multiplyByScalar(9);                      //�������� ������ �� ��������� ������

    assert(FIRST == SECOND);

    /////////

    for (int i = 0; i < 3; i++)                                             
        for (int j = 0; j < 3; j++)                                                                                       
            SECOND.setElement(i, j, 5);
    FIRST.setElement(0, 0, 1);
    FIRST.setElement(0, 1, 2);
    FIRST.setElement(0, 2, 3);
    FIRST.setElement(1, 0, 4);
    FIRST.setElement(1, 1, 5);
    FIRST.setElement(1, 2, 6);
    FIRST.setElement(2, 0, 7);
    FIRST.setElement(2, 1, 8);
    FIRST.setElement(2, 2, 9);

    FIRST.multiplyByMatrix(SECOND);

    for (int j = 0; j < 3; j++)
        THIRD.setElement(0, j, 30);
    for (int j = 0; j < 3; j++)
        THIRD.setElement(1, j, 75);
    for (int j = 0; j < 3; j++)
        THIRD.setElement(2, j, 120);

    assert(FIRST == THIRD);                         //�������� ��������� ������� �� �������

    FIRST.setElement(0, 0, 1);
    FIRST.setElement(0, 1, 2);
    FIRST.setElement(0, 2, 3);
    FIRST.setElement(1, 0, 4);
    FIRST.setElement(1, 1, 5);
    FIRST.setElement(1, 2, 6);
    FIRST.setElement(2, 0, 7);
    FIRST.setElement(2, 1, 8);
    FIRST.setElement(2, 2, 9);

    SECOND.setElement(0, 0, 1);
    SECOND.setElement(0, 1, 4);
    SECOND.setElement(0, 2, 7);
    SECOND.setElement(1, 0, 2);
    SECOND.setElement(1, 1, 5);
    SECOND.setElement(1, 2, 8);
    SECOND.setElement(2, 0, 3);
    SECOND.setElement(2, 1, 6);
    SECOND.setElement(2, 2, 9);

    FIRST.transpose();                              //�������� ���������������� �������

    FIRST.setElement(0, 0, 23);
    FIRST.setElement(0, 1, 76);
    FIRST.setElement(0, 2, 44);
    FIRST.setElement(1, 0, 11);
    FIRST.setElement(1, 1, 56);
    FIRST.setElement(1, 2, 96);
    FIRST.setElement(2, 0, 44);
    FIRST.setElement(2, 1, 22);
    FIRST.setElement(2, 2, 15);

    Inter = FIRST.Determinant();

    assert(Inter == -37352);                        //�������� ���������� ������������ �������

    FIRST.setElement(0, 0, 8);
    FIRST.setElement(0, 1, 4);
    FIRST.setElement(0, 2, 6);
    FIRST.setElement(1, 0, 2);
    FIRST.setElement(1, 1, 2);
    FIRST.setElement(1, 2, 4);
    FIRST.setElement(2, 0, 0);
    FIRST.setElement(2, 1, 0);
    FIRST.setElement(2, 2, 6);

    SECOND.setElement(0, 0, 1);
    SECOND.setElement(0, 1, 0);
    SECOND.setElement(0, 2, 0);
    SECOND.setElement(1, 0, 0);
    SECOND.setElement(1, 1, 1);
    SECOND.setElement(1, 2, 0);
    SECOND.setElement(2, 0, 0);
    SECOND.setElement(2, 1, 0);
    SECOND.setElement(2, 2, 1);

    FIRST.invertToDiagonal();

    assert(FIRST == SECOND);                        //������� ������� ���������� ������� � ������������� ����

    for (int i = 0; i < 3; i++)                                             
        for (int j = 0; j < 3; j++)                                                                                       
            FIRST.setElement(i, j, 5);                             
    for (int i = 0; i < 3; i++)                                             
        for (int j = 0; j < 3; j++)                                                                                         
            SECOND.setElement(i, j, 8);

    FIRST.AddScalar(3);

    assert(FIRST == SECOND);                        //������� ������� ���������� ������� � �������

    for (int i = 0; i < 3; i++)                                             
        for (int j = 0; j < 3; j++)                                                                                       
            FIRST.setElement(i, j, 17);                             
    for (int i = 0; i < 3; i++)                                             
        for (int j = 0; j < 3; j++)                                                                                         
            SECOND.setElement(i, j, 11);

    FIRST.SubtractScalar(6);

    assert(FIRST == SECOND);                        //������� ������� ��������� ������� � �������
    
    FIRST.setElement(0, 0, 2);
    FIRST.setElement(0, 1, 1);
    FIRST.setElement(0, 2, 1);
    FIRST.setElement(1, 0, 1);
    FIRST.setElement(1, 1, 1);
    FIRST.setElement(1, 2, 0);
    FIRST.setElement(2, 0, 0);
    FIRST.setElement(2, 1, 1);
    FIRST.setElement(2, 2, 0);

    SECOND.setElement(0, 0, 0);
    SECOND.setElement(0, 1, 1);
    SECOND.setElement(0, 2, -1);
    SECOND.setElement(1, 0, 0);
    SECOND.setElement(1, 1, 0);
    SECOND.setElement(1, 2, 1);
    SECOND.setElement(2, 0, 1);
    SECOND.setElement(2, 1, -2);
    SECOND.setElement(2, 2, 1);    

    FIRST.invertMatrix();
    //���������� ���� ������ ������ ������ � ������ � �������
    assert(FIRST == SECOND);                        //������� ������� ��������� �������� �������                                            
}