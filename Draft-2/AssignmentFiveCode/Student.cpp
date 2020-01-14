#include <iostream>
#include "Student.h"

using namespace std;

Student::Student(){}

Student::Student(int studentID, string studentName, string studentLevel, string studentMajor, double studentGPA,int studentAdvisorID)
{
  id = studentID;
  name = studentName;
  level = studentLevel;
  major = studentMajor;
  gpa = studentGPA;
  advisorID = studentAdvisorID;
}

Student::~Student()
{

}
