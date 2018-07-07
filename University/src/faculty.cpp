#include "../include/faculty.h"
#include<cassert>
#include<cstring>
#include<iostream>

using namespace std;

const int MAX_LECTURERS_COUNT = 1024;
const int MAX_FACULTY_GUARDS_COUNT = 128;
const int MAX_SPECIALITIES_COUNT = 1024;

Faculty::Faculty()
{
  name = NULL;
  lecturersCount = 0;
  facultyGuardsCount = 0;
  specialitiesCount = 0;
  lecturers = NULL;
  facultyGuards = NULL;
  specialities = NULL;
}

Faculty::Faculty(const char* name, int lecturersCount, int facultyGuardsCount, int specialitiesCount, Lecturer* lecturers,
                 FacultyGuard* facultyGuards, Speciality* specialities)
{
  int nameLength = strlen(name);
  assert(nameLength > 0);
  assert(lecturersCount > 0);
  assert(facultyGuardsCount > 0);
  assert(specialitiesCount > 0);

  copyDynamicMemoryString(this->name, name);
  this->lecturersCount = lecturersCount;
  this->facultyGuardsCount = facultyGuardsCount;
  this->specialitiesCount = specialitiesCount;
  copyLecturers(this->lecturers, lecturers, lecturersCount);
  copyFacultyGuards(this->facultyGuards, facultyGuards, facultyGuardsCount);
  copySpecialities(this->specialities, specialities, specialitiesCount);
}

Faculty::Faculty(const Faculty &otherFaculty)
{
  copyFaculty(otherFaculty);
}

Faculty::~Faculty()
{
  deleteFaculty();
}

Faculty& Faculty::operator=(const Faculty &otherFaculty)
{
  if (this != &otherFaculty)
  {
    deleteFaculty();
    copyFaculty(otherFaculty);
  }

  return *this;
}

char* Faculty::getName() const
{
  return (char*)name;
}

int Faculty::getLecturersCount() const
{
  return lecturersCount;
}

int Faculty::getFacultyGuardsCount() const
{
  return facultyGuardsCount;
}

int Faculty::getSpecialitiesCount() const
{
  return specialitiesCount;
}

Lecturer* Faculty::getLecturers() const
{
  return lecturers;
}

FacultyGuard* Faculty::getFacultyGuards() const
{
  return  facultyGuards;
}

Speciality* Faculty::getSpecialities() const
{
  return specialities;
}

void Faculty::setName(const char* name)
{
  int nameLength = strlen(name);
  if (nameLength == 0)
  {
    cerr << "Error ! The name of the faculty can not be empty string !" << endl;
    return;
  }
  delete this->name;
  copyDynamicMemoryString(this->name, name);
}

void Faculty::setLecturers(int lecturersCount, const Lecturer* lecturers)
{
  if (lecturersCount == 0)
  {
    cerr << "Error ! Faculty can not have zero lecturers !" << endl;
    return;
  }

  delete [] this->lecturers;
  this->lecturersCount = lecturersCount;
  copyLecturers(this->lecturers, lecturers, lecturersCount);
}

void Faculty::setFacultyGuards(int facultyGuardsCount, const FacultyGuard* facultyGuards)
{
  if (facultyGuardsCount == 0)
  {
    cerr << "Error ! The number of faculty guards can not be zero !" << endl;
    return;
  }

  delete [] this->facultyGuards;
  this->facultyGuardsCount = facultyGuardsCount;
  copyFacultyGuards(this->facultyGuards, facultyGuards, facultyGuardsCount);
}

void Faculty::setSpecialities(int specialititesCount, const Speciality* specialitites)
{
  if (specialititesCount == 0)
  {
    cerr << "Error ! The number of specialities can not be zero !" << endl;
    return;
  }

  delete [] this->specialities;
  this->specialitiesCount = specialititesCount;
  copySpecialities(this->specialities, specialitites, specialititesCount);
}

void Faculty::addLecturer(const Lecturer &lecturer)
{
  if (lecturersCount + 1 > MAX_LECTURERS_COUNT)
  {
    cerr << "Error ! Can not have more than " << MAX_LECTURERS_COUNT << " lecturers in the faculty !" << endl;
    return;
  }

  lecturers[lecturersCount++] = lecturer;
}

void Faculty::addFacultyGuard(const FacultyGuard &facultyGuard)
{
  if (facultyGuardsCount + 1 > MAX_FACULTY_GUARDS_COUNT)
  {
    cerr << "Error ! Can not have more than " << MAX_FACULTY_GUARDS_COUNT << " faculty guards in the faculty !" << endl;
    return;
  }

  facultyGuards[facultyGuardsCount++] = facultyGuard;
}

