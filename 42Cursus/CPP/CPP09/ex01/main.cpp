#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "\033[1;31mError : Format : 'number number operation...'" << std::endl;
        return 1;
    }

    std::string line = argv[1];
    RPN calculator(line);

    while (calculator.getError() != 1)
    {
        std::stack<long> resultStack = calculator.getStack();
        if (resultStack.size() != 1)
        {
            std::cerr << "\033[1;31mError : Invalid expression" << std::endl;
            return 1;
        }
        else {
            std::cout << resultStack.top() << std::endl;
            return 0;
        }
    }
    return 0;
}
