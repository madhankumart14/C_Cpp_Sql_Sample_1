#include <iostream>
#include <memory>
#include "UserEngine.hpp"

int main() {
    std::cout << "=== Multi-Language System Application Startup ===" << std::endl;

    // Instantiate engine component safely using a smart pointer
    auto appEngine = std::make_unique<UserEngine>("production_cluster.db");
    std::cout << "Application Engine Running Version: " << appEngine->getVersion() << std::endl;
    std::cout << "------------------------------------------------" << std::endl;

    // Trigger runtime data transaction path
    bool success = appEngine->registerUser("charlie_hacks", "charlie@domain.com");
    
    if (success) {
        std::cout << "\n[Main] Transaction processing finished successfully." << std::endl;
    } else {
        std::cout << "\n[Main] Critical failure during execution pipeline." << std::endl;
    }

    return 0;
}
