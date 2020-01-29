#include<string>
#include<iostream>
#include<list>

class Resource
{
    public:
        Resource()
        {
            value = 0;
        }
        void reset()
        {
            value = 0;
        }
        int getValue()
        {
            return value;
        }
        void setValue(int k)
        {
            value = k;
        }
    private:
        int value;
};

class ObjectPool
{
    private:
        std::list <Resource *> resource;
        static ObjectPool * instance;
        ObjectPool() {}

    public:
        static ObjectPool * getInstance()
        {
            if(instance == nullptr)
            {
                instance = new ObjectPool;
            }
            return instance;
        }

        Resource * getResource()
        {
            if(resource.empty())
            {
                return new Resource;
            }
            else 
            {
                std::cout << "\n Reusing the resources";
                Resource *  res = resource.front();
                resource.pop_front();
                return res;

            }
        }
        void returnResource(Resource * object)
        {
            object->reset();
            resource.push_back(object);
        }
};

ObjectPool* ObjectPool::instance = nullptr;

int main()
{
    ObjectPool * pool = ObjectPool::getInstance();

    Resource * one;
    Resource * two;

    one = pool->getResource();
    one->setValue(10);

    std::cout << "\n Value of resource one :"<< one->getValue();


    two = pool->getResource();
    two->setValue(20);

    std::cout << "\n Value of the resource two :"<< two->getValue();

    pool->returnResource(one);
    pool->returnResource(two);

    one = pool->getResource();
    std::cout << "\n Value of resource one :"<< one->getValue();

    two = pool->getResource();
    std::cout << "\n Value of resource one :"<< two->getValue();

}