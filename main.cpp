#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace std;

// ������� �������� �������� ���'��
template <typename T>
T* allocate_memory(size_t size) {
    return new T[size];
}

// ������� ����������� ���������� ������
template <typename T>
void initialize_array(T* array, size_t size) {
    srand(time(0)); 
    for (size_t i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }
}

// ������� ����� ���������� ������
template <typename T>
void print_array(T* array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// ������� ��������� ���������� ������
template <typename T>
void delete_array(T* array) {
    delete[] array;
}

// ������� ��������� �������� � ����� ������
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

// ������� ������� �������� �� �������� ��������
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

// ������� ��������� �������� �� �������� ��������
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
    cout << "������ ������� ������: ";
    cin >> size;

    // ������� �� ����������� ���������� ������
    int* array = allocate_memory<int>(size);
    initialize_array(array, size);

    // ������� ��������� �����
    cout << "�����: ";
    print_array(array, size);

    // ��������� �������� � ����� ������
    int valueToAdd = 99;
    cout << "������ ������� " << valueToAdd << " � ����� ������..." << endl;
    if (push_back(array, size, valueToAdd)) {
        cout << "����� ���� ���������: ";
        print_array(array, size);
    }
    else {
        cout << "������� �� ��� ��������� ��������." << endl;
    }

    // ������� �������� �� �������� ��������
    int valueToInsert = 55;
    size_t indexToInsert = 2;
    cout << "���������� ������� " << valueToInsert << " �� �������� " << indexToInsert << "..." << endl;
    if (insert_element(array, size, valueToInsert, indexToInsert)) {
        cout << "����� ���� �������: ";
        print_array(array, size);
    }
    else {
        cout << "������� �� ��� ������� ��������." << endl;
    }

    // ��������� �������� �� �������� ��������
    size_t indexToDelete = 1;
    cout << "��������� ������� �� �������� " << indexToDelete << "..." << endl;
    if (delete_element(array, size, indexToDelete)) {
        cout << "����� ���� ���������: ";
        print_array(array, size);
    }
    else {
        cout << "������� �� ��� ��������� ��������." << endl;
    }

    // ��������� ���'��, ��� ���� ������� ��� ������
    delete_array(array);

    return 0;
}
