#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat {
 public:
  static const int kHighestGrade = 1;
  static const int kLowestGrade = 150;
  Bureaucrat(const std::string name, int grade);
  ~Bureaucrat();
  const std::string &getName() const;
  int getGrade() const;
  void getPromoted();
  void getDemoted();

  class GradeTooHighException : public std::exception {
    virtual const char *what() const throw();
    static const char* kErrMsgGradeTooHigh;
  };

  class GradeTooLowException : public std::exception {
    virtual const char *what() const throw();
    static const char* kErrMsgGradeTooLow;
  };

 private:
  Bureaucrat();
  Bureaucrat(const Bureaucrat &other);
  Bureaucrat &operator=(const Bureaucrat &other);
  const std::string name_;
  int grade_;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);

#endif // BUREAUCRAT_HPP
