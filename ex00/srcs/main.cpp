#include "Bureaucrat.hpp"

#include <iostream>

int main(void)
{
  Bureaucrat john("John", 100);
  Bureaucrat john_copy(john);

  std::cout << john << std::endl;
  std::cout << john_copy << std::endl;

  // get promoted
  john.getPromoted();
  std::cout << john << std::endl;

  // get demoted
  john.getDemoted();
  std::cout << john << std::endl;

  // test error handling
  Bureaucrat vice_minister("Vice Minister", 1);
  Bureaucrat intern("Intern", 150);
  std::cout << vice_minister << std::endl;
  std::cout << intern << std::endl;

  try {
    vice_minister.getPromoted();
  } catch (std::exception const &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    intern.getDemoted();
  } catch (std::exception const &e) {
    std::cout << e.what() << std::endl;
  }

  // test constructor error handling
  try {
    Bureaucrat no_name;
  } catch (std::exception const &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    Bureaucrat too_low("too low", 200);
  } catch (std::exception const &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    Bureaucrat too_high("too high", -200);
  } catch (std::exception const &e) {
    std::cout << e.what() << std::endl;
  }
}

#ifdef LEAKS
void	detect_leak(void)__attribute__((destructor));

void	detect_leak(void)
{
  system("leaks -q a.out");
}
#endif
