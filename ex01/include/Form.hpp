#ifndef FORM_HPP
#define FORM_HPP

#include <string>

class Bureaucrat;

class Form {
 public:
  Form(const std::string name, const int grade_to_sign, const int grade_to_execute);
  ~Form();
  const std::string &getName() const;
  const bool &checkIfSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  void beSigned(Bureaucrat &b);

  class GradeTooHighException : public std::exception {
    virtual const char *what() const throw ();
    static const char* kErrMsgGradeTooHigh;
  };

  class GradeTooLowException : public std::exception {
    virtual const char *what() const throw ();
    static const char* kErrMsgGradeTooLow;
  };

 private:
  Form();
  Form(const Form &other);
  Form &operator=(const Form &other);
  const std::string name_;
  bool is_signed_;
  const int grade_to_sign_;
  const int grade_to_execute_;
};

std::ostream &operator<<(std::ostream &os, const Form &f);

#endif // FORM_HPP
