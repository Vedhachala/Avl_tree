#include<iostream>
#include"avl.h"
using namespace std;

avl::avl()
{
	root = NULL;
}

avl::node* avl::createleaf(int key)
{
	node* n = new node;
	n->key = key;
	n->height = 0;
	n->parent = NULL;
	n->left = NULL;
	n->right = NULL;

	return n;
}

void avl::addleaf(int key)
{
	addleaf_private(root,key);
}

void avl::addleaf_private(node* ptr,int key)
{
	temp = createleaf(key);

	if(root == NULL)
		root = temp;

	else if(key < ptr->key){

		if(ptr->left == NULL){
			ptr->left = temp;
			temp->parent = ptr;
			ht_update(ptr);
		}

		else
			addleaf_private(ptr->left,key);
	}

	else if(key > ptr->key){
			
		if(ptr->right == NULL){
			ptr->right = temp;
			temp->parent = ptr;
			ht_update(ptr);
		}

		else
			addleaf_private(ptr->right,key);
	}

	else{
		cout<<"Already added"<<endl;
		return;
	}

	avl_fix(ptr);
}

void avl::ht_update(node* ptr)
{
	while(ptr!=NULL){
		ptr->height = max(ht(ptr->left),ht(ptr->right))+1;
		ptr = ptr->parent;
	}
}

void avl::avl_fix(node* ptr)
{
	if(ptr != NULL){
		if(ht(ptr->right)-ht(ptr->left) > 1){

			if(ht(ptr->right->left)-ht(ptr->right->right) > 0){
				right_rotate_pr(ptr->right);
				left_rotate_pr(ptr);
			}

			else
				left_rotate_pr(ptr);
	
		}

		else if(ht(ptr->left)-ht(ptr->right) > 1){

			if(ht(ptr->left->right)-ht(ptr->left->left) > 0){
				left_rotate_pr(ptr->left);
				right_rotate_pr(ptr);
			}

			else
				right_rotate_pr(ptr);
	
		}

		else
			avl_fix(ptr->parent);
	}
}

int avl::ht(node* ptr)
{
	if(ptr == NULL)
		return -1;
	else
		return ptr->height;
}

void avl::left_rotate_pr(node* ptr)
{

	temp = ptr->right;
	swap(ptr->height,temp->height);
	ptr->right = temp->left;
	temp->left = ptr;
	temp->parent = ptr->parent;
	ptr->parent = temp;

	if(temp->parent == NULL)
		root = temp;
	else if(temp->parent->key > temp->key)
		temp->parent->left = temp;
	else
		temp->parent->right = temp;
	
	ht_update(ptr);
	
}

void avl::right_rotate_pr(node* ptr)
{
	temp = ptr->left;
	ptr->left = temp->right;
	temp->right = ptr;
	temp->parent = ptr->parent;
	ptr->parent = temp;

	if(temp->parent == NULL)
		root = temp;
	else if(temp->parent->key > temp->key)
		temp->parent->left = temp;
	else
		temp->parent->right = temp;

	ht_update(ptr);
}

void avl::traversal()
{
	traversal_private(root);
}

void avl::traversal_private(node* ptr)
{
	if(ptr->left != NULL)
		traversal_private(ptr->left);
	cout<<ptr->key<<" "<<ht(ptr)<<endl;
	if(ptr->right != NULL)
		traversal_private(ptr->right);
}
