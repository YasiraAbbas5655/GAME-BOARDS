#include <iostream>
using namespace std;
#include "rectangles.h"
#include "myconsole.h"
#include <queue>
#include <math.h>
#include <xtgmath.h>
template <class type> class BinaryTree;


template <class type>
class myNode
{
public:
	myNode(type val){data = val;left=nullptr;right=nullptr;}
private:
	type data;
	/*int NodeNum;*/
	myNode<type> *left;
	myNode<type> *right;
	friend class BinaryTree<type>;

};


template <class type>
class BinaryTree{
public:
	BinaryTree(){rootNode=nullptr;/*current_node_num=0;*/}
	//myNode<type> *find(int num)
	//{
	//	queue<myNode<type>*> q;

 //  // Push the root
	//	q.push(rootNode);
	//	while ( ! q.empty() )
	//	{
 //      // Dequeue a node from front
	//		myNode<type>* v = q.front();
	//		if (v->NodeNum==num)
	//		{
	//			return v;
	//		}

 //      // Enqueue the left children
	//		if ( v->left != nullptr )
	//			q.push(v->left);

 //      // Enqueue the right children
	//		if ( v->right != nullptr )
	//			q.push(v->right);

 //      // Pop the visited node
	//		q.pop();
	//	}
	//	
	//	return nullptr;
	//}
	void print()
	{
		queue<myNode<type>*> q;
		if (rootNode)
		{
		q.push(rootNode);
		}
		while ( ! q.empty() )
		{
			myNode<type>* v = q.front();
			v->data.draw();
			if ( v->left != nullptr )
				q.push(v->left);
			if ( v->right != nullptr )
				q.push(v->right);
			q.pop();

		}
		
		/*int total_nodes=pow(2,compute_height(rootnode))-1;
		for (int i=1;i<=total_nodes;i++)
		{
			mynode<type>* temp =find1(i);
			temp->data.draw();
		}*/
		
	}
	void Make_a_tree(int Height)
	{
		
			rectangles r1(0,0,145,35);
			myNode<type>* temp=new myNode<type>(r1);
			/*temp->NodeNum=1;*/
			rootNode=temp;
			/*current_node_num=1;*/
			int total_nodes=pow(2,Height-1)-1;
			for (int i=1;i<=total_nodes;i++)
			{

				insert_a_node(i);
			}
		

	}
	void insert_a_node(int Nodeno)
	{
		myNode<type>* temp=find1(Nodeno);
		rectangles r2;
        rectangles r3;
		temp->data.split(r2,r3);
		myNode<type>* temp1=new myNode<type>(r2);
		/*current_node_num++;*/
		/*temp1->NodeNum=current_node_num;*/
		myNode<type>* temp2=new myNode<type>(r3);
		/*current_node_num++;
		temp2->NodeNum=current_node_num;*/
		temp->left=temp1;
		temp->right=temp2;
	}
	bool draw_node_no(int num)
	{
		int total_nodes=pow(2,compute_height(rootNode))-1;
		if (num>total_nodes)
		{
			cout<<"invalid input";
			return false;
		}
		else
		{
		    myNode<type>* temp=find1(num);
		    temp->data.draw();
		}
		return true;
	}
	void Delete_Node(int num)
	{
		int total_nodes=pow(2,compute_height(rootNode))-1;
		if (num>total_nodes)
		{
			cout<<"invalid input";
		}
		else{
		queue<myNode<type>*> q;
		q.push(find1(num));
		while ( ! q.empty() )
		{
			myNode<type>* v = q.front();
			q.pop();
			if ( v->left != nullptr )
				q.push(v->left);
			if ( v->right != nullptr )
				q.push(v->right);
			
			delete v;
			
		}
		if (num==1)
		{
			rootNode=nullptr;
		}
		else{
		myNode<type> *temp=find1(num/2);
		if (num%2==0)
		{
			temp->left=nullptr;
		}
		else
		{
			temp->right=nullptr;
		}
		}
		}
	}
	int compute_height(myNode<type> *n)
	{
		int i=0;
		int j=0;
		myNode<type>* temp1=n;
		myNode<type>* temp2=n;
		while (temp1)
		{
			temp1=temp1->left;
			i++;
		}
		while (temp2)
		{
			temp2=temp2->right;
			j++;
		}
		if (i>j)
		{
			return i;
		}
		else
			return j;
	

	}
	int max(int num1,int num2)
	{
		if (num1>=num2)
		{
			return num1;
		}
		else
			return num2;
	}
	myNode<type> *find1(int num)
	{
		if (num==1)
		{
			return rootNode;
		}
		myNode<type>* temp;
		temp=find1(num/2);
		if (num%2==0)
		{
			return temp->left;
		}
		else
		{
			return temp->right;
		}
	}
private:
	/*int current_node_num;*/
	myNode<type> *rootNode;
};





























//
//rectangles r2;
//		    rectangles r3;
//			temp->data.split(r2,r3);
//			myNode<type>* temp1=new myNode<type>(r2);
//			myNode<type>* temp2=new myNode<type>(r3);
//			temp->left=temp1;
//			temp->right=temp2;
//
//			rectangles r4;
//		    rectangles r5;
//			temp1->data.split(r4,r5);
//			myNode<type>* temp3=new myNode<type>(r4);
//			myNode<type>* temp4=new myNode<type>(r5);
//			temp1->left=temp3;
//			temp1->right=temp4;
//
//			rectangles r6;
//		    rectangles r7;
//			temp2->data.split(r6,r7);
//			myNode<type>* temp5=new myNode<type>(r6);
//			myNode<type>* temp6=new myNode<type>(r7);
//			temp2->left=temp5;
//			temp2->right=temp6;