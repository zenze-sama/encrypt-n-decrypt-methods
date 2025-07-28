#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <stdexcept>
#include <limits>

int caesar_cipher_main(int argc, char* argv[]);
int affine_cipher_main(int argc, char* argv[]);
int vigenere_cipher_main(int argc, char* argv[]);
int rail_fence_cipher_main(int argc, char* argv[]);

void runCaesarCipher();
void runAffineCipher();
void runVigenereCipher();
void runRailFenceCipher();
void displayMenu();
void clearScreen();
void waitForEnter();

int main() {
    while (true) {
        clearScreen();
        displayMenu();
        
        std::string choice;
        std::cout << "Enter your choice (1-5): ";
        std::getline(std::cin, choice);
        
        clearScreen();
        
        try {
            switch (choice[0]) {
                case '1':
                    runCaesarCipher();
                    break;
                case '2':
                    runAffineCipher();
                    break;
                case '3':
                    runVigenereCipher();
                    break;
                case '4':
                    runRailFenceCipher();
                    break;
                case '5':
                    std::cout << "Exiting program. Goodbye!\n";
                    return 0;
                default:
                    std::cout << "Invalid choice. Please try again.\n";
                    waitForEnter();
                    continue;
            }
            waitForEnter();
        } catch (const std::exception& e) {
            std::cout << "An error occurred: " << e.what() << "\n";
            waitForEnter();
        }
    }
}

void displayMenu() {
    std::cout << "================================\n";
    std::cout << "  Encryption/Decryption Tool     \n";
    std::cout << "================================\n";
    std::cout << "1. Caesar Cipher\n";
    std::cout << "2. Affine Cipher\n";
    std::cout << "3. Vigenere Cipher\n";
    std::cout << "4. Rail Fence Cipher\n";
    std::cout << "5. Exit\n";
    std::cout << "================================\n";
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void waitForEnter() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void runCaesarCipher() {
    std::cout << "=== Caesar Cipher ===\n";
    std::cout << "Enter text: ";
    std::string text;
    std::getline(std::cin, text);
    
    std::cout << "Mode (1=encrypt, 2=decrypt): ";
    std::string mode;
    std::getline(std::cin, mode);
    
    std::vector<char*> argv;
    char arg0[] = "caesar-cipher";
    char* arg1 = &text[0];
    argv.push_back(arg0);
    argv.push_back(arg1);
    
    if (mode == "2") {
        std::cout << "Enter shift value: ";
        std::string shift;
        std::getline(std::cin, shift);
        
        char arg2[] = "decrypt";
        char* arg3 = &shift[0];
        argv.push_back(arg2);
        argv.push_back(arg3);
    }
    
    argv.push_back(nullptr);
    
    caesar_cipher_main(argv.size() - 1, argv.data());
}

void runAffineCipher() {
    std::cout << "=== Affine Cipher ===\n";
    std::cout << "Enter text: ";
    std::string text;
    std::getline(std::cin, text);
    
    std::cout << "Mode (1=encrypt, 2=decrypt): ";
    std::string mode;
    std::getline(std::cin, mode);
    
    std::string a_str, b_str;
    std::cout << "Enter value for 'a' (must be coprime with 26): ";
    std::getline(std::cin, a_str);
    std::cout << "Enter value for 'b': ";
    std::getline(std::cin, b_str);
    
    std::vector<char*> argv;
    char arg0[] = "affine-cipher";
    char* arg1 = &text[0];
    char* arg2 = &a_str[0];
    char* arg3 = &b_str[0];
    argv.push_back(arg0);
    argv.push_back(arg1);
    argv.push_back(arg2);
    argv.push_back(arg3);
    
    if (mode == "2") {
        char arg4[] = "decrypt";
        argv.push_back(arg4);
    }
    
    argv.push_back(nullptr);
    
    affine_cipher_main(argv.size() - 1, argv.data());
}

void runVigenereCipher() {
    std::cout << "=== Vigenere Cipher ===\n";
    std::cout << "Enter text: ";
    std::string text;
    std::getline(std::cin, text);
    
    std::cout << "Mode (1=encrypt, 2=decrypt): ";
    std::string mode;
    std::getline(std::cin, mode);
    
    std::string key;
    std::cout << "Enter encryption key: ";
    std::getline(std::cin, key);
    
    std::vector<char*> argv;
    char arg0[] = "vigenere-cipher";
    char* arg1 = &text[0];
    char* arg2 = &key[0];
    argv.push_back(arg0);
    argv.push_back(arg1);
    argv.push_back(arg2);
    
    if (mode == "2") {
        char arg3[] = "decrypt";
        argv.push_back(arg3);
    }
    
    argv.push_back(nullptr);
    
    vigenere_cipher_main(argv.size() - 1, argv.data());
}

void runRailFenceCipher() {
    std::cout << "=== Rail Fence Cipher ===\n";
    std::cout << "Enter text: ";
    std::string text;
    std::getline(std::cin, text);
    
    std::cout << "Mode (1=encrypt, 2=decrypt): ";
    std::string mode;
    std::getline(std::cin, mode);
    
    std::string rails_str;
    std::cout << "Enter number of rails (default=3): ";
    std::getline(std::cin, rails_str);
    
    std::vector<char*> argv;
    char arg0[] = "rail-fence-cipher";
    char* arg1 = &text[0];
    argv.push_back(arg0);
    argv.push_back(arg1);
    
    if (!rails_str.empty()) {
        char* arg2 = &rails_str[0];
        argv.push_back(arg2);
    }
    
    if (mode == "2") {
        char arg3[] = "decrypt";
        argv.push_back(arg3);
    }
    
    argv.push_back(nullptr);
    
    rail_fence_cipher_main(argv.size() - 1, argv.data());
}