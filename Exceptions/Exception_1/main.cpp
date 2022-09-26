#include <iostream>
#include <exception>


// Class prototype
class MyException;


class MyException : public std::exception
{
public:
    const char* what() const throw()
    {
        return "Hey! This is @MyException";
    }
};


// Function prototype
static void breakMeDown(void);


static void breakMeDown(void)
{
    bool throwInt = false;
    bool throwCString = false;
    bool throwMyException = true;


    if(throwInt == true)
        throw 8;

    if(throwCString == true)
        throw "Some exception occured";

    if(throwMyException == true)
        throw MyException();

    return;
}


int main(void)
{
    try
    {
        breakMeDown();
    }
    catch(int error)
    {
        std::cout << "Error message is " << error << std::endl;
    }
    catch(const char *errorMsg)
    {
        std::cout << "Exception: " << errorMsg << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
        
    return 0;
}