#include "shape.h"
#include <iostream>

using std::cout;
using std::endl;
using std::cin;

int main(int argc, char** argv)
{

	Rectangle* test1 = new Rectangle(1, 1, 10, 10);

	cout << test1->getX() << " " << test1->getY() << endl;
	cout << test1->getWidth() << " " << test1->getHeight() << endl;

	return 0;
}

