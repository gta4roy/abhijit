#include <iostream>
using namespace std;

class IPrinter
{
    public:
        virtual void Print() = 0;
};

class IScanner 
{
    public:
        virtual void Scan() = 0;
};

class Printer : public IPrinter
{
    public:
        void Print()
        {
            std::cout << "\nPrinting started...";
        }
};

class Scanner :public IScanner
{   
    public:
        void Scan()
        {
            std::cout << "\n Scanning started ....";
        }
};

class PrinterScanner : public IPrinter, public IScanner
{
    public:
        void Scan()
        {
            m_scanObj.Scan();
        }
        void Print()
        {
            m_printObj.Print();
        }
    private:
        Printer m_printObj;
        Scanner m_scanObj;
};

class PrintManager
{
    public:
        void printJob(IPrinter & obj)
        {
            obj.Print();
        }
};

class ScanManager
{
    public:
        void ScanJob(IScanner & obj)
        {
            obj.Scan();
        }
};


int main()
{
    PrinterScanner obj;
    PrintManager  pMgr;
    ScanManager   scMgr;
    pMgr.printJob(obj);
    scMgr.ScanJob(obj);
}