#include <filesystem>
#include <iostream>
#include <fstream>

static const std::string inBasePath = "../shaders";
static const std::string outBasePath = "../src/shaders/";

void exportFile(const std::filesystem::path &inPath) {
    std::ifstream inFile(inPath, std::ios::ate | std::ios::binary);

    if (!inFile.is_open()) {
        throw std::runtime_error("failed to open file: " + inPath.string());
    }

    const size_t fileSize = inFile.tellg();
    std::vector<char> buffer(fileSize);
    inFile.seekg(0);
    inFile.read(buffer.data(), static_cast<std::streamsize>(fileSize));

    std::filesystem::path exportPath = outBasePath;
    exportPath += inPath.stem();
    exportPath += ".h";

    std::ofstream exportedFile(exportPath, std::ios::binary);

    std::string arrayName = inPath.stem().string();

    exportedFile
            << "#pragma once\n\n"
            << "#include <vector>\n\n"
            << "namespace shaders {\n"
            << "\tstatic inline const std::vector<unsigned char> " << arrayName << " {\n\t\t";

    for (size_t i = 0; i < buffer.size(); i++) {
        exportedFile
                << "0x" << std::setw(2) << std::setfill('0') << std::hex
                << static_cast<int>(static_cast<unsigned char>(buffer[i])) << ", ";

        if (i % 16 == 15 || i == buffer.size() - 1) {
            exportedFile << std::endl;

            if (i != buffer.size() - 1) {
                exportedFile << "\t\t";
            }
        }
    }

    exportedFile << "\t};\n}\n";
}

int main() {
    for (const auto &entry: std::filesystem::directory_iterator(inBasePath)) {
        if (entry.path().extension() != ".spv") {
            continue;
        }

        exportFile(entry.path());
    }
}
