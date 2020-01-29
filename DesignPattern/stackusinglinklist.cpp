#include<iostream>
using namespace std;

struct StackNode
{
    int data;
    StackNode * next;
};

class Stack
{
    public:
        Stack(int max)
        {
            m_max = max;
            m_startPointer = nullptr;
        }

        void push(int data)
        {
            if(m_startPointer == nullptr)
            {
                m_startPointer = new StackNode;
                m_startPointer->data = data;
                m_startPointer->next = nullptr;
            }
            else 
            {
                StackNode * temp = m_startPointer;
                int i = 0;
                while(temp->next != nullptr)
                {
                    i++;
                    temp= temp->next;
                }
                if(i < m_max)
                {
                    StackNode * newBuffer = new StackNode();
                    newBuffer->data = data;
                    temp->next = newBuffer;
                    newBuffer->next = nullptr;
                }
                else 
                {
                    cout << "\n Buffer Overflow ....";
                }
            }
        }

        int pop()
        {
            StackNode * temp = m_startPointer;
            if(temp != nullptr)
            {
                StackNode * prev = nullptr;
                while(temp->next != nullptr)
                {
                    prev = temp;
                    temp = temp->next;
                }

                int popedElement = temp->data;
                delete temp;
                if(prev)
                    prev ->next = nullptr;
                else 
                    m_startPointer = nullptr;

                return popedElement;
            }
            else 
            {
                cout << "\n Buffer is empty can't pop..";
                return -1;
            }
        }

        int peek()
        {
            StackNode * temp = m_startPointer;
            while(temp->next != nullptr)
                temp= temp->next;
            return temp->data;
        }

        bool isEmpty()
        {
            if(m_startPointer == nullptr)
                return true;
            else
            {
                return false;
            }       
        }

    private:
        int         m_max;
        StackNode * m_startPointer;
};

int main()
{
    Stack st(10);
    st.push(78);
    st.push(67);
    st.push(12);
    st.push(43);
    st.push(12);
    st.push(67);
    st.push(23);
    st.push(13);
    st.push(67);
    st.push(93);
    st.push(109);
    st.push(203);

    std::cout <<"\nPoped Element:"<< st.pop();
    std::cout <<"\nPoped Element:"<< st.pop();
    std::cout <<"\nPoped Element:"<< st.pop();
    std::cout <<"\nPoped Element:"<< st.pop();
    std::cout <<"\nPoped Element:"<< st.pop();
    std::cout <<"\nPoped Element:"<< st.pop();
    std::cout <<"\nPoped Element:"<< st.pop();
    std::cout <<"\nPoped Element:"<< st.pop();
    std::cout <<"\nPoped Element:"<< st.pop();
    std::cout <<"\nPoped Element:"<< st.pop();
    std::cout <<"\nPoped Element:"<< st.pop();
    std::cout <<"\nPoped Element:"<< st.pop();
    std::cout <<"\nPoped Element:"<< st.pop();

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);

    std::cout << endl;
    std::cout << endl;
    std::cout << endl;
    std::cout << endl;

    while(!st.isEmpty())
    {
        cout << st.pop();
        cout << "\t";
    }

}