#ifndef LEXER_H_
#define LEXER_H_ 1

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

#include "Token.h"

enum class State
{
	/* dont modify */
	ERROR = -2,
	ACCEPT,
	START,
	/* modifiable */
	ID,
	INTEGER,
	FLOAT,
	ASSIGN,
	EQUALS,
};

class Lexer
{
public:
	Lexer(const std::string& src);
	virtual ~Lexer(void);

	Token* getNextToken(void);

protected:
	State state;
	char c;
	std::fstream fin;
};


#endif /* LEXER_H_ */
