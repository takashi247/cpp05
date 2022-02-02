#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form {
 public:
  PresidentialPardonForm(const std::string &target);
  virtual ~PresidentialPardonForm();

  void takeAction() const;

 private:
  static const std::string kFormName;
  static const int kGradeToSign = 25;
  static const int kGradeToExec = 5;

  PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm &other);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

  const std::string &target_;
};

#endif // PRESIDENTIALPARDONFORM_HPP
