#include "../include/catch.hpp"
#include "../include/faculty.h"
#include<cstring>
#include<cassert>

void createTwoLecturers(Lecturer lecturers[])
{
  lecturers[0] = Lecturer("Ivan Ivanov", "Sofia", 1985, 20, 1985.23, "Professor");
  lecturers[1] = Lecturer("Petar Petrov", "Yambol", 1980, 25, 2500.21, "Professor");
}

void createTwoFacultyGuards(FacultyGuard facultyGuards[])
{
  facultyGuards[0] = FacultyGuard("Ivan Petrov", "Pernik", 1987, 15, 1200.23, false);
  facultyGuards[1] = FacultyGuard("Dimitar Ivanov", "Vratsa", 1977, 18, 1356.89, true);
}

void createNewDisciplines(int disciplinesCount, char** &disciplines, char disciplinesHandyRepresentation[][64])
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

void deleteDisciplines(int disciplinesCount, char** disciplines)
{
  for (int i = 0; i < disciplinesCount; i++)
  {
    delete disciplines[i];
  }
  delete disciplines;
}

void createTwoSpecialities(Speciality specialities[])
{
  char disciplinesHandyRepresentation[8][64] = { "UP", "OOP", "SDP", "DAA", "DIS", "OS", "FP",  '\0' };
  int firstSpecialitydisciplinesCount = 7;
  char** firstSpecialityDisciplines;
  createNewDisciplines(firstSpecialitydisciplinesCount, firstSpecialityDisciplines, disciplinesHandyRepresentation);

  int secondSpecialityDisciplinesCount = 7;
  char** secondSpecialityDisciplines;
  createNewDisciplines(secondSpecialityDisciplinesCount, secondSpecialityDisciplines, disciplinesHandyRepresentation);

  specialities[0] = Speciality("Computer Science", 158, firstSpecialitydisciplinesCount, firstSpecialityDisciplines);
  specialities[1] = Speciality("Informatics", 60, secondSpecialityDisciplinesCount, secondSpecialityDisciplines);

  deleteDisciplines(firstSpecialitydisciplinesCount, firstSpecialityDisciplines);
  deleteDisciplines(secondSpecialityDisciplinesCount, secondSpecialityDisciplines);
}

Faculty createFaculty()
{
  char facultyName[4] = { 'F', 'M', 'I', '\0' };
  int lecturersCount = 2;
  int facultyGuardsCount = 2;
  int specialitiesCount = 2;
  Lecturer lecturers[2];
  createTwoLecturers(lecturers);
  FacultyGuard facultyGuards[2];
  createTwoFacultyGuards(facultyGuards);
  Speciality specialities[2];
  createTwoSpecialities(specialities);

  Faculty faculty(facultyName, lecturersCount, facultyGuardsCount, specialitiesCount, lecturers, facultyGuards, specialities);
  return faculty;
}

TEST_CASE("Faculty  class - faculty can be created")
{
  Faculty faculty = createFaculty();
  REQUIRE(strcmp(faculty.getName(), "FMI") == 0);
}

TEST_CASE("Faculty class - lecturer can be added to faculty")
{
  Faculty faculty = createFaculty();
  int lecturersCountBefore = faculty.getLecturersCount();
  Lecturer lecturer("Dimo Petrov", "Pleven", 1990, 3, 1200.37, "Assistant");
  faculty.addLecturer(lecturer);
  int lecturersCountAfter = faculty.getLecturersCount();
  REQUIRE(lecturersCountBefore == lecturersCountAfter - 1);
  for (int i = 0; i < lecturersCountAfter; i++)
  {
    Lecturer currentLecturer = faculty.getLecturers()[i];
    if (strcmp(currentLecturer.getName(), "Dimo Petrov") == 0)
    {
      REQUIRE(true);
      return;
    }
  }
  REQUIRE(false); //If we reach this line of code we have not found the newly added lecturer.
}

TEST_CASE("Faculty class - faculty guard can be added to faculty")
{
  Faculty faculty = createFaculty();
  int facultyGuardsCountBefore = faculty.getFacultyGuardsCount();
  FacultyGuard facultyGuard("Milko Vasilev", "Dobrich", 1989, 5, 1000.39, false);
  faculty.addFacultyGuard(facultyGuard);
  int facultyGuardsCountAfter = faculty.getFacultyGuardsCount();
  REQUIRE(facultyGuardsCountBefore == facultyGuardsCountAfter - 1);
  for (int i = 0; i < facultyGuardsCountAfter; i++)
  {
    FacultyGuard currentFacultyGuard = faculty.getFacultyGuards()[i];
    if (strcmp(currentFacultyGuard.getName(), "Milko Vasilev") == 0)
    {
      REQUIRE(true);
      return;
    }
  }
  REQUIRE(false); //If we reach this line of code we have not found the newly added faculty guard.
}

TEST_CASE("Faculty class - lecturer can be removed from faculty")
{
  Faculty faculty = createFaculty();
  int lecturersCountBefore = faculty.getLecturersCount();
  faculty.removeLecturer("Ivan Ivanov"); //createFaculty() function creates two lecturers one of whom is Ivan Ivanov.
  int lecturersCountAfter = faculty.getLecturersCount();
  REQUIRE(lecturersCountBefore == lecturersCountAfter + 1);
  for (int i = 0; i < lecturersCountAfter; i++)
  {
    Lecturer currentLecturer = faculty.getLecturers()[i];
    REQUIRE(strcmp(currentLecturer.getName(), "Ivan Ivanov") != 0);
  }
}

TEST_CASE("Faculty class - faculty guard can be removed from faculty")
{
  Faculty faculty = createFaculty();
  int facultyGuardsCountBefore = faculty.getFacultyGuardsCount();
  faculty.removeFacultyGuard("Dimitar Ivanov"); //createFaculty() function creates two faculty guards one of whom is Dimitar Ivanov.
  int facultyGuardsCountAfter = faculty.getFacultyGuardsCount();
  REQUIRE(facultyGuardsCountBefore == facultyGuardsCountAfter + 1);
  for (int i = 0; i < facultyGuardsCountAfter; i++)
  {
    FacultyGuard currentFacultyGuard = faculty.getFacultyGuards()[i];
    REQUIRE(strcmp(currentFacultyGuard.getName(), "Dimitar Ivanov") != 0);
  }
}

TEST_CASE("Faculty class - speciality can be removed from faculty")
{
  Faculty faculty = createFaculty();
  int specialitiesCountBefore = faculty.getSpecialitiesCount();
  faculty.removeSpeciality("Informatics"); //createFaculty() function creates two specialities one of whom is Informatics.
  int specialitiesCountAfter = faculty.getSpecialitiesCount();
  REQUIRE(specialitiesCountBefore == specialitiesCountAfter + 1);
  for (int i = 0; i < specialitiesCountAfter; i++)
  {
    Speciality currentSpeciality = faculty.getSpecialities()[i];
    REQUIRE(strcmp(currentSpeciality.getName(), "Informatics") != 0);
  }
}
