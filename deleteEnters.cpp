#include <iostream> 
#include <fstream>
#include <string>


void deleteEnters(std::string filename) { 
    std::ifstream iostr; 
    iostr.open(filename);
    int i = 0; 
    std::ofstream ostr("newfile.txt"); 
    std::string line;
    while (std::getline(iostr, line)) { 
        if (i % 2 == 0) { 
            ostr << line;
        }
        i++;
    }
}


int main() { 
    deleteEnters("file.txt");
    return 1;
}