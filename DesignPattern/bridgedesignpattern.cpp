#include <iostream>
#include<string>
#include <vector>
using namespace std;

class DrawingAPI
{
    public:
    virtual void drawCircle(float x, float y ,float radius ) const = 0;
};

class DrawingAPI101 : public DrawingAPI
{
    public:
       void  drawCircle(float x, float y , float radius ) const override 
        {
           cout << "\n Drawing circle from AP 101 "<< x << y<< radius;
        }
};


class DrawingAPI102 : public DrawingAPI
{
    public:
       void  drawCircle(float x, float y , float radius ) const override 
        {
           cout << "\n Drawing circle from AP 102 "<< x << y<< radius;
        }
};


class Shape 
{
    public:
    Shape(DrawingAPI * api)
        :
        m_drawingApi(api)
    {

    }
    virtual void draw() = 0;
    protected:
        DrawingAPI * m_drawingApi;
};

class CircleShape : public Shape
{
    public:
        CircleShape(int x , int y , int radius , DrawingAPI * api)
        :
       m_x(x), m_y(y), m_radius(radius) , Shape(api)
       {

       }
       void draw () override
       {
           m_drawingApi->drawCircle(m_x,m_y,m_radius);
       }
    
    private:
        int m_x;
        int m_y;
        int m_radius;
};
int main()
{
    DrawingAPI * api101 = new DrawingAPI101();
    DrawingAPI * api102 = new DrawingAPI102();

    Shape * circleShape = new CircleShape(12,13,23,api101);
    circleShape->draw();

    Shape * circleShape2 = new CircleShape(12,34,12,api102);
    circleShape2->draw();
}