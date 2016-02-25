#include<iostream>
#include"avl.cpp"
using namespace std;
int main()
{
	avl tree;
	int a[3] = {64,62,63};

	for (int i = 0; i < 3; ++i)
	{
		tree.addleaf(a[i]);
	}

	tree.traversal();
	cout<<endl;
	return(0);
}