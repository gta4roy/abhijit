#include <iostream>
#include <vector>
using namespace std;


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
       const std::string & getPatientID() const { return m_patID;}
       const std::string & getPatientName() const { return m_name;}
       const int getAge() const { return m_age;}
       const std::string & getEmail() const { return m_email;}
       const std::string & getPhone() const{ return m_phone;}
        
    private:
        std::string     m_patID;
        std::string     m_name;
        int             m_age;
        std::string     m_email;
        std::string     m_phone;
};

class IPatientDataFilter
{
    public:
        virtual void filter(const std::vector<PatientModel> &,std::vector<PatientModel> & ) = 0;
};

class CompositePatientDataFilter :  public IPatientDataFilter
{
    public:
     void filter(const std::vector<PatientModel> & actualList,std::vector<PatientModel> & resultList)
     {
         for(auto& filter: filterCollection)
         {
             filter.filter(actualList,resultList);
         }
     }

     void addFilter(IPatientDataFilter filter)
     {
         filterCollection.push_back(filter);
     }

     void RemoveFilter(int /*index*/)
     {
        // filterCollection.erase(index);
     }

    private:
        std::vector<IPatientDataFilter> filterCollection;
};

class PatientIDFilter : public IPatientDataFilter
{
    public:
        PatientIDFilter(std::string id)
        {
            ID = id;
        }

        void filter(const std::vector<PatientModel> & actualList,std::vector<PatientModel> & resultList)
        {
            for(int i = 0; i < actualList.size() ; i++)
            {
                if(actualList[i].getPatientID() == ID)
                {
                    resultList.push_back(actualList[i]);
                }
            }
        }
    private:
        std::string ID;
};

class PatientNameFilter : public IPatientDataFilter
{
    public:
        PatientNameFilter(std::string name)
        {
            m_name = name;
        }

        void filter(const std::vector<PatientModel> & actualList,std::vector<PatientModel> & resultList)
        {
            for(int i = 0; i < actualList.size() ; i++)
            {
                if(actualList[i].getPatientName() == m_name)
                {
                    resultList.push_back(actualList[i]);
                }
            }
        }
    private:
        std::string m_name;
};

class PatientDataService
{
    public:
        void addPatient(PatientModel  obj)
        {
            m_patientList.push_back(obj);
        }
        std::vector<PatientModel>  search(IPatientDataFilter & filter)
        {
            std::vector<PatientModel> result;
            filter.filter(m_patientList,result);
            return result;
        }
    private:
        std::vector<PatientModel>  m_patientList;
};

int main()
{
    PatientModel  model1("1","Abhijit",34,"gta4roy1@gmail.com","7829712286");
    PatientModel  model2("2","Rahul",24,"gta4roy2@gmail.com","7829712286");
    PatientModel  model3("2","Marlen",24,"gta4roy3@gmail.com","7829712286");
    PatientModel  model4("3","Saurav",30,"gta4roy4@gmail.com","7829712286");
    PatientModel  model5("4","Gaurva",30,"gta4roy5@gmail.com","7829712286");
    PatientModel  model6("5","Marcus",20,"gta4roy6@6gmail.com","7829712286");
    PatientModel  model7("6","Stella",21,"gta4roy@gmail.com","7829712286");

    PatientDataService service;
    service.addPatient(model1);
    service.addPatient(model2);
    service.addPatient(model3);
    service.addPatient(model4);
    service.addPatient(model5);
    service.addPatient(model6);
    service.addPatient(model7);

    PatientIDFilter filterID("2");
    PatientNameFilter filterName("Abhijit");
    std::vector<PatientModel> result = service.search(filterID);

    for(PatientModel & res : result)
    {
       res.printDetails();
    }

    result.clear();

    result = service.search(filterName);

    for(PatientModel & res : result)
    {
       res.printDetails();
    }

    result.clear();

    CompositePatientDataFilter compositeFilter;

    IPatientDataFilter * _filterID = new PatientIDFilter("2");
    IPatientDataFilter * _filterName = new PatientNameFilter("2");

    compositeFilter.addFilter(*_filterID);
    compositeFilter.addFilter(*_filterName);
    
    result = service.search(compositeFilter);

    for(PatientModel & res : result)
    {
       res.printDetails();
    }

}