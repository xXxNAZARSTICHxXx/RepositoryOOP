

//�������� ���� ����� ���-22
///������ ���� ������� � ������ ArrayMODULE.cpp
#include <string>		///����������� ���������� string, ��� ������ � ����� �������� �����
using namespace std;	///����������� ������������ std, ����� ��������� ���

///����������� ������������ ���� ArrayFuncs - ������� �������
namespace ArrayFuncs{
///������� ���������� ������� ���������� �������
///n - ���������� ��������� � �������; a - ������������ ��������; b - ����������� ��������; massive - ���������� �������;
void FillArrayRandom(int n, int a, int b, float* massive);	

///������� ���������� ������� ������ ������� - ������
///n - ���������� ��������� � �������; massive - ���������� �������;	
void FillArrayWithHands(int n, float* massive);

///������� ��� ������ �������		
///n - ���������� ��������� � �������; massive - ���������� �������;						
void ShowArrayOfNumbers(int n, float* massive);	

///������� �������� ����� ���� ��������� �������	
///n - ���������� ��������� � �������; massive - ���������� �������;						
float SumArray(int n, float* massive);	

///������� �������� �� ������ (feat. �������� ������������� ��������)							
int input(); 																	

///������� ������ ����� ���� float � �������� ����
///filename - �������� ��������� �����; massive - ���������� �������; n - ���������� ��������� � �������
void writeBinaryFile(const string& filename, float* massive, size_t n);

///������� ������ ������ �� ��������� �����
///filename - �������� ��������� �����; n - ���������� ��������� � �������
float* readBinaryFile(const string& filename, size_t &n);

///������� ������ ��������� �����
///filename - �������� ��������� �����;
void clearBinaryFile(const string& filename);
}
