#include <filesystem>
#include <fstream>
#include <iostream>
#include <set>

void get_defines(std::stringstream &buffer, std::set<std::string> &constants, std::set<std::string> &macros) {
    std::set<std::string> lines;
    std::string word, next_word;
    std::string line;
    while (std::getline(buffer, line)) {
        std::stringstream line_buffer(line);
        line_buffer >> word;
        if (word == "#define") {
            //std::cout << line << std::endl;
            line_buffer >> next_word;
            bool is_macro = false;
            for (auto i : next_word) {
                if (i == '(') {
                    is_macro = true;
                    break;
                }
            }
            if (is_macro) {
                macros.insert(line);
            } else {
                constants.insert(line);
            }
        }
    }
}



int main() {

    std::string dir_path = "/mnt/c/Users/harb2/Documents/Univer/1 sem/algo/dz/clion";
    std::set<std::string> constants, macros;
    for (auto& file_entry : std::filesystem::recursive_directory_iterator(dir_path)) {
        if (file_entry.path().extension() != ".c") {
            continue;
        }

        std::ifstream file(file_entry.path());

        std::stringstream buffer;
        buffer << file.rdbuf();
        //std::cout << file_entry.path() << std::endl;
        get_defines(buffer, constants, macros);

    }

    std::ofstream f_macros("/mnt/c/Users/harb2/Documents/Univer/2 sem/Lab12/macros.txt");
    std::ofstream f_constants("/mnt/c/Users/harb2/Documents/Univer/2 sem/Lab12/constants.txt");
    for (const auto& i : macros) {
        f_macros << i << "\n";
    }

    for (const auto& i : constants) {
        f_constants << i << "\n";
    }

    f_macros.close();
    f_constants.close();


}

