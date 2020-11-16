#pragma once
#ifndef SHAPE_H
#define SHAPE_H

class Point2D
{

	private:
		int x;
		int y;
	public:
		Point2D();
		Point2D(int, int);
		int getX();
		int getY();
		void setX(int);
		void setY(int);
};

class Rectangle
{

	private:
		Point2D* origin;
		Point2D* size;
	public:
		Rectangle(); //default constructor
		Rectangle(int, int, int, int);
		~Rectangle(); //destructor definition

		//getters and setters
		int getX();
		int getY();
		int getWidth();
		int getHeight();

		void setX(int);
		void setY(int);
		void setWidth(int);
		void setHeight(int);

};

#endif

