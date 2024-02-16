#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <clocale> 
using namespace std;

// ������� ������ ����� � �������
//template <typename A> ��������� ��� ����, ����� ��������� ������� � ������ ������
//n - ������ �������; arr - ������; //x - �����, ������� ������������ � ��������� �������
template <typename A>
string seek_run(size_t n, A arr[], A x) {
	for (int i = 0; i < n; i++)
		if (arr[i] == x) {
			cout << "\n������ ����� " << x << " ������������� �� " << i << " ������� � �������" << endl;
			return "����� ������������";
			break;
		}	
	return "����� �����������";
}

// ������� ���������� ���������
//template <typename A> ��������� ��� ����, ����� ��������� ������� � ������ ������
//n - ������ �������; arr - ������;
template <typename A>
void insertion_sort(size_t n, A arr[]) {
	for (int i = 1; i < n; i++) {
		A key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

// ������� ���������� ��������������
//template <typename A> ��������� ��� ����, ����� ��������� ������� � ������ ������
//n - ������ �������; arr - ������;
template <typename A>
void cocktail_sort(size_t n, A arr[]) {
	bool swapped = true;
	int start = 0;
	int end = n - 1;
	while (swapped) {
		swapped = false;
		for (int i = start; i < end; i++) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}
		if (!swapped) break; 
		swapped = false;
		end--;
		for (int i = end - 1; i >= start; i--) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				swapped = true;
			}
		}
		start++;
	}
}

// ������� ������ ������� � ���� 
//template <typename A> ��������� ��� ����, ����� ��������� ������� � ������ ������
//n - ������ �������; arr - ������; filename - ��� �����
template <typename A>
void save_in_file(size_t n, A arr[], const string& filename) {
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


// ������� ���������� ����� ���������� C++
//template <typename A> ��������� ��� ����, ����� ��������� ������� � ������ ������
//n - ������ �������; arr - ������;
template <typename A>
void algoritm_sort_array(size_t n, A arr[]) {
	sort(arr, arr + n);
}

// ������� ���������� ���������
//template <typename A> ��������� ��� ����, ����� ��������� ������� � ������ ������
//n - ������ �������; arr - ������;
template <typename A>
void bubble_sort(size_t n, A arr[]) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

// ������� ������ ������� �� ����� (�� ������������)
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
//n - ������ �������; arr - ������; //min - ����������� �������� ��������� �����; max - ������������ �������� ��������� �����;
template <typename A>
float filling_array(size_t n, A min, A max, A arr[]) {
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

// ������������� �������� ���������� - ����������� ������ �� �����������
//template <typename A> ��������� ��� ����, ����� ��������� ������� � ������ ������
//n - ������ �������; arr - ������;
template <typename A>
bool is_sorted(size_t n, A arr[]) {
	for (size_t i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1]) {
			return false;
		}
	}
	return true;
}



// Assert ������� - �������� �������
void assert_run() {

	int arr1[] = { 5, 3, 2, 4, 1 };
	int arr2[] = { 5, 2, 3, 1, 4 };
	int arr3[] = { 1, 2, 5, 4, 3 };
	int arr4[] = { 2, 3, 4, 1, 5 };
	int arr7[] = { 5, 3, 4, 1, 5, 3, 9, 2, 5, 27, 4, 42, -5, 0, 1 };
	int expected_arr[] = { 1, 2, 3, 4, 5 };
	int n = 5;
	
	//seek run
	string answ=seek_run<int>(15, arr7, 42);
	assert("����� ������������" == answ);
    answ = seek_run<int>(15, arr7, 128);
	assert("����� �����������" == answ);


	bubble_sort<int>(n, arr1);
	for (int i = 0; i < n; i++) {
		assert(arr1[i] == expected_arr[i]);
	}

	cocktail_sort<int>(n, arr2);
	for (int i = 0; i < n; i++) {
		assert(arr2[i] == expected_arr[i]);
	}

	insertion_sort<int>(n, arr3);
	for (int i = 0; i < n; i++) {
		assert(arr3[i] == expected_arr[i]);
	}

	algoritm_sort_array<int>(n, arr4);
	for (int i = 0; i < n; i++) {
		assert(arr4[i] == expected_arr[i]);
	}

	int arr5[] = { 1, 2, 3, 4, 5 };
	assert(is_sorted(5, arr5) == true);

	int arr6[] = { 5, 3, 2, 4, 1 };
	assert(is_sorted(5, arr6) == false);

}