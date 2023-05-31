#ifndef SCANNER_HH
#define SCANNER_HH

#include "parser.hh"

#ifndef yyFlexLexerOnce
#include <FlexLexer.h>
#endif

#include <iostream>

class driver;

class scanner : public yyFlexLexer
{
public:
    scanner()
        : yyFlexLexer{}
    {
    }

    explicit scanner(std::istream& is)
        : yyFlexLexer{is, std::cout}
    {
    }

    yy::parser::symbol_type yylex(driver& drv);
};

#endif // SCANNER_HH
