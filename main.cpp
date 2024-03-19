#include <iostream>
#include <Windows.h>

void select(int* array, int size) {
    int* dod = new int[size];
    int* vid = new int[size];
    int* zero = new int[size];
    int k_dod = 0;
    int k_vid = 0;
    int k_zero = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] > 0) {
            dod[k_dod] = array[i];
            k_dod++;
        }
        else if (array[i] < 0) {
            vid[k_vid] = array[i];
            k_vid++;
        }
        else {
            zero[k_zero] = array[i];
            k_zero++;
        }
    }

    std::cout << "Додатні елементи: ";
    for (int i = 0; i < k_dod; i++) {
        std::cout << dod[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Від'ємні елементи: ";
    for (int i = 0; i < k_vid; i++) {
        std::cout << vid[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Нульові елементи: ";
    for (int i = 0; i < k_zero; i++) {
        std::cout << zero[i] << " ";
    }
    std::cout << std::endl;

    delete[] dod;
    delete[] vid;
    delete[] zero;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int array[] = { 3, -1, 0, 5, -2, 0 };
    int size = sizeof(array) / sizeof(array[0]);
    select(array, size);
    return 0;
}