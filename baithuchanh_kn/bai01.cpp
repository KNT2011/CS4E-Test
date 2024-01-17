#include <iostream>
#include <vector>

class DivisorSumCalculator {
public:
    DivisorSumCalculator(int n) : number(n) {}

    int calculateSumOfDivisors() const {
        int divisorsSum = 0;
        for (int i = 1; i <= number; ++i) {
            if (number % i == 0) {
                divisorsSum += i;
            }
        }
        return divisorsSum;
    }

private:
    int number;
};

int main() {
    int T; // S? l??ng test case
    std::cin >> T;

    for (int i = 0; i < T; ++i) {
        int n;
        std::cin >> n;

        DivisorSumCalculator calculator(n);
        int result = calculator.calculateSumOfDivisors();

        std::cout << result << std::endl;
    }

    return 0;
}
