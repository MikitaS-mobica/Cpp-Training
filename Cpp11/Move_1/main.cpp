#include <iostream>
#include <string>
#include <vector>
#include <functional>   // Probably required for the bind function


class Test
{
private:
    std::string _name{"Test object"};

public:
    // Constructors
    Test() = default;
    Test(const std::string &name) : _name(name)
    {
        //std::cout << "Explicit constructor" << std::endl;
    };

    Test(Test &&other) : _name(other._name)
    {
        std::cout << "Move constructor" << std::endl;
    };

    // Move assignment operator
    virtual Test &operator=(Test &&other)
    {
        std::cout << "Move assignment" << std::endl;
        _name = other._name;
        return *this;
    };

    // Useful functions
    friend std::ostream &operator<<(std::ostream &stream, Test &obj)
    {
        stream << "lValue << function " << obj._name;
        return stream;
    };

    friend std::ostream &operator<<(std::ostream &stream, Test &&obj)
    {
        stream << "rValue << function " << obj._name;
        return stream;
    };
};

class CastTest : public Test
{
public:
    CastTest() = default;
    CastTest(const CastTest &other) {};
};


void printRef(Test &ref)
{
    std::cout << "lValue function: " << ref << std::endl;
}


void printRef(Test &&ref)
{
    std::cout << "rValue function: " << ref << std::endl;
}


Test getObj()
{
    return Test("rValue tester");
}


void bindTester(int a, int b, int c)
{
    std::cout << __func__ << ": ";
    std::cout << "A = " << a << "; ";
    std::cout << "B = " << b << "; ";
    std::cout << "C = " << c;
    std::cout << std::endl;;
    
    return;
}


int main()
{
    // Non-const lValue reference to the rValue doesn't work
    //Test &refTest = Test();

    // Const lValue reference to the rValue prolongs it's life
    const Test &constRefTest = Test();

    //Test testObj = Test("rValue tester");
    Test testObj = getObj();    // Hmm, looks like optimisation kicked in...
    testObj = getObj();
    Test &lRef = testObj;

    std::vector<Test> vec;
    vec.push_back(getObj());    // A-ha, here we can see move constructor

    // rValue reference? Seems like we have lValue here anyway
    Test &&rRef = Test();
    // But I can't assign an lValue to the rValue reference
    //Test &&newRRef = testObj;

    // Yep, rValue reference is an lValue
    Test &newLRef = rRef;

    printRef(lRef);
    printRef(rRef);
    printRef(Test());


    // Test casting
    CastTest castTester;
    Test &castedTest = castTester;
    CastTest castTesterRef = dynamic_cast<CastTest &>(castedTest);
    // I had to declare operator= function as a virtual
    // to get rid of "Test is not polymorphic" error


    // Test bind
    auto bindTester1 = std::bind(bindTester, 20, 40, std::placeholders::_1);
    bindTester1(10);

    return 0;
}
