
#ifndef _ECSERVER_DATABASE_H_
#define _ECSERVER_DATABASE_H_

#include "Define.h"

#include "mysql/mysql_connection.h"
#include "mysql/mysql_driver.h"
#include "mysql/cppconn/resultset.h"
#include "mysql/cppconn/driver.h"
#include "mysql/cppconn/exception.h"
#include "mysql/cppconn/resultset.h"
#include "mysql/cppconn/statement.h"
#include "mysql/cppconn/prepared_statement.h"

#include "glog/logging.h"

#include "Config.h"
#include "MutexLock.h"

using namespace sql;
using namespace std;

class DataBase
{
    public:
        ~DataBase ();

        bool Init (string host, string username, string password, string database);
        Connection* getConnection ();
        Statement*  getStatement ();
        PreparedStatement* preStatement (string sql);

        static DataBase* instance ();
        MutexLock m_mutex;

    private:
        DataBase ();
        Driver* m_pDriver;
        Connection* m_pConn;
        string m_host;
        string m_user_name;
        string m_password;
        string m_database;
        static DataBase *pinstance;
};

#define DATABASE DataBase::instance()

#endif
