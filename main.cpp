#include <iostream>
#include <utility>

long long mystery(long long n) {
    long long sum = 0;
    for (long long i = 1; i <= n; ++i) {
        sum += i * i;
    }
    return sum;
}

long long mysteryFormula(long long n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}

double secret(const double a[], int n) {
    double minValue = a[0];
    double maxValue = a[0];

    for (int i = 1; i < n; ++i) {
        if (a[i] < minValue) {
            minValue = a[i];
        }
        if (a[i] > maxValue) {
            maxValue = a[i];
        }
    }

    return maxValue - minValue;
}

double secretPairs(const double a[], int n) {
    double minValue = a[0];
    double maxValue = a[0];
    int i = 1;

    if (n % 2 == 0) {
        maxValue = a[1];
        if (minValue > maxValue) {
            std::swap(minValue, maxValue);
        }
        i = 2;
    }

    while (i < n) {
        double smaller = a[i];
        double larger = a[i + 1];

        if (smaller > larger) {
            std::swap(smaller, larger);
        }
        if (smaller < minValue) {
            minValue = smaller;
        }
        if (larger > maxValue) {
            maxValue = larger;
        }

        i += 2;
    }

    return maxValue - minValue;
}

constexpr int maxMatrixSize = 100;

bool enigma(const double matrix[][maxMatrixSize], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    // Задача 1. Сумма квадратов
    /*
    long long number;
    std::cout << "Введите целое положительное число: ";
    if (!(std::cin >> number) || number <= 0) {
        std::cout << "Неверное число.\n";
        return 1;
    }

    std::cout << "Сумма квадратов (цикл): " << mystery(number) << '\n';
    std::cout << "Сумма квадратов (формула): " << mysteryFormula(number) << '\n';
    */

    // Задача 2. Размах массива
    /*
    const int maxSize = 1000;
    double a[maxSize];
    int arraySize;

    std::cout << "Введите количество элементов (от 1 до 1000): ";
    if (!(std::cin >> arraySize) || arraySize < 1 || arraySize > maxSize) {
        std::cout << "Неверное количество элементов.\n";
        return 1;
    }

    std::cout << "Введите элементы массива через пробел:\n";
    for (int i = 0; i < arraySize; ++i) {
        if (!(std::cin >> a[i])) {
            std::cout << "Ошибка ввода.\n";
            return 1;
        }
    }

    std::cout << "Обычная версия: " << secret(a, arraySize) << '\n';
    std::cout << "Попарная версия: " << secretPairs(a, arraySize) << '\n';
    */

    // Задача 3. Проверка симметричности матрицы
    double matrix[maxMatrixSize][maxMatrixSize];
    int n;

    std::cout << "Введите порядок матрицы (от 1 до " << maxMatrixSize << "): ";
    if (!(std::cin >> n) || n < 1 || n > maxMatrixSize) {
        std::cout << "Неверный размер матрицы.\n";
        return 1;
    }

    std::cout << "Введите элементы матрицы построчно:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(std::cin >> matrix[i][j])) {
                std::cout << "Ошибка ввода.\n";
                return 1;
            }
        }
    }

    if (enigma(matrix, n)) {
        std::cout << "Матрица симметрична.\n";
    } else {
        std::cout << "Матрица несимметрична.\n";
    }

    return 0;
}