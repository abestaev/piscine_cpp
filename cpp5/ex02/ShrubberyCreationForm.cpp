#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 
                                                       145, 
                                                       137, 
                                                       "default_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 
                                                                                145, 
                                                                                137,
                                                                                target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src) {
    if (this != &src) {
        AForm::operator=(src);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > getGradeRequiredToExecute()) {
        throw AForm::GradeTooLowException();
    }
    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());
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