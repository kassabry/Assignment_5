#include <iostream>

using namespace std;

class Student
{
public:
  Student();
  Student(int studentID, string studentName, string studentLevel, string studentMajor, double studentGPA,int studentAdvisorID);
  ~Student();

  int id;
	string name;
	string level;
	string major;
	double gpa;
	int advisorID;

  //TreeNode<Student>* foundStudent;
  //TreeNode<Faculty>* foundFaculty;
};
