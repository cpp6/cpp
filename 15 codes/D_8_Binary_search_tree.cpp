/*
D-8
Beginning with an empty binary search tree, Construct a binary search tree by inserting the values in the order given. 
After constructing a binary tree -i. Insert new node ii. Find the number of nodes in the longest path from root 
iii. Minimum data value found in the tree iv. Change a tree so that the roles of the left and right pointers are swapped at every node v. Search for a value. (ANY 3)
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

int height(Node* root) {
    if (root == nullptr)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int findMin(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty\n";
        return -1;
    }
    while (root->left != nullptr)
        root = root->left;
    return root->data;
}

void mirror(Node* root) {
    if (root == nullptr)
        return;
    mirror(root->left);
    mirror(root->right);

    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

bool search(Node* root, int key) {
    if (root == nullptr)
        return false;
    if (root->data == key)
        return true;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

void inorder(Node* root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}


int main() {
    Node* root = nullptr;
    int n, val;

    cout << "How many values do you want to insert into the BST? ";
    cin >> n;
    if (n > 0) {
        cout << "Enter " << n << " values:\n";
        for (int i = 0; i < n; ++i) {
            cin >> val;
            root = insert(root, val);
        }
    }

    int choice;
    do {
        cout << "\n--- BST Operations Menu ---\n";
        cout << "1. Insert a new node\n";
        cout << "2. Find height (longest path from root)\n";
        cout << "3. Find minimum value in tree\n";
        cout << "4. Mirror the tree (swap left/right at every node)\n";
        cout << "5. Search for a value\n";
        cout << "6. Display inorder traversal\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> val;
                root = insert(root, val);
                cout << val << " inserted.\n";
                break;

            case 2: {
                int h = height(root);
                cout << "Height (number of nodes in longest path): " << h << "\n";
                break;
            }

            case 3: {
                if (root == nullptr) cout << "Tree is empty.\n";
                else {
                    int mn = findMin(root);
                    cout << "Minimum value in the tree: " << mn << "\n";
                }
                break;
            }

            case 4:
                mirror(root);
                cout << "Tree mirrored (left and right pointers swapped at every node).\n";
                break;

            case 5:
                cout << "Enter value to search: ";
                cin >> val;
                cout << (search(root, val) ? "Found.\n" : "Not Found.\n");
                break;

            case 6:
                cout << "Inorder traversal: ";
                inorder(root);
                cout << "\n";
                break;

            case 7:
                cout << "Exiting.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);

    return 0;
}
