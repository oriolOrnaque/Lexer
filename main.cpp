#include <iostream>
#include <string>

#include "Lexer.h"
#include "Token.h"

int main()
{
	Lexer lex("test.bit");

	Token* t = nullptr;

	while((t = lex.getNextToken()) != nullptr)
	{
		std::cout << *t << std::endl;
		delete t;
	}

	return 0;
}
