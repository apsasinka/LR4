#include <iostream>
#include <vector>

int main() {
    setlocale(LC_ALL, "Russian");
    int n;
    double C;

    // Запрашиваем у пользователя размер массива
    std::cout << "Введите размер массива: ";
    std::cin >> n;

    if (n <= 0) {
        std::cerr << "Размер массива должен быть положительным числом." << std::endl;
        return 1;
    }

    // Запрашиваем у пользователя значение C
    std::cout << "Введите значение C: ";
    std::cin >> C;

    // Создаем динамический массив размером n
    double* arr = new double[n];

    // Заполняем массив элементами
    std::cout << "Введите элементы массива:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    // Инициализируем вектор для хранения индексов элементов, больших C
    std::vector<int> indices;

    // Перебираем элементы массива и находим те, которые больше C
    for (int i = 0; i < n; i++) {
        if (arr[i] > C) {
            indices.push_back(i);
        }
    }

    // Выводим результаты
    if (indices.empty()) {
        std::cout << "Нет элементов, больших " << C << " в массиве." << std::endl;
    }
    else {
        std::cout << "Количество элементов, больших " << C << ": " << indices.size() << std::endl;
        std::cout << "Индексы элементов, больших " << C << ": ";
        for (int i = 0; i < indices.size(); i++) {
            std::cout << indices[i];
            if (i < indices.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }

    // Освобождаем выделенную память
    delete[] arr;

    return 0;
}
