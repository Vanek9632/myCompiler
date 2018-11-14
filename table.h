#ifndef TABLE_H
#define TABLE_H

#define SIZETABLE 11
#define NAMESIZE 32

typedef enum {
	semiTok, commaTok, nameTok, numTok, LbraketTok,
	RbraketTok, multTok, divTok, moreTok, lessTok,
	moreEQTok, lessEQTok, assignTok, minusTok, plusTok,
	equalTok, modTok, RbracesTok, LbracesTok, forTok,
	elseTok, whileTok, ifTok, startTok, noneTok,
	typeTok, varTok, notEQTok, printTok, scanTok,
	doblPTok, doblMTok, doblQuotTok, singlQuotTok,
	backSlashTok, eofTok, andTok, orTok, multATok,
	divATok, plusATok, minusATok, modATok
} TokenType;

typedef enum {
	intType, doubleType, charType, noneType, 
	boolType, constType
} TypeVar;

struct embeddedNames {
	char name[6];
	TokenType type;
} TableNames[SIZETABLE];

typedef struct Token {
	char name[NAMESIZE];
	int *value;
	TokenType tokenType;
	TypeVar typeVar;
	struct Token* low;
} StackTok;

extern StackTok *top;

void newToken(char *_name, int _value, TokenType _tokenType, TypeVar _typeVar);
int searchTN(char *_name);
StackTok* find(char *_name);
TypeVar findType(char *_name);
void enter(void);

#endif