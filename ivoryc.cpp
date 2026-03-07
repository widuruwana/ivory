#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>

/**
 * Ivory Compiler (ivoryc)
 * A lightweight transpiler that converts .ivy esoteric source code into native executables.
 * * Architecture:
 * This tool acts as a single-pass transpiler. It maps Ivory instructions to an intermediate 
 * C++ representation of a Turing-complete tape machine. It then forks a system process, 
 * invoking the local GCC toolchain to perform Ahead-of-Time (AOT) compilation into a 
 * standalone ELF/PE binary artifact.
 */

int main(int argc, char* argv[]) {
    // Validate CLI arguments for standard compiler invocation
    if (argc < 2 || argc > 3) {
        std::cerr << "Usage: " << argv[0] << " <input.ivy> [output_binary_name]\n";
        return 1;
    }

    std::ifstream inFile(argv[1]);
    if (!inFile.is_open()) {
        std::cerr << "Fatal Error: Unable to open input stream.\n";
        return 1;
    }

    // Initialize the Intermediate Representation (IR) file
    std::string tempFile = "temp_ivory_build.cpp";
    std::ofstream outFile(tempFile);

    // Emit target runtime environment boilerplate.
    // The runtime utilizes a 64-bit sparse memory architecture (hash map) for a
    // bi-directionally infinite tape, alongside threading for I/O timing constraints.
    outFile << "#include <iostream>\n";
    outFile << "#include <thread>\n";
    outFile << "#include <chrono>\n";
    outFile << "#include <random>\n";
    outFile << "#include <vector>\n";
    outFile << "#include <cstdlib>\n";
    outFile << "#include <ctime>\n";
    outFile << "#include <unordered_map>\n";
    outFile << "int main() {\n";
    outFile << "    std::mt19937_64 rng(time(NULL));\n"; // 64-bit Mersenne Twister
    outFile << "    std::unordered_map<int, long long> tape;\n";
    outFile << "    int p = 0;\n";
    outFile << "    std::vector<long long> memories;\n";

    std::string word;
    // ---> Tokenization and IR Emission <---
    // Unrecognized string tokens are intentionally ignored, acting as implicit comments.
    while (inFile >> word) {

        // ---> Core Turing Machine Operations <---
        // Standard tape memory and pointer manipulation.
        if (word == "adore")        outFile << "    tape[p]++;\n";
        else if (word == "miss")    outFile << "    tape[p]--;\n";
        else if (word == "hold")    outFile << "    p++;\n";
        else if (word == "release") outFile << "    p--;\n";

        // ---> I/O and Control Flow <---
        // Handles standard streams and while-loop brackets.
        else if (word == "whisper") {
            outFile << "    std::cout << static_cast<char>(tape[p]) << std::flush;\n";
            outFile << "    std::this_thread::sleep_for(std::chrono::milliseconds(50));\n";
        }
        else if (word == "listen") {
            outFile << "    char _c; std::cin.get(_c); tape[p] = _c;\n";
        }
        else if (word == "promise") outFile << "    while(tape[p]) {\n";
        else if (word == "always")  outFile << "    }\n";

        // ---> LIFO Memory Stack <---
        // Hybrid Tape/Stack VM Architecture.
        else if (word == "cherish") {
            outFile << "    memories.push_back(tape[p]);\n";
        }
        else if (word == "reminisce") {
            outFile << "    if (!memories.empty()) {\n";
            outFile << "        tape[p] = memories.back();\n";
            outFile << "        memories.pop_back();\n";
            outFile << "    }\n";
        }

        // ---> Temporal & Environment Manipulation <---
        // Allows the VM to interact with host thread and terminal canvas.
        else if (word == "breathe")    outFile << "    std::this_thread::sleep_for(std::chrono::milliseconds(1000));\n";
        else if (word == "clear")      outFile << "    std::cout << \"\\033[2J\\033[1;1H\";\n";

        // ---> Dev QOL features <---
        // O(1) bulk arithmetic and state inspection for ease of hand-coding.
        else if (word == "passion")    outFile << "    tape[p] += 10;\n";
        else if (word == "heartbreak") outFile << "    tape[p] -= 10;\n";
        else if (word == "forget")     outFile << "    tape[p] = 0;\n";
        else if (word == "confess")    outFile << "    std::cout << tape[p] << \"\\n\";\n";

        // ---> Low-Level Architecture and Entropy <---
        // Direct memory addressing and interrupts.
        else if (word == "destiny") outFile << "    p = static_cast<int>(tape[p]);\n";
        else if (word == "wonder")  outFile << "    tape[p] = rng();\n";
        else if (word == "fade")    outFile << "    exit(0);\n";
    }

    outFile << "    return 0;\n";
    outFile << "}\n";
    outFile.close();

    // Resolve target output names, falling back to standard toolchain defaults
    std::string outName;

    if (argc == 3) {
        outName = argv[2];
    } else {
    #ifdef _WIN32
        outName = "a.exe";
    #else
        outName = "a.out";
    #endif
    }

    // Construct the compiler command and invoke the system subprocess
    std::string compileCmd = "g++ -O3 " + tempFile + " -o " + outName; 
    std::cout << "Compiling " << argv[1] << " to native binary...\n";

    int result = system(compileCmd.c_str());

    if (result == 0) {
        std::cout << "Success! Executable created: ./" << outName << "\n";
        // Cleanup: Remove the IR file
        remove(tempFile.c_str());
    } else {
        std::cerr << "Compilation failed.\n";
    }

    return 0;
}