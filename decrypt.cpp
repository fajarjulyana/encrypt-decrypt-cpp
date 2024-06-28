#include <iostream>
#include <fstream>
#include <string>

void processFile(std::string inputFileName, std::string outputFileName, char key) {
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

void encryptFile(std::string inputFileName, std::string outputFileName, char key) {
    std::cout << "Encrypting file: " << inputFileName << std::endl;
    processFile(inputFileName, outputFileName, key);
    std::cout << "File encrypted successfully: " << outputFileName << std::endl;
}

void decryptFile(std::string inputFileName, std::string outputFileName, char key) {
    std::cout << "Decrypting file: " << inputFileName << std::endl;
    processFile(inputFileName, outputFileName, key);
    std::cout << "File decrypted successfully: " << outputFileName << std::endl;
}

int main() {
    std::string inputFileName, outputFileName;
    char key;
    int choice;

    std::cout << "1. Encrypt File\n2. Decrypt File\nChoose an option: ";
    std::cin >> choice;

    std::cout << "Enter input file name: ";
    std::cin >> inputFileName;

    std::cout << "Enter output file name: ";
    std::cin >> outputFileName;

    std::cout << "Enter encryption key (single character): ";
    std::cin >> key;

    if (choice == 1) {
        encryptFile(inputFileName, outputFileName, key);
    } else if (choice == 2) {
        decryptFile(inputFileName, outputFileName, key);
    } else {
        std::cerr << "Invalid choice!" << std::endl;
    }

    return 0;
}
