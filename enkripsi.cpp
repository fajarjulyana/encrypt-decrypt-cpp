#include <iostream>
#include <fstream>
#include <string>

void encryptDecrypt(std::string inputFileName, std::string outputFileName, char key) {
    std::ifstream inputFile(inputFileName, std::ios::binary);
    std::ofstream outputFile(outputFileName, std::ios::binary);

    if (!inputFile || !outputFile) {
        std::cerr << "Error opening files!" << std::endl;
        return;
    }

    char buffer;
    while (inputFile.get(buffer)) {
        buffer ^= key; // Enkripsi/Dekripsi dengan XOR
        outputFile.put(buffer);
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    std::string inputFileName, outputFileName;
    char key;

    std::cout << "Enter input file name: ";
    std::cin >> inputFileName;

    std::cout << "Enter output file name: ";
    std::cin >> outputFileName;

    std::cout << "Enter encryption key (single character): ";
    std::cin >> key;

    encryptDecrypt(inputFileName, outputFileName, key);

    std::cout << "File encryption/decryption completed." << std::endl;

    return 0;
}
