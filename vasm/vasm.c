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

/*! ===> Creates on 2021/9/14. <=== */

/*!
 * @author 范特西
 */
#include "vasm/vasm.h"

static void loadvasm()
{
        VASM_CVAP_DATABASE = (f_vasm_cvap_database) create_database;
        VASM_CVAP_TABLE = (f_vasm_cvap_table) create_table;
        VASM_CVAP_COLUMN = (f_vasm_cvap_column) create_column;
        VASM_ADD_COLUMN = (f_vasm_add_column) table_add_column;
        VASM_ADD_TABLE = (f_vasm_add_table) vacat_add_table;
        VASM_LVAP_DATABASE = (f_vasm_lvap_database) vacat_add_table;
        VASM_LVAP_TABLE = (f_vasm_lvap_table) vacat_get_table;
        VASM_LVAP_COLUMN = (f_vasm_lvap_column) table_get_column;
        VASM_LVAP_DATABASE = (f_vasm_lvap_database) load_database;
        VASM_FVAP_DATABASE = (f_vasm_fvap_database) destroy_database;
        VASM_MOD_DATABASE_NAME = (f_vasm_mod_database_name) modify_database_name;
}