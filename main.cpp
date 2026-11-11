#include <iostream>

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



int main() {
    int n;
    std::cout << "Введите целое положительное число: ";
    std::cin >> n;
    std::cout << mystery(n) << std::endl;
    std::cout << mysteryFormula(n) << std::endl;
    return 0;
}