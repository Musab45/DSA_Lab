#include<iostream>


struct Node {
    int info;
    Node* left;
    Node* right;
    Node* parent;
};

Node* get_node() {
    Node* newnode = new Node();
    newnode->left = nullptr;
    newnode->right = nullptr;
    newnode->parent = nullptr;
    return newnode;
}

class Binary_Tree {
private:
    int itr = -1;

public:
    Binary_Tree() { }

    Node* maketree(int x) {
        Node* p = get_node();
        p->info = x;
        p->left = NULL;
        p->right = NULL;
        return (p);
    }

    Node* Build_Tree(int arr[], int size) {
        itr++;
        if (arr[itr] == -1 || itr >= size) {
            return NULL;
        }
        Node* newnode = maketree(arr[itr]);
        newnode->left = Build_Tree(arr, size);
        newnode->right = Build_Tree(arr, size);
        return newnode;
    }
    void Pre_Order_Traversal(Node* root) {
        if (root == nullptr) {
            return;
        }
        std::cout << root->info << std::endl;
        Pre_Order_Traversal(root->left);
        Pre_Order_Traversal(root->right);
    }
    void In_Order_Traversal(Node* root) {
        if (root == nullptr) {
            return;
        }
        In_Order_Traversal(root->left);
        std::cout << root->info << std::endl;

        Pre_Order_Traversal(root->right);
    }
    void Post_Order_Traversal(Node* root) {
        if (root == nullptr) {
            return;
        }
        Post_Order_Traversal(root->left);
        Post_Order_Traversal(root->right);
        std::cout << root->info << std::endl;
    }

};
int main() {
    Binary_Tree tree;
    Node* root = nullptr;
    int choice;
    bool treeBuilt = false;

    while (true) {
        std::cout << "========= Menu =========\n" << std::endl
            << "1. Build Tree" << std::endl
            << "2. Pre-Order Traversal" << std::endl
            << "3. In-Order Traversal" << std::endl
            << "4. Post-Order Traversal" << std::endl
            << "5. Exit\n" << std::endl
            << "Enter your choice: ";
        std::cin >> choice;
        system("cls");

        if (choice == 1) {
            int size;
            std::cout << "Enter the number of elements in the array e.g (17): ";
            std::cin >> size;

            if (size <= 0) {
                std::cout << "Invalid size. Please try again.\n";
                system("pause");
                system("cls");
            }
            else {
                int* arr = new int[size];
                std::cout << "Enter the elements (-1 for NULL nodes):\n";
                for (int i = 0; i < size; i++) {
                    std::cin >> arr[i];
                }

                root = tree.Build_Tree(arr, size);
                delete[] arr;
                treeBuilt = true;
                std::cout << "Tree built successfully.\n";
                system("pause");
                system("cls");
            }

        }
        else if (choice == 2) {
            if (treeBuilt) {
                std::cout << "Pre-Order Traversal: " << std::endl;
                tree.Pre_Order_Traversal(root);
                std::cout << std::endl;
                system("pause");
                system("cls");
            }
            else {
                std::cout << "Tree not built yet. Please build the tree first.\n";
                system("pause");
                system("cls");
            }

        }
        else if (choice == 3) {
            if (treeBuilt) {
                std::cout << "In-Order Traversal: ";
                tree.In_Order_Traversal(root);
                std::cout << std::endl;
                system("pause");
                system("cls");
            }
            else {
                std::cout << "Tree not built yet. Please build the tree first.\n";
                system("pause");
                system("cls");
            }

        }
        else if (choice == 4) {
            if (treeBuilt) {
                std::cout << "Post-Order Traversal: ";
                tree.Post_Order_Traversal(root);
                std::cout << std::endl;
                system("pause");
                system("cls");
            }
            else {
                std::cout << "Tree not built yet. Please build the tree first.\n";
                system("pause");
                system("cls");
            }

        }
        else if (choice == 5) {
            std::cout << "Exiting program.\n";
            return 0;

        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
            system("pause");
            system("cls");
        }
    }

    return 0;
}