#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
 public:
  class InvalidFormNameException : public std::exception {
    virtual const char *what() const throw ();
    static const char* kErrMsgInvalidFormName;
  };

  Intern();
  Intern(const Intern &other);
  Intern &operator=(const Intern &other);
  ~Intern();

  Form *makeForm(const std::string &form_name, const std::string &target);

 private:
  typedef Form* (Intern::*memFuncPtr)(const std::string &target) const;

  static const int kShrubberyIndex = 0;
  static const int kRobotomyIndex = 1;
  static const int kPresidentialIndex = 2;
  static const int kInvalidIndex = 3;
  static const std::string kShrubberyFormName;
  static const std::string kRobotomyFormName;
  static const std::string kPresidentialFormName;

  int getIndex(const std::string &form_name) const;
  Form *makeShrubberyCreationForm(const std::string &target) const ;
  Form *makeRobotomyRequestForm(const std::string &target) const ;
  Form *makePresidentialPardonForm(const std::string &target) const ;

  memFuncPtr funcs[3];
};

#endif // INTERN_HPP
