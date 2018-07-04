class Employee
{
public:
  Employee(const char*, const char*, int, int);
  Employee(const Employee&);
  ~Employee();
  Emplooyee& operator=(const Empoyee&);

  char* getName() const;
  char* getAddress() const;
  int getBirthYear() const;
  int getExpereince() const;

  void setName(const char*);
  void setAddress(const char*);
  void setExperience(int);

  int calculateAge() const;
  virtual void increaseAnnualSalary() = 0;

private:
  char* name;
  char* address;
  int birthYear;
  int expereince;

  void copyEmployee(const University&);
  void deleteEmployee();
  void copyDynamicMemoryString(char*, char*);
};
