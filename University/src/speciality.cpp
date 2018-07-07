#include "../include/speciality.h"
#include<iostream>
#include<cstring>
#include<cassert>

using namespace std;

const int MAX_NUMBER_OF_DISCIPLINES = 60;

Speciality::Speciality()
{
  name = NULL;
  enrolledPeopleMaxCount = 0;
  disciplinesCount = 0;
  disciplines = NULL;
}

Speciality::Speciality(const char* name, int enrolledPeopleMaxCount, int disciplinesCount, char** disciplines)
{
  int lengthOfName = strlen(name);
  assert(lengthOfName > 0);
  assert(enrolledPeopleMaxCount > 0);
  assert(disciplinesCount > 0);
  checkDisciplinesLength(disciplinesCount,
                         disciplines);

  copyDynamicMemoryString(this->name, name);
  this->enrolledPeopleMaxCount = enrolledPeopleMaxCount;
  this->disciplinesCount = disciplinesCount;
  this->disciplines = new char*[MAX_NUMBER_OF_DISCIPLINES];
  assert(this->disciplines != NULL);
  copyDisciplines(disciplinesCount, disciplines);
}

Speciality::Speciality(const Speciality &otherSpeciality)
{
  copySpeciality(otherSpeciality);
}

Speciality::~Speciality()
{
  deleteSpeciality();
}

Speciality& Speciality::operator=(const Speciality &otherSpeciality)
{
  if (this != &otherSpeciality)
  {
    deleteSpeciality();
    copySpeciality(otherSpeciality);
  }

  return *this;
}

char* Speciality::getName() const
{
  return (char*)name;
}

int Speciality::getEnrolledPeopleMaxCount() const
{
  return enrolledPeopleMaxCount;
}

int Speciality::getDisciplinesCount() const
{
  return disciplinesCount;
}

char** Speciality::getDisciplines() const
{
  return (char**)disciplines;
}

void Speciality::setName(const char* name)
{
  if (strlen(name) == 0)
  {
    cerr << "Error ! The name of the speciality can not be empty string !" << endl;
    return;
  }

  delete this->name;
  copyDynamicMemoryString(this->name, name);
}

void Speciality::setEnrolledPeopleMaxCount(int enrolledPeopleMaxCount)
{
  if (enrolledPeopleMaxCount <= 0)
  {
    cerr << "Error ! The maximum enrolled people can not be non-positive number !" << endl;
    return;
  }

  this->enrolledPeopleMaxCount = enrolledPeopleMaxCount;
}

void Speciality::setDisciplines(int disciplinesCount, char** disciplines)
{
  for (int i = 0; i < disciplinesCount; i++)
  {
    int disciplineLength = strlen(disciplines[i]);
    if (disciplineLength == 0)
    {
      cerr << "Error ! Discipline " << i << " can not be empty string !" << endl;
      return;
    }
  }

  for (int i = 0; i < disciplinesCount; i++)
  {
    delete disciplines[i];
  }

  this->disciplinesCount = disciplinesCount;
  copyDisciplines(disciplinesCount, disciplines);
}

void Speciality::addDiscipline(const char* discipline)
{
  int disciplineLength = strlen(discipline);
  if (disciplineLength == 0)
  {
    cerr << "Error ! Discipline can not be empty string !" << endl;
    return;
  }

  if (disciplinesCount + 1 > MAX_NUMBER_OF_DISCIPLINES)
  {
    cerr << "Error ! Maximal number of disciplines is " << MAX_NUMBER_OF_DISCIPLINES << endl;
    cerr << "Can not add more disciplines !" << endl;
    return;
  }

  copyDynamicMemoryString(disciplines[disciplinesCount], discipline);
  disciplinesCount++;
}

void Speciality::removeDiscipline(const char* discipline)
{
  for (int disciplineIndex = 0; disciplineIndex < disciplinesCount; disciplineIndex++)
  {
    if (strcmp(disciplines[disciplineIndex], discipline) == 0)
    {
      delete disciplines[disciplineIndex];
      redirectDisciplinesPointers(disciplineIndex);
      disciplinesCount--;
      return;
    }
  }

  cerr << "Error ! There is no discipline named " << discipline << " !" << endl;
}

void Speciality::copySpeciality(const Speciality &otherSpeciality)
{
  copyDynamicMemoryString(name, otherSpeciality.name);
  enrolledPeopleMaxCount = otherSpeciality.enrolledPeopleMaxCount;
  disciplinesCount = otherSpeciality.disciplinesCount;
  disciplines = new char*[MAX_NUMBER_OF_DISCIPLINES];
  assert(disciplines != NULL);
  copyDisciplines(otherSpeciality.disciplinesCount, otherSpeciality.disciplines);
}

void Speciality::deleteSpeciality()
{
  delete name;
  for (int i = 0; i < disciplinesCount; i++)
  {
    delete disciplines[i];
  }
  delete disciplines;
}

void Speciality::checkDisciplinesLength(int disciplinesCount, char** disciplines)
{
  for (int i = 0; i < disciplinesCount; i++)
  {
    int disciplineLength = strlen(disciplines[i]);
    assert(disciplineLength > 0);
  }
}

void Speciality::copyDisciplines(int disciplinesCount, char** disciplines)
{
  for (int i = 0; i < disciplinesCount; i++)
  {
    copyDynamicMemoryString(this->disciplines[i], disciplines[i]);
  }
}

void Speciality::redirectDisciplinesPointers(int disciplineIndex)
{
  for (int i = disciplineIndex; i < disciplinesCount - 1; i++)
  {
    disciplines[i] = disciplines[i + 1];
  }
  disciplines[disciplinesCount - 1] = NULL;
}

void Speciality::copyDynamicMemoryString(char* &destinationString, const char* sourceString)
{
  destinationString = new char[strlen(sourceString)];
  assert(destinationString != NULL);
  strcpy(destinationString, sourceString);
}
