#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <text_to_encrypt> [rails]\n";
        std::cout << "Example: " << argv[0] << " hello 3\n";
        return 1;
    }

    std::string plain = argv[1];
    int rails = 3;
    
    if (argc >= 3) {
        rails = std::stoi(argv[2]);
        if (rails < 2) {
            std::cout << "Number of rails must be at least 2\n";
            return 1;
        }
    }

    std::vector<std::string> fence(rails);
    int rail = 0;
    bool down = false;

    for (char c : plain) {
        fence[rail] += c;
        if (rail == 0 || rail == rails - 1) down = !down;
        rail += down ? 1 : -1;
    }

    std::string cipher;
    for (const std::string& row : fence) {
        cipher += row;
    }

    std::cout << "Rail Fence encryption: " << cipher << "\n";
    return 0;
}