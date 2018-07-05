#include "../include/catch.hpp"
#include "../include/facultyGuard.h"
#include<cstring>

TEST_CASE("FacultyGuard class - faculty guard can be created")
{
  FacultyGuard facultyGuard("Dimitar Ivanov", "Varna", 1965, 35, 1777.7, true);
  REQUIRE(strcmp(facultyGuard.getName(), "Dimitar Ivanov") == 0);
}

bool areSalariesEqual(double firstNumber, double secondNumber)
{
  return firstNumber - secondNumber > -0.0001 && firstNumber - secondNumber < 0.0001;
}

TEST_CASE("FacultyGuard class - faculty guard's salary can be annually increased")
{
  const int FACULTY_GUARD_ANNUAL_SALARY_INCREASE = 150;
  FacultyGuard facultyGuard("Dimitar Ivanov", "Varna", 1965, 35, 1777.7, true);
  const double salaryBeforeIncrease = facultyGuard.getSalary();
  facultyGuard.increaseAnnualSalary();
  const double salaryAfterIncrease = facultyGuard.getSalary();
  const double expectedSalary = salaryBeforeIncrease + FACULTY_GUARD_ANNUAL_SALARY_INCREASE;
  REQUIRE(areSalariesEqual(salaryAfterIncrease, expectedSalary));
}

TEST_CASE("FacultyGuard class - set faculty guard's eligibility status for wearing gun")
{
  FacultyGuard facultyGuard("Dimitar Ivanov", "Varna", 1965, 35, 1777.7, true);
  REQUIRE(facultyGuard.getGunEligibilityStatus() == true);
}
