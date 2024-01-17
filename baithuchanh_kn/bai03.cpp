#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

class StringEncoder {
public:
    StringEncoder(const std::string& input) : originalString(input) {}

    std::string EncodeString() {
        std::stack<char> charStack;
        std::stack<int> countStack;

        for (char c : originalString) {
            if (charStack.empty() || charStack.top() != c) {
                // Ký t? ??u tiên ho?c ký t? khác ký t? trên cùng c?a stack
                charStack.push(c);
                countStack.push(1);
            }
            else {
                // Ký t? gi?ng ký t? trên cùng c?a stack
                int currentCount = countStack.top();
                countStack.pop();
                countStack.push(currentCount + 1);
            }
        }

        std::string encodedString;
        while (!charStack.empty()) {
            encodedString += std::to_string(countStack.top());
            encodedString += charStack.top();
            charStack.pop();
            countStack.pop();
        }

        return encodedString;
    }

private:
    std::string originalString;
};

int main() {
    std::string inputString;
    std::cout << "Nhap vao mot chuoi chi gom ky tu viet thuong: ";
    std::cin >> inputString;

    StringEncoder encoder(inputString);
    std::string encodedString = encoder.EncodeString();

    // ??o ng??c chu?i k?t qu?
    std::reverse(encodedString.begin(), encodedString.end());

    std::cout << "Chuoi ma hoa dao nguoc: " << encodedString << std::endl;

    return 0;
}
