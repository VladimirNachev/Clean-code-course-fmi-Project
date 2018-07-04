#ifndef Lecturer_h
#define Lecturer_h
#include "./employee.h"

class Lecturer : public Employee
{
public:
  Lecturer(const char*, const char*, int, int, double, const char*);
  Lecturer(const Lecturer&);
  ~Lecturer();
  Lecturer& operator=(const Lecturer&);

  char* getAcademicRank() const;

  void setAcademicRank(const char*);

  void increaseAnnualSalary();

private:
  char* academicRank;
};

#endif // Lecturer_h
