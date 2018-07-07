#include "./Lecturer.h"
#include "./FacultyGuard.h"
#include "./Faculty.h"
#include "./Speciality.h"

using namespace std;

bool areNumbersEqual(double firstNumber, double secondNumber);
void createDisciplines(int disciplinesCount, char** &disciplines, char disciplinesHandyRepresentation[][64]);
void deleteDisciplines(int disciplinesCount, char** disciplines);
void createTwoLecturers(Lecturer lecturers[]);
void createTwoFacultyGuards(FacultyGuard facultyGuards[]);
Faculty createFaculty(const char* facultyName);
void createTwoSpecialities(Speciality specialities[]);
