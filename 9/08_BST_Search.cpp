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
    int n, value;

    cout << "How many values do you want to insert into the BST? ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nInorder traversal of original BST:\n";
    inorder(root);
    cout << "\n";

    cout << "\nEnter a value to insert into the BST: ";
    cin >> value;
    root = insert(root, value);

    cout << "\nAfter inserting " << value << ":\n";
    inorder(root);
    cout << "\n";

    int treeHeight = height(root);
    cout << "\nLongest path from root (height): " << treeHeight << "\n";

    int minValue = findMin(root);
    cout << "Minimum value in BST: " << minValue << "\n";

    mirror(root);
    cout << "\nInorder traversal of mirrored BST:\n";
    inorder(root);
    cout << "\n";

    cout << "\nEnter a value to search in the BST: ";
    cin >> value;
    bool found = search(root, value);
    cout << "Searching for value " << value << ": ";
    if (found)
        cout << "Found!\n";
    else
        cout << "Not Found.\n";

    return 0;
}
