#include <iostream>
#include "Faculty.h"


using namespace std;

Faculty::Faculty(){}

Faculty::Faculty(int facultyID, string facultyName, string facultyLevel, string facultyDepartment)
{
  id = facultyID;
	name = facultyName;
	level = facultyLevel;
	department = facultyDepartment;
}

Faculty::~Faculty(){}

void Faculty::addAdvisee(int adviseeID)
{
  if(advisees->find(adviseeID) == -1)
  {
    advisees->insertFront(adviseeID);
  }
  else
  {
    cout << "The Advisee is already being advised by this faculty member." << endl;
  }
}
