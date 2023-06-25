#include<stdio.h>
#include <stdlib.h>

using namespace std;

struct Node
{
    struct Node* left;
    int item;
    struct Node* right;
};
Node* root = nullptr;
struct Node* createNode(int data)
{
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->item = data;
    temp->left = nullptr;
    temp->right = nullptr;
    if (root == nullptr)
        root = temp;
    return temp;
}
struct Node* insert(struct Node* r, int data)
{
    if (r == nullptr)
        return createNode(data);
    if (data < r->item)
        r->left = insert(r->left, data);
    else
        r->right = insert(r->right, data);
    return r;
}
struct Node* successorNode(struct Node* r)
{
    struct Node* cur = r;
    while (cur && cur->left != nullptr)
        cur = cur->left;
    return cur;
}
struct Node* deleteNode(struct Node* r, int data)
{
    if (r == nullptr)
        return r;
    if (data < r->item)
        r->left = deleteNode(r->left, data);
    else if (data > r->item)
        r->right = deleteNode(r->right, data);
    else
    {
        if (r->left == nullptr)
        {
            struct Node* temp = r->right;
            free(r);
            return temp;
        }
        else if (r->right == nullptr)
        {
            struct Node* temp = r->left;
            free(r);
            return temp;

        }
        struct Node* temp = successorNode(r->right);
        r->item = temp->item;
        r->right = deleteNode(r->right, temp->item);
    }
    return r;
}
void inorder(struct Node* root)
{
    if (root) {
        inorder(root->left);
        printf("%d ", root->item);
        inorder(root->right);
    }
}
void preorder(struct Node* root)
{
    if (root) {
        printf("%d ", root->item);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root)
{
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->item);
    }
}
struct Node* search(struct Node* root, int data)
{
    if (root == nullptr)
        return root;
    if (root->item == data)
        return root;
    if (data < root->item)
        return search(root->left, data);
    else
        return search(root->right, data);
}


int main() {
	int choice;
	cout << "***Storing data in tree****" << endl << endl;
	while (true) {
		cout << "1. insert data to node in tree" << endl;
		cout << "2. search data in tree " << endl;
		cout << "3. delete data from tree" << endl;
		cout << "4. traverse preorder in tree" << endl;
		cout << "5. traverse ineorder in tree" << endl;
		cout << "6. traverse postorder in tree" << endl;
		cout << "Enter your choice" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			int enterData;
			cout << "Enter data ";
			cin >> enterData;
			insert(root, enterData);
			break;
		case 2:
			int searchData;
			cout << "Enter data ";
			cin >> searchData;
			if (search(root, searchData))
				cout << "Data found" << endl;
			else
				cout << "Data not found" << endl;
			break;
		case 3:
			int deleteData;
			cout << "Enter data ";
			cin >> deleteData;
			deleteNode(root, deleteData);
			break;
		case 4:
			preorder(root);
			break;
		case 5:
			inorder(root);
			break;
		case 6:
			postorder(root);
			break;
		}

	}

	return 0;
}