#include "shape.h"

Point2D::Point2D()
{

	this->x = 0;
	this-> y = 0;
}

Point2D::Point2D(int xv, int yv)
{

	this->x = xv;
	this->y = yv;
}

int  Point2D::getX()
{

	return this->x;
}

int Point2D::getY()
{

	return this->y;

}

void Point2D::setX(int val)
{

	this->x = val;

}

void Point2D::setY(int val)
{


	this->y = val;

}

/*
 * Class Rectangle
*/

Rectangle::Rectangle()
{

	this->origin = new Point2D();
	this->size = new Point2D();

}

Rectangle::Rectangle(int x, int y, int width, int height)
{

	this->origin = new Point2D(x, y);
	this->size = new Point2D(width, height);

}

Rectangle::~Rectangle() //destructor, remove these pointers but not original this
{

	delete this->origin;
	delete this->size;

}

int Rectangle::getX()
{

	return this->origin->getX();

}

int Rectangle::getY()
{

	return this->origin->getY();

}

int Rectangle::getWidth()
{

	return this->size->getX();

}

int Rectangle::getHeight()
{

	return this->size->getY();

}

//because origin and size are pointers we use '->' to reference them

void Rectangle::setX(int val)
{


	this->origin->setX(val);

}

void Rectangle::setY(int val)
{

	this->origin->setY(val);

}

void Rectangle::setWidth(int val)
{

	this->origin->setX(val);

}

void Rectangle::setHeight(int val)
{


	this->origin->setY(val);

}



