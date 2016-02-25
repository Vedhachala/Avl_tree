class avl
{
	struct node
	{
		int key;
		int height;
		node* parent;
		node* left;
		node* right; 
	};

	node* root;
	node* temp;

	node* createleaf(int key);
	void addleaf_private(node* ptr,int key);
	void avl_fix(node* ptr);
	int ht(node* ptr);
	void ht_update(node* ptr);
	void left_rotate_pr(node* ptr);
	void right_rotate_pr(node* ptr);

	void traversal_private(node* ptr);

public:

	avl();
	void addleaf(int key);
	void traversal();
};