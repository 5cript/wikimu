#include "comments.hpp"

#include "twisted-spirit/core/parse.hpp"
#include "parsers/comments.hpp"

#include "../conversion.hpp"

namespace WikiMarkup { namespace Components {
//####################################################################################
    std::string CommentText::toMarkup()
    {
        return std::string("<!--") + data + "-->";
    }
//-----------------------------------------------------------------------------------
    ParsingResult CommentText::fromMarkup(std::string const& mu)
    {
        using namespace WikiMarkup::Components::Parser;
        using namespace TwistedSpirit;

        TYPEDEF_GRAMMAR(comment_grammar);

        auto res = parse <grammar> (mu);
        *this = res.second;
        return res.first;
    }
//-----------------------------------------------------------------------------------
    std::string CommentText::toJson()
    {
        return toJson(*this, getMetaInfo().name);
    }
//-----------------------------------------------------------------------------------
    void CommentText::fromJson(std::string const& str)
    {
        fromJson(*this, str);
    }
//-----------------------------------------------------------------------------------
    MetaInfo CommentText::getMetaInfo() const
    {
        return {
            "CommentText",
            false
        };
    }
//-----------------------------------------------------------------------------------
    CommentText* CommentText::clone() const
    {
        return new CommentText(*this);
    }
//####################################################################################
} // namespace Components
} // namespace WikiMarkup
