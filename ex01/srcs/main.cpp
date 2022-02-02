#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"

#include <iostream>

int main(void)
{
  Bureaucrat john("John", 100);

  std::cout << john << std::endl;

  Form form("simple form", 99, 99);

  std::cout << form << std::endl;

  // test exception handling for form
  john.signForm(form);

  // get promoted
  john.getPromoted();
  std::cout << john << std::endl;

  // test exception handling for form
  john.signForm(form);

  // test error handling for Form
  try {
    Form too_high("too high", -100, 100);
  } catch (std::exception const &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    Form too_low("too low", 100, 300);
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
