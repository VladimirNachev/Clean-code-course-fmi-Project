#ifndef Employee_h
#define Employee_h

class Employee
{
public:
  Employee(const char*, const char*, int, int, double);
  Employee(const Employee&);
  ~Employee();
  Employee& operator=(const Employee&);

  char* getName() const;
  char* getAddress() const;
  int getBirthYear() const;
  int getExpereince() const;
  double getSalary() const;

  void setName(const char*);
  void setAddress(const char*);
  void setExperience(int);

  int calculateAge() const;
  virtual void increaseAnnualSalary() = 0;

private:
  char* name;
  char* address;
  int birthYear;
  int experience;
  double salary;

  void copyEmployee(const Employee&);
  void deleteEmployee();
  void copyDynamicMemoryString(char*&, const char*);
  int getCurrentYear() const;
};

#endif // Employee_h
