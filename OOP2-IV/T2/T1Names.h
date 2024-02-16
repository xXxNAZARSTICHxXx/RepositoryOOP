#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <clocale> 
using namespace std;

// ������� ������ ������� �� �����
//template <typename A> ��������� ��� ����, ����� ��������� ������� � ������ ������
//n - ������ �������; arr - ������;
template <typename A>
void show_array(int n, A arr[]) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

// ������� �������� ������� � ���������� ��� ���������� �������
//template <typename A> ��������� ��� ����, ����� ��������� ������� � ������ ������
//n - ������ �������; arr - ������;
template <typename A>
double filling_array(int n, int min, int max, A arr[]) {
	for (int i = 0; i < n; i++) {
		arr[i] = 1.0 * rand() / RAND_MAX * (max - min) + min;
	}
	return *arr;
}

// ������� ����� ����������� �������
int array_size() {
	int n;
	cout << "������� ����������� �������: ";
	cin >> n;
	return n;
}

// ������� ����� ��������� ��������� �����
//template <typename A> ��������� ��� ����, ����� ��������� ������� � ������ ������
//min - ����������� �������� ��������� �����; max - ������������ �������� ��������� ����� ;
void random_diaposon(int& min, int& max) {
	cout << "������� �������� ��������� ����� ��� ���������� ������� MIN, MAX: ";
	cin >> min;
	cin >> max;
}

// ������� ���������� ������� � ����
//template <typename A> ��������� ��� ����, ����� ��������� ������� � ������ ������
//n - ������ �������; arr - ������;�������� ����� - constant ���������� fname
template <typename A>
void save_in_file(int n, A arr[], const string& filename) {
	ofstream outfile(filename);
	if (!outfile.is_open()) {
		throw runtime_error("������ �������� ����� ��� ������");
	}

	for (int i = 0; i < n; i++) {
		if (i % 21 == 20) {
			outfile << "\n";
		}
		outfile << arr[i] << " ";
	}
	outfile.close();
	cout << "\n������ ������� ������� � ����" << endl;
}