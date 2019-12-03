#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>

int main(int argc, char** argv) {

    if (argc != 3) {
        return 0;
    }

    std::fstream input;
    std::string line;
    std::map<std::string, int> freq;
    std::vector<std::pair<int, std::string>> result;

    input.open(argv[1]);
    size_t index = std::stoi(argv[2]);

    if (input.is_open()) {
        while (!input.eof() && input.good ()) {
            int count = 0;
            std::getline(input, line);
            std::stringstream ss(line);
            std::string token;

            while (!ss.eof () && ss.good ()) {
                std::getline (ss, token, ',');
                if (count == index) {
                    if (freq.find(token) != freq.end()) {
                        freq[token] += 1;
                    } else {
                        freq[token] = 1;
                    }
                }
                count++;
            }
        }
    }

    for (std::map<std::string, int>::iterator it = freq.begin(); it != freq.end(); it++) {
        std::pair<int, std::string> temp = {it->second, it->first};
        result.push_back(temp);
    }

    std::sort(result.begin(), result.end());

    for (std::pair<int, std::string> & pair : result) {
        std::cout << pair.first << ' ' << pair.second << std::endl;
    }

    return 0;
}

