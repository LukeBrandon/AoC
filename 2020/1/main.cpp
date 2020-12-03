/*
 * https://adventofcode.com/2020/day/1
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

const string INPUT_FILE_NAME = "input.txt";
vector<int> numbers;

void read_input(){
    ifstream inputFile;
    string line;

    inputFile.open(INPUT_FILE_NAME);

    while(getline(inputFile, line)){
        numbers.push_back(stoi(line));
    }

    inputFile.close();
}

// Finds 2 numbers that sum to 2020 and multiplies them together
int find_2(){
    for (int i = 0; i < numbers.size(); i++){
        for(int j = 0; j < numbers.size(); j++){

            if(numbers[i] + numbers[j] == 2020){
                return(numbers[i]*numbers[j]);
                printf("\n");
                break;
            }

        }
    }
}

// Finds 3 numbers that sums to 2020 and multiplies them together
int find_3(){
    for (int i = 0; i < numbers.size(); i++){
        for(int j = 0; j < numbers.size(); j++){
            for(int k = 0; k < numbers.size(); k++){

                if(numbers[i] + numbers[j] + numbers[k] == 2020){
                    return(numbers[i]*numbers[j]*numbers[k]);
                    break;
                }
            }
        }
    }
}

int main(){

    read_input();

    // Find numbers that sum to 2020
    printf("2: %i \n",find_2());

    printf("3: %i \n",find_3());
    

    return 0;
}