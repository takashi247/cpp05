#include "../include/Bureaucrat.hpp"

#include <iostream>

#include "../include/Form.hpp"

const char* Bureaucrat::GradeTooHighException::kErrMsgGradeTooHigh =
"Error: Bureaucrat: Grade is too high";

const char* Bureaucrat::GradeTooLowException::kErrMsgGradeTooLow =
"Error: Bureaucrat: Grade is too low";

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : name_(name), grade_(grade) {
  if (grade_ < kHighestGrade) {
    throw Bureaucrat::GradeTooHighException();
  } else if (kLowestGrade < grade_) {
    throw Bureaucrat::GradeTooLowException();
  }
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const { return name_; }

int Bureaucrat::getGrade() const { return grade_; }

void Bureaucrat::getPromoted() {
  if (grade_ != kHighestGrade) {
    --grade_;
  } else {
    throw Bureaucrat::GradeTooHighException();
  }
}

void Bureaucrat::getDemoted() {
  if (grade_ != kLowestGrade) {
    ++grade_;
  } else {
    throw Bureaucrat::GradeTooLowException();
  }
}

void Bureaucrat::signForm(Form &form) {
  try {
    form.beSigned(*this);
    std::cout << name_ << " signs " << form.getName() << std::endl;
  } catch (std::exception const &e) {
    std::cout << name_ << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
  }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return Bureaucrat::GradeTooHighException::kErrMsgGradeTooHigh;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return Bureaucrat::GradeTooLowException::kErrMsgGradeTooLow;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
  os << b.getName() << ", bureaucrate grade " << b.getGrade();
  return (os);
}
