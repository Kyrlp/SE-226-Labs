#include <iostream>

double power(double base, int exp) {
    if (exp == 0) return 1;
    return base * power(base, exp - 1);
}


double calculate_Gn_cpp(int n, double r) {
    // Base case: r^0 = 1
    if (n == 0) {
        return 1.0;
    }

    return power(r, n) + calculate_Gn_cpp(n - 1, r);
}

int main() {
    int n;
    double r;

    std::cout << "--- Question 4: G_n Series in C++ ---" << std::endl;


    std::cout << "Enter the number of terms (n): ";
    std::cin >> n;

    std::cout << "Enter the common ratio (r): ";
    std::cin >> r;


    double result = calculate_Gn_cpp(n, r);
    std::cout << "Result G_n = " << result << std::endl;

    return 0;
}