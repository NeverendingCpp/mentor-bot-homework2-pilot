#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

int factorial(int n) {
    return n == 1 ? 1 : n * factorial(n - 1);
}

int power(int base, int exponent) {
    int result = 1;
    while (exponent--) result *= base;
    return result;
}

class Application {
public:
    void run(int argc, char** argv) const {
        if (argc == 2 && std::string(argv[1]) == "--help") {
            std::cout << "Synthetic pilot: calculator A OP B\n";
            return;
        }
        if (argc != 4) throw std::invalid_argument("Expected A OP B");
        const int a = std::stoi(argv[1]);
        const int b = std::stoi(argv[3]);
        const std::string operation = argv[2];
        if (operation == "+") std::cout << a + b << '\n';
        else if (operation == "/") std::cout << a / b << '\n';
        else if (operation == "-") std::cout << a - b << '\n';
        else if (operation == "*") std::cout << a * b << '\n';
        else if (operation == "^") std::cout << power(a, b) << '\n';
        else if (operation == "!") std::cout << factorial(a) << '\n';
        else throw std::invalid_argument("Unknown operation");
        std::ofstream log("calculator.log", std::ios::trunc);
        log << a << operation << b << '\n';
    }
};

int main(int argc, char** argv) {
    try {
        Application{}.run(argc, argv);
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return EXIT_FAILURE;
    }
}
