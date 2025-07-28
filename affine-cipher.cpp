#include <iostream>
#include <string>
#include <stdexcept>

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    throw std::runtime_error("Modular inverse doesn't exist");
}

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

std::string affineDecrypt(const std::string& cipher, int a, int b) {
    std::string plain;
    int a_inv = modInverse(a, 26);
    for (char c : cipher) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int y = c - base;
            int decrypted = (a_inv * (y - b + 26)) % 26;
            plain += static_cast<char>(decrypted + base);
        } else {
            plain += c;
        }
    }
    return plain;
}

int affine_cipher_main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cout << "Usage: " << argv[0] << " <text> <a> <b> [mode]\n";
        std::cout << "Modes:\n";
        std::cout << "  encrypt (default)\n";
        std::cout << "  decrypt\n";
        std::cout << "Example: " << argv[0] << " hello 5 8\n";
        std::cout << "Note: 'a' must be coprime with 26 (gcd(a,26)=1)\n";
        std::cout << "Valid 'a' values: 1,3,5,7,9,11,15,17,19,21,23,25\n";
        return 1;
    }

    std::string text = argv[1];
    int a = std::stoi(argv[2]);
    int b = std::stoi(argv[3]);
    std::string mode = argc > 4 ? argv[4] : "encrypt";

    if (!isCoprime(a, 26)) {
        std::cout << "Error: 'a' must be coprime with 26 (gcd(a,26)=1)\n";
        std::cout << "Valid 'a' values: 1,3,5,7,9,11,15,17,19,21,23,25\n";
        return 1;
    }

    if (mode == "decrypt") {
        std::string plain = affineDecrypt(text, a, b);
        std::cout << "Affine decryption: " << plain << "\n";
    } else {
        std::string cipher = affineEncrypt(text, a, b);
        std::cout << "Affine encryption: " << cipher << "\n";
    }
    return 0;
}