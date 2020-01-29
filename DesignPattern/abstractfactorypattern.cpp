#include <iostream>
using namespace std;

class ProductA 
{
    public:
        virtual void execute() = 0;
};

class ProductB
{
    public:
        virtual void execute() = 0;
};

class ProductAX : public ProductA
{
    public:
    void execute()
    {
        std::cout << "\n Executing the Product AX";
    }
};

class ProductAY : public ProductA
{
    public:
    void execute()
    {
        std::cout << "\n Executing the Product AY";
    }
};


class ProductBX : public ProductB
{
    public:
    void execute()
    {
        std::cout << "\n Executing the Product BX";
    }
};

class ProductBY : public ProductB
{
    public:
    void execute()
    {
        std::cout << "\n Executing the Product BY";
    }
};

class AbstractFactory
{
    public:
        virtual ProductA * createProductA() = 0;
        virtual ProductB * createProductB() = 0;
};

class concreateFactoryX : public AbstractFactory
{
    public:
        ProductA * createProductA()
        {
            return new ProductAX();
        }

        ProductB * createProductB()
        {
            return new ProductBX();
        }
};

class concreateFactoryY : public AbstractFactory
{
    public:
        ProductA * createProductA()
        {
            return new ProductAY();
        }

        ProductB * createProductB()
        {
            return new ProductBY();
        }
};


int main()
{
    AbstractFactory * abstractFactoryObj = new concreateFactoryX();
    abstractFactoryObj->createProductA()->execute();
    abstractFactoryObj->createProductB()->execute();

    AbstractFactory * abstractFactoryObjY = new concreateFactoryY();
    abstractFactoryObjY->createProductA()->execute();
    abstractFactoryObjY->createProductB()->execute();

}