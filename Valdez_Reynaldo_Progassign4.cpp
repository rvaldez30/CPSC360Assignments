//Reynaldo Valdez
//Assignment 4

#include <iostream>
#include <fstream>
#include <string>

//Fuctions 
void start_file(std::string fn);
void last_file(std::string fn);

//variables 
std::fstream file;
std::string filename;
std::string word;
std::string newFile = "filestats.txt";
std::string longestWord = " ";
std::string you_Choose = "y";

void startFile(std::string fn){
	//open file
	file.open(fn, std::ios::in);
	
	//open failure
	if (!file){
		std::cout << "File didn't open. Try again." << std::endl;
		exit(1);
	}
	//appends words from file to file
	std::ofstream n_file(newFile);
	while (file >> word) {
		n_file << word << ' ';
	}
	file.close();
	n_file.close();
}

void last_file(std::string fn){
	//variables 
	std::string lWord;
	int n_words = 0;
	int n_char_in_word = 0;
	
	file.open(fn, std::ios::in);
	
	while(file >> word){
		std::size_t letter = word.find('e');
		if (letter != std::string::npos){
			n_words += 1;
			lWord = word;
		}
		
		if(lWord.length() > longestWord.length()){
			longestWord = lWord;
		}
	}
	
	//character with the letter e
	n_char_in_word = longestWord.length();
	std::cout << "\nWords where the letter e appears: " << n_words << std::endl;
	std::cout << "Longest word that contains the letter e: " << longestWord << std::endl;
	std::cout << "Length of longest word with e in it: " << n_char_in_word << std::endl;
	
	//file close
	file.close();
}

int main(){
	std::cout << "This is a file word analyzer" << std::endl;
	
	do{
		std::cout << "\nFile you want to analyze: ";
		std::cin >> filename;
		std::cin.ignore(100,'\n');
		
		startFile(filename);
		last_file(newFile);
		
		std::cout << "\nDo you want to analyze another file? Y/N: " << std::endl;
		std::cin >> you_Choose;
		
		if (you_Choose == "n"){
			std::cout << "Thanks for using the program" << std::endl;
			exit(1);
		}
	} while (you_Choose == "y");
	return 0;
}
