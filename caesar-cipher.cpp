#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <text_to_encrypt>\n";
        std::cout << "Example: " << argv[0] << " hello\n";
        return 1;
    }

    std::string plain = argv[1];
    std::string cipher;

    std::cout << "All ROT encryptions for '" << plain << "':\n";
    
    for(int shift = 1; shift < 26; shift++) {
        cipher.clear();
        for (char c : plain) {
            if (c >= 'a' && c <= 'z') {
                c = 'a' + (c - 'a' + shift) % 26;
            } else if (c >= 'A' && c <= 'Z') {
                c = 'A' + (c - 'A' + shift) % 26;
            }
            cipher.push_back(c);
        }
        std::cout << "ROT" << shift << ": " << cipher << "\n";
    }

    return 0;
}