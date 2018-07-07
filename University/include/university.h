#ifndef University_h
#define University_h
#include "./faculty.h"

class University
{
public:
  University(const char*, int, const char*, int, int, const Faculty*);
  University(const University&);
  ~University();
  University& operator=(const University&);

  char* getName() const;
  int getFoundationYear() const;
  char* getRectorName() const;
  int getFacultiesCount() const;
  int getMaximalFacultiesCount() const;
  Faculty* getFaculties() const;
  Faculty getFaculty(const char*) const;

  void setName(const char*);
  void setRectorName(const char*);

  void addFaculty(const Faculty&);
  void removeFaculty(const char*);

private:
  char* name;
  int foundationYear;
  char* rectorName;
  int facultiesCount;
  int maximalFacultiesCount;
  Faculty* faculties;

  void copyUniversity(const University&);
  void deleteUniversity();
  void copyDynamicMemoryString(char*&, const char*);
  void doubleMaximalFacultiesCount();
  void shiftFaculties(int);
  void copyFaculties(const Faculty*);
};

#endif // University_h
