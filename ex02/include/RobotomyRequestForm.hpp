#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form {
 public:
  RobotomyRequestForm(const std::string &target);
  virtual ~RobotomyRequestForm();

  void takeAction() const;

 private:
  static const std::string kFormName;
  static const int kGradeToSign = 72;
  static const int kGradeToExec = 45;
  static const int kMaxRandomNum = 10;

  RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm &other);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

  const std::string &target_;
};

#endif // ROBOTOMYREQUESTFORM_HPP
