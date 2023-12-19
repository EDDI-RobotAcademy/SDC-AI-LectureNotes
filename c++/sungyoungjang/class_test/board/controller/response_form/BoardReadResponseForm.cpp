//
// Created by eddi on 23. 12. 7.
//

#include "BoardReadResponseForm.h"

BoardReadResponseForm::BoardReadResponseForm (
        const std::string& title, const std::string& writer, const std::string& content)
                                        : title(title), writer(writer), content(content) { }

std::string BoardReadResponseForm::getTitle() {
    return title;
}

std::string BoardReadResponseForm::getWriter() {
    return writer;
}

std::string BoardReadResponseForm::getContent() {
    return content;
}
