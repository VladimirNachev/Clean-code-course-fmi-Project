#include "../include/catch.hpp"
#include "../include/university.h"
#include<cstring>
#include<cassert>

void createTwoLecturers1(Lecturer lecturers[])
{
  lecturers[0] = Lecturer("Ivan Ivanov", "Sofia", 1985, 20, 1985.23, "Professor");
  lecturers[1] = Lecturer("Petar Petrov", "Yambol", 1980, 25, 2500.21, "Professor");
}

void createTwoFacultyGuards1(FacultyGuard facultyGuards[])
{
  facultyGuards[0] = FacultyGuard("Ivan Petrov", "Pernik", 1987, 15, 1200.23, false);
  facultyGuards[1] = FacultyGuard("Dimitar Ivanov", "Vratsa", 1977, 18, 1356.89, true);
}

void createNewDisciplines1(int disciplinesCount, char** &disciplines, char disciplinesHandyRepresentation[][64])
{
  disciplines = new char*[disciplinesCount];
  assert(disciplines != NULL);
  for (int i = 0; i < disciplinesCount; i++)
  {
    disciplines[i] = new char[8];
    assert(disciplines[i] != NULL);
    strcpy(disciplines[i], disciplinesHandyRepresentation[i]);
  }
}

void deleteDisciplines1(int disciplinesCount, char** disciplines)
{
  for (int i = 0; i < disciplinesCount; i++)
  {
    delete disciplines[i];
  }
  delete disciplines;
}

void createTwoSpecialities1(Speciality specialities[])
{
  char disciplinesHandyRepresentation[8][64] = { "UP", "OOP", "SDP", "DAA", "DIS", "OS", "FP",  '\0' };
  int firstSpecialitydisciplinesCount = 7;
  char** firstSpecialityDisciplines;
  createNewDisciplines1(firstSpecialitydisciplinesCount, firstSpecialityDisciplines, disciplinesHandyRepresentation);

  int secondSpecialityDisciplinesCount = 7;
  char** secondSpecialityDisciplines;
  createNewDisciplines1(secondSpecialityDisciplinesCount, secondSpecialityDisciplines, disciplinesHandyRepresentation);

  specialities[0] = Speciality("Computer Science", 158, firstSpecialitydisciplinesCount, firstSpecialityDisciplines);
  specialities[1] = Speciality("Informatics", 60, secondSpecialityDisciplinesCount, secondSpecialityDisciplines);

  deleteDisciplines1(firstSpecialitydisciplinesCount, firstSpecialityDisciplines);
  deleteDisciplines1(secondSpecialityDisciplinesCount, secondSpecialityDisciplines);
}

Faculty createFaculty1(const char* facultyName)
{
  int lecturersCount = 2;
  int facultyGuardsCount = 2;
  int specialitiesCount = 2;
  Lecturer lecturers[2];
  createTwoLecturers1(lecturers);
  FacultyGuard facultyGuards[2];
  createTwoFacultyGuards1(facultyGuards);
  Speciality specialities[2];
  createTwoSpecialities1(specialities);

  Faculty faculty(facultyName, lecturersCount, facultyGuardsCount, specialitiesCount, lecturers, facultyGuards, specialities);
  return faculty;
}

University createUniversity()
{
  char name[17];
  strcpy(name, "Sofia University");
  int foundationYear = 1888;
  char rectorName[19];
  strcpy(rectorName, "Anastas Gerdzhikov");
  int facultiesCount = 2;
  int maximalFacultiesCount = 2;
  Faculty faculties[2];
  faculties[0] = createFaculty1("FMI");
  faculties[1] = createFaculty1("SF");
  University university(name, foundationYear, rectorName, maximalFacultiesCount, facultiesCount, faculties);
  return university;
}

TEST_CASE("University class - university can be created")
{
  University university = createUniversity();
  REQUIRE(strcmp(university.getName(), "Sofia University") == 0);
}

TEST_CASE("University class - faculty can be added to university")
{
  University university = createUniversity();
  int facultiesCountBefore = university.getFacultiesCount();
  Faculty faculty = createFaculty1("LF");
  university.addFaculty(faculty);
  int facultiesCountAfter = university.getFacultiesCount();
  REQUIRE(facultiesCountBefore == facultiesCountAfter - 1);
  for (int i = 0; i < facultiesCountAfter; i++)
  {
    Faculty currentFaculty = university.getFaculties()[i];
    if (strcmp(currentFaculty.getName(), "LF") == 0)
    {
      REQUIRE(true);
      return;
    }
  }
  REQUIRE(false); //If we reach this line of code we have not found the newly added faculty.
}

TEST_CASE("University class - faculty can be removed from university")
{
  University university = createUniversity();
  int facultiesCountBefore = university.getFacultiesCount();
  university.removeFaculty("SF");
  int facultiesCountAfter = university.getFacultiesCount();
  REQUIRE(facultiesCountBefore == facultiesCountAfter + 1);
}
