#include<bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node *lt;
	struct Node *rt;
};

Node* FindMin(Node* r)
{
	while(r->lt != NULL)
        r = r->lt;

	return r;
}

Node* FindMax(Node* r)
{
	while(r->rt != NULL)
        r = r->rt;

	return r;
}

struct Node* Remove(struct Node *r, int data) {
	if(r == NULL)
        return r;

	else if(data < r->data)
        r->lt = Remove(r->lt, data);

	else if (data > r->data)
        r->rt = Remove(r->rt,data);

	else {
	    if(r->lt == NULL && r->rt == NULL) {
			delete r;
			r = NULL;
		}

		else if(r->lt == NULL) {
			struct Node *temp = r;
			r = r->rt;
			delete temp;
		}

		else if(r->rt == NULL) {
			struct Node *temp = r;
			r = r->lt;
			delete temp;
		}

		else {
			struct Node *temp = FindMin(r->rt);
			r->data = temp->data;
			r->rt = Remove(r->rt,temp->data);
		}
	}
	return r;
}

Node* Insert(Node *r,char data) {
	if(r == NULL) {
		r = new Node();
		r->data = data;
		r->lt = r->rt = NULL;
	}
	else if(data <= r->data)
		r->lt = Insert(r->lt,data);
	else
		r->rt = Insert(r->rt,data);
	return r;
}

void Inorder(Node *r) {
	if(r == NULL)
        return;

	Inorder(r->lt);
	printf("%d ",r->data);
	Inorder(r->rt);
}
int main() {
	Node* r = NULL;
	r = Insert(r, 60);
    r = Insert(r, 41);
	r = Insert(r, 74);
	r = Insert(r, 16);
	r = Insert(r, 53);
	r = Insert(r, 65);
    r = Insert(r, 25);
	r = Insert(r, 46);
	r = Insert(r, 55);
	r = Insert(r, 63);
	r = Insert(r, 79);
	r = Insert(r, 42);
	r = Insert(r, 62);
	r = Insert(r, 64);
	r = Insert(r, 47);
    cout<<"\n Printing Tree After Insertion: ";
	Inorder(r);
	cout<<"\n";
	r = Remove(r, 47);
	cout<<"\n Printing Tree After Deletion: ";
	Inorder(r);
	cout<<"\n";
    Node *temp = FindMin(r);
    cout << "\n Minimum Element in tree: " << temp->data << endl;
    Node *temp1 = FindMax(r);
    cout << "\n Maximum Element in tree: " << temp1->data << endl;
}
