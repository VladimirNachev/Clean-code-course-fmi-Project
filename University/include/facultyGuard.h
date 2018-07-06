#ifndef FacultyGuard_h
#define FacultyGuard_h
#include "./employee.h"

class FacultyGuard : public Employee
{
public:
  FacultyGuard();
  FacultyGuard(const char*, const char*, int, int, double, bool);
  FacultyGuard(const FacultyGuard&);
  ~FacultyGuard();
  FacultyGuard& operator=(const FacultyGuard&);

  bool getGunEligibilityStatus() const;

  void setGunEligibilityStatus(bool);

  void increaseAnnualSalary();

private:
  bool isEligibleToWearGun;
};

#endif // FacultyGuard_h
