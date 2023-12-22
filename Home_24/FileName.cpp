#include <iostream>
#include <cstdlib>
#include <ctime>


void fill_arr(int arr[], int size, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (max - min) + min;
}

template <typename T>
void show_arr(T arr[], int size) {
	std::cout << "[";
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}

void resize_arr(int arr[], int size, int new_size) {
	int *F = new int[new_size];
	if (new_size < size)
	for (int i = 0; i < new_size; i++)
		F[i] = arr[i];
	else
		if (new_size > size) 
			for (int i = 0; i < size; i++)
				F[i] = arr[i];
	for (int i = size; i < new_size; i++) {
		int* ptr = &arr[i];
		arr [i] = rand() % (50 - 10) + 10;
		F[i] = *(ptr + i);
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

// Задание 1
int n, m,k;
std::cout << "Введите длины массивов: ";
std::cin >> n >> m;
int* A = new int[n];
int* B = new int[m];

fill_arr (A, n, 15, 38);
fill_arr (B, m, 59, 65);

std:: cout << "Массив A:\n";
show_arr(A, n);
std::cout << "Массив B:\n";
show_arr(B, m);

int* C = new int [n + m];
for (int i = 0; i < n; i++)
	C[i] = A[i];
for (int i = n; i < n + m; i++)
	C[i] = B [i-n];

std::cout << "Массив C:\n";
show_arr(C, n + m);
delete[] A;
delete[] B;

//Задание 2

std::cout << "Введите длину массива: ";
std::cin >> k;
int* D = new int[k];
fill_arr(D, k, 17, 45);
std::cout << "Массив:\n";
show_arr(D, k);

int c;
std::cout << "Введите новую длину массива: ";
std::cin >> c;
resize_arr(D,k,c);
show_arr(D, c);
delete[] D;
return 0;
}
