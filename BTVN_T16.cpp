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
struct Node 
{
    int data;             
    Node* left;         
    Node* right;        
    int height; // Chiều cao của nút

    Node(int val)
    {
        data = val;
		left = NULL;
        right = NULL;
        height = 0; 
    }
};

//Hàm khởi tạo cây
void Init_AVL(Node*& root)
{
   root = NULL;
}

//Hàm kiểm tra rỗng
int isEmpty(Node* root)
{
   return root == NULL? 1 : 0; 
}

// Hàm trả về chiều cao của một nút
int height(Node* node) 
{
    return node == NULL ? -1 : node->height;
}

// Cập nhật chiều cao của một nút
void updateHeight(Node* node) 
{
    if (node != NULL) 
    {
        node->height = max(height(node->left), height(node->right)) + 1;
    }
}

// Hàm xoay phải
void rotateWithLeftChild(Node*& k2) 
{
    Node* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;
    updateHeight(k2);
    updateHeight(k1);
    k2 = k1;
}

// Hàm xoay trái
void rotateWithRightChild(Node*& k2) 
{
    Node* k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;
    updateHeight(k2);
    updateHeight(k1);
    k2 = k1;
}

// Hàm xoay kép trái-phải
void doubleWithLeftChild(Node*& k3) 
{
    rotateWithRightChild(k3->left);
    rotateWithLeftChild(k3);
}

// Hàm xoay kép phải-trái
void doubleWithRightChild(Node*& k3) 
{
    rotateWithLeftChild(k3->right);
    rotateWithRightChild(k3);
}

// Hàm cân bằng cây
void balance(Node*& node) 
{
    if (node == NULL) return;

    if (height(node->left) - height(node->right) > 1) 
    {
        if (height(node->left->left) >= height(node->left->right)) 
        {
        rotateWithLeftChild(node);
        }
        else doubleWithLeftChild(node);
    } 
    else if (height(node->right) - height(node->left) > 1) 
    {
        if (height(node->right->right) >= height(node->right->left)) 
        {
            rotateWithRightChild(node);
        } 
        else 
        {
            doubleWithRightChild(node);
        }
    }
    updateHeight(node);
}

// Hàm chèn giá trị vào cây AVL
void insert(int val, Node*& node) 
{
    if (node == NULL) 
    {
        node = new Node(val);
    } 
    else if (val < node->data) 
    {
        insert(val, node->left);
    } 
    else if (val > node->data) 
    {
        insert(val, node->right);
    }
    balance(node);
}

// Hàm duyệt cây
void inOrderTraversal(Node* node) 
{
    if (node != nullptr) {
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }
}

// Hàm chính
int main() 
{
    Node* root;
    Init_AVL(root); // Khởi tạo cây AVL

    if (isEmpty(root)) 
    {
        cout << "Cay AVL rong" << endl;
    }

    int data[] = {17, 23, 201, 98, 67, 83, 13, 23, 10, 191, 84, 58};
    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) 
    {
    insert(data[i], root);
    }
    cout << "Cay AVL: ";
    inOrderTraversal(root);
    return 0;
}


