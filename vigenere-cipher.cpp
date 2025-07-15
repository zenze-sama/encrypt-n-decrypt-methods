#include <iostream>
#include <string>
#include <cctype>

int vigenere_cipher_main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cout << "Usage: " << argv[0] << " <text_to_encrypt> <key>\n";
        std::cout << "Example: " << argv[0] << " hello KEY\n";
        return 1;
    }

    std::string plain = argv[1];
    std::string key = argv[2];
    std::string cipher;

    std::string processed_key;
    for (char c : key) {
        if (isalpha(c)) {
            processed_key.push_back(toupper(c));
        }
    }

    if (processed_key.empty()) {
        std::cout << "Error: Key must contain at least one letter\n";
        return 1;
    }

    cipher.clear();
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

    std::cout << "Plaintext: " << plain << "\n";
    std::cout << "Key: " << key << " (processed as: " << processed_key << ")\n";
    std::cout << "Ciphertext: " << cipher << "\n";

    return 0;
}