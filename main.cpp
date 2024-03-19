#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;

// Функція розподілу динамічної пам'яті
template <typename T>
T* allocate_memory(size_t size) {
    return new T[size];
}

// Функція ініціалізації динамічного масиву
template <typename T>
void initialize_array(T* array, size_t size) {
    srand(time(0)); 
    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

// Функція друку динамічного масиву
template <typename T>
void print_array(T* array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Функція видалення динамічного масиву
template <typename T>
void delete_array(T* array) {
    delete[] array;
}

// Функція додавання елемента в кінець масиву
template <typename T>
bool push_back(T*& array, size_t& size, T value) {
    T* new_array = allocate_memory<T>(size + 1);
    if (new_array == nullptr) {
        return false;
    }
    for (size_t i = 0; i < size; i++) {
        new_array[i] = array[i];
    }
    new_array[size] = value;
    delete_array(array);
    array = new_array;
    size++;
    return true;
}

// Функція вставки елемента за вказаним індексом
template <typename T>
bool insert_element(T*& array, size_t& size, T value, size_t index) {
    if (index > size) {
        return false;
    }
    T* new_array = allocate_memory<T>(size + 1);
    if (new_array == nullptr) {
        return false;
    }
    for (size_t i = 0; i < index; i++) {
        new_array[i] = array[i];
    }
    new_array[index] = value;
    for (size_t i = index; i < size; i++) {
        new_array[i + 1] = array[i];
    }
    delete_array(array);
    array = new_array;
    size++;
    return true;
}

// Функція видалення елемента за вказаним індексом
template <typename T>
bool delete_element(T*& array, size_t& size, size_t index) {
    if (index >= size) {
        return false;
    }
    T* new_array = allocate_memory<T>(size - 1);
    if (new_array == nullptr) {
        return false;
    }
    for (size_t i = 0; i < index; i++) {
        new_array[i] = array[i];
    }
    for (size_t i = index + 1; i < size; i++) {
        new_array[i - 1] = array[i];
    }
    delete_array(array);
    array = new_array;
    size--;
    return true;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    size_t size;
    cout << "Введіть довжину масива: ";
    cin >> size;

    // Розподіл та ініціалізація динамічного масиву
    int* array = allocate_memory<int>(size);
    initialize_array(array, size);

    // Друкуємо динамічний масив
    cout << "Масив: ";
    print_array(array, size);

    // Додавання елемента в кінець масиву
    int valueToAdd = 99;
    cout << "Додаємо елемент " << valueToAdd << " в кінець масиву..." << endl;
    if (push_back(array, size, valueToAdd)) {
        cout << "Масив після додавання: ";
        print_array(array, size);
    }
    else {
        cout << "Помилка під час додавання елемента." << endl;
    }

    // Вставка елемента за вказаним індексом
    int valueToInsert = 55;
    size_t indexToInsert = 2;
    cout << "Вставляємо елемент " << valueToInsert << " за індексом " << indexToInsert << "..." << endl;
    if (insert_element(array, size, valueToInsert, indexToInsert)) {
        cout << "Масив після вставки: ";
        print_array(array, size);
    }
    else {
        cout << "Помилка під час вставки елемента." << endl;
    }

    // Видалення елемента за вказаним індексом
    size_t indexToDelete = 1;
    cout << "Видаляємо елемент за індексом " << indexToDelete << "..." << endl;
    if (delete_element(array, size, indexToDelete)) {
        cout << "Масив після видалення: ";
        print_array(array, size);
    }
    else {
        cout << "Помилка під час видалення елемента." << endl;
    }

    // Звільнення пам'яті, яка була виділена для масиву
    delete_array(array);

    return 0;
}
