#include <iostream>
#include <string>

std::string caesarDecrypt(const std::string& cipher, int shift) {
    std::string plain;
    for (char c : cipher) {
        if (c >= 'a' && c <= 'z') {
            c = 'a' + (c - 'a' - shift + 26) % 26;
        } else if (c >= 'A' && c <= 'Z') {
            c = 'A' + (c - 'A' - shift + 26) % 26;
        }
        plain.push_back(c);
    }
    return plain;
}

int caesar_cipher_main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <text> [mode] [shift]\n";
        std::cout << "Modes:\n";
        std::cout << "  encrypt (default) - show all ROT encryptions\n";
        std::cout << "  decrypt - decrypt with specific shift\n";
        std::cout << "Examples:\n";
        std::cout << "  " << argv[0] << " hello\n";
        std::cout << "  " << argv[0] << " ifmmp decrypt 1\n";
        return 1;
    }

    std::string text = argv[1];
    std::string mode = argc > 2 ? argv[2] : "encrypt";

    if (mode == "decrypt") {
        if (argc < 4) {
            std::cout << "Error: decrypt mode requires a shift value\n";
            return 1;
        }
        int shift = std::stoi(argv[3]);
        std::string plain = caesarDecrypt(text, shift);
        std::cout << "Decrypted with ROT" << shift << ": " << plain << "\n";
    } 
    else {
        std::cout << "All ROT encryptions for '" << text << "':\n";
        for(int shift = 1; shift < 26; shift++) {
            std::string cipher;
            for (char c : text) {
                if (c >= 'a' && c <= 'z') {
                    c = 'a' + (c - 'a' + shift) % 26;
                } else if (c >= 'A' && c <= 'Z') {
                    c = 'A' + (c - 'A' + shift) % 26;
                }
                cipher.push_back(c);
            }
            std::cout << "ROT" << shift << ": " << cipher << "\n";
        }
    }

    return 0;
}