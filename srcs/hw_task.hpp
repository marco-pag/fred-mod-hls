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

#ifndef SLOTS_HPP
#define SLOTS_HPP

#include <stdint.h>
#include "ap_int.h"

#define ARGS_SIZE 8
#define ID_WIDTH 32

// User customizable
#define DATA_WIDTH 128
#define ARGS_WIDTH 64

typedef ap_uint<ID_WIDTH> id_ht;
typedef ap_uint<ARGS_WIDTH> args_ht;
typedef ap_uint<DATA_WIDTH> data_ht;

void hw_task_0(id_ht *id, args_ht args[ARGS_SIZE], volatile data_ht *mem_in, volatile data_ht *mem_out);

void hw_task_1(id_ht *id, args_ht args[ARGS_SIZE], volatile data_ht *mem_in, volatile data_ht *mem_out);

void hw_task_2(id_ht *id, args_ht args[ARGS_SIZE], volatile data_ht *mem_in, volatile data_ht *mem_out);

void hw_task_3(id_ht *id, args_ht args[ARGS_SIZE], volatile data_ht *mem_in, volatile data_ht *mem_out);

#endif /* SLOTS_HPP */
