/*
 * Set.h
 * Created on: Dec 31, 2020
 * Author: SE XI-1
 */

#ifndef SET_H_
#define SET_H_

class Set {
	int set[20];
	int n;
public:
	Set();
	void input(int);
	void display();
	void set_union(Set,Set);
	void set_intersection(Set,Set);
	void set_difference(Set,Set);
	void set_symmeticDiff(Set,Set);
	void addNew();
	virtual ~Set();
};

#endif /* SET_H_ */
