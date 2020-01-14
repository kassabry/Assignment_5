#include <iostream>
#include "GenDoublyLinkedList.h"

using namespace std;

class Faculty
{
public:
  Faculty();
  Faculty(int facultyID, string facultyName, string facultyLevel, string facultyDept);
  ~Faculty();

  void addAdvisee(int adviseeID);

  int id;
	string name;
	string level;
	string department;
	GenDoublyLinkedList<int>* advisees;
};
