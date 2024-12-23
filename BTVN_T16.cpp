/*
Cài đặt cây AVL để nhập một dãy số cho trước thành một cây AVL:
17 23 201 98 67 83 13 23 10 191 84 58 
Yêu cầu:
1. Cài đặt hàm nhập node mới
2. Cài đặt hàm xoay đơn/kép
3. Cài đặt hàm kiểm tra cân bằng
4. Cài đặt hàm in cây AVL (theo thứ tự duyệt)
*/
#include <iostream>
#include <algorithm> // Để sử dụng hàm std::max

using namespace std;

//Cài đặt thuộc tính cho một node trên cây 
struct Node {
    int data;             
    Node* left;         
    Node* right;        
    int height; // Chiều cao của nút

    //Hàm constructor khởi tạo những giá trị ban đầu 
    AvlNode(int val) : value(val), left(nullptr), right(nullptr), height(0) {}
};

// Hàm trả về chiều cao của một nút
int height(AvlNode* node) {
    return node == nullptr ? -1 : node->height;
}

// Cập nhật chiều cao của một nút
void updateHeight(AvlNode* node) {
    if (node != nullptr) {
        node->height = max(height(node->left), height(node->right)) + 1;
    }
}

// Hàm xoay phải
void rotateWithLeftChild(AvlNode*& k2) {
    AvlNode* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    updateHeight(k2);
    updateHeight(k1);
    k2 = k1;
}

// Hàm xoay trái
void rotateWithRightChild(AvlNode*& k2) {
    AvlNode* k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    updateHeight(k2);
    updateHeight(k1);
    k2 = k1;
}

// Hàm xoay kép trái-phải
void doubleWithLeftChild(AvlNode*& k3) {
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

// Hàm xoay kép phải-trái
void doubleWithRightChild(AvlNode*& k3) {
    rotateWithLeftChild(k3->right);
    rotateWithRightChild(k3);
}

// Hàm cân bằng cây
void balance(AvlNode*& node) {
    if (node == nullptr) return;

    if (height(node->left) - height(node->right) > 1) {
        if (height(node->left->left) >= height(node->left->right)) {
            rotateWithLeftChild(node);
        } else {
            doubleWithLeftChild(node);
        }
    } else if (height(node->right) - height(node->left) > 1) {
        if (height(node->right->right) >= height(node->right->left)) {
            rotateWithRightChild(node);
        } else {
            doubleWithRightChild(node);
        }
    }

    updateHeight(node);
}

// Hàm chèn giá trị vào cây AVL
void insert(int value, AvlNode*& node) {
    if (node == nullptr) {
        node = new AvlNode(value);
    } else if (value < node->value) {
        insert(value, node->left);
    } else if (value > node->value) {
        insert(value, node->right);
    }
    balance(node);
}

// Hàm duyệt cây theo thứ tự giữa (in-order traversal)
void inOrderTraversal(AvlNode* node) {
    if (node != nullptr) {
        inOrderTraversal(node->left);
        cout << node->value << " ";
        inOrderTraversal(node->right);
    }
}

// Hàm chính
int main() {
    AvlNode* root = nullptr;
    int values[] = {17, 23, 201, 98, 67, 83, 13, 23, 10, 191, 84, 58};

    for (int value : values) {
        insert(value, root);
    }

    cout << "Cây AVL sau khi chèn các giá trị theo thứ tự duyệt giữa: ";
    inOrderTraversal(root);

    return 0;
}


