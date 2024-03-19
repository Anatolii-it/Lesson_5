#include <iostream>
#include <Windows.h>

using namespace std;

void split_array(int* array, size_t size, int*& positive_array, size_t& positive_size,
    int*& negative_array, size_t& negative_size, int*& zero_array, size_t& zero_size) {
    size_t positive = 0;
    size_t negative = 0;
    size_t zero = 0;

    for (size_t i = 0; i < size; i++) {
        if (array[i] > 0) {
            positive++;
        }
        else if (array[i] < 0) {
            negative++;
        }
        else {
            zero++;
        }
    }

    positive_size = positive;
    negative_size = negative;
    zero_size = zero;

    positive_array = new int[positive_size];
    negative_array = new int[negative_size];
    zero_array = new int[zero_size];

    size_t positive_index = 0;
    size_t negative_index = 0;
    size_t zero_index = 0;

    for (size_t i = 0; i < size; i++) {
        if (array[i] > 0) {
            positive_array[positive_index++] = array[i];
        }
        else if (array[i] < 0) {
            negative_array[negative_index++] = array[i];
        }
        else {
            zero_array[zero_index++] = array[i];
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const size_t size = 10;
    int array[size] = { 3, -2, 0, 5, -7, 0, 8, -4, 6, 0 };

    int* positive_array;
    size_t positive_size;
    int* negative_array;
    size_t negative_size;
    int* zero_array;
    size_t zero_size;

    split_array(array, size, positive_array, positive_size, negative_array, negative_size, zero_array, zero_size);

    cout << "Додатні елементи: ";
    for (size_t i = 0; i < positive_size; i++) {
        cout << positive_array[i] << " ";
    }
    cout << endl;

    cout << "Від'ємні елементи: ";
    for (size_t i = 0; i < negative_size; i++) {
        cout << negative_array[i] << " ";
    }
    cout << endl;

    cout << "Нульові елементи: ";
    for (size_t i = 0; i < zero_size; i++) {
        cout << zero_array[i] << " ";
    }
    cout << endl;

   
    delete[] positive_array;
    delete[] negative_array;
    delete[] zero_array;

    return 0;
}
