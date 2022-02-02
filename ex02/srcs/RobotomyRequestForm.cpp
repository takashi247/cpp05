#include "../include/RobotomyRequestForm.hpp"

#include <stdlib.h> // for NULL
#include <stdio.h> // for srand, rand
#include <time.h> // for time

#include <iostream>

const std::string RobotomyRequestForm::kFormName = "RobotomyRequestForm";

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : Form(kFormName, kGradeToSign, kGradeToExec), target_(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::takeAction() const {
  std::cout << "Rizzzzzzzzzzzzzzzzzz...." << std::endl;
  srand(time(NULL));
  int random_num = rand() % kMaxRandomNum;
  if (random_num < kMaxRandomNum / 2) {
    std::cout << "SUCCESS: " << target_ << " has been robotomized" << std::endl;
  } else {
    std::cout << "FAILURE: " << target_ << " was gone..." << std::endl;
  }
}
