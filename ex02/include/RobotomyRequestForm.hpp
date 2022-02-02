#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "../include/Form.hpp"

class RobotomyRequestForm : public Form {
 public:
  RobotomyRequestForm(const std::string target);
  virtual ~RobotomyRequestForm();

 private:
  RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm &other);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

};

#endif // ROBOTOMYREQUESTFORM_HPP
