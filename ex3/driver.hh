#ifndef DRIVER_HH
#define DRIVER_HH

#include "parser.hh"
#include "scanner.hh"

#include <string>
#include <map>

#ifndef yyFlexLexerOnce
#include <FlexLexer.h>
#endif

#undef YY_DECL

// Give Flex the prototype of yylex we want.
#define YY_DECL yy::parser::symbol_type scanner::yylex(driver& drv)

class driver
{
public:
    driver();

    std::map<std::string, int> variables;
    int result;

    // Run the parser on file F. Return 0 on success.
    int parse(const std::string& f);

    // The name of the file being parsed.
    std::string file;

    // Whether to generate parser debug traces.
    bool trace_parsing;

    // Whether to generate scanner debug traces.
    bool trace_scanning;

    // The token's location used by the scanner.
    yy::location location;

    // The scanner.
    scanner lexer;
};

#endif // DRIVER_HH
