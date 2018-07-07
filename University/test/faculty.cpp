#include "../include/catch.hpp"
#include "../include/faculty.h"
#include "../include/commonFunctions.h"
#include<cstring>
#include<cassert>

TEST_CASE("Faculty  class - faculty can be created")
{
  char facultyName[4];
  strcpy(facultyName, "FMI");
  Faculty faculty = createFaculty(facultyName);
  REQUIRE(strcmp(faculty.getName(), "FMI") == 0);
}

TEST_CASE("Faculty class - lecturer can be added to faculty")
{
  char facultyName[4];
  strcpy(facultyName, "FMI");
  Faculty faculty = createFaculty(facultyName);
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
  char facultyName[4];
  strcpy(facultyName, "FMI");
  Faculty faculty = createFaculty(facultyName);
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
  char facultyName[4];
  strcpy(facultyName, "FMI");
  Faculty faculty = createFaculty(facultyName);
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
  char facultyName[4];
  strcpy(facultyName, "FMI");
  Faculty faculty = createFaculty(facultyName);
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
  char facultyName[4];
  strcpy(facultyName, "FMI");
  Faculty faculty = createFaculty(facultyName);
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
