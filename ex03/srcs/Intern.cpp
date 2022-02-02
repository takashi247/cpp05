#include "../include/Intern.hpp"

#include <iostream>

const std::string Intern::kShrubberyFormName = "shrubbery creation form";

const std::string Intern::kRobotomyFormName = "robotomy request form";

const std::string Intern::kPresidentialFormName = "presidential pardon form";

const char* Intern::InvalidFormNameException::kErrMsgInvalidFormName =
"Error: Intern: Invalid form name";

Intern::Intern() {
  funcs[kShrubberyIndex] = &Intern::makeShrubberyCreationForm;
  funcs[kRobotomyIndex] = &Intern::makeRobotomyRequestForm;
  funcs[kPresidentialIndex] = &Intern::makePresidentialPardonForm;
}

Intern::Intern(Intern const &other) { *this = other; }

Intern &Intern::operator=(Intern const &other) {
  (void)other;
  return *this;
}

Intern::~Intern() {}

int Intern::getIndex(const std::string &form_name) const
{
  return (form_name == kShrubberyFormName) * kShrubberyIndex +
         (form_name == kRobotomyFormName) * kRobotomyIndex +
         (form_name == kPresidentialFormName) * kPresidentialIndex +
         (form_name != kShrubberyFormName && form_name != kRobotomyFormName &&
          form_name != kPresidentialFormName) * kInvalidIndex;
}

Form *Intern::makeForm(const std::string &form_name, const std::string &target) {
  int index = getIndex(form_name);
  if (index == kInvalidIndex) {
    throw Intern::InvalidFormNameException();
  } else {
    std::cout << "Intern creates " << form_name << std::endl;
    return (this->*funcs[index])(target);
  }
}

Form *Intern::makeShrubberyCreationForm(const std::string &target) const {
  return new ShrubberyCreationForm(target);
}

Form *Intern::makeRobotomyRequestForm(const std::string &target) const {
  return new RobotomyRequestForm(target);
}

Form *Intern::makePresidentialPardonForm(const std::string &target) const {
  return new PresidentialPardonForm(target);
}

const char *Intern::InvalidFormNameException::what() const throw() {
  return Intern::InvalidFormNameException::kErrMsgInvalidFormName;
}
