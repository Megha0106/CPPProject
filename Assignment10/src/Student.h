/*
 * Student.h
 * Author: Megha Sonavane
 */

#ifndef STUDENT_H_
#define STUDENT_H_

class Student {
	int rollNo;
	std::string name;
	std::string address;
	std::string div;
public:
	Student();
	void input();
	void show();
	int getRollNo();
	void setRollNo(int);
	void setName(std::string);
	void setAddress(std::string);
	void setDivision(std::string);
	virtual ~Student();
};

#endif /* STUDENT_H_ */
