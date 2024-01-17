#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

class SuperPrimeNumberGenerator {
public:
    SuperPrimeNumberGenerator(int n) : limit(n) {}

    std::vector<int> GenerateSuperPrimeNumbers() {
        std::vector<int> result;
        std::queue<int> q;

        // Bắt đầu với các chữ số từ 2 đến 9
        for (int i = 2; i <= 9; ++i) {
            q.push(i);
            result.push_back(i);
        }

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int i = 1; i <= 9; i += 2) {
                int next = current * 10 + i;
                if (next <= limit && IsPrime(next)) {
                    q.push(next);
                    result.push_back(next);
                }
            }
        }

        return result;
    }

private:
    bool IsPrime(int num) {
        if (num < 2) {
            return false;
        }

        for (int i = 2; i <= sqrt(num); ++i) {
            if (num % i == 0) {
                return false;
            }
        }

        return true;
    }

    int limit;
};

int main() {
    int n;
    std::cout << "Input: ";
    std::cin >> n;

    SuperPrimeNumberGenerator generator(n);
    std::vector<int> superPrimes = generator.GenerateSuperPrimeNumbers();

    std::cout << "Output: ";
    for (int prime : superPrimes) {
        std::cout << prime << " ";
    }

    return 0;
}
