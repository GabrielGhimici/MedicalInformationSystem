#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <windows.h>
#include <iostream>
#include <vector>

namespace MedicalInformationSystemServer {
	class Tokenizer
	{
	public:
		Tokenizer();
		~Tokenizer();
		static std::vector<std::string> tokenize(std::string str, char delimiter);
	};
}

#endif
