#include <iostream>
#include <string>

using namespace std;

template<class T>
struct OpNewCreator
{
    static T * Create()
    {
        std::cout << "\n Created Using New Operator";
        return new T;
    }
};

template <class T>
struct MallocCreator
{
    static T * Create()
    {
         std::cout << "\n Created Using Malloc call";
        void * buf = std::malloc(sizeof(T));
        if(buf)
            return 0;
        return new(buf) T;
    }
};

template<class T>
struct PrototypeCreator
{
    PrototypeCreator(T * pObj = 0)
    : pPrototype_(pObj)
    {}

    T * Create()
    {
        return pPrototype_ ? pPrototype_->clone() : 0;
    }
    T * GetPrototype()
    {
        return pPrototype_;
    }
    void SetPrototype(T * pObj)
    {
        pPrototype_ = pObj;
    }
    private:
        T * pPrototype_;
};

class Widget
{
    public:
        Widget()
        {
            std::cout << "Widget Created ...";
        }
};

template <class CreationPolicy>
class WidgetManager : public CreationPolicy
{

};

typedef WidgetManager< OpNewCreator<Widget> > MyWidgetMgr;

int main()
{
    WidgetManager <OpNewCreator<Widget> > ourWidget;
    Widget * widGet = ourWidget.Create();

    WidgetManager<MallocCreator< Widget> > mallocCreatedWidget;
    Widget * mallCreated = mallocCreatedWidget.Create();
}