#include "../include/catch.hpp"
#include "../include/facultyGuard.h"
#include "../include/commonFunctions.h"
#include<cstring>

TEST_CASE("FacultyGuard class - faculty guard can be created")
{
  FacultyGuard facultyGuard("Dimitar Ivanov", "Varna", 1965, 35, 1777.7, true);
  REQUIRE(strcmp(facultyGuard.getName(), "Dimitar Ivanov") == 0);
}

TEST_CASE("FacultyGuard class - faculty guard's salary can be annually increased")
{
  const int FACULTY_GUARD_ANNUAL_SALARY_INCREASE = 150;
  FacultyGuard facultyGuard("Dimitar Ivanov", "Varna", 1965, 35, 1777.7, true);
  const double salaryBeforeIncrease = facultyGuard.getSalary();
  facultyGuard.increaseAnnualSalary();
  const double salaryAfterIncrease = facultyGuard.getSalary();
  const double expectedSalary = salaryBeforeIncrease + FACULTY_GUARD_ANNUAL_SALARY_INCREASE;
  REQUIRE(areNumbersEqual(salaryAfterIncrease, expectedSalary));
}

TEST_CASE("FacultyGuard class - set faculty guard's eligibility status for wearing gun")
{
  FacultyGuard facultyGuard("Dimitar Ivanov", "Varna", 1965, 35, 1777.7, true);
  REQUIRE(facultyGuard.getGunEligibilityStatus() == true);
}
