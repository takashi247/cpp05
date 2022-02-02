#include "../include/ShrubberyCreationForm.hpp"

#include <iostream>
#include <fstream>

const std::string ShrubberyCreationForm::kFormName = "ShrubberyCreationForm";

const std::string ShrubberyCreationForm::kShrubberyAsciiArt =
"\n"
"                                                         .\n"
"                                              .         ;  \n"
"                 .              .              ;%     ;;   \n"
"                   ,           ,                :;%  %;   \n"
"                    :         ;                   :;%;'     .,   \n"
"           ,.        %;     %;            ;        %;'    ,;\n"
"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
"              %;       %;%;      ,  ;       %;  ;%;   ,%;' \n"
"               ;%;      %;        ;%;        % ;%;  ,%;'\n"
"                `%;.     ;%;     %;'         `;%%;.%;'\n"
"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
"                    `:%;.  :;bd%;          %;@%;'\n"
"                      `@%:.  :;%.         ;@@%;'   \n"
"                        `@%.  `;@%.      ;@@%;         \n"
"                          `@%%. `@%%    ;@@%;        \n"
"                            ;@%. :@%%  %@@%;       \n"
"                              %@bd%%%bd%%:;     \n"
"                                #@%%%%%:;;\n"
"                                %@@%%%::;\n"
"                                %@@@%(o);  . '         \n"
"                                %@@@o%;:(.,'         \n"
"                            `.. %@@@o%::;         \n"
"                               `)@@@o%::;         \n"
"                                %@@(o)::;        \n"
"                               .%@@@@%::;         \n"
"                               ;%@@@@%::;.          \n"
"                              ;%@@@@%%:;;;. \n"
"                          ...;%@@@@@%%:;;;;,..\n";

const std::string ShrubberyCreationForm::kFileNameSuffix = "_shrubbery";

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
    : Form(kFormName, kGradeToSign, kGradeToExec), target_(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::takeAction() const {
  std::ofstream ofs(target_ + kFileNameSuffix);
  if (!ofs) {
    std::cerr << "Failed to open the file" << std::endl;
    std::exit(EXIT_FAILURE);
  }
  ofs << kShrubberyAsciiArt << std::endl;
}
