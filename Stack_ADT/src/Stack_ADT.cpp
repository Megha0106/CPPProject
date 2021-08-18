//============================================================================
// Name        : Stack_ADT.cpp
// Author      : Megha Sonavane
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"StackAdt.h"
using namespace std;

int main() {

	StackAdt <int>s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.display();
	return 0;
}
