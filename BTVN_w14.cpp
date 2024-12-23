/*
Cài đặt cây biểu thức cho biểu thức a*5 - (b*c^6)/d + (h-f)*e^(1/2), và in ra biểu thức theo các cách biểu diễn Trung tố, hậu tố, và tiền tố.
Định nghĩa và khai báo các hàm sau:
1. Cài đặt thuộc tính cho 1 node trên cây 
2. Cài đặt hàm khởi tạo cây (không được bỏ qua hàm kiểm tra rỗng)
3. Cài đặt hàm nhập phần tử (bổ sung) vào cây 
4. In các phần tử trên cây theo 3 giải thuật duyệt 
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std; 
//Cài đặt thuộc tính cho một Node trên cây 
struct Node {
    string data;
    Node* left;
    Node* right;

    Node(string value)
    {
        data = value;
		left = NULL;
        right = NULL;
    }
};

//Hàm khởi tạo cây
void Init_Tree(Node* root)
{
   root = NULL;
}

//Hàm kiểm tra rỗng
int isEmpty(Node* root)
{
   return root == NULL? 1 : 0; 
}

//Hàm nhập cây 
Node* insertNode()
{
    Node* root = new Node("+");
    root->left = new Node("-");
    root->right = new Node("*");
    
    root->left->left = new Node("*");
    root->left->right = new Node("*");

   root->left->left->left = new Node("a");
   root->left->left->right = new Node("5");

   root->left->right->left = new Node("b");
   root->left->right->right = new Node("/");

   root->left->right->right->left = new Node("^");
   root->left->right->right->right = new Node("d");
   root->left->right->right->left->left = new Node("c");
   root->left->right->right->left->right = new Node("6");

   root->right->left = new Node("-");
   root->right->right = new Node("^");

   root->right->left->left = new Node("h");
   root->right->left->right = new Node("f"); 

   root->right->right->left = new Node("e");
   root->right->right->right = new Node("/");

   root->right->right->right->left = new Node("1");
   root->right->right->right->right = new Node("2");

   return root;

}


//Duyệt Trung tố
void inOrder(Node* root) 
{
    if (root != NULL) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

//Duyệt Tiền tố
void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

//Duyệt Hậu tố
void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root;
    Init_Tree(root);
    if(isEmpty(root)) return 0;

    root = insertNode();

    cout << "Duyet Trung to: ";
    inOrder(root);
    cout << endl;

    cout << "Duyet Tien to: ";
    preOrder(root);
    cout << endl;

    cout << "Duyet Hau to: ";
    postOrder(root);
    cout << endl;

    return 0;
}
