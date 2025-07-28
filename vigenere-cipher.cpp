#include <iostream>
#include <string>
#include <cctype>

std::string vigenereEncrypt(const std::string& plain, const std::string& key) {
    std::string cipher;
    std::string processed_key;
    
    for (char c : key) {
        if (isalpha(c)) {
            processed_key.push_back(toupper(c));
        }
    }

    if (processed_key.empty()) {
        throw std::runtime_error("Key must contain at least one letter");
    }

    for (size_t i = 0; i < plain.size(); i++) {
        char c = plain[i];
        if (isupper(c)) {
            char key_char = processed_key[i % processed_key.size()];
            c = 'A' + (c - 'A' + (key_char - 'A')) % 26;
        } else if (islower(c)) {
            char key_char = processed_key[i % processed_key.size()];
            c = 'a' + (c - 'a' + (key_char - 'A')) % 26;
        }
        cipher.push_back(c);
    }
    return cipher;
}

std::string vigenereDecrypt(const std::string& cipher, const std::string& key) {
    std::string plain;
    std::string processed_key;
    
    for (char c : key) {
        if (isalpha(c)) {
            processed_key.push_back(toupper(c));
        }
    }

    if (processed_key.empty()) {
        throw std::runtime_error("Key must contain at least one letter");
    }

    for (size_t i = 0; i < cipher.size(); i++) {
        char c = cipher[i];
        if (isupper(c)) {
            char key_char = processed_key[i % processed_key.size()];
            c = 'A' + (c - 'A' - (key_char - 'A') + 26) % 26;
        } else if (islower(c)) {
            char key_char = processed_key[i % processed_key.size()];
            c = 'a' + (c - 'a' - (key_char - 'A') + 26) % 26;
        }
        plain.push_back(c);
    }
    return plain;
}

int vigenere_cipher_main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " <text> <key> [mode]\n";
        std::cout << "Modes:\n";
        std::cout << "  encrypt (default)\n";
        std::cout << "  decrypt\n";
        std::cout << "Example: " << argv[0] << " hello KEY\n";
        return 1;
    }

    std::string text = argv[1];
    std::string key = argv[2];
    std::string mode = argc > 3 ? argv[3] : "encrypt";

    try {
        if (mode == "decrypt") {
            std::string plain = vigenereDecrypt(text, key);
            std::cout << "Plaintext: " << plain << "\n";
            std::cout << "Key: " << key << " (processed as: " << [processed key] << ")\n";
        } else {
            std::string cipher = vigenereEncrypt(text, key);
            std::cout << "Plaintext: " << text << "\n";
            std::cout << "Key: " << key << " (processed as: " << [processed key] << ")\n";
            std::cout << "Ciphertext: " << cipher << "\n";
        }
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}