#include "../include/PresidentialPardonForm.hpp"

#include <iostream>

const std::string PresidentialPardonForm::kFormName = "PresidentialPardonForm";

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : Form(kFormName, kGradeToSign, kGradeToExec), target_(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::takeAction() const {
  std::cout << target_ << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
