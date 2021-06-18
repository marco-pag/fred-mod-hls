/*
 * Fred hardware accelerator stub.
 *
 * Copyright (C) 2021, Marco Pagani, ReTiS Lab.
 * <marco.pag(at)outlook.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
*/

#ifndef HW_MOD_H
#define HW_MOD_H

#include "hw_task.hpp"

// Export for test bench
static const args_ht MODULE_ID = 1;

const unsigned int BLOCK_SIZE_BYTE = (1024 * 1024);
const unsigned int BLOCK_SIZE_DHT = (BLOCK_SIZE_BYTE / sizeof(data_ht));

void hw_mod(id_ht *id, args_ht args[ARGS_SIZE], volatile data_ht *mem_in, volatile data_ht *mem_out);

#endif /* HW_MOD_H */
