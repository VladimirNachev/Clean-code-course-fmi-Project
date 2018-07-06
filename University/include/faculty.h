#ifndef Faculty_h
#define Faculty_h
#include "./lecturer.h"
#include "./facultyGuard.h"
#include "./speciality.h"

class Faculty
{
public:
  Faculty(const char*, int, int, int, Lecturer*, FacultyGuard*, Speciality*);
  Faculty(const Faculty&);
  ~Faculty();
  Faculty& operator=(const Faculty&);

  char* getName() const;
  int getLecturersCount() const;
  int getFacultyGuardsCount() const;
  int getSpecialitiesCount() const;
  Lecturer* getLecturers() const;
  FacultyGuard* getFacultyGuards() const;
  Speciality* getSpecialities() const;

  void setName(const char*);
  void setLecturers(int, const Lecturer*);
  void setFacultyGuards(int, const FacultyGuard*);
  void setSpecialities(int, const Speciality*);

  void addLecturer(const Lecturer&);
  void addFacultyGuard(const FacultyGuard&);
  void addSpeciality(const Speciality&);
  void removeLecturer(const char*);
  void removeFacultyGuard(const char*);
  void removeSpeciality(const char*);

private:
  char* name;
  int lecturersCount;
  int facultyGuardsCount;
  int specialitiesCount;
  Lecturer* lecturers;
  FacultyGuard* facultyGuards;
  Speciality* specialities;

  void copyFaculty(const Faculty&);
  void deleteFaculty();
  void copyLecturers(Lecturer*&, const Lecturer*, int);
  void copyFacultyGuards(FacultyGuard*&, const FacultyGuard*, int);
  void copySpecialities(Speciality*&, const Speciality*, int);
  void shiftLecturers(int);
  void shiftFacultyGuards(int);
  void shiftSpecialities(int);
  void copyDynamicMemoryString(char*&, const char*);
};

#endif // Faculty_h
