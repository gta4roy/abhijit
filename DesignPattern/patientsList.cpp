#include <iostream>
#include <vector>
using namespace std;
#define MAX 10

class DataModel
{
    public :
        virtual void printDetails() = 0;
};

class PatientModel : public DataModel
{
    public:
        PatientModel(const string patId, const string name, const int age, const string email ,const string phone )
        :
            m_patID(patId),
            m_name(name),
            m_age(age),
            m_email(email),
            m_phone(phone)
        {

        }

        void operator = (const PatientModel & obj)
        {
             this->m_patID = obj.m_patID;
            this->m_age = obj.m_age;
            this->m_email = obj.m_email;
            this->m_name = obj.m_name;
            this->m_phone = obj.m_phone;
        }
        PatientModel(const PatientModel & obj)
        {
            this->m_patID = obj.m_patID;
            this->m_age = obj.m_age;
            this->m_email = obj.m_email;
            this->m_name = obj.m_name;
            this->m_phone = obj.m_phone;
        }
        void printDetails()
        {
            std::cout << "\n MRN :"<< this->m_patID;
            std::cout << "\n Name :"<< this->m_name;
            std::cout << "\n Age :"<< this->m_age;
            std::cout << "\n Email :"<< this->m_email;
            std::cout << "\n Phone :"<< this->m_phone;
        }
    private:
        std::string     m_patID;
        std::string     m_name;
        int             m_age;
        std::string     m_email;
        std::string     m_phone;
};
class IIteratable;
class IIterator
{
    public:
        virtual void MoveNext()             = 0;
        virtual DataModel * getCurrent()    = 0;
        virtual bool   isEnd()              = 0;
    private:
        int moveIndex;
};

class IIteratable
{
    public:
        virtual IIterator * getIterator() = 0;
};

class PatientDataIterator: public IIterator
{
    public:
        PatientDataIterator(PatientModel * itr[MAX])
        {
            for(int i = 0; i <MAX ; i++ )
            {
                m_list[i] = itr[i];
            }
        }
        void MoveNext()
        {
            index++;
            if(m_list[index] != nullptr)
                m_current = m_list[index];
            else 
            {
                index ++;
                m_current = nullptr;
            }
        }

        bool isEnd()
        {
            if(index < MAX)
                return false;
            else 
                return true;
        }
        PatientModel * getCurrent()
        {
            return m_current;
        }
    private:
        int index = -1;
        PatientModel * m_current;
        PatientModel * m_list[MAX];
};

class PatientList : public IIteratable
{
    public:
        PatientList()
        {
            for(int i = 0; i < MAX ; i++)
                m_patientList[i] = nullptr;

            index = -1;
        }
        void Add(const PatientModel &obj)
        {
            index++;
            if(index < MAX)
            {
                m_patientList[index] = new PatientModel(obj);
            }
            else 
            {
                std::cout << "\n Container is full";
            }
        }

        void Remove(const int index)
        {
            if(index >=0 && index < MAX)
            {
                if(m_patientList[index] != nullptr)
                {
                    std::cout << "\n  removing the patient ID :";
                    m_patientList[index]->printDetails();
                    delete m_patientList[index];
                    m_patientList[index] = nullptr;
                }
            }
        }

        std::vector<PatientModel> getAll()
        {
            std::vector<PatientModel>  result;
            for(int i = 0; i < MAX ; i++)
            {
                if(m_patientList[i] != nullptr)
                {
                    result.push_back(*m_patientList[i]);
                }
            }
            return result;
        }

        int getCount()
        {
            int count = 0;
            for(int i = 0; i < MAX ; i++)
            {
                if(m_patientList[i] != nullptr)
                    count ++;
            }
            return count;
        }

        IIterator * getIterator() 
        {
            if(m_dataIterator != nullptr)
            {
                delete m_dataIterator;
            }
            m_dataIterator = new PatientDataIterator(m_patientList);
            return m_dataIterator;
        }

        
    private:
        int index;
        PatientModel * m_patientList[MAX];
        PatientDataIterator * m_dataIterator;
};
int main()
{

    PatientModel  obj1("1233","Abhijit Roy",23,"gtsssa4roy@gmail.com","7829712296");
    PatientModel  obj2("373","Abhijit Roy",23,"gtsssa4roy@gmail.com","7829712296");
    PatientModel  obj3("3763","Abhijit Roy",23,"gtsssa4roy@gmail.com","7829712296");
    PatientModel  obj4("362","Abhijit Roy",23,"gtsssa4roy@gmail.com","7829712296");
    PatientModel  obj5("837","Abhijit Roy",23,"gtsssa4roy@gmail.com","7829712296");
    PatientModel  obj6("1262","Abhijit Roy",23,"gtsssa4roy@gmail.com","7829712296");
    PatientList list;
    list.Add(obj1);
    list.Add(obj2);
    list.Add(obj3);
    list.Add(obj4);
    list.Add(obj5);
    list.Add(obj6);

    IIterator * itrPtr = list.getIterator();

    while(!itrPtr->isEnd())
    {
        itrPtr->MoveNext();
        if(itrPtr->getCurrent())
            itrPtr->getCurrent()->printDetails();
    
    }
}