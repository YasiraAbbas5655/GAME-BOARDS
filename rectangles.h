#ifndef RECTANGLES_H
#define RECTANGLES_H

class points
{
public:
	points(){x=0;y=0;}
	points(int a,int b){x=a;y=b;}
	points(const points &pt):x(pt.x),y(pt.y){}
	int getX(){return x;}
	int getY(){return y;}
	void set(int a,int b){x=a;y=b;}
	void setX(int a){x=a;}
	void setY(int b){y=b;}
	points operator -(const points &pt){points p(*this);p.x-=pt.x;p.y-=pt.y; return p;}
	points operator +(const points &pt){points p(*this);p.x+=pt.x;p.y+=pt.y; return p;}

private:

	int x;
	int y;

};

class rectangles
{
public:
	//constructor
	rectangles(){};
	rectangles(int topX,int topY,int bottomX,int bottomY){topLeft.set(topX,topY);bottomRight.set(bottomX,bottomY);};
	//draw the rectangle
	void draw(char symbol='-');
	//split the rectangle and return two rectangles
	void split(rectangles &r1,rectangles &r2);
	void DrawShrinkedRectangle(int x=1,int y=1,char symb='-');
private:
	void drawLine(points p1,points p2,char symbol='-');
	points topLeft,bottomRight;

};


#endif