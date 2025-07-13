#include <iostream>
#include <string>
#include <stdexcept>

bool isCoprime(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a == 1;
}

std::string affineEncrypt(const std::string& plain, int a, int b) {
    std::string cipher;
    for (char c : plain) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int x = c - base;
            int encrypted = (a * x + b) % 26;
            cipher += static_cast<char>(encrypted + base);
        } else {
            cipher += c;
        }
    }
    return cipher;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cout << "Usage: " << argv[0] << " <text_to_encrypt> <a> <b>\n";
        std::cout << "Example: " << argv[0] << " hello 5 8\n";
        std::cout << "Note: 'a' must be coprime with 26 (gcd(a,26)=1)\n";
        std::cout << "Valid 'a' values: 1,3,5,7,9,11,15,17,19,21,23,25\n";
        return 1;
    }

    std::string plain = argv[1];
    int a = std::stoi(argv[2]);
    int b = std::stoi(argv[3]);

    if (!isCoprime(a, 26)) {
        std::cout << "Error: 'a' must be coprime with 26 (gcd(a,26)=1)\n";
        std::cout << "Valid 'a' values: 1,3,5,7,9,11,15,17,19,21,23,25\n";
        return 1;
    }

    std::string cipher = affineEncrypt(plain, a, b);
    std::cout << "Affine encryption: " << cipher << "\n";
    return 0;
}