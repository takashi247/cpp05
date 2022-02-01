#include "Bureaucrat.hpp"

#include <iostream>

const char* Bureaucrat::GradeTooHighException::kErrMsgGradeTooHigh = "Error: Grade is too high";

const char* Bureaucrat::GradeTooLowException::kErrMsgGradeTooLow = "Error: Grade is too low";

Bureaucrat::Bureaucrat() {
  // std::cout << "Bureaucrat's default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
    : name_(name), grade_(grade) {
  // std::cout << name_ << "'s constructor called" << std::endl;
  if (grade_ < kHighestGrade) {
    throw GradeTooHighException();
  } else if (kLowestGrade < grade_) {
    throw GradeTooLowException();
  }
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) {
  // std::cout << "Bureaucrat's copy constructor called" << std::endl;
  *this = other;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
  // std::cout << "Bureaucrat's assignation operator called" << std::endl;
  if (this != &other) {
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {
  // std::cout << name_ << "'s destructor called" << std::endl;
}

const std::string &Bureaucrat::getName() const {
  return name_;
}

int Bureaucrat::getGrade() const {
  return grade_;
}

void Bureaucrat::getPromoted() {
  if (kHighestGrade < grade_ && grade_ <= kLowestGrade) {
    --grade_;
  } else {
    throw GradeTooHighException();
  }
}

void Bureaucrat::getDemoted() {
  if (grade_ != kLowestGrade) {
    ++grade_;
  } else {
    throw GradeTooLowException();
  }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return kErrMsgGradeTooHigh;
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return kErrMsgGradeTooLow;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
  os << b.getName() << ", bureaucrate grade " << b.getGrade();
  return (os);
}
