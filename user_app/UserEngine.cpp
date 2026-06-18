#include "UserEngine.hpp"
#include <iostream>

UserEngine::UserEngine(const std::string& dbName) : engineVersion("v2.4.0") {
    std::cout << "[C++ Engine] Booting UserEngine core architecture..." << std::endl;
    // Calling the native C initialization function
    dbContext = init_database(dbName.c_str());
}

UserEngine::~UserEngine() {
    std::cout << "[C++ Engine] Shutting down application engine modules." << std::endl;
    if (dbContext != nullptr) {
        close_database(dbContext);
    }
}

bool UserEngine::registerUser(const std::string& username, const std::string& email) {
    std::cout << "[C++ Engine] Validating entry criteria for: " << username << std::endl;
    
    if (username.empty() || email.find('@') == std::string::npos) {
        std::cerr << "[C++ Engine] Error: Validation failed." << std::endl;
        return false;
    }

    // Call underlying C data transaction utility
    int status = execute_insert_user(dbContext, username.c_str(), email.c_str());
    return (status == 1);
}

std::string UserEngine::getVersion() const {
    return engineVersion;
}
