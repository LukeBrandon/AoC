/*
 * https://adventofcode.com/2020/day/2
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const string INPUT_FILE_NAME = "input.txt";

vector<pair<char, pair<int, int>>> reqs;
vector<string> passwords;

void read_input(){
    ifstream inputFile;
    string line;

    inputFile.open(INPUT_FILE_NAME);

    while(getline(inputFile, line)){
        // Get min and max
        int dashIndex = line.find("-", 0);
        int spaceIndex = line.find_first_of(" ", 0);

        // Find min and erase it from string
        int min = stoi(line.substr(0, line.find("-")));
        line.erase(0,line.find("-") + 1);

        // Find max and erase it from string
        int max = stoi(line.substr(0, line.find_first_of(" ")));
        line.erase(0, line.find_first_of(" ") + 1);

        // Find the character to look for in the passwords
        char character = line[0];
        line.erase(0,3);

        string password = line;

        // Add to the vector
        reqs.push_back(make_pair(character, make_pair(min, max)));
        passwords.push_back(line);
    }

    inputFile.close();
}


void first_style_passwords(){
    int total_count = 0;
    for(int i = 0; i < reqs.size(); i++){
        
        // Count number of expected characters in the password
        int count = 0;
        for(int j = 0; j < passwords[i].length(); j++){
            if(passwords[i][j] == reqs[i].first){
                count ++;
            }
        }

        if(count >= reqs[i].second.first && count <= reqs[i].second.second){
            total_count += 1;
        }
    }

    printf("Total Valid Passwords: %i \n", total_count);
}

void second_style_passwords(){
    int total_count = 0;
    
    for(int i = 0; i < passwords.size(); i++){

        string current_password = passwords[i];
        int first_index = reqs[i].second.first -1;
        int second_index = reqs[i].second.second -1;
        char character = reqs[i].first;

        // If either the first or the second index is equal to the character, but can't be both
        if((current_password[first_index] == character) != (current_password[second_index] == character)){
            total_count++;
        }
        
    }

    printf("Total Valid Passwords: %i \n", total_count);
}

int main(){

    read_input();

    first_style_passwords();
    second_style_passwords();

    return 0;
}