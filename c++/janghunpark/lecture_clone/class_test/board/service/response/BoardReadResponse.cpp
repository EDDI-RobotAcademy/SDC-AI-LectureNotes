//
// Created by eddi on 23. 12. 7.
//

#include "BoardReadResponse.h"
#include "../../controller/response_form/BoardReadResponseForm.h"

BoardReadResponse::BoardReadResponse (
        const std::string& title, const std::string& writer, const std::string& content)
                                        : title(title), writer(writer), content(content) { }

BoardReadResponseForm *BoardReadResponse::toBoardReadResponseForm()
{
    return new BoardReadResponseForm(title, writer, content);
}
