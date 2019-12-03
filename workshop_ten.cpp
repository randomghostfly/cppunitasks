#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include <algorithm>
#include <cmath>

void howManyCountries(const std::vector<std::vector<std::string>>& worldCities) {
    std::unordered_set<std::string> countries;
    for (const std::vector<std::string> & vec : worldCities) {
        if (vec.size() > 4) {
            countries.insert(vec[4]);
        }
    }
    std::cout << countries.size() << std::endl;
}

void countryCapital(const std::vector<std::vector<std::string>>& worldCities) {
    for (const std::vector<std::string> & vec : worldCities) {
        if (vec[8].find("primary") != std::string::npos) {
            std::cout << vec[4] << " - " << vec[1] << std::endl;
        }
    }
}

void uninhabitedLongitude(const std::vector<std::vector<std::string>>& worldCities) {
    std::unordered_set<int> longs;
    for (size_t j = 1; j < worldCities.size(); j++) {
        longs.insert(floor(std::stod(worldCities[j][2])));
    }
    for (int i = -180; i < 180; i++) {
        if (longs.find(i) == longs.end()) {
            std::cout << i << std::endl;
        }
    }
}

int main() {
    std::fstream input;
    std::string line;
    input.open("worldcities.csv");
    std::vector<std::vector<std::string>> worldCities;

    if (input.is_open()) {
        while (!input.eof() && input.good ()) {
            int count = 0;
            std::getline(input, line);
            if (line.empty()) {
                break;
            }
            std::stringstream ss(line);
            std::vector<std::string> currentLine;
            std::string token;
            while (!ss.eof () && ss.good ()) {
                std::getline (ss, token, ',');
                if (token.empty()) {
                    currentLine.emplace_back(" ");
                } else {
                    token.erase(std::remove(token.begin(), token.end(), '\"'), token.end());
                    currentLine.emplace_back(token);
                }
            }
            worldCities.emplace_back(currentLine);
        }
        howManyCountries(worldCities);
        countryCapital(worldCities);
        uninhabitedLongitude(worldCities);
    }
    return 0;
}
