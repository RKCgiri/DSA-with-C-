#include <iostream>
#include <cmath>

// Function to calculate the nth Fibonacci number using the golden ratio
int fibonacciGoldenRatio(int n) {
    const double phi = (1 + sqrt(5)) / 2;  // Golden ratio

    return static_cast<int>(round((pow(phi, n) - pow(1 - phi, n)) / sqrt(5)));
}

int main() {
    int n;

    // Get the position of the Fibonacci number to calculate
    std::cout << "Enter the position (n) of the Fibonacci number to calculate: ";
    std::cin >> n;

    // Calculate and display the nth Fibonacci number using the golden ratio
    int fib_n = fibonacciGoldenRatio(n);
    std::cout << "Fibonacci number at position " << n << ": " << fib_n << "\n";

    return 0;
}
