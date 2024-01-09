#include <iostream>
#include <fstream>

std::string readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file: " << filename << std::endl;
        exit(1);
    } else if (file.peek() == EOF) {
        std::cerr << "Error: file is empty: " << filename << std::endl;
        exit(1);
    }

    std::string line;
    std::string fileContents;
    while (std::getline(file, line)) {
        fileContents += line;
        fileContents += '\n';
    }

    file.close();
    if (file.is_open()) {
        std::cerr << "Error: could not close file: " << filename << std::endl;
        exit(1);
    }
    return fileContents;
}


void replaceAndWriteToFile(const std::string& filename, const std::string& fileContents, const std::string& stringToReplace, const std::string& stringToReplaceWith) {
    size_t index = 0;
    std::string modifiedContents = fileContents;

    index = modifiedContents.find(stringToReplace, index);
    if (index == std::string::npos) {
        std::cerr << "Error: string to replace not found in the file." << std::endl;
        exit(1);
    }

    while((index = modifiedContents.find(stringToReplace, index)) != std::string::npos) {
        modifiedContents.erase(index, stringToReplace.length());
        modifiedContents.insert(index, stringToReplaceWith);
        index += stringToReplaceWith.length();
    }

    std::ofstream newFile(filename + ".replace");
    if (!newFile.is_open()) {
        std::cerr << "Error: could not create or open file: " << filename + ".replace" << std::endl;
        exit(1);
    }

    newFile << modifiedContents;
    newFile.close();
    if (newFile.is_open()) {
        std::cerr << "Error: could not close file: " << filename + ".replace" << std::endl;
        exit(1);
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cerr << "Usage: ./replace <filename> <string_to_replace> <string_to_replace_with>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string stringToReplace = argv[2];
    std::string stringToReplaceWith = argv[3];

    std::string fileContents = readFromFile(filename);
    replaceAndWriteToFile(filename, fileContents, stringToReplace, stringToReplaceWith);

    std::cout << "Replacement complete. Output written to: " << filename + ".replace" << std::endl;

    return 0;
}
