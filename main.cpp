#include <iostream>
#include <Windows.h>
#include <vector>
#include <conio.h>

using namespace std;

void calc(const int* array, int size, int* sum_ptr, int* dobutok_ptr) {
    int sum = 0;
    int dobutok = 1;

    
    for (int i = 0; i < size; i++) {
        sum += array[i];
        dobutok *= array[i];
    }

    
    *sum_ptr = sum;
    *dobutok_ptr = dobutok;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum, dobutok;

    
    calc(arr, size, &sum, &dobutok);

    
    cout << "   Сума: " << sum << endl;
    cout << "Добуток: " << dobutok << endl;
    _getch();
    return 0;
}
