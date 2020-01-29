#include<iostream>
using namespace std;

#define MAX 10

class Stack
{
    public:
        Stack()
        :index(-1)
        {

        }
        void push(int no)
        {
            if(index < MAX)
            {
                index++;
                m_buffer[index]= no;
            }
            else 
            {
                cout << "\nBuffer Overflow ....";
            }
        }

        int pop()
        {
            if(index >= 0)
            {
                int topElement = m_buffer[index];
                m_buffer[index] = -1;
                index --;
                return topElement;
            }
            else 
            {
                cout << "\n Buffer is empty cant pop....";
                return -1;
            }
  
        }

        int peek()
        {
            return m_buffer[index];
        }

        bool isEmpty()
        {
            if(index < 0)
            {
                return true;
            }
            else 
            {
                return false;
            }
        }

    private:
        int index;
        int m_buffer[MAX];
};

int main()
{
    Stack st;
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


}