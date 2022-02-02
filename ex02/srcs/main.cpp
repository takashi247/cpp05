#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"

#include <iostream>

void printHeader(std::string header) {
  std::cout << "\n---" << header << "---" << std::endl;
}

void printFooter(std::string footer) {
  std::cout << "---" << footer << "---\n" << std::endl;
}

void testShrubberyCreationForm() {
  printHeader("start ShrubberyCreationForm class test");

  Bureaucrat john("John", 100);
  Bureaucrat bob("Bob", 140);
  Bureaucrat will("Will", 150);

  std::cout << john << std::endl;
  std::cout << bob << std::endl;
  std::cout << will << std::endl;

  // test for ShrubberyCreationForm
  ShrubberyCreationForm form("my_home");

  std::cout << std::endl;
  std::cout << form << std::endl;
  std::cout << std::endl;

  // test NotSignedException
  john.executeForm(form);

  // test GradeTooLowExeption for signing
  will.signForm(form);

  // test GradeTooLowExeption for executing
  bob.signForm(form);
  bob.executeForm(form);

  // test successful execution
  john.executeForm(form);

  printFooter("end ShrubberyCreationForm class test");
}

void testRobotomyRequestForm() {
  printHeader("start RobotomyRequestForm class test");

  Bureaucrat john("John", 30);
  Bureaucrat bob("Bob", 50);
  Bureaucrat will("Will", 100);

  std::cout << john << std::endl;
  std::cout << bob << std::endl;
  std::cout << will << std::endl;

  // test for ShrubberyCreationForm
  RobotomyRequestForm form("Minister");

  std::cout << std::endl;
  std::cout << form << std::endl;
  std::cout << std::endl;

  // test NotSignedException
  john.executeForm(form);

  // test GradeTooLowExeption for signing
  will.signForm(form);

  // test GradeTooLowExeption for executing
  bob.signForm(form);
  bob.executeForm(form);

  // test successful execution
  john.executeForm(form);

  printFooter("end RobotomyRequestForm class test");
}

int main(void) {
  testShrubberyCreationForm();
  testRobotomyRequestForm();
}

#ifdef LEAKS
void	detect_leak(void)__attribute__((destructor));

void	detect_leak(void) {
  system("leaks -q a.out");
}
#endif
