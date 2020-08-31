#include "Token.h"

/*
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄▄ ▄▄█▀▄▄▀█ █▀█ ▄▄█ ▄▄▀██
███ ███ ██ █ ▄▀█ ▄▄█ ██ ██
███ ████▄▄██▄█▄█▄▄▄█▄██▄██
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
*/

Token::Token(const TokenType type, const std::string& lexeme)
	: type(type), lexeme(lexeme)
{

}

Token::~Token(void)
{

}

TokenType Token::getType(void) const
{
	return this->type;
}

const std::string& Token::getLexeme(void) const
{
	return this->lexeme;
}

std::ostream& operator<<(std::ostream& os, const Token& token)
{
	os << (int)token.getType() << ", \"" << token.getLexeme() << "\"";

	return os;
}


/*
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄▄ ▄▄█▀▄▄▀█ █▀█ ▄▄█ ▄▄▀█▄ ▄█ ▄▄▀█▄ ▄█ ▄▄█ ▄▄▄█ ▄▄█ ▄▄▀██
███ ███ ██ █ ▄▀█ ▄▄█ ██ ██ ██ ██ ██ ██ ▄▄█ █▄▀█ ▄▄█ ▀▀▄██
███ ████▄▄██▄█▄█▄▄▄█▄██▄█▀ ▀█▄██▄██▄██▄▄▄█▄▄▄▄█▄▄▄█▄█▄▄██
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
*/

TokenInteger::TokenInteger(const std::string& lexeme)
	: Token(TokenType::INTEGER, lexeme)
{
	this->value = atoi(lexeme.c_str());
}

/*
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄▄ ▄▄█▀▄▄▀█ █▀█ ▄▄█ ▄▄▀██ ▄▄▄█ ██▀▄▄▀█ ▄▄▀█▄ ▄██
███ ███ ██ █ ▄▀█ ▄▄█ ██ ██ ▄▄██ ██ ██ █ ▀▀ ██ ███
███ ████▄▄██▄█▄█▄▄▄█▄██▄██ ████▄▄██▄▄██▄██▄██▄███
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
*/

TokenFloat::TokenFloat(const std::string& lexeme)
	: Token(TokenType::FLOAT, lexeme)
{
	this->value = atof(lexeme.c_str());
}


/*
▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
█▄▄ ▄▄█▀▄▄▀█ █▀█ ▄▄█ ▄▄▀██ ▄▄▄█ ▄▄▀█▀▄▀█▄ ▄█▀▄▄▀█ ▄▄▀█ ██ ██
███ ███ ██ █ ▄▀█ ▄▄█ ██ ██ ▄▄██ ▀▀ █ █▀██ ██ ██ █ ▀▀▄█ ▀▀ ██
███ ████▄▄██▄█▄█▄▄▄█▄██▄██ ████▄██▄██▄███▄███▄▄██▄█▄▄█▀▀▀▄██
▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
*/

Token* TokenFactory::createToken(const TokenType type, const std::string& lexeme)
{
	Token* token = nullptr;

	switch(type)
	{
		/*case TokenType::ID:
			token = new Token(type, lexeme);
		break;*/
		case TokenType::INTEGER:
			token = new TokenInteger(lexeme);
			break;
		case TokenType::FLOAT:
			token = new TokenFloat(lexeme);
			break;
		default:
			token = new Token(type, lexeme);
	}

	return token;
}