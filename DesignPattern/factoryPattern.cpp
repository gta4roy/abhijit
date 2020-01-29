#include <iostream>
#include <vector>
using namespace std;

//Example of factory class

enum class MobileType
{
    Samsumg, Nokia , Moto
};

class IMobile
{
    public:
    virtual void call(const std::string &no) = 0;
    virtual void message(const std::string& no , const string & messageString) = 0;
};

class NokiaPhone: public IMobile 
{
    public:
        void call(const std::string & no)
        {
            std::cout << "\nNokia Phone making call to :"<< no;
        }
        void message(const std::string & no , const string & messageString)
        {
            std::cout << "\nNokia Phone sending messages "<< messageString << "to "<< no;
        }
};

class SamsumgPhone: public IMobile 
{
    public:
        void call(const std::string & no)
        {
            std::cout << "\nSamsumgPhone Phone making call to :"<< no;
        }
        void message(const std::string & no , const string & messageString)
        {
            std::cout << "\nSamsumgPhone Phone sending messages "<< messageString << "to "<< no;
        }
};


class MotoPhone: public IMobile 
{
    public:
        void call(const std::string & no)
        {
            std::cout << "\nMotoPhone Phone making call to :"<< no;
        }
        void message(const std::string & no , const string & messageString)
        {
            std::cout << "\nMotoPhone Phone sending messages "<< messageString << "to "<< no;
        }
};

class PhoneFactory 
{
    public:
        IMobile * getPhone(const MobileType & type)
        {
            switch(type)
            {
                case MobileType::Samsumg:
                {
                    return new SamsumgPhone();
                }
                break;
                case MobileType::Nokia:
                {
                    return new NokiaPhone();
                }
                break;
                case MobileType::Moto:
                {
                    return new MotoPhone();
                }
                break;
            }
        }
};

int main()
{
    std::vector<IMobile *> phones;
    PhoneFactory factory;

    phones.emplace_back(factory.getPhone(MobileType::Moto));
    phones.emplace_back(factory.getPhone(MobileType::Samsumg));
    phones.emplace_back(factory.getPhone(MobileType::Nokia));

    for( auto & phone: phones)
    {
        phone->call("7829712286");
        phone->message("7829712298","Hi how are you");
    }

}
