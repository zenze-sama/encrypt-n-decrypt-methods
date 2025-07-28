#include <iostream>
#include <string>
#include <vector>

std::string railFenceEncrypt(const std::string& plain, int rails) {
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
    return cipher;
}

std::string railFenceDecrypt(const std::string& cipher, int rails) {
    std::vector<std::string> fence(rails);
    std::vector<int> rail_lengths(rails, 0);
    
    // Calculate the length of each rail
    int rail = 0;
    bool down = false;
    for (size_t i = 0; i < cipher.size(); i++) {
        rail_lengths[rail]++;
        if (rail == 0 || rail == rails - 1) down = !down;
        rail += down ? 1 : -1;
    }
    
    // Split cipher into rails
    size_t pos = 0;
    for (int r = 0; r < rails; r++) {
        fence[r] = cipher.substr(pos, rail_lengths[r]);
        pos += rail_lengths[r];
    }
    
    // Reconstruct plaintext
    std::string plain;
    rail = 0;
    down = false;
    std::vector<size_t> rail_positions(rails, 0);
    
    for (size_t i = 0; i < cipher.size(); i++) {
        plain += fence[rail][rail_positions[rail]++];
        if (rail == 0 || rail == rails - 1) down = !down;
        rail += down ? 1 : -1;
    }
    
    return plain;
}

int rail_fence_cipher_main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <text> [rails] [mode]\n";
        std::cout << "Modes:\n";
        std::cout << "  encrypt (default)\n";
        std::cout << "  decrypt\n";
        std::cout << "Example: " << argv[0] << " hello 3\n";
        return 1;
    }

    std::string text = argv[1];
    int rails = 3;
    if (argc >= 3) {
        rails = std::stoi(argv[2]);
        if (rails < 2) {
            std::cout << "Number of rails must be at least 2\n";
            return 1;
        }
    }
    
    std::string mode = argc > 3 ? argv[3] : "encrypt";

    if (mode == "decrypt") {
        std::string plain = railFenceDecrypt(text, rails);
        std::cout << "Rail Fence decryption: " << plain << "\n";
    } else {
        std::string cipher = railFenceEncrypt(text, rails);
        std::cout << "Rail Fence encryption: " << cipher << "\n";
    }
    return 0;
}