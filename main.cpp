#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}


int* remove_primes(int* array, size_t size, size_t& new_size) {
    
    size_t count = 0;
    for (size_t i = 0; i < size; i++) {
        if (!is_prime(array[i])) {
            count++;
        }
    }

    int* new_array = new int[count];
    size_t index = 0;
    for (size_t i = 0; i < size; i++) {
        if (!is_prime(array[i])) {
            new_array[index++] = array[i];
        }
    }

    
    new_size = count;

    return new_array;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const size_t size = 10;
    int array[size] = { 4, 7, 8, 9, 10, 1, 14, 15, 16, 18 };


    cout << "Оригінальний масив: ";
    for (size_t i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    size_t new_size = 0;
    int* new_array = remove_primes(array, size, new_size);

    cout << "Масив після видалення простих чисел: ";
    for (size_t i = 0; i < new_size; i++) {
        cout << new_array[i] << " ";
    }
    cout << endl;

    
    delete[] new_array;

    return 0;
}
