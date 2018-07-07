#include "../include/university.h"
#include<iostream>
#include<cstring>
#include<cassert>

using namespace std;

University::University(const char* name, int foundationYear, const char* rectorName, int facultiesCount, int maximalFacultiesCount,
                       const Faculty* faculties)
{
  assert(strlen(name) > 0);
  assert(foundationYear > 0);
  assert(strlen(rectorName) > 0);
  assert(facultiesCount > 0);
  assert(maximalFacultiesCount > 0);
  assert(faculties != NULL);

  copyDynamicMemoryString(this->name, name);
  this->foundationYear = foundationYear;
  copyDynamicMemoryString(this->rectorName, rectorName);
  this->facultiesCount = facultiesCount;
  this->maximalFacultiesCount = maximalFacultiesCount;
  copyFaculties(faculties);
}

University::University(const University &otherUniversity)
{
  copyUniversity(otherUniversity);
}

University::~University()
{
  deleteUniversity();
}

University& University::operator=(const University &otherUniversity)
{
  if (this != &otherUniversity)
  {
    deleteUniversity();
    copyUniversity(otherUniversity);
  }

  return *this;
}

char* University::getName() const
{
  return (char*)name;
}

int University::getFoundationYear() const
{
  return foundationYear;
}

char* University::getRectorName() const
{
  return (char*)rectorName;
}

int University::getFacultiesCount() const
{
  return facultiesCount;
}

int University::getMaximalFacultiesCount() const
{
  return maximalFacultiesCount;
}

Faculty* University::getFaculties() const
{
  return faculties;
}

Faculty University::getFaculty(const char* facultyName) const
{
  for (int i = 0; i < facultiesCount; i++)
  {
    if (strcmp(faculties[i].getName(), facultyName) == 0)
    {
      return faculties[i];
    }
  }

  cerr << "Error ! There is no faculty named " << facultyName << " !" << endl;
  return Faculty();
}

void University::setName(const char* name)
{
  if (strlen(name) == 0)
  {
    cerr << "Error ! Length of the new name of the university can not be 0 !" << endl;
    return;
  }
  delete this->name;
  copyDynamicMemoryString(this->name, name);
}

void University::setRectorName(const char* rectorName)
{
  if (strlen(rectorName) == 0)
  {
    cerr << "Error ! Length of the name of the new rector can not be 0 !" << endl;
    return;
  }
  delete this->rectorName;
  copyDynamicMemoryString(this->rectorName, rectorName);
}

void University::addFaculty(const Faculty &faculty)
{
  if (facultiesCount + 1 > maximalFacultiesCount)
  {
    doubleMaximalFacultiesCount();
  }
  faculties[facultiesCount++] = faculty;
}

void University::removeFaculty(const char* facultyName)
{
  for (int facultyIndex = 0; facultyIndex < facultiesCount; facultyIndex++)
  {
    if (strcmp(faculties[facultyIndex].getName(), facultyName) == 0)
    {
      shiftFaculties(facultyIndex);
      facultiesCount--;
      return;
    }
  }

  cerr << "Error ! There is no faculty named " << facultyName << " !" << endl;
}


void University::copyUniversity(const University &otherUniversity)
{
  copyDynamicMemoryString(name, otherUniversity.name);
  foundationYear = otherUniversity.foundationYear;
  copyDynamicMemoryString(rectorName, otherUniversity.rectorName);
  facultiesCount = otherUniversity.facultiesCount;
  maximalFacultiesCount = otherUniversity.maximalFacultiesCount;
  copyFaculties(otherUniversity.faculties);
}

void University::deleteUniversity()
{
  delete name;
  delete rectorName;
  delete [] faculties;
}

void University::copyDynamicMemoryString(char*& destinationString, const char* sourceString)
{
  destinationString = new char[strlen(sourceString)];
  assert(destinationString != NULL);
  strcpy(destinationString, sourceString);
}

void University::doubleMaximalFacultiesCount()
{
  Faculty* temporarySavedFaculties = faculties;
  maximalFacultiesCount *= 2;
  faculties = new Faculty[maximalFacultiesCount];
  assert(faculties != NULL);
  for (int i = 0; i < maximalFacultiesCount / 2; i++)
  {
    faculties[i] = temporarySavedFaculties[i];
  }
  delete temporarySavedFaculties;
}

void University::shiftFaculties(int facultyIndex)
{
  for (int i = facultyIndex; i < facultiesCount - 1; i++)
  {
    faculties[i] = faculties[i + 1];
  }
}

void University::copyFaculties(const Faculty* faculties)
{
  this->faculties = new Faculty[this->maximalFacultiesCount];
  assert(this->faculties != NULL);
  for (int i = 0; i < this->facultiesCount; i++)
  {
    this->faculties[i] = faculties[i];
  }
}
