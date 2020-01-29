#include<iostream>
#include<string>

class HandlerBase 
{
    public:
        HandlerBase()
        {
            next = nullptr;
        }
        void setNext(HandlerBase * n)
        {
            next = n;
        }
        void add(HandlerBase * n)
        {
            if(next)
            {
                next->add(n);
            }
            else 
                next = n;
        }
        virtual void handle(const std::string & buffer)
        {
            if(next)
                next->handle(buffer);
        }
    private:
        HandlerBase * next;
};


class AuthenticationBufferhandler : public HandlerBase
{
    public:
        void handle(const std::string & buffer)
        {
            if(buffer.size() > 5)
            {
                std::cout << "\n Authentication buffer passed ...";
                HandlerBase::handle(buffer);
            }
            else 
            {
                std::cout << "Authentication Buffer failed ";
            }
        }
};

class AuthorisationBufferhandler : public HandlerBase
{
    public:
        void handle(const std::string & buffer)
        {
            if(buffer.size() % 2 == 0)
            {
                std::cout << "\n Authorisation buffer passed ...";
                HandlerBase::handle(buffer);
            }
            else 
            {
                std::cout << "Authorization Buffer failed ";
            }
        }
};

class ProcessBufferhandler : public HandlerBase
{
    public:
        void handle(const std::string & buffer)
        {
            std::cout << "Finally Reading Buffer";
        }
};

using namespace std;
int main()
{
        HandlerBase * rootHandler = new AuthenticationBufferhandler();
        HandlerBase * authorisationBuffer = new AuthorisationBufferhandler();
        HandlerBase * finalHandler = new ProcessBufferhandler();

        rootHandler->add(authorisationBuffer);
        authorisationBuffer->add(finalHandler);
        finalHandler->setNext(nullptr);

        rootHandler->handle("Abhijith");
}
