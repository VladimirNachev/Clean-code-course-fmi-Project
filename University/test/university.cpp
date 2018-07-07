#include "../include/catch.hpp"
#include "../include/university.h"
#include "../include/commonFunctions.h"
#include<cstring>
#include<cassert>

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
  faculties[0] = createFaculty("FMI");
  faculties[1] = createFaculty("SF");
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
  Faculty faculty = createFaculty("LF");
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
