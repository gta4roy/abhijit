#include <iostream>
#include <string>
using namespace std;

class Prototype 
{
    protected:
        std::string type;
        int         value;

    public:
        virtual Prototype * clone() = 0;

        std::string getType()
        {
            return type;
        }

        int getValue()
        {
            return value;
        }
};

class ConcretePrototype1 : public Prototype
{
    public:
        ConcretePrototype1(int number)
        {
            this->type = "Concrete Prototype 1";
            this->value = number;
        }
        Prototype * clone()
        {
            return new ConcretePrototype1(*this);
        }
};

class ConcretePrototype2 : public Prototype
{
    public:
        ConcretePrototype2(int number)
        {
            this->type = "Concrete Prototype 2";
            this->value = number;
        }
        Prototype * clone()
        {
            return new ConcretePrototype2(*this);
        }
};

class ObjectFactory
{
    private:
        static Prototype * type1Value1;
        static Prototype * type1Value2;
        static Prototype * type2Value1;
        static Prototype * type2Value2;
    
    public:
        static void initialise()
        {
            type1Value1 = new ConcretePrototype1(1);
            type1Value2 = new ConcretePrototype1(2);
            type2Value1 = new ConcretePrototype2(1);
            type2Value2 = new ConcretePrototype2(2);
        }

        static Prototype * getType1Value1()
        {
             return type1Value1->clone();
        }

        static Prototype * getType1Value2()
        {
             return type1Value2->clone();
        }

        static Prototype * getType2Value1()
        {
             return type2Value1->clone();
        }

        static Prototype * getType2Value2()
        {
             return type2Value2->clone();
        }
};  
Prototype * ObjectFactory::type1Value1 = nullptr;
Prototype * ObjectFactory::type1Value2 = nullptr;
Prototype * ObjectFactory::type2Value1 = nullptr;
Prototype * ObjectFactory::type2Value2 = nullptr;

int main()
{
    Prototype * object;
    ObjectFactory::initialise();

    object = ObjectFactory::getType1Value1();
    cout << object->getType();
    cout << object->getValue();

    object = ObjectFactory::getType1Value2();
    cout << object->getType();
    cout << object->getValue();

    object = ObjectFactory::getType2Value1();
    cout << object->getType();
    cout << object->getValue();

    object = ObjectFactory::getType2Value1();
    cout << object->getType();
    cout << object->getValue();

    return 0;
}