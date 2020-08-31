#include "Lexer.h"

Lexer::Lexer(const std::string& src)
{
	this->fin.open(src, std::ios::in);
	/* fin >> skips whitespace. 
	   fin.get() doesnt and therefore its preferred */
	c = fin.get();
}

Lexer::~Lexer(void)
{
	this->fin.close();
}


Token* Lexer::getNextToken(void)
{
	Token* token = nullptr;
	TokenType type;
	std::string lexeme;

	state = State::START;

	while(state >= State::START)
	{
		switch(state)
		{
			/*
			▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
			██ ▄▄▄ █▄ ▄█ ▄▄▀█ ▄▄▀█▄ ▄██
			██▄▄▄▀▀██ ██ ▀▀ █ ▀▀▄██ ███
			██ ▀▀▀ ██▄██▄██▄█▄█▄▄██▄███
			▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
			*/
			case State::START:
				if(isalpha(c))
				{
					lexeme += c;
					state = State::ID;
					c = fin.get();
				}
				else if(isdigit(c))
				{
					lexeme += c;
					state = State::INTEGER;
					c = fin.get();
				}
				else if(isspace(c))
				{
					c = fin.get();
				}
				else if(c == '=')
				{
					lexeme += c;
					state = State::ASSIGN;
					c = fin.get();
				}
				else if(c == ';')
				{
					lexeme += c;
					c = fin.get();
					state = State::ACCEPT;
					type = TokenType::SEMICOLON;
				}
				else
				{
					state = State::ERROR;
				}
			break;

			/*=============================*/
			/*
			▄▄▄▄▄▄▄▄▄▄▄▄
			█▄ ▄██ ▄▄▀██
			██ ███ ██ ██
			█▀ ▀██ ▀▀ ██
			▀▀▀▀▀▀▀▀▀▀▀▀
			*/
			case State::ID:
				type = TokenType::ID;
				if(isalpha(c) || isdigit(c))
				{
					lexeme += c;
					c = fin.get();
				}
				else
				{
					state = State::ACCEPT;
				}
			break;

			/* ============================= */
			/*
			▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
			█▄ ▄█ ▄▄▀█▄ ▄█ ▄▄█ ▄▄▄█ ▄▄█ ▄▄▀██
			██ ██ ██ ██ ██ ▄▄█ █▄▀█ ▄▄█ ▀▀▄██
			█▀ ▀█▄██▄██▄██▄▄▄█▄▄▄▄█▄▄▄█▄█▄▄██
			▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
			*/
			case State::INTEGER:
				type = TokenType::INTEGER;
				if(isdigit(c))
				{
					lexeme += c;
					c = fin.get();
				}
				else if(c == '.')
				{
					lexeme += c;
					c = fin.get();
					state = State::FLOAT;
				}
				else
				{
					state = State::ACCEPT;
				}
			break;

			/* ============================= */
			/*
			▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
			██ ▄▄▄█ ██▀▄▄▀█ ▄▄▀█▄ ▄██
			██ ▄▄██ ██ ██ █ ▀▀ ██ ███
			██ ████▄▄██▄▄██▄██▄██▄███
			▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
			*/
			case State::FLOAT:
				type = TokenType::FLOAT;
				if(isdigit(c))
				{
					lexeme += c;
					c = fin.get();
				}
				else
				{
					state = State::ACCEPT;
				}
			break;

			/* ============================= */
			/*
			▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
			█ ▄▄▀█ ▄▄█ ▄▄██▄██ ▄▄▄█ ▄▄▀██
			█ ▀▀ █▄▄▀█▄▄▀██ ▄█ █▄▀█ ██ ██
			█ ██ █▄▄▄█▄▄▄█▄▄▄█▄▄▄▄█▄██▄██
			▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
			*/
			case State::ASSIGN:
				type = TokenType::ASSIGN;
				if(c == '=')
				{
					lexeme += c;
					type = TokenType::EQUALS;
					state = State::ACCEPT;
				}
				else
				{
					state = State::ACCEPT;
				}
			break;

			/* ============================= */

		}
	}

	/* accept if in accepting state or if the input has finished just return the already read */
	if(state == State::ACCEPT || (state > State::START && fin.eof()))
	{
		/* check if is id and keyword */
		/* register to symtab */
		token = TokenFactory::createToken(type, lexeme);
	}

	return token;
}