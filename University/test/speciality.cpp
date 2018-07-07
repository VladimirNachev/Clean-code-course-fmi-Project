#include "../include/catch.hpp"
#include "../include/speciality.h"
#include<cstring>
#include<string>
#include<cassert>

using namespace std;

int defaultDisciplinesCount = 7;

void createDisciplines(int disciplinesCount, char** &disciplines, char disciplinesHandyRepresentation[][64])
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

void deleteExistingDisciplines(int disciplinesCount, char** disciplines)
{
  for (int i = 0; i < disciplinesCount; i++)
  {
    delete disciplines[i];
  }
  delete disciplines;
}

Speciality createSpeciality(int &disciplinesCount = defaultDisciplinesCount)
{
  char disciplinesHandyRepresentation[8][64] = { "UP", "OOP", "SDP", "DAA", "DIS", "OS", "FP",  '\0' };
  int enrolledPeopleMaxCount = 158;
  disciplinesCount = 7;
  char** disciplines;
  createDisciplines(disciplinesCount, disciplines, disciplinesHandyRepresentation);
  Speciality speciality("Computer Science", enrolledPeopleMaxCount, disciplinesCount, disciplines);
  deleteExistingDisciplines(disciplinesCount, disciplines);
  return speciality;
}

TEST_CASE("Speciality class - speciality can be created")
{
  Speciality speciality = createSpeciality();

  REQUIRE(strcmp(speciality.getName(), "Computer Science") == 0);
}

TEST_CASE("Speciality class - new disciplines can be set")
{
  Speciality speciality = createSpeciality();

  char newDisciplinesHandyRepresentation[8][64] = { "LA", "AA", "DS" };
  int newDisciplinesCount = 3;
  char** newDisciplines;
  createDisciplines(newDisciplinesCount, newDisciplines, newDisciplinesHandyRepresentation);

  speciality.setDisciplines(newDisciplinesCount, newDisciplines);

  REQUIRE(speciality.getDisciplinesCount() == newDisciplinesCount);
  for (int i = 0; i < newDisciplinesCount; i++)
  {
    REQUIRE(strcmp(speciality.getDisciplines()[i], newDisciplines[i]) == 0);
  }
}

TEST_CASE("Speciality class - can add new discipline to speciality")
{
  int disciplinesCount;
  Speciality speciality = createSpeciality(disciplinesCount);

  speciality.addDiscipline("GEOM");
  int newDisciplinesCount = speciality.getDisciplinesCount();

  REQUIRE(newDisciplinesCount == disciplinesCount + 1);
  char newlyAddedDiscipline[64];
  strcpy(newlyAddedDiscipline, speciality.getDisciplines()[newDisciplinesCount - 1]);
  REQUIRE(strcmp(newlyAddedDiscipline, "GEOM") == 0);
}

TEST_CASE("Speciality class - can remove disicpline from speciality")
{
  int disciplinesCount;
  Speciality speciality = createSpeciality(disciplinesCount);

  Speciality copyOfSpeciality = speciality;
  char removedDiscipline[64];
  strcpy(removedDiscipline, "SDP");

  speciality.removeDiscipline(removedDiscipline);

  REQUIRE(speciality.getDisciplinesCount() == disciplinesCount - 1);
  int newDisciplinesCount = speciality.getDisciplinesCount();
  int indexPreviousDisciplines = 0, indexActualDisciplines = 0;
  while (indexPreviousDisciplines < disciplinesCount && indexActualDisciplines < newDisciplinesCount)
  {
    char* previousDiscipline = copyOfSpeciality.getDisciplines()[indexPreviousDisciplines];
    if (strcmp(previousDiscipline, removedDiscipline) == 0)
    {
      indexPreviousDisciplines++;
      continue;
    }
    char* actualDiscipline = speciality.getDisciplines()[indexActualDisciplines];
    REQUIRE(strcmp(actualDiscipline, previousDiscipline) == 0);
    indexPreviousDisciplines++;
    indexActualDisciplines++;
  }
}
