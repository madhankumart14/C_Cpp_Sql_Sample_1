# C_Cpp_Sql_Sample_1
User Management Application written in C, C++, and SQL

# 1. Compile the C database file into an object file
gcc -c db_layer.c -o db_layer.o

# 2. Compile the C++ files alongside the object file into the final executable
g++ main.cpp UserEngine.cpp db_layer.o -o user_management_app

# 3. Run the application
./user_management_app
