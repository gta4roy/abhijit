#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Circle;
class Rectangle;
class Ellipse;
class IPrinter
{
    public:
       virtual void print(Circle * obj) = 0;
       virtual void print(Rectangle * obj) = 0;
       virtual void print(Ellipse * obj) = 0;
};

class IShape
{   
    public:
       virtual void print(IPrinter * printer) = 0;
};

class Circle :public IShape
{
    public:
        void print(IPrinter * printer)
        {
            printer->print(this);
        }
};

class Ellipse :public IShape
{
    public:
        void print(IPrinter * printer)
        {
            printer->print(this);
        }
};

class Rectangle :public IShape
{
    public:
        void print(IPrinter * printer)
        {
            printer->print(this);
        }
};



class DotMatrixPrinter : public IPrinter
{
    public:
        void print(Circle * obj)
        {
            std::cout << "\nPrinting circle on Dot matrix Printer";
        }
        void print(Rectangle * obj)
        {
            std::cout << "\nPrinting rectangle on Dot matrix Printer";
        }
        void print(Ellipse * obj)
        {
            std::cout << "\nPrinting Ellipse on Dot matrix Printer";
        }
};

class inkJetPrinter : public IPrinter
{
    public:
         void print(Circle * obj)
        {
            std::cout << "\nPrinting circle on inkJetPrinter Printer";
        }
        void print(Rectangle * obj)
        {
            std::cout << "\nPrinting rectangle on inkJetPrinter Printer";
        }
        void print(Ellipse * obj)
        {
            std::cout << "\nPrinting Ellipse on inkJetPrinter Printer";
        }
};


class lazorPrinter : public IPrinter
{
    public:
        void print(Circle * obj)
        {
            std::cout << "\nPrinting circle on lazorPrinter Printer";
        }
        void print(Rectangle * obj)
        {
            std::cout << "\nPrinting rectangle on lazorPrinter Printer";
        }
         void print(Ellipse * obj)
        {
            std::cout << "\nPrinting Ellipse on lazorPrinter Printer";
        }
};

class Picture
{
    public:
        void addShapes(IShape * shape)
        {
            m_shapes.push_back(shape);
        }
        void PrintAll(IPrinter * printer)
        {
            for(IShape * shape: m_shapes)
            {
                shape->print(printer);
            }
        }
    private:
        std::vector<IShape *> m_shapes;
};

int main()
{
    Picture m_picture;
    IShape * circle = new Circle();
    IShape * rect = new Rectangle();
    IShape * ellipse = new Ellipse();

    m_picture.addShapes(circle);
    m_picture.addShapes(rect);
    m_picture.addShapes(ellipse);

    m_picture.PrintAll(new DotMatrixPrinter());
    m_picture.PrintAll(new inkJetPrinter());
    m_picture.PrintAll(new lazorPrinter());
}