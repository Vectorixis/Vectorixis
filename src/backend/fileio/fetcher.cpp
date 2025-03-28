#include <iostream>
#include <filesystem>
#include <cstdlib>

namespace fs = std::filesystem;

std::string getDocumentsPath() {
    char* userProfile = std::getenv("USERPROFILE");
    if (!userProfile) {
        std::cerr << "Error: USERPROFILE not found." << std::endl;
        return "";
    }
    return std::string(userProfile) + "\\Documents\\Vectorixis";
}

void checkOrCreateVectorixisFolder() {
    std::string basePath = getDocumentsPath();
    
    if (basePath.empty()) return;

    if (!fs::exists(basePath)) {
        fs::create_directories(basePath);
        std::cout << "Created Vectorixis directory at: " << basePath << std::endl;
    } else {
        std::cout << "Vectorixis directory found at: " << basePath << std::endl;
    }

    // List all project files with the `.vctrix` extension
    std::cout << "Project Files:\n";
    for (const auto& entry : fs::directory_iterator(basePath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".vctrix") {
            std::cout << " - " << entry.path().filename().string() << std::endl;
        }
    }
}

int main() {
    checkOrCreateVectorixisFolder();
    return 0;
}