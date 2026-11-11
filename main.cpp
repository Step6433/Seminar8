#include <iostream>
#include <utility>

constexpr int maxMatrixSize = 100;

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

void multiply(const double a[][maxMatrixSize],
              const double b[][maxMatrixSize],
              double c[][maxMatrixSize], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void multiplyLocal(const double a[][maxMatrixSize],
                   const double b[][maxMatrixSize],
                   double c[][maxMatrixSize], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            double sum = 0;
            for (int k = 0; k < n; ++k) {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }
}

void multiplyOptimized(const double a[][maxMatrixSize],
                       const double b[][maxMatrixSize],
                       double c[][maxMatrixSize], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            double sum = a[i][0] * b[0][j];
            for (int k = 1; k < n; ++k) {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
        }
    }
}

bool readMatrix(double matrix[][maxMatrixSize], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(std::cin >> matrix[i][j])) {
                return false;
            }
        }
    }
    return true;
}

void printMatrix(const double matrix[][maxMatrixSize], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
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
    double values[maxSize];
    int arraySize;

    std::cout << "Введите количество элементов (от 1 до 1000): ";
    if (!(std::cin >> arraySize) || arraySize < 1 || arraySize > maxSize) {
        std::cout << "Неверное количество элементов.\n";
        return 1;
    }

    std::cout << "Введите элементы массива через пробел:\n";
    for (int i = 0; i < arraySize; ++i) {
        if (!(std::cin >> values[i])) {
            std::cout << "Ошибка ввода.\n";
            return 1;
        }
    }

    std::cout << "Обычная версия: " << secret(values, arraySize) << '\n';
    std::cout << "Попарная версия: " << secretPairs(values, arraySize) << '\n';
    */

    // Задача 3. Проверка симметричности матрицы
    /*
    double matrix[maxMatrixSize][maxMatrixSize];
    int matrixSize;

    std::cout << "Введите порядок матрицы (от 1 до " << maxMatrixSize << "): ";
    if (!(std::cin >> matrixSize) || matrixSize < 1 || matrixSize > maxMatrixSize) {
        std::cout << "Неверный размер матрицы.\n";
        return 1;
    }

    std::cout << "Введите элементы матрицы построчно:\n";
    if (!readMatrix(matrix, matrixSize)) {
        std::cout << "Ошибка ввода.\n";
        return 1;
    }

    if (enigma(matrix, matrixSize)) {
        std::cout << "Матрица симметрична.\n";
    } else {
        std::cout << "Матрица несимметрична.\n";
    }
    */

    // Задача 4. Умножение матриц
    int n;
    std::cout << "Введите порядок матриц (от 1 до " << maxMatrixSize << "): ";
    if (!(std::cin >> n) || n < 1 || n > maxMatrixSize) {
        std::cout << "Неверный размер матриц.\n";
        return 1;
    }

    double a[maxMatrixSize][maxMatrixSize];
    double b[maxMatrixSize][maxMatrixSize];
    double c[maxMatrixSize][maxMatrixSize];

    std::cout << "Введите матрицу A построчно:\n";
    if (!readMatrix(a, n)) {
        std::cout << "Ошибка ввода матрицы A.\n";
        return 1;
    }

    std::cout << "Введите матрицу B построчно:\n";
    if (!readMatrix(b, n)) {
        std::cout << "Ошибка ввода матрицы B.\n";
        return 1;
    }

    multiply(a, b, c, n);
    std::cout << "Обычная версия:\n";
    printMatrix(c, n);

    multiplyLocal(a, b, c, n);
    std::cout << "Версия с локальной суммой:\n";
    printMatrix(c, n);

    multiplyOptimized(a, b, c, n);
    std::cout << "Оптимизированная версия:\n";
    printMatrix(c, n);

    return 0;
}