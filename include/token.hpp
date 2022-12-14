#ifndef LEXER_TOKEN_HPP
#define LEXER_TOKEN_HPP

#include <ios>
#include <optional>
#include <variant>

namespace lexer {
enum class Token : int {
    // End of file token
    T_ERROR = -2,
    T_EOF = -1,
    T_NULL = 0,
    T_OTHER = 1,

    // Keywords
    T_FUNC = 2,
    T_EXTERN = 3,
    T_RETURN = 4,
    T_COMMENT = 5,

    // Identifiers
    T_IDENTIFIER = 6,
    T_NUMBER = 7,

    // Symbols
    T_OBRACKET = 8,
    T_CBRACKET = 9,
    T_SEMICOLON = 10,
    T_COMMA = 11,
    T_EQUAL = 12,
    T_NAME = 13,
    T_AGE = 14
};

struct TokenData {
    TokenData() : m_token(Token::T_NULL), m_file_ptr_pos(0), m_data({}) {}

    // Token
    Token m_token;
    // File pointer position after identifier
    std::streampos m_file_ptr_pos;
    // Identifier data, number or string
    std::optional<std::variant<double, std::string>> m_data;
    // Overload for formating log
    template <typename outStream>
    friend outStream& operator<<(outStream& t_stream, const TokenData& t_data) {
        return t_stream << "begin position: [" << t_data.m_file_ptr_pos << "]";
    }
};
} // namespace lexer

#endif
