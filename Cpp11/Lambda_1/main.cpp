#include <iostream>
#include <functional>
#include <string>


class testLambdaClass
{
private:
    int _value1;
    int _value2;

public:
    testLambdaClass() : _value3(0), _value4(0) {};
    // I can't initialize any members while delegating a constructor
    testLambdaClass(int value1) : testLambdaClass(){ _value1 = value1; };
    testLambdaClass(int value1, int value2) : testLambdaClass(value1) { _value2 = value2; };

    int _value3;
    int _value4;

    // This is mostly useless, but why not
    void (*m_pLambda)() = [](){};
    
    void run()
    {
        // Capturing this allows to use private variables, this is always captured by reference
        auto pLambda = [this]()
        {
            _value1 = 1;
            this->_value3 = 3;
        };

        return;
    };
};


struct newFunctor
{
    void operator()(const std::string &name)
    {
        std::cout << "Say my name!" << std::endl;
        std::cout << name << "." << std::endl;
        std::cout << "You're god damn right!" << std::endl;
    };
} stdFunctionFunctor;


void stdFunctionTest(const std::string &name)
{
    std::cout << "Say my name!" << std::endl;
    std::cout << name << "." << std::endl;
    std::cout << "You're god damn right!" << std::endl;
}


void testLambdaExpression(std::function<void(const std::string &)> expressionToTest)
{
    expressionToTest("Heisenberg");
    return;
}


int main() {
    // Simple Lambda-expression example
    // [] for capturing variables to the Lambda expression scope,
    // () for arguments, {} for implementation, () for function call
    [](){}();

    // -> is to set function return type
    auto printScaryPhrase = [](const std::string &name) -> void
    {
        std::cout << "Say my name!" << std::endl;
        std::cout << name << "." << std::endl;
        std::cout << "You're god damn right!" << std::endl;
    };

    std::cout << "Lambda:" << std::endl;
    testLambdaExpression(printScaryPhrase);
    std::cout << "Function:" << std::endl;
    testLambdaExpression(stdFunctionTest);
    std::cout << "Functor:" << std::endl;
    testLambdaExpression(stdFunctionFunctor);
    std::cout << std::endl;


    // Capturing training
    int testInt1 = 1;
    int testInt2 = 2;
    int testInt3 = 3;

    // No variables captured
    [](){}();

    // All local varibales captured by value by default, @testInt3 is captured by reference instead
    [=, &testInt3](){ std::cout << ++testInt3 << std::endl; }();

    // All local varibales captured by reference by default, @testInt3 is captured by value instead
    [&, testInt3](){ std::cout << testInt3 << std::endl; }();

    // Variables captured by value are read only
    // But...
    // Here we passed all the variables by value and lifted read-only rule
    // So this is just copying variables like arguments in a normal function
    [=]() mutable { std::cout << testInt3 << std::endl; }();


    // This doesn't work
    //[const &](){}();
    // This neither
    //[const &testInt1](){}();

    return 0;
}
