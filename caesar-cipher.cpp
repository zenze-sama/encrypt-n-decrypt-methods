#include <iostream>
#include <string>

int main() {
    std::string plain = "abcdefghijklmnopqrstuvwxyz";
    std::string cipher;
    
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