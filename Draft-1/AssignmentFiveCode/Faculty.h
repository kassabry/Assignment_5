#include <iostream>
#include "GenDoublyLinkedList.h"

using namespace std;

class Faculty
{
  Faculty();
  Faculty(int facultyID, string facultyName, string facultyLevel, string facultyDept);
  ~Faculty();

  void addAdvisee(int adviseeID);

  int id;
	string name;
	string level;
	string department;
	DoublyLinkedList<int>* advisees;
};
