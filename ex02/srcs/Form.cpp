#include "../include/Form.hpp"

#include <iostream>

#include "../include/Bureaucrat.hpp"

const char* Form::GradeTooHighException::kErrMsgGradeTooHigh =
"Error: Form: Grade is too high";

const char* Form::GradeTooLowException::kErrMsgGradeTooLow =
"Error: Form: Grade is too low";

const char* Form::NotSignedException::kErrMsgNotSigned=
"Error: Form: Form has NOT been signed yet";

Form::Form(const std::string name, const int grade_to_sign, const int grade_to_execute)
    : name_(name),
      is_signed_(false),
      grade_to_sign_(grade_to_sign),
      grade_to_execute_(grade_to_execute) {
  // std::cout << "Form " << name_ << "'s constructor called" << std::endl;
  if (grade_to_sign_ < Bureaucrat::kHighestGrade || grade_to_execute_ < Bureaucrat::kHighestGrade) {
    throw Form::GradeTooHighException();
  } else if (Bureaucrat::kLowestGrade < grade_to_sign_ || Bureaucrat::kLowestGrade < grade_to_execute_) {
    throw Form::GradeTooLowException();
  }
}

Form::~Form() {
  // std::cout << "Form's destructor called" << std::endl;
}

const std::string &Form::getName() const { return name_; }

const bool &Form::checkIfSigned() const { return is_signed_; }

int Form::getGradeToSign() const { return grade_to_sign_; }

int Form::getGradeToExecute() const { return grade_to_execute_; }

void Form::beSigned(Bureaucrat &b) {
  if (grade_to_sign_ < b.getGrade()) {
    throw Form::GradeTooLowException();
  } else {
    is_signed_ = true;
  }
}

void Form::execute(Bureaucrat const &executor) const {
  if (is_signed_ == false) {
    throw Form::NotSignedException();
  } else if (grade_to_execute_ < executor.getGrade()) {
    throw Form::GradeTooLowException();
  } else {
    takeAction();
  }
}

const char *Form::GradeTooHighException::what() const throw() {
  return Form::GradeTooHighException::kErrMsgGradeTooHigh;
}

const char *Form::GradeTooLowException::what() const throw() {
  return Form::GradeTooLowException::kErrMsgGradeTooLow;
}

const char *Form::NotSignedException::what() const throw() {
  return Form::NotSignedException::kErrMsgNotSigned;
}

std::ostream &operator<<(std::ostream &os, const Form &f) {
  os << "Form name: " << f.getName() << "\nIs singed?: " << std::boolalpha
  << f.checkIfSigned() << "\nMin. grade to sign: " << f.getGradeToSign()
  << "\nMin. grade to execute: " << f.getGradeToExecute();
  return (os);
}
