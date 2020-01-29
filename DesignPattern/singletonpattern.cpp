#include <iostream>
using namespace std;

class SingleTonClass 
{
    public:
       static  SingleTonClass * getInstance();
    private:
        static SingleTonClass * instance;
        SingleTonClass() {}
};

SingleTonClass * SingleTonClass::instance = 0;
SingleTonClass * SingleTonClass::getInstance()
{
    if(instance == nullptr)
        instance = new SingleTonClass();
    return instance;    
}

int main()
{
    SingleTonClass  * aObj = SingleTonClass::getInstance();
    SingleTonClass * bObj = SingleTonClass::getInstance();

    if(aObj == bObj)
    {
        std::cout << "\n Both instances are same ";
    }
}