#include<iostream>


template <class t>
class Queue 
{
private:
    int front, rear;
    t* Array;
    int arraysize;
public:
    int count;

    Queue(int size = 2) 
    {
        rear = 0;
        front = 0;
        count = 0;
        arraysize = size;
        Array = new t[arraysize];
    }

    ~Queue() 
    {
        delete[] Array;
    }

    bool isEmpty() 
    {
        return count == 0;
    }

    bool isFull() 
    {
        return count == arraysize;
    }

    void Push(t value) 
    {
        if (!isFull())
        {
            Array[rear] = value;
            rear = (rear + 1) % arraysize;
            count++;
        }
        else
        {
            std::cout << "Queue Overflow" << std::endl;
        }
    }

    t Pop() 
    {
        if (!isEmpty()) 
        {
            t temp = Array[front];
            front = (front + 1) % arraysize;
            count--;
            return temp;
        }
        else 
        {
            std::cout << "Queue Underflow" << std::endl;
            return "";
        }
    }
};

int main() 
{
    int arraysize;
    std::cout << "How many persons will be there: ";
    std::cin >> arraysize;
    system("cls");

    Queue<std::string> TeacherQueue(arraysize), StudentQueue(arraysize), AdminQueue(arraysize), MainQueue(arraysize * 3);

    std::string choice;

    while (true)
    {
        std::cout << "Welcome to Priority Queue implementation." << std::endl;
        std::cout << "1. Add Admin" << std::endl
            << "2. Add Teacher" << std::endl
            << "3. Add Student" << std::endl
            << "4. Display" << std::endl
            << "5. Exit" << std::endl
            << "Enter your choice: ";
        std::cin >> choice;
        system("cls");

        if (choice[0] == '1') 
        {
            for (int i = 0; i < arraysize; i++) 
            {
                std::string Name;
                std::cout << "Enter Admin Name: ";
                std::cin >> Name;
                AdminQueue.Push(Name);
            }
        }
        else if (choice[0] == '2') 
        {
            for (int i = 0; i < arraysize; i++)
            {
                std::string Name;
                std::cout << "Enter Teacher Name: ";
                std::cin >> Name;
                TeacherQueue.Push(Name);
            }
        }
        else if (choice[0] == '3')
        {
            for (int i = 0; i < arraysize; i++)
            {
                std::string Name;
                std::cout << "Enter Student Name: ";
                std::cin >> Name;
                StudentQueue.Push(Name);
            }
        }
        else if (choice[0] == '4')
        {
            int teachercount = TeacherQueue.count;
            int studentcount = StudentQueue.count;
            int admincount = AdminQueue.count;

            for (int i = 0; i < admincount; i++) 
            {
                MainQueue.Push(AdminQueue.Pop());
            }
            for (int i = 0; i < teachercount; i++)
            {
                MainQueue.Push(TeacherQueue.Pop());
            }
            for (int i = 0; i < studentcount; i++) 
            {
                MainQueue.Push(StudentQueue.Pop());
            }

            int maincount = MainQueue.count;
            std::cout << "Displaying Priority wise data: " << std::endl;
            for (int i = 0; i < maincount; i++)
            {
                std::cout << (i + 1) << ". " << MainQueue.Pop() << std::endl;
            }
        }
        else if (choice[0] == '5') 
        {
            std::cout << "Exiting Priority Queue Program." << std::endl;
            break;
        }
        else 
        {
            std::cout << "Invalid input, please try again." << std::endl;
            system("pause");
        }
        system("cls");
    }

    return 0;
}