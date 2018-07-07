#include "../include/commonFunctions.h"
#include<cstring>
#include<cassert>

/** @brief Function used to check whether salaries of employees are equal.
 *
 * @param firstNumber is used to represent the salary of one of the employees
 * @param secondNumber is used to represent the salary of the other employee
 * @return true or false whether salaries are equal or not
 */
bool areNumbersEqual(double firstNumber, double secondNumber)
{
  return firstNumber - secondNumber > -0.0001 && firstNumber - secondNumber < 0.0001;
}

/** @brief Function used to create disciplines.
 *
 * @param disciplinesCount is used to represent the number of the disciplines to be created
 * @param disciplines is used to store the created disciplines
 * @param disciplinesHandyRepresentation is used to store the disciplines in a convenient way which helps us to transfer them into
 *        parameter disciplines
 */
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

/** @brief Function used to delete disciplines given as second parameter.
 *
 * @param disciplinesCount represents the number of the disciplines to be deleted
 * @param disciplines represents the disciplines to be deleted
 */
void deleteDisciplines(int disciplinesCount, char** disciplines)
{
  for (int i = 0; i < disciplinesCount; i++)
  {
    delete disciplines[i];
  }
  delete disciplines;
}

/** @brief Function used to create exactly two lecturers.
 *
 * @param lecturers[] is a container which stores the created lecturers
 */
void createTwoLecturers(Lecturer lecturers[])
{
  lecturers[0] = Lecturer("Ivan Ivanov", "Sofia", 1985, 20, 1985.23, "Professor");
  lecturers[1] = Lecturer("Petar Petrov", "Yambol", 1980, 25, 2500.21, "Professor");
}

/** @brief Function used to create exactly two faculty guards.
 *
 * @param facultyGuards[] is a container which stores the created faculty guards
 */
void createTwoFacultyGuards(FacultyGuard facultyGuards[])
{
  facultyGuards[0] = FacultyGuard("Ivan Petrov", "Pernik", 1987, 15, 1200.23, false);
  facultyGuards[1] = FacultyGuard("Dimitar Ivanov", "Vratsa", 1977, 18, 1356.89, true);
}

/** @brief Function used to create single faculty.
 *
 * @param facultyName is used as a name for the created faculty
 * @return The created faculty
 */
Faculty createFaculty(const char* facultyName)
{
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

/** @brief Function used to create exactly two specialities.
 *
 * @param specialities[] is a container which stores the created specialities
 */
void createTwoSpecialities(Speciality specialities[])
{
  char disciplinesHandyRepresentation[8][64] = { "UP", "OOP", "SDP", "DAA", "DIS", "OS", "FP",  '\0' };
  int firstSpecialitydisciplinesCount = 7;
  char** firstSpecialityDisciplines;
  createDisciplines(firstSpecialitydisciplinesCount, firstSpecialityDisciplines, disciplinesHandyRepresentation);

  int secondSpecialityDisciplinesCount = 7;
  char** secondSpecialityDisciplines;
  createDisciplines(secondSpecialityDisciplinesCount, secondSpecialityDisciplines, disciplinesHandyRepresentation);

  specialities[0] = Speciality("Computer Science", 158, firstSpecialitydisciplinesCount, firstSpecialityDisciplines);
  specialities[1] = Speciality("Informatics", 60, secondSpecialityDisciplinesCount, secondSpecialityDisciplines);

  deleteDisciplines(firstSpecialitydisciplinesCount, firstSpecialityDisciplines);
  deleteDisciplines(secondSpecialityDisciplinesCount, secondSpecialityDisciplines);
}
