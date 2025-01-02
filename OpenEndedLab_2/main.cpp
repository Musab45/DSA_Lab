#include <iostream>
using namespace std;

const int MAX_INT = 2147483647; // like infinity

class Graph {
private:
    int vertices;
    int** adjMatrix; //double pointer

public:
    Graph(int v) {
        vertices = v;
        adjMatrix = new int* [vertices];
        for (int i = 0; i < vertices; i++) {
            adjMatrix[i] = new int[vertices];
            for (int j = 0; j < vertices; j++)
                adjMatrix[i][j] = 0;
        }
    }

    void addEdge(int src, int dest, int weight) {
        adjMatrix[src][dest] = weight;
    }

    int minDistance(int dist[], bool visited[]) {
        int min = MAX_INT, min_index = -1;
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }

    void dijkstra(int src, int dest) {
        int* dist = new int[vertices];
        bool* visited = new bool[vertices];
        int* parent = new int[vertices];

        for (int i = 0; i < vertices; i++) {
            dist[i] = MAX_INT;
            visited[i] = false;
            parent[i] = -1;
        }

        dist[src] = 0;

        for (int count = 0; count < vertices - 1; count++) {
            int u = minDistance(dist, visited);
            visited[u] = true;

            for (int v = 0; v < vertices; v++) {
                if (!visited[v] && adjMatrix[u][v] &&
                    dist[u] != MAX_INT &&
                    dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                    parent[v] = u;
                }
            }
        }

        cout << "Shortest distance: " << dist[dest] << "\nPath: ";
        printPath(parent, dest);
        cout << endl;

        delete[] dist;
        delete[] visited;
        delete[] parent;
    }

    void printPath(int parent[], int j) {
        if (parent[j] == -1) return;
        printPath(parent, parent[j]);
        cout << j << " ";
    }

    ~Graph() {
        for (int i = 0; i < vertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    Node* insertRec(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->data) node->left = insertRec(node->left, value);
        else if (value > node->data) node->right = insertRec(node->right, value);
        return node;
    }

    Node* findMin(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    Node* deleteRec(Node* node, int value) {
        if (!node) return node;

        if (value < node->data) node->left = deleteRec(node->left, value);
        else if (value > node->data) node->right = deleteRec(node->right, value);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteRec(node->right, temp->data);
        }
        return node;
    }

    void inorderRec(Node* node) {
        if (node) {
            inorderRec(node->left);
            cout << node->data << " ";
            inorderRec(node->right);
        }
    }

    void preorderRec(Node* node) {
        if (node) {
            cout << node->data << " ";
            preorderRec(node->left);
            preorderRec(node->right);
        }
    }

    void postorderRec(Node* node) {
        if (node) {
            postorderRec(node->left);
            postorderRec(node->right);
            cout << node->data << " ";
        }
    }

public:
    BST() : root(nullptr) {}
    void insert(int value) { root = insertRec(root, value); }
    void remove(int value) { root = deleteRec(root, value); }
    void inorder() { inorderRec(root); cout << endl; }
    void preorder() { preorderRec(root); cout << endl; }
    void postorder() { postorderRec(root); cout << endl; }
};

class Sorting {
private:
    int comparisons, swaps;

    void merge(int arr[], int left, int mid, int right) {
        int i = left, j = mid + 1, k = 0;
        int* temp = new int[right - left + 1];

        // Check for problem
        while (i <= mid && j <= right) {
            comparisons++;
            if (arr[i] <= arr[j]) temp[k++] = arr[i++];
            else temp[k++] = arr[j++];
            swaps++;
        }

        while (i <= mid) { temp[k++] = arr[i++]; swaps++; }
        while (j <= right) { temp[k++] = arr[j++]; swaps++; }

        for (i = left, k = 0; i <= right; i++, k++)
            arr[i] = temp[k];

        delete[] temp;
    }

    void mergeSort(int arr[], int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    int partition(int arr[], int low, int high) {
        int pivot = arr[high], i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            comparisons++;
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                swaps++;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp; // temp
        swaps++;
        return i + 1;
    }

    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

public:
    void performMergeSort(int arr[], int size) {
        comparisons = swaps = 0;
        mergeSort(arr, 0, size - 1);
        cout << "Merge Sort - Comparisons: " << comparisons << ", Swaps: " << swaps << endl;
    }

    void performQuickSort(int arr[], int size) {
        comparisons = swaps = 0;
        quickSort(arr, 0, size - 1);
        cout << "Quick Sort - Comparisons: " << comparisons << ", Swaps: " << swaps << endl;
    }
};

int main() {
    int choice;
    while (true) {
        cout << "\nMenu:\n1. Graph\n2. BST\n3. Sorting\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            int v, e;
            cout << "Vertices: ";
            cin >> v;
            Graph g(v);

            cout << "Edges: ";
            cin >> e;
            cout << "Enter edges (src dest weight):\n";
            for (int i = 0; i < e; i++) {
                int src, dest, weight;
                cin >> src >> dest >> weight;
                g.addEdge(src, dest, weight);
            }

            int source, destination;
            cout << "Source and destination: ";
            cin >> source >> destination;
            g.dijkstra(source, destination);
        }
        else if (choice == 2) {
            BST bst;
            int op;
            do {
                cout << "\nBST:\n1. Insert\n2. Delete\n3. Traversals\n4. Back\nChoice: ";
                cin >> op;

                if (op == 1) {
                    int val;
                    cout << "Value: ";
                    cin >> val;
                    bst.insert(val);
                }
                else if (op == 2) {
                    int val;
                    cout << "Value: ";
                    cin >> val;
                    bst.remove(val);
                }
                else if (op == 3) {
                    cout << "Inorder: "; bst.inorder();
                    cout << "Preorder: "; bst.preorder();
                    cout << "Postorder: "; bst.postorder();
                }
            } while (op != 4);
        }
        else if (choice == 3) {
            int size;
            cout << "Array size: ";
            cin >> size;

            int* arr1 = new int[size];
            int* arr2 = new int[size];

            cout << "Elements:\n";
            for (int i = 0; i < size; i++) {
                cin >> arr1[i];
                arr2[i] = arr1[i];
            }

            Sorting sorter;
            sorter.performMergeSort(arr1, size);
            cout << "Merge Sorted: ";
            for (int i = 0; i < size; i++) cout << arr1[i] << " ";
            cout << endl;

            sorter.performQuickSort(arr2, size);
            cout << "Quick Sorted: ";
            for (int i = 0; i < size; i++) cout << arr2[i] << " ";
            cout << endl;

            delete[] arr1;
            delete[] arr2;
        }
        else if (choice == 4) break;
    }
    system("pause");
    system("cls"); // doesnot work, fix later
    return 0;
}