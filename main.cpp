#include <iostream>
using namespace std;
#include "rectangles.h"
#include "Header.h"
#include "myconsole.h"
int main()
{
	
	BinaryTree<rectangles> b1;
main:
	system("cls");
	b1.print();
	PlaceCursor(0,36);
	cout<<"To make a Tree of height n press 1"<<endl<<"To delete a Node press 2"<<endl<<"To insert node press 3"<<endl<<"To Draw a Node Press 4"<<endl;
	int num;
	cin>>num;
	if (num==1)
	{
		int x;
		cin>>x;
	
		b1.Make_a_tree(x);
		goto main;
	}

	if (num==2)
	{
		int x;
		cin>>x;
		b1.Delete_Node(x);
		goto main;
	}

	if (num==3)
	{
		int x;
		cin>>x;
		b1.insert_a_node(x);
		goto main;
	}

	if (num==4)
	{
		int x;
		cin>>x;
		system("cls");
		b1.draw_node_no(x);
		_sleep(2000);
		goto main;
	}
	
	system("pause");
	return 0;
}









/*rectangles r1(1,1,40,40);
	rectangles r2;
	rectangles r3;
	r1.split(r2,r3);
	r2.draw();
	r3.draw();
	r1.draw();*/