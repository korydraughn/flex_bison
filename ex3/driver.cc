#include "driver.hh"

#ifndef yyFlexLexerOnce
#include <FlexLexer.h>
#endif

#include <cstdlib>
#include <fstream>

driver::driver()
    : trace_parsing{}
    , trace_scanning{}
{
    variables["one"] = 1;
    variables["two"] = 2;
}

int driver::parse(const std::string& f)
{
    file = f;
    location.initialize(&file);

    std::ifstream in{file};
    if (!in) {
        std::exit(EXIT_FAILURE);
    }

    lexer.set_debug(trace_scanning);
    lexer.switch_streams(&in);

    yy::parser parse(*this);
    parse.set_debug_level(trace_parsing);

    return parse();
}