void Faculty::addSpeciality(const Speciality &speciality)
{
  if (specialitiesCount + 1 > MAX_SPECIALITIES_COUNT)
  {
    cerr << "Error ! Can not have more than " << MAX_SPECIALITIES_COUNT << " specialities in the faculty !" << endl;
    return;
  }

  specialities[specialitiesCount++] = speciality;
}

void Faculty::removeLecturer(const char* lecturerName)
{
  for (int lecturerIndex = 0; lecturerIndex < lecturersCount; lecturerIndex++)
  {
    if (strcmp(lecturers[lecturerIndex].getName(), lecturerName) == 0)
    {
      shiftLecturers(lecturerIndex);
      lecturersCount--;
      return;
    }
  }

  cerr << "Error ! There is no lecturer named " << lecturerName << " !" << endl;
}

void Faculty::removeFacultyGuard(const char* facultyGuardName)
{
  for (int facultyGuardIndex = 0; facultyGuardIndex < facultyGuardsCount; facultyGuardIndex++)
  {
    if (strcmp(facultyGuards[facultyGuardIndex].getName(), facultyGuardName) == 0)
    {
      shiftFacultyGuards(facultyGuardIndex);
      facultyGuardsCount--;
      return;
    }
  }

  cerr << "Error ! There is no faculty guard named " << facultyGuardName << " !" << endl;
}

void Faculty::removeSpeciality(const char* specialityName)
{
  for (int specialityIndex = 0; specialityIndex < specialitiesCount; specialityIndex++)
  {
    if (strcmp(specialities[specialityIndex].getName(), specialityName) == 0)
    {
      shiftSpecialities(specialityIndex);
      specialitiesCount--;
      return;
    }
  }

  cerr << "Error ! There is no speciality named " << specialityName << " !" << endl;
}

void Faculty::copyFaculty(const Faculty &otherFaculty)
{
  copyDynamicMemoryString(name, otherFaculty.name);
  lecturersCount = otherFaculty.lecturersCount;
  facultyGuardsCount = otherFaculty.facultyGuardsCount;
  specialitiesCount = otherFaculty.specialitiesCount;
  copyLecturers(lecturers, otherFaculty.lecturers, otherFaculty.lecturersCount);
  copyFacultyGuards(facultyGuards, otherFaculty.facultyGuards, otherFaculty.facultyGuardsCount);
  copySpecialities(specialities, otherFaculty.specialities, otherFaculty.specialitiesCount);
}

void Faculty::deleteFaculty()
{
  delete name;
  delete [] lecturers;
  delete [] facultyGuards;
  delete [] specialities;
}

void Faculty::copyLecturers(Lecturer* &destination, const Lecturer* source, int lecturersCount)
{
  destination = new Lecturer[MAX_LECTURERS_COUNT];
  assert(destination != NULL);
  for (int i = 0; i < lecturersCount; i++)
  {
    destination[i] = source[i];
  }
}

void Faculty::copyFacultyGuards(FacultyGuard* &destination, const FacultyGuard* source, int facultyGuardsCount)
{
  destination = new FacultyGuard[MAX_FACULTY_GUARDS_COUNT];
  assert(destination != NULL);
  for (int i = 0; i < facultyGuardsCount; i++)
  {
    destination[i] = source[i];
  }
}

void Faculty::copySpecialities(Speciality* &destination, const Speciality* source, int specialitiesCount)
{
  destination = new Speciality[MAX_SPECIALITIES_COUNT];
  assert(destination != NULL);
  for (int i = 0; i < specialitiesCount; i++)
  {
    destination[i] = source[i];
  }
}

void Faculty::shiftLecturers(int lecturerIndex)
{
  for (int i = lecturerIndex; i < lecturersCount - 1; i++)
  {
    lecturers[i] = lecturers[i + 1];
  }
}

void Faculty::shiftFacultyGuards(int facultyGuardIndex)
{
  for (int i = facultyGuardIndex; i < facultyGuardsCount - 1; i++)
  {
    facultyGuards[i] = facultyGuards[i + 1];
  }
}

void Faculty::shiftSpecialities(int specialityIndex)
{
  for (int i = specialityIndex; i < specialitiesCount - 1; i++)
  {
    specialities[i] = specialities[i + 1];
  }
}

void Faculty::copyDynamicMemoryString(char* &destinationString, const char* sourceString)
{
  destinationString = new char[strlen(sourceString)];
  assert(destinationString != NULL);
  strcpy(destinationString, sourceString);
}
