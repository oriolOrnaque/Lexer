#ifndef TOKEN_H_
#define TOKEN_H_ 1

#include <iostream>
#include <string>

/*
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄▄ ▄▄█▀▄▄▀█ █▀█ ▄▄█ ▄▄▀█▄▄ ▄▄█ ██ █▀▄▄▀█ ▄▄██
███ ███ ██ █ ▄▀█ ▄▄█ ██ ███ ███ ▀▀ █ ▀▀ █ ▄▄██
███ ████▄▄██▄█▄█▄▄▄█▄██▄███ ███▀▀▀▄█ ████▄▄▄██
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
*/

enum class TokenType
{
	ID = 1,
	INTEGER,
	FLOAT,
	ASSIGN,
	EQUALS,
	SEMICOLON,
};

/*
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄▄ ▄▄█▀▄▄▀█ █▀█ ▄▄█ ▄▄▀██
███ ███ ██ █ ▄▀█ ▄▄█ ██ ██
███ ████▄▄██▄█▄█▄▄▄█▄██▄██
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
*/

class Token
{
public:
	Token(const TokenType type, const std::string& lexeme);
	virtual ~Token(void);

	TokenType getType(void) const;
	const std::string& getLexeme(void) const;

protected:
	TokenType type;
	std::string lexeme;
};

std::ostream& operator<<(std::ostream& os, const Token& token);


/*
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄▄ ▄▄█▀▄▄▀█ █▀█ ▄▄█ ▄▄▀█▄ ▄█ ▄▄▀█▄ ▄█ ▄▄█ ▄▄▄█ ▄▄█ ▄▄▀██
███ ███ ██ █ ▄▀█ ▄▄█ ██ ██ ██ ██ ██ ██ ▄▄█ █▄▀█ ▄▄█ ▀▀▄██
███ ████▄▄██▄█▄█▄▄▄█▄██▄█▀ ▀█▄██▄██▄██▄▄▄█▄▄▄▄█▄▄▄█▄█▄▄██
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
*/

class TokenInteger : public Token
{
public:
	TokenInteger(const std::string& lexeme);
protected:
	int value;
};

/*
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄▄ ▄▄█▀▄▄▀█ █▀█ ▄▄█ ▄▄▀██ ▄▄▄█ ██▀▄▄▀█ ▄▄▀█▄ ▄██
███ ███ ██ █ ▄▀█ ▄▄█ ██ ██ ▄▄██ ██ ██ █ ▀▀ ██ ███
███ ████▄▄██▄█▄█▄▄▄█▄██▄██ ████▄▄██▄▄██▄██▄██▄███
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
*/

class TokenFloat : public Token
{
public:
	TokenFloat(const std::string& lexeme);
protected:
	double value;
};

/*
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄▄ ▄▄█▀▄▄▀█ █▀█ ▄▄█ ▄▄▀██ ▄▄▄█ ▄▄▀█▀▄▀█▄ ▄█▀▄▄▀█ ▄▄▀█ ██ ██
███ ███ ██ █ ▄▀█ ▄▄█ ██ ██ ▄▄██ ▀▀ █ █▀██ ██ ██ █ ▀▀▄█ ▀▀ ██
███ ████▄▄██▄█▄█▄▄▄█▄██▄██ ████▄██▄██▄███▄███▄▄██▄█▄▄█▀▀▀▄██
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
*/

class TokenFactory
{
public:
	static Token* createToken(const TokenType type, const std::string& lexeme);
};

#endif /* TOKEN_H_ */
