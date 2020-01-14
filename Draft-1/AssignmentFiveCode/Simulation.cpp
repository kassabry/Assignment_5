#include "Simulation.h"

using namespace std;

// Number 7
void Simulation::addStudent(Student student)
{
  if(!masterStudent->contains(student->id))
  {
    masterStudent->insert(student->id);
  }
  else
  {
    cout << student->name << " is already in the database." << endl;
  }
}

// Number 9
void Simulation::addFaculty(Faculty faculty)
{
  if(!masterFaculty->contains(faculty->id))
  {
    masterFaculty->insert(faculty->id);
  }
  else
  {
    cout << faculty->name << " is already in the database." << endl;
  }
}

// Number 3
void Simulation::findStudent(int studentID)
{
  if(masterStudent->contains(studentID))
  {
    TreeNode<Student>* foundStudent = masterStudent->find(studentID);

    string studentName = foundStudent->name;
    string studentLevel = foundStudent->level;
    stirng studentMajor = foundStudent->major;
    double studentGPA = foundStudent->gpa;
    int studentAdvisor = foundStudent->advisorID;

    TreeNode<Faculty>* foundFaculty = masterFaculty->find(studentAdvisor);
    string advisorName = foundFaculty->name;

    cout << "Name: " << studentName << endl;
    cout << "Level: " << studentLevel << endl;
    cout << "Major: " << studentMajor << endl;
    cout << "GPA: " << studentGPA << endl;
    cout << "Advisor: " << advisorName << endl;
  }
  else
  {
    cout << "The student is not in the database." << endl;
  }
}

Faculty Simulation::getAdvisor(int facultyID)
{
  if(masterFaculty->contains(facultyID))
  {
    TreeNode<Faculty>* foundFaculty = masterFaculty->find(facultyID);
    // If these two sets of code do not work uncomment the two lines below it and
    // comment these two lines, and change the type to this function from Faculty
    // to string
    // But try to make this work cause we need this to work
    Faculty advisor = foundFaculty;
    return advisor;
  /*
    string advisorName = foundFaculty->name;
    return advisorName;
  */
  }
  else
  {
    cout << "The advisor is not in the database." << endl;
  }
}

// Nubmer 4
void Simulation::findFaculty(int facultyID)
{
  if(masterFaculty->contains(facultyID))
  {
    TreeNode<Faculty>* foundFaculty = masterFaculty->find(facultyID);

    string advisorName = foundFaculty->name;
    string advisorLevel = foundFaculty->level;
    string advisorDepartment = foundFaculty->department;

    cout << "Name: " << advisorName << endl;
    cout << "Level: " << advisorLevel << endl;
    cout << "Department: " << advisorDepartment << endl;
  }
  else
  {
    cout << "The advisor is not in the database." << endl;
  }
}

// Number 5
void Simulation::printStudentAdvisor(int studentID)
{
  if(masterStudent->contains(studentID))
  {
    TreeNode<Student>* foundStudent = masterStudent->find(studentID);

    int facultyID = foundStudent->advisorID;

    findFaculty(facultyID);
  }
  else
  {
    cout << "The student is not in the database." << endl;
  }
}

// Number 6
void Simulation::printAdvisees(int facultyID)
{
  if(masterFaculty->contains(facultyID))
  {
    TreeNode<Faculty>* foundFaculty = masterFaculty->find(facultyID);

    DoublyLinkedList<int>* facultyAdvisees = foundFaculty->advisees;
    ListNode<int>* base = facultyAdvisees->front;
    while(base->next != NULL)
    {
      int id = base->data;

      TreeNode<Student>* foundStudent = masterStudent->find(id);

      string studName = foundStudent->name;
      string studLevel = foundStudent->level;
      stirng studMajor = foundStudent->major;
      double studGPA = foundStudent->gpa;

      cout << "Name: " << studName << "; Level: " << studLevel << "; Major: " << studMajor << "; GPA: " << studGPA << endl;
    }
  }
  else
  {
    cout << "The advisor is not in the database." << endl;
  }
}

// Number 12
void Simulation::removeAdvisee(int facultyID, int studentID)
{
  if(masterFaculty->contains(facultyID))
  {
    TreeNode<Faculty>* foundFaculty = masterFaculty->find(facultyID);

    DoublyLinkedList<int>* facultyAdvisees = foundFaculty->advisees;
    int index = facultyAdvisees->find(studentID);

    //Reassign the student to a new advisor and update both the student and new advisor

    if(index != -1)
    {
      facultyAdvisees->deletePos(index);

      cout << "Advisee sucessfully removed" << endl;
    }
  }
  else
  {
    cout << "The advisor is not in the database." << endl;
  }
}

//Nubmer 11
void Simulation::changeAdvisor(int studentID, int newFacultyID)
{
  if(masterStudent->contains(studentID))
  {
    TreeNode<Student>* foundStudent = masterStudent->find(studentID);

    if(masterFaculty->contains(newFacultyID))
    {
      foundStudent->advisorID = newFacultyID;

      cout << "Advisor successfully changed" << endl;
    }
    else
    {
      cout << "The new faculty member is not in the database" << endl;
    }
  }
  else
  {
    cout << "The student is not in the database" << endl;
  }
}

// Number 14
void Simulation::exit()
{
  // Print out all of masterFaculty and masterStudent to corresponding txt files
  // with all of their information contained maybe with pipe delimited format
  // and then exit the program
}
