#include <iostream>
#include <ctime>
#include <cstdlib>

class DynamicArray 
{
private:
    int* arr;
    int capacity;
    int size;

    void resize(int newCapacity)
    {
        int* newArr = new int[newCapacity];
        for (int i = 0; i < size; ++i)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
    }

public:
    DynamicArray(int initialCapacity = 10)
    {
        arr = new int[initialCapacity];
        capacity = initialCapacity;
        size = 0;
    }

    ~DynamicArray()
    {
        delete[] arr;
    }

    void add(int value) 
    {
        if (size == capacity)
        {
            resize(capacity * 2);
        }
        arr[size++] = value;
    }

    void bubbleSort() 
    {
        for (int i = 0; i < size - 1; ++i)
        {
            for (int j = 0; j < size - i - 1; ++j)
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }

    void selectionSort() 
    {
        for (int i = 0; i < size - 1; ++i)
        {
            int minIdx = i;
            for (int j = i + 1; j < size; ++j)
            {
                if (arr[j] < arr[minIdx])
                {
                    minIdx = j;
                }
            }
            if (minIdx != i) 
            {
                int temp = arr[i];
                arr[i] = arr[minIdx];
                arr[minIdx] = temp;
            }
        }
    }

    DynamicArray* clone()
    {
        DynamicArray* newArray = new DynamicArray(capacity);
        for (int i = 0; i < size; ++i) {
            newArray->add(arr[i]);
        }
        return newArray;
    }

    int getSize() const 
    {
        return size;
    }

    int* getData() 
    {
        return arr;
    }

    void setData(int index, int value) 
    {
        if (index < size) {
            arr[index] = value;
        }
    }
};

struct Node 
{
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST 
{
private:
    Node* root;
    int index;

    Node* insert(Node* node, int value)
    {
        if (node == nullptr) 
        {
            return new Node(value);
        }
        if (value < node->data)
        {
            node->left = insert(node->left, value);
        }
        else 
        {
            node->right = insert(node->right, value);
        }
        return node;
    }

    void inorderTraversal(Node* node, DynamicArray* arr) 
    {
        if (node != nullptr) 
        {
            inorderTraversal(node->left, arr);
            arr->setData(index++, node->data);
            inorderTraversal(node->right, arr);
        }
    }

    void deleteTree(Node* node) 
    {
        if (node != nullptr)
        {
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

public:
    BST() : root(nullptr), index(0) {}

    ~BST()
    {
        deleteTree(root);
    }

    void insert(int value)
    {
        root = insert(root, value);
    }

    void treeSort(DynamicArray* arr)
    {
        index = 0;
        root = nullptr;

        for (int i = 0; i < arr->getSize(); i++)
        {
            insert(arr->getData()[i]);
        }

        inorderTraversal(root, arr);
    }
};

class Timer 
{
private:
    clock_t start_time;
    clock_t end_time;

public:
    void start()
    {
        start_time = clock();
    }

    double stop() 
    {
        end_time = clock();
        return static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
    }
};

void testSortingAlgorithms()
{
    srand(time(NULL));

    int sizes[] = { 10, 100, 1000, 10000, 100000 };

    std::cout << "Sorting Algorithms Scalability Test\n";
    std::cout << "Array Size\tBubble Sort (s)\tSelection Sort (s)\tBST Sort (s)\n";

    for (int sizeIndex = 0; sizeIndex < 5; ++sizeIndex) 
    {
        int currentSize = sizes[sizeIndex];

        DynamicArray* originalArr = new DynamicArray();

        for (int i = 0; i < currentSize; ++i)
        {
            originalArr->add(rand() % 10000);
        }

        DynamicArray* bubbleArr = originalArr->clone();
        DynamicArray* selectionArr = originalArr->clone();
        DynamicArray* bstArr = originalArr->clone();

        Timer timer;
        BST bst;

        timer.start();
        bubbleArr->bubbleSort();
        double bubbleTime = timer.stop();

        timer.start();
        selectionArr->selectionSort();
        double selectionTime = timer.stop();

        timer.start();
        bst.treeSort(bstArr);
        double bstTime = timer.stop();

        std::cout << currentSize << "\t\t"
            << bubbleTime << "\t\t"
            << selectionTime << "\t\t"
            << bstTime << std::endl;

        delete originalArr;
        delete bubbleArr;
        delete selectionArr;
        delete bstArr;
    }
}

int main() {
    testSortingAlgorithms();
    return 0;
}