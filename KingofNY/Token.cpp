#include "pch.h"
#include "Token.h"


Token::Token()
{
	this->type = "";
}

Token::Token(string tokenType)
{
	this->type = tokenType;
}


Token::~Token()
{
}

string Token::getTokenType()
{
	return this->type;
}


