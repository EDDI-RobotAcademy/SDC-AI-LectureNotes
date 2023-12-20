//
// Created by eddi on 23. 11. 30.
//

#include "BoardRegisterResponse.h"

BoardRegisterResponse::BoardRegisterResponse (
        const std::string& title, const std::string& writer, const std::string& content)
                                : title(title), writer(writer), content(content) { }

BoardRegisterResponseForm *BoardRegisterResponse::toBoardRegisterResponseForm()
{
    return new BoardRegisterResponseForm(title, writer, content);
}
