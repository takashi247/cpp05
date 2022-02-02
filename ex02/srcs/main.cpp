#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"

#include <iostream>

void printHeader(std::string header) {
  std::cout << "\n---" << header << "---" << std::endl;
}

void printFooter(std::string footer) {
  std::cout << "---" << footer << "---\n" << std::endl;
}

void testShrubberyCreationForm() {
  printHeader("start ShrubberyCreationForm class test");

  Bureaucrat john_100("John", 100);
  Bureaucrat bob_140("Bob", 140);
  Bureaucrat will_150("Will", 150);

  std::cout << john_100 << std::endl;
  std::cout << bob_140 << std::endl;
  std::cout << will_150 << std::endl;

  // test for ShrubberyCreationForm
  ShrubberyCreationForm s_form("my_home");

  std::cout << std::endl;
  std::cout << s_form << std::endl;
  std::cout << std::endl;

  // test NotSignedException
  john_100.executeForm(s_form);

  // test GradeTooLowExeption for signing
  will_150.signForm(s_form);

  // test GradeTooLowExeption for executing
  bob_140.signForm(s_form);
  bob_140.executeForm(s_form);

  // test successful execution
  john_100.executeForm(s_form);

  printFooter("end ShrubberyCreationForm class test");
}

int main(void) {
  testShrubberyCreationForm();
}

#ifdef LEAKS
void	detect_leak(void)__attribute__((destructor));

void	detect_leak(void) {
  system("leaks -q a.out");
}
#endif
