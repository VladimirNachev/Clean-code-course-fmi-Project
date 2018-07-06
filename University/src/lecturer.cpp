#include "../include/lecturer.h"
#include "../include/employee.h"
#include<iostream>
#include<cstring>
#include<cassert>

using namespace std;

const int LECTURER_ANNUAL_SALARY_INCREASE = 350;
const char DEFAULT_ACADEMIC_RANK[7] = { 'd', 'o', 'c', 'e', 'n', 't', '\0' };

Lecturer::Lecturer() : Employee()
{
  copyDynamicMemoryString(academicRank, DEFAULT_ACADEMIC_RANK);
}

Lecturer::Lecturer(const char* name, const char* address, int birthYear, int experience, double salary, const char* academicRank) :
  Employee(name, address, birthYear, experience, salary)
{
  int academicRankStringLength = strlen(academicRank);
  assert(academicRankStringLength > 0);

  copyDynamicMemoryString(this->academicRank, academicRank);
}

Lecturer::Lecturer(const Lecturer &otherLecturer) : Employee(otherLecturer)
{
  copyDynamicMemoryString(this->academicRank, otherLecturer.academicRank);
}

Lecturer::~Lecturer()
{
  delete academicRank;
}

Lecturer& Lecturer::operator=(const Lecturer &otherLecturer)
{
  if (this != &otherLecturer)
  {
    Employee::operator=(otherLecturer);
    delete academicRank;
    copyDynamicMemoryString(academicRank, otherLecturer.academicRank);
  }

  return *this;
}

char* Lecturer::getAcademicRank() const
{
  return (char*)academicRank;
}

void Lecturer::setAcademicRank(const char* academicRank)
{
  int academicRankLength = strlen(academicRank);
  if (academicRankLength == 0)
  {
    cerr << "Error ! Academic rank can not be empty string !" << endl;
    return;
  }

  copyDynamicMemoryString(this->academicRank, academicRank);
}

void Lecturer::increaseAnnualSalary()
{
  salary += LECTURER_ANNUAL_SALARY_INCREASE;
}
