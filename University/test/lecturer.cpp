#include "../include/catch.hpp"
#include "../include/lecturer.h"
#include<cstring>
#include<cassert>

TEST_CASE("Lecturer class - lecturer can be created")
{
  Lecturer lecturer("Georgi Georgiev", "Sofia", 1978, 28, 1365.79, "Professor");
  REQUIRE(strcmp(lecturer.getName(), "Georgi Georgiev") == 0);
}

bool areEqual(double firstNumber, double secondNumber)
{
  return firstNumber - secondNumber > -0.0001 && firstNumber - secondNumber < 0.0001;
}

TEST_CASE("Lecturer class - lecturer's salary can be annually increased")
{
  const int LECTURER_ANNUAL_SALARY_INCREASE = 350;
  Lecturer lecturer("Georgi Georgiev", "Sofia", 1978, 28, 1365.79, "Professor");
  const double salaryBeforeIncrease = lecturer.getSalary();
  lecturer.increaseAnnualSalary();
  const double salaryAfterIncrease = lecturer.getSalary();
  const double expectedSalary = salaryBeforeIncrease + LECTURER_ANNUAL_SALARY_INCREASE;
  REQUIRE(areEqual(salaryAfterIncrease, expectedSalary));
}

void initializeOldLecturersRank(char*& oldLecturersRank, const Lecturer &lecturer)
{
  int lecturersRankLength = strlen(lecturer.getAcademicRank());
  oldLecturersRank = new char[lecturersRankLength];
  assert(oldLecturersRank != NULL);
  strcpy(oldLecturersRank, lecturer.getAcademicRank());
}

TEST_CASE("Lecturer class - set academic rank to lecturer")
{
  Lecturer lecturer("Georgi Georgiev", "Sofia", 1978, 28, 1365.79, "Professor");

  SECTION("Set valid academic rank to lecturer")
  {
    lecturer.setAcademicRank("Academic");
    REQUIRE(strcmp(lecturer.getAcademicRank(), "Academic") == 0);
  }
  SECTION("Set invalid academic rank to lecturer and expect that the old valid rank remains")
  {
    char* oldLecturersRank;
    initializeOldLecturersRank(oldLecturersRank, lecturer);
    lecturer.setAcademicRank("");
    REQUIRE(strcmp(lecturer.getAcademicRank(), oldLecturersRank) == 0);

    delete oldLecturersRank;
  }
}
