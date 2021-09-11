/*! ************************************************************************
 *
 * Copyright (C) 2020 luots All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 *! ************************************************************************/

/*! ===> Creates on 2021/9/4. <=== */

/*!
 * @author 范特西
 */
#include <vasm/vasm.h>
#include "kernel/database.h"

void init_config();
void build_table(struct database *base);

int main(void)
{

        vacat_exec_comp("../.vacat");
//        init_config();
//
//        struct database base;
//        if (!create_database(&base, "mydb"))
//                return 1;
//
//        build_table(&base);
//
//        struct database lbase;
//        load_database(&lbase, kconf_data_dir(), "mydb");
//
//        destroy_database(&base);
//        destroy_database(&lbase);
//        kconf_destroy();
        return 0;
}

void init_config()
{
        kconf_init("/home/shitbro/vacatsql");
}

void build_table(struct database *base)
{
        struct table table0;
        struct table table1;
        table_init(&table0, "user", "fuck you.");
        table_init(&table1, "mytable", "去你妈的");

        struct column username;
        struct column password;
        struct column admin;
        struct column user;
        struct column member;

        column_init(&username, "username", _VARCHAR, 255);
        column_init(&password, "password", _VARCHAR, 255);
        column_init(&admin, "admin", _VARCHAR, 255);
        column_init(&user, "user", _VARCHAR, 255);
        column_init(&member, "member", _VARCHAR, 255);

        strncpy(username.vdef, "root", _VDEF_MAX);
        strncpy(username.remark, "用户名", _REMARK_MAX);
        strncpy(password.remark, "密码", _REMARK_MAX);

        table_add_column(&table0, &password);
        table_add_column(&table0, &username);
        table_add_column(&table0, &admin);
        table_add_column(&table0, &user);
        table_add_column(&table0, &member);

        table_add_column(&table1, &user);
        table_add_column(&table1, &member);

        vacat_add_table(base, &table0);
        vacat_add_table(base, &table1);
}