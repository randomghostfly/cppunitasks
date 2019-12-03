#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

std::string join(const std::vector<std::string> & vector, char delim) {
    std::string result;
    result += vector[0];
    if (vector.size() > 1) {
        for (size_t i = 1; i < vector.size(); i++) {
            result += delim + vector[i];
        }
    }
    return result;
}

int main(int argc, char** argv) {
    std::fstream input, output;
    std::string line;
    std::vector<int> cols;

    input.open(argv[1]);
    output.open(argv[2]);

    for (int i = 3; i < argc; ++i) {
        cols.push_back(std::stoi(argv[i]));
    }

    if (input.is_open()) {
        while (!input.eof() && input.good ()) {
            int count = 0;
            std::getline(input, line);
            std::vector<std::string> tokens;
            std::stringstream ss(line);
            std::string token;
            while (!ss.eof () && ss.good ()) {
                std::getline (ss, token, ',');
                if (std::find(cols.begin(), cols.end(), count) != cols.end()) {
                    tokens.push_back(token);
                }
                count++;
            }
            output << join(tokens, ',') << std::endl;
        }
    }
    return 0;
}

