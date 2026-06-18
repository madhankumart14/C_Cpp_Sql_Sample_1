#ifndef USER_ENGINE_HPP
#define USER_ENGINE_HPP

#include <string>
#include "db_layer.h" // Include C header directly

class UserEngine {
private:
    DBConnection* dbContext;
    std::string engineVersion;

public:
    UserEngine(const std::string& dbName);
    ~UserEngine();
    
    bool registerUser(const std::string& username, const std::string& email);
    std::string getVersion() const;
};

#endif // USER_ENGINE_HPP
