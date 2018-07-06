#include "../include/employee.h"
#include<iostream>
#include<ctime>
#include<cstring>
#include<cassert>

using namespace std;

const int STARTING_YEAR = 1900;
const int DEFAULT_NAME_LENGTH = 12;
const int DEFAULT_ADDRESS_LENGTH = 6;
const char DEFAULT_EMPLOYEE_NAME[DEFAULT_NAME_LENGTH] = { 'I', 'v', 'a', 'n', ' ' , 'I', 'v', 'a', 'n', 'o', 'v', '\0' };
const char DEFAULT_EMPLOYEE_ADDRESS[DEFAULT_ADDRESS_LENGTH] = { 'S', 'o', 'f', 'i', 'a', '\0' };
const int DEFAULT_BIRTHDAY_YEAR = 1980;
const int DEFAULT_EXPERIENCE = 15;

Employee::Employee()
{
  copyDynamicMemoryString(name, DEFAULT_EMPLOYEE_NAME);
  copyDynamicMemoryString(address, DEFAULT_EMPLOYEE_ADDRESS);
  birthYear = DEFAULT_BIRTHDAY_YEAR;
  experience = DEFAULT_EXPERIENCE;
}

Employee::Employee(const char* name, const char* address, int birthYear, int experience, double salary)
{
  int employeeNameLength = strlen(name), employeeAddressLength = strlen(address);
  assert(employeeNameLength > 0);
  assert(employeeAddressLength > 0);
  assert(birthYear > 0);
  assert(experience >= 0);

  copyDynamicMemoryString(this->name, name);
  copyDynamicMemoryString(this->address, address);
  this->birthYear = birthYear;
  this->experience = experience;
  this->salary = salary;
}

Employee::Employee(const Employee &otherEmployee)
{
  copyEmployee(otherEmployee);
}

Employee::~Employee()
{
  deleteEmployee();
}

Employee& Employee::operator=(const Employee &otherEmployee)
{
  if (this != &otherEmployee)
  {
    deleteEmployee();
    copyEmployee(otherEmployee);
  }

  return *this;
}

char* Employee::getName() const
{
  return (char*)name;
}

char* Employee::getAddress() const
{
  return (char*)address;
}

double Employee::getSalary() const
{
  return salary;
}

int Employee::getBirthYear() const
{
  return birthYear;
}

int Employee::getExpereince() const
{
  return experience;
}

void Employee::setName(const char* name)
{
  if (strlen(name) == 0)
  {
    cerr << "Error ! Length of the new name of the employee can not be 0 !" << endl;
    return;
  }

  copyDynamicMemoryString(this->name, name);
}

void Employee::setAddress(const char* address)
{
  if (strlen(address) == 0)
  {
    cerr << "Error ! Length of the new address of the employee can not be 0 !" << endl;
    return;
  }

  copyDynamicMemoryString(this->address, address);
}

void Employee::setExperience(int experience)
{
  this->experience = experience;
}

int Employee::calculateAge() const
{
  return getCurrentYear() - birthYear;
}

void Employee::copyEmployee(const Employee &otherEmployee)
{
  copyDynamicMemoryString(name, otherEmployee.name);
  copyDynamicMemoryString(address, otherEmployee.address);
  birthYear = otherEmployee.birthYear;
  experience = otherEmployee.experience;
  salary = otherEmployee.salary;
}

void Employee::deleteEmployee()
{
  delete name;
  delete address;
}

void Employee::copyDynamicMemoryString(char* &destinationString, const char* sourceString)
{
  destinationString = new char[strlen(sourceString)];
  assert(destinationString != NULL);
  strcpy(destinationString, sourceString);
}

int Employee::getCurrentYear() const
{
  time_t currentTime = time(NULL);
	tm* localTime = localtime(&currentTime);
	return localTime->tm_year + STARTING_YEAR;
}
