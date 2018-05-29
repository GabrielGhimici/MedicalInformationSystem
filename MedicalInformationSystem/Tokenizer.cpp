#include "Tokenizer.h"

MedicalInformationSystem::Tokenizer::Tokenizer() {}

MedicalInformationSystem::Tokenizer::~Tokenizer() {}

std::vector<std::string> MedicalInformationSystem::Tokenizer::tokenize(std::string inputString, char delimiter) {
	std::vector<std::string> tokens;
	size_t start = inputString.find_first_not_of(delimiter), end = start;
	while (start != std::string::npos) {
		end = inputString.find_first_of(delimiter, start);
		tokens.push_back(inputString.substr(start, end - start));
		start = inputString.find_first_not_of(delimiter, end);
	}
	return tokens;
}