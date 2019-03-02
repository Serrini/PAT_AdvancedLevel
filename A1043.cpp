#include <cstdio>
#include <vector>
using namespace std;


struct node
{
	int data;
	node* left;
	node* right;
};

void insert(node* &root, int data){
	if (root == NULL)
	{
		//找到插入位置
		root = new node;
		root->data = data;
		root->left = NULL;
		root->right = NULL;
		return;
	}
	if (data < root->data)
	{
		//如果要插入的数字比当前数字小，则往左子树上插入
		insert(root->left, data);
	}else{
		//否则往右子树上插入
		insert(root->right, data);
	}
}

//前序
void preorder(node* root, vector<int> &vi){
	if(root == NULL) return;
	vi.push_back(root->data);
	preorder(root->left, vi);
	preorder(root->right, vi);
}

//前序镜像
void preMorder(node* root, vector<int> &vi){
	if(root == NULL) return;
	vi.push_back(root->data);
	preMorder(root->right, vi);
	preMorder(root->left, vi);
}

//后序
void postorder(node* root, vector<int> &vi){
	if(root == NULL) return;
	postorder(root->left, vi);
	postorder(root->right, vi);
	vi.push_back(root->data);
}

//后序镜像
void postMorder(node* root, vector<int> &vi){
	if(root == NULL) return;
	postMorder(root->right, vi);
	postMorder(root->left, vi);
	vi.push_back(root->data);
}

vector<int> origin, pre, preM, post, postM;

int main()
{
	node* root = NULL; //定义头节点，初始化为NULL
	int n, data;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &data);
		origin.push_back(data);
		insert(root, data);
	}

	preorder(root, pre);
	preMorder(root, preM);
	postorder(root, post);
	postMorder(root, postM);

	if (origin == pre)
	{
		printf("YES\n");
		for (int i = 0; i < post.size(); i++)
		{
			printf("%d", post[i]);
			if (i < post.size()-1)
			{
				printf(" ");
			}
		}
	}else if (origin == preM)
	{
		printf("YES\n");
		for (int i = 0; i < postM.size(); i++)
		{
			printf("%d", postM[i]);
			if (i < postM.size()-1)
			{
				printf(" ");
			}
		}
	}else{
		printf("NO\n");
	}

	return 0;
}