#include "../include/facultyGuard.h"
#include "../include/employee.h"
#include<iostream>
#include<cassert>

using namespace std;

const int FACULTY_GUARD_ANNUAL_SALARY_INCREASE = 150;
const bool DEFAULT_ELIGIBILITY_STATUS = false;

FacultyGuard::FacultyGuard() : Employee()
{
  isEligibleToWearGun = DEFAULT_ELIGIBILITY_STATUS;
}

FacultyGuard::FacultyGuard(const char* name, const char* address, int birthYear, int experience, double salary, bool isEligibleToWearGun) :
  Employee(name, address, birthYear, experience, salary)
{
  this->isEligibleToWearGun = isEligibleToWearGun;
}

FacultyGuard::FacultyGuard(const FacultyGuard &otherFacultyGuard) : Employee(otherFacultyGuard)
{
  this->isEligibleToWearGun = otherFacultyGuard.isEligibleToWearGun;
}

FacultyGuard::~FacultyGuard() { }

FacultyGuard& FacultyGuard::operator=(const FacultyGuard &otherFacultyGuard)
{
  if (this != &otherFacultyGuard)
  {
    Employee::operator=(otherFacultyGuard);
    this->isEligibleToWearGun = otherFacultyGuard.isEligibleToWearGun;
  }

  return *this;
}

bool FacultyGuard::getGunEligibilityStatus() const
{
  return isEligibleToWearGun;
}

void FacultyGuard::setGunEligibilityStatus(bool isEligibleToWearGun)
{
  this->isEligibleToWearGun = isEligibleToWearGun;
}

void FacultyGuard::increaseAnnualSalary()
{
  salary += FACULTY_GUARD_ANNUAL_SALARY_INCREASE;
}
