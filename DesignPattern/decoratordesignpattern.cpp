    #include <iostream>
using namespace std;

class Widget 
{
    public:
        virtual void draw() = 0;
};

class TextField : public Widget
{
    public:
        TextField(int w, int h)
        :
        width(w),
        height(h)
        {
        }
        void draw() override
        {
            cout << "Text Field "<< width <<","<< height<< "\n";
        }
    private:
        int width, height;
};

class Decorator : public Widget
{
    public:
        Decorator(Widget * ptr)
        {
            m_widget = ptr;
        }

        void draw() override
        {
            cout <<" Decorator ";
            m_widget->draw();
        }
    private:
        Widget * m_widget;
};

class BorderDecorator : public Decorator 
{
    public:
        BorderDecorator(Widget * ptr): Decorator(ptr){}
        void draw()
        {
            Decorator::draw();
            cout << "Border decorator drawn";
        }
};

class ScrollDecorator : public Decorator 
{
    public:
        ScrollDecorator(Widget * ptr): Decorator(ptr){}
        void draw()
        {
            Decorator::draw();
            cout << "Border decorator drawn";
        }
};

int main()
{
    Widget * aWidget = new BorderDecorator(new BorderDecorator(new ScrollDecorator(new TextField(80,24))));
    aWidget->draw();
}

