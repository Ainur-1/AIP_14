#include <iostream>
using namespace std;

void ex_1();
void ex_2();
void f(int n);
void Sort(int*arr, int left, int right);

int main() {
	ex_1();
	ex_2();
	return 0;
}

void ex_1() {
	int n = 100;
	cout << 1 << endl;
	f(n);
	cout << endl;
}

void f(int n) {
	if (n == 1) return;
	else if (n % 2) 
	{
		f(n - 1);
		cout << n - 1 << "+1 =" << ' ' << n << '\n';
	}
	else 
	{
		f(n / 2);
		cout << n / 2 << "*2 =" << ' ' << n << '\n';
	}
}

void ex_2() {
    int arr[10] = { 2,6,8,10,9,7,5,4,1,3 };
    Sort(arr, 0, 9);
	for (int i = 0; i < 10; i++) printf("%d	", arr[i]);
}

void Sort(int* arr, int left, int right) {
	int min = 99999,
		max = -1,
		temp, imax, imin;

	for (int i = left; i <= right; i++) { // Поиск индекса наибольшего элемента
		if (arr[i] > max) {
			max = arr[i];
			imax = i;
		}
	}

	// Замена наиболшего элемента с крайне левым элементом
	temp = arr[left];
	arr[left] = arr[imax];
	arr[imax] = temp;

	for (int i = left; i <= right; i++) { // Поиск индекса наименьшего элемента
		if (arr[i] < min) {
			min = arr[i];
			imin = i;
		}
	}
	
	// Замена наименьшего элемента с крайне правым элементом
	temp = arr[right];
	arr[right] = arr[imin];
	arr[imin] = temp;

	// Пока левая и правая грани не столкнуться рекурсивно повторем функцию
	if (abs(left - right) > 1) {
		Sort(arr, left + 1, right - 1); // Уменьшаем грани массива (т.е. ближе к центру)
	}
}
