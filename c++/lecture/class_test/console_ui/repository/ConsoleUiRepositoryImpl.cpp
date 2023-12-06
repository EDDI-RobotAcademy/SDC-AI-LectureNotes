//
// Created by eddi on 23. 12. 6.
//

#include <sstream>
#include "ConsoleUiRepositoryImpl.h"
#include "../../mysql/DbProcess.h"

ConsoleUiRepositoryImpl& ConsoleUiRepositoryImpl::getInstance()
{
    static ConsoleUiRepositoryImpl instance;
    return instance;
}

// 원래는 Redis 등에서 Session 뽑아와야 하지만 그냥 MySQL에 박아놓습니다.
int ConsoleUiRepositoryImpl::getSignInSession() {
    DbProcess* dbInstance = DbProcess::getInstance();

    std::string queryString = "SELECT * FROM session LIMIT 1";

    MYSQL_ROW row = dbInstance->findRowData(queryString);

    if (row != nullptr) {
        int session_id = std::stoi(row[1]);
        return session_id;
    }

    return -1;
}

void ConsoleUiRepositoryImpl::storeSignInSession(int uniqueSessionId) {
    DbProcess* dbInstance = DbProcess::getInstance();

    std::ostringstream oss;
    oss << uniqueSessionId;
    std::string uniqueSessionIdStr = oss.str();

    std::string queryString = "INSERT INTO session (session_id) VALUES ('" + uniqueSessionIdStr + "')";

    dbInstance->insertData(queryString);
}
