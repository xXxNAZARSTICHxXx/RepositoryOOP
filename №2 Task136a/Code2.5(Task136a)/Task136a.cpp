/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//�������� ���� ����� ���-22
#include <iostream>                         //����������� ������� ���������� ��� ������ � ��������� ������ �����
#include <cstdlib>                          //����������� ���������� ��� ��������� if���
#include <clocale>                          //����������� ����������, ������� ���������� ������� ���� ��� ��������� ���������
#include <cassert>                          //����������� ���������� assert, ������� � ������� ����� ���������� �������, ���� ����� ������� �������������, �� ��������������� ���������� ��������.
#include <fstream>                          //����������� ���������� ��� ������ � �������
#include <string>                           //����������� ���������� time ��� �������� ������������
#include <time.h>                           //����������� ������������ ������ �������
#include <vector>                           //����������� vector ��� ������ � ��������

#include "ArrayNAMEMODULE.h"                //����������� ���������� string, ��� ������ � ����� �������� �����
#include "ArrayNewNAMEMODULE.h"                //����������� ���������� string, ��� ������ � ����� �������� �����

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//136a ���� ����������� ����� n, �������������� ����� a1,..., an. ���������: �) a1 + ... + an;

using namespace std;                        //����������� ������������ std, ����� ��������� ���
using namespace ArrayFuncs;                 //����������� ������������ ������������ ���� - � ��������� ������� ����� vector
//using namespace ArrayNewFuncs;            //����������� ������������ ������������ ���� - � ��������� ������� ����� new - ������������ ������ �.� ����� ������������ ����
int main(int argc, char *argv[]) {          //������� ������ � ������������ �����������

    string filename = "data.dat";                           //�������� �����
    int t;                                                  //����� ��� "����� �������� �� ������, ���������� �����"
    size_t n;                                               //����� ����� - ������ �������

    ArrayNewFuncs::RunAllTests();                           // �������� ���� assert ������� ����� ���� �������


    float a;                                                  //������������ �������� ��� �������
    float b;                                                  //����������� �������� ��� �������
    vector<float> arr;                                        //�������� �������

    srand( time(nullptr) );                 //������������� ���������� ��������� �����
    setlocale(LC_ALL, "Russian");           //��������� ��������� ��� ������������� �������� �����     
    t = atoi(argv[1]);                      //���������� ���������� ����� - ��������� - �� ��������� ������

    if (t == 1){                            //���� �� ����� 1
    try {
        arr=readBinaryFile(filename,n);     //�������� ����� �� ������
    }
    catch (const runtime_error&e) {         //���� ����������� throw runtime_error
        cerr << e.what() << endl;  //��������� ������
       
    }
    }

    if (t == 2){                            //���� �� ����� 2

        cout << "������� ���������� ���������: ";       //����� ������� "������� ���������� ���������: "

        do{                                 //�������� �� ������ (feat. �������� ������������� ��������)
        cin >> n;                           //���� ����������� ������� (������ �� input(t), ������ ��� ��� ������ �������))
        }while(n<1);                        //��������, ��� ������� => 1
        arr.resize(n);

        cout << "�� ������ ��������� �������� ������ ��� ������, ������� 1 ��� 2 ��������������: ";     //����� ������� "�� ������ ��������� �������� ������ ��� ������, ������� 1 ��� 2 ��������������: "
        
        t=input();                          //�������� �� ������ (feat. �������� ������������� ��������)
        if (t == 1){                        //���� �� ����� 1
            cout << "������ ����� - MAX�������� ��������, ������ ����� MIN�������� ��������, ������� ���������, �� " << endl;       //����� ������� "������ ����� - MAX�������� ��������, ������ ����� MIN�������� ��������, ������� ���������, �� "
            cout << "���� �� ���������� ������ ���� �� �������: " << endl;                              //����� ������� "���� �� ���������� ������ ���� �� �������: "
            do{                             //���� � ������������
            cin >> a;                       //���� ������������� ���������
            cin >> b;                       //���� ������������ ���������
        }while(a==0 && b==0);               //���� ��� �������� ���� ��������
            FillArrayRandom<float>(a, b, arr);  //���������� ������� ��������� �������
        };
        if (t == 2){                        //���� �� ����� 2
            FillArrayWithHands<float>(arr);     //���������� ������� ������ ��������
        }
    }

    cout << "�� ������ ������� ������, 1 ��� 2 - �� ��� ��� �������������� : ";                         //����� ������� "�� ������ ������� ������, 1 ��� 2 - �� ��� ��� �������������� : "
    
    t=input();                              //�������� �� ������ (feat. �������� ������������� ��������)
    if (t == 1){                            //���� �� ����� 1
        cout << "������: ";
        ShowArrayOfNumbers<float>(arr);         //����� ������� � ��������� ������
        cout << endl;
    }

    cout << "�� ������ ������ ����� ��������� �������, 1 ��� 2 - �� ��� ��� �������������� : ";     //����� ������� "�� ������ ������ ����� ��������� �������, 1 ��� 2 - �� ��� ��� �������������� : "
    
    t=input();                              //�������� �� ������ (feat. �������� ������������� ��������)
    if (t == 1){                            //���� �� ����� 1
        cout << "����� ��� ��������� �������: " << SumArray<float>(arr) << endl;                        //������������ ���� ��������� ������� � ����� �������� �� �����
    }



    cout << "�� ������ �������� ������ � ����, 1 ��� 2 - �� ��� ��� �������������� : "; //����� ������� "�� ������ �������� ������ � ����, 1 ��� 2 - �� ��� ��� �������������� : "

    t=input();                              //�������� �� ������ (feat. �������� ������������� ��������)
    if (t == 1){                            //���� �� ����� 1

    try {
        clearBinaryFile(filename);          //������� �����
    }
    catch (const runtime_error& e) {        //���� ����������� throw runtime_error
        cerr << e.what() << endl;  //��������� ������
       
    }


    try {
        writeBinaryFile<float>(filename,arr);   //������ ������� � ����
    }
    catch (const runtime_error& e) {        //���� ����������� throw runtime_error
        cerr << e.what() << endl;  //��������� ������
       
    }


    }
    cout << "������ ���������, ������ �����";   //����� ������� "������ ���������, ������ �����"  

    return 0;                               //���������� ������� ������� - ��������� 0 � ��������� ������
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/