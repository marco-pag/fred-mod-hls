/*
 * Fred hardware accelerator stub.
 *
 * Copyright (C) 2019, Marco Pagani, ReTiS Lab.
 * <marco.pag(at)outlook.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
*/

#ifndef FRED_HWACC_H
#define FRED_HWACC_H

#include "slots.hpp"

// Export for test bench
static const args_t MODULE_ID = 128;

const unsigned int BLOCK_SIZE_BYTE = (1024 * 1024);
const unsigned int BLOCK_SIZE_DT = (BLOCK_SIZE_BYTE / sizeof(data_t));

void fred_hwacc(args_t *id, args_t args[ARGS_SIZE], volatile data_t *mem_in, volatile data_t *mem_out);

void fred_hwacc_2(args_t *id, args_t args[ARGS_SIZE], volatile data_t *mem_in, volatile data_t *mem_out);

#endif /* FRED_HWACC_H */
