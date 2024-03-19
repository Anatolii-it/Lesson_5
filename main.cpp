#include <iostream>
#include <Windows.h>
#include <vector>
#include <conio.h>

using namespace std;

void count_elements(const int* array, int size, int* negativ_ptr, int* positive_ptr, int* zero_ptr) {
    int negativ = 0;
    int positive = 0;
    int zero = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] < 0)
            negativ++;
        else if (array[i] > 0)
            positive++;
        else
            zero++;
    }

    *negativ_ptr = negativ;
    *positive_ptr = positive;
    *zero_ptr = zero;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int arr[] = { 1, 2, 3, -4, 0, -5 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int negativ, positive, zero;

    count_elements(arr, size, &negativ, &positive, &zero);

    cout << "  Негативних чисел: " << negativ << endl;
    cout << "  Позитивних чисел: " << positive << endl;
    cout << "Нуль зустрічається: " << zero << endl;

    _getch();
    return 0;
}
