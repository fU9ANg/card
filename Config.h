
#ifndef _ECSERVER_CONFIG_H_
#define _ECSERVER_CONFIG_H_

#include "Define.h"
#include "lua5.2/lua.hppp"

using namespace std;

class Config
{
    public:
        ~Config ();
        static class Config* instance ();
        void readconfig (string file);

    public:
        string  db_host;
        string  db_username;
        string  db_password;
        string  db_database;
        string  server_ip;

        int     server_port;
        int     school_id;
        int     game_count;

    private:
        Config();
        static class Config* m_config;
};

#define CONFIG Config::instance()

#endif
