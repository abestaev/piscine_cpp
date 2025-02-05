#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src), _target(src._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) {
    if (this != &src) {
        _target = src._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > getGradeRequiredToExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    file <<
    "\n"
    "                                                     .\n"
    "                                          .         ;\n"  
    "             .              .              ;%     ;;\n"
    "               ,           ,                :;%  %;\n"   
    "                :         ;                   :;%;'     .,\n"   
    "       ,.        %;     %;            ;        %;'    ,;\n"
    "         ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
    "          %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
    "           ;%;      %;        ;%;        % ;%;  ,%;'\n"
    "            `%;.     ;%;     %;'         `;%%;.%;'\n"
    "             `:;%.    ;%%. %@;        %; ;@%;%'\n"
    "                `:%;.  :;bd%;          %;@%;'\n"
    "                  `@%:.  :;%.         ;@@%;'\n"   
    "                    `@%.  `;@%.      ;@@%;\n"         
    "                      `@%%. `@%%    ;@@%;\n"        
    "                        ;@%. :@%%  %@@%;\n"       
    "                          %@bd%%%bd%%:;\n"     
    "                            #@%%%%%:;;\n"
    "                            %@@%%%::;\n"
    "                            %@@@%(o);  . '\n"         
    "                            %@@@o%;:(.,'\n"         
    "                        `.. %@@@o%::;\n"         
    "                           `)@@@o%::;\n"         
    "                            %@@(o)::;\n"     
    "                           .%@@@@%::;\n"      
    "                           ;%@@@@%::;.\n"        
    "                          ;%@@@@%%:;;;.\n"
    "                      ...;%@@@@@%%:;;;;,..\n";
    file.close();
}