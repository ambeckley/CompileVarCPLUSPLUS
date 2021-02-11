#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


int some_execute_function(const std::string& code)
{
    const std::string dynamic_filename("dynamic.cpp");
    const std::string dynamic_executable("./dynamic.out");
    std::ofstream dynamic(dynamic_filename);
    dynamic << "#include <iostream>\n"
            << "#include <cstdlib>\n"
            << "int main(){\n"
            << code << ";\n"
            << "return EXIT_SUCCESS;\n"
            << "}\n";
    dynamic.close();

    const std::string build_command("g++ -std=c++14 -O2 -Wall -pedantic -pthread " + dynamic_filename + " -o " + dynamic_executable);    
    bool it_didnt_compile = system(build_command.c_str());
    if(it_didnt_compile)
    {
        return EXIT_FAILURE;
    }
    else
    {
        return system(dynamic_executable.c_str());
    }
}

int main()
{
    std::string a;
    std::cout << "Input Formula: ";
    std::cin >> a;
    std::string firststr;
    std::string laststr;
    firststr = "std::cout << \"The Solution is: \" <<";
    laststr = ";";
    std::string code_string = firststr + a + laststr;
    //std::string code_string = "std::cout << \"Hello World!!\\\n\";";
    //std::cout << "The Solution is: ";
    return some_execute_function(code_string);
}