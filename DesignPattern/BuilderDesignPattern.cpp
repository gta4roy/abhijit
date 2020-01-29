#include<iostream>
#include<string>
using namespace std;

class Wheel 
{
    public:
        int size;
};

class Engine
{
    public:
        int horsepower;
};

class Body 
{
    public:
        std::string shape;
};

class Car
{
    public:
        Wheel * wheels[4];
        Engine * engine;
        Body * body ;

    void specification()
    {
        std::cout << "\n Body size :"<< body->shape;
        std::cout << "\n Engine Horse Power :"<< engine->horsepower;
        std::cout << "\n Tyre size :"<<wheels[0]->size;
    }
};

class Builder 
{
    public:
        virtual Wheel * getWeels() =0;
        virtual Engine * getEngine() = 0;
        virtual Body * getBody() = 0;
};

class MarutiBuilder : public Builder 
{
    public:
        Wheel * getWeels()
        {
            Wheel * objWheel = new Wheel();
            objWheel->size = 24;
            return objWheel;
        }

        Engine * getEngine() 
        {
            Engine * objEngine = new Engine();
            objEngine->horsepower = 34;
            return objEngine;
        }

        Body * getBody()
        {
            Body *  m_body = new Body();
            m_body->shape = "Maruthi Body";
            return m_body;
        }
};

class SantroBuilder : public Builder 
{
    public:
        Wheel * getWeels()
        {
            Wheel * objWheel = new Wheel();
            objWheel->size = 24;
            return objWheel;
        }

        Engine * getEngine() 
        {
            Engine * objEngine = new Engine();
            objEngine->horsepower = 34;
            return objEngine;
        }

        Body * getBody()
        {
            Body *  m_body = new Body();
            m_body->shape = "Maruthi Body";
            return m_body;
        }
};

class CarManager
{
    public:
        void setBuilder(Builder * newBuilder)
        {
            builder = newBuilder;
        }
        Car * getCar()
        {
            Car * obj = new Car();
            obj->body = builder->getBody();
            obj->engine = builder->getEngine();
            obj->wheels[0] = builder->getWeels();
            obj->wheels[1] = builder->getWeels();
            obj->wheels[2] = builder->getWeels();
            obj->wheels[3] = builder->getWeels();
            return obj;
        }
    private:
        Builder * builder ;
};

int main()
{
    Car     *       obj;
    CarManager        director;

    MarutiBuilder     maruthiBuilder;
    SantroBuilder     santroBuilder;

    std::cout << "Jeep "<<std::endl;

    director.setBuilder(&maruthiBuilder);
    obj = director.getCar();
    obj->specification();


    director.setBuilder(&santroBuilder);
    obj = director.getCar();
    obj->specification();

}