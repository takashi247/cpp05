#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form {
 public:
  ShrubberyCreationForm(const std::string &target);
  virtual ~ShrubberyCreationForm();

  void takeAction() const;

 private:
  static const std::string kFormName;
  static const std::string kShrubberyAsciiArt;
  static const std::string kFileNameSuffix;
  static const int kGradeToSign = 145;
  static const int kGradeToExec = 137;

  ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

  const std::string &target_;
};

#endif // SHRUBBERYCREATIONFORM_HPP
