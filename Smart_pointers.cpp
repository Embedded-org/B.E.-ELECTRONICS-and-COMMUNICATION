#include <iostream>

#include <bits/stdc++.h>
using namespace std;

class Rectangle {
	int length;
	int breadth;

public:
	Rectangle(int l, int b) {
		length = l;
		breadth = b;
	}

	int area() {
		return length * breadth;
	}
};

int main() {
    
    cout<<"Create unique_ptr Smart Pointer"<<endl;
     unique_ptr<Rectangle> Q1(new Rectangle(10, 5));
    cout <<"using unique_ptr1 "<<Q1->area() << endl; 
    unique_ptr<Rectangle> Q2;

    cout<<"Copy the addres of P1 into p2"<<endl;
    Q2 = move(Q1);
    cout <<"using unique_ptr2 "<<Q2->area() << endl; 

	cout<<endl<<"Create shared_ptr Smart Pointer"<<endl;
	shared_ptr<Rectangle> P1(new Rectangle(10, 5));
    cout <<"using shared_ptr "<<P1->area() << endl; Q2->area();

	// Created a weak_ptr smart pointer
	weak_ptr<Rectangle> P2 (P1);
   if (auto shared = P2.lock()) {
        cout <<"using weak pointer "<<shared->area() << endl;
    } else {
        cout << "Not available" << endl;
    }
	cout <<"P2.use_count before reset()"<<P2.use_count()<<endl;
	// freeing the shared pointer
    P1.reset();
    
    if (auto shared = P2.lock()) {
        cout << shared->area() << endl;
    } else {
        cout << "Not available" << endl;
    }

	// Returns the number of shared_ptr
	// objects that manage the object
	cout <<"P2.use_count() after reset"<<P2.use_count()<<endl;
	return 0;
}