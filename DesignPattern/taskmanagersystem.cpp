#include<iostream>
#include<vector>
#include<string>
#include <iostream>
#include <map>
using namespace std;

enum class TaskState
{
    CREATED, RUNNING , CANCELLED , COMPLETED , ABORTED , SUSPENDED
};

class Task 
{
    public:
    Task(const std::string & id,const  std::string & name,const  std::string & description,const TaskState & state)
    :
    m_id(id), m_name(name), m_description(description), m_state(state)
    {

    }
    Task & operator= (const Task & task)
    {
        m_id = task.m_id;
        m_description = task.m_description;
        m_name = m_name;
        m_state = m_state;
        return *this;
    }

    std::string getID()
    {
        return m_id;
    }

    void printOnScreen()
    {
        std::cout << "\n ----------------------";
        std::cout << "\n Task Name:"<< m_name;
        std::cout << "\n Task ID:"<< m_id;
        std::cout << "\n Task Description:"<< m_description;
        std::cout << "\n Task State:";
        switch (m_state)
        {
            case TaskState::CREATED:
                /* code */
                std::cout << "Created";
                break;
            case TaskState::ABORTED:
                /* code */
                std::cout << "Aborted";
                break;
            case TaskState::COMPLETED:
                /* code */
                std::cout <<"Completed";
                break;
            case TaskState::CANCELLED:
                /* code */
                std::cout <<"Cancelled";
                break;
            case TaskState::RUNNING:
                /* code */
                std::cout << "Running";
                break;
            case TaskState::SUSPENDED:
                /* code */
                std::cout <<"Suspended";
                break;
        }
        std::cout << "\n ----------------------";

    }

    void changeState(const TaskState & state)
    {
        m_state = state;
    }

    private:
        std::string m_id;
        std::string m_name;
        std::string m_description;
        TaskState m_state;
};



class ITaskObserver
{
    public:
         virtual void taskCreatedNotification(Task * task) = 0;
         virtual  void taskUpdatedNotification(Task * task) = 0;
};

class TaskGrid : public ITaskObserver
{
    public:
        void selectTaskById(std::string & id)
        {
            auto itr = std::find_if(m_taskList.begin(), m_taskList.end(), [&](Task * task){
                return task->getID() == id;
            });

            (*itr)->printOnScreen();
        }
        void Display()
        {
            std::cout << "\n -------Task List-------- ";
            for(Task * task: m_taskList)
            {
                task->printOnScreen();
            }
        }

        void taskCreatedNotification(Task * task)
        {
                m_taskList.push_back(task);
                std::cout << "Task created ";
        }

        void taskUpdatedNotification(Task * task)
        {
            auto foundTaskItr = std::find_if(m_taskList.begin() , m_taskList.end(), [&](Task * mTask){
                    return (mTask->getID() == task->getID());
            });

            if(foundTaskItr != m_taskList.end())
            {
                *foundTaskItr = task;
            }
            std::cout <<"\n Task Updated";
        }

    private:
        std::vector<Task *> m_taskList;
};

class Mediator 
{
    public:
        void Subscribe(const std::string & eventStr, ITaskObserver * observer)
        {
            auto eventItr = m_eventList.find(eventStr);
            if(eventItr != m_eventList.end())
            {
                eventItr->second.push_back(observer);
            }
            else
            {
                std::vector<ITaskObserver *> eventvector;
                eventvector.push_back(observer);
                m_eventList.insert(std::pair<std::string , std::vector<ITaskObserver *> >(eventStr,eventvector));
            }
        }
        void publish(const std::string & eventStr,Task * task)
        {
            std::vector<ITaskObserver *> eventList = m_eventList[eventStr];
            for(ITaskObserver * taskObserver: eventList)
            {
                if(eventStr == "created")
                    taskObserver->taskCreatedNotification(task);
                else if(eventStr == "updated")
                    taskObserver->taskUpdatedNotification(task);
            }
        }
    private:
        std::map<std::string , std::vector< ITaskObserver *> >  m_eventList;
};
class TaskManager
{
    public:
        void createATask(Task * task)
        {
            m_taskEventHandler->publish("created", task);
        }
        void updateTask(const std::string & id, Task * task)
        {
            m_taskEventHandler->publish("updated", task);
        }
        void SetEventHandler(Mediator * taskEventHandler)
        {
            m_taskEventHandler = taskEventHandler;
        }
    private:
        Mediator * m_taskEventHandler;
};

int main()
{
    Mediator * eventHandler = new Mediator();
    TaskGrid  m_TaskGrid;
    ITaskObserver * taskObserver = &m_TaskGrid;

    TaskManager * mTaskManager = new TaskManager();
    mTaskManager->SetEventHandler(eventHandler);
    eventHandler->Subscribe("created",taskObserver);
    eventHandler->Subscribe("updated",taskObserver);

    Task * m_Task1 = new Task("12","Exported","Marginal Scinec", TaskState::CREATED);
    mTaskManager->createATask(m_Task1);

    Task * m_Task2 = new Task("18","Second task","Science Observer",TaskState::CREATED);
    mTaskManager->createATask(m_Task2);

    m_TaskGrid.Display();

    m_Task1->changeState(TaskState::RUNNING);
    mTaskManager->updateTask("12",m_Task1);

    m_TaskGrid.Display();
}