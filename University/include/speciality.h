#ifndef Speciality_h
#define Speciality_h

class Speciality
{
public:
  Speciality();
  Speciality(const char*, int, int, char**);
  Speciality(const Speciality&);
  ~Speciality();
  Speciality& operator=(const Speciality&);

  char* getName() const;
  int getEnrolledPeopleMaxCount() const;
  int getDisciplinesCount() const;
  char** getDisciplines() const;

  void setName(const char*);
  void setEnrolledPeopleMaxCount(int);
  void setDisciplines(int, char**);

  void addDiscipline(const char*);
  void removeDiscipline(const char*);

private:
  char* name;
  int enrolledPeopleMaxCount;
  int disciplinesCount;
  char** disciplines;

  void copySpeciality(const Speciality&);
  void deleteSpeciality();
  void checkDisciplinesLength(int, char**);
  void copyDisciplines(int, char**);
  void redirectDisciplinesPointers(int);
  void copyDynamicMemoryString(char*&, const char*);
};

#endif // Speciality_h
