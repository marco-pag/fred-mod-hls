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

#include "fred_hwacc.hpp"

void fred_hwacc(args_t *id, args_t args[ARGS_SIZE], volatile data_t *mem_in, volatile data_t *mem_out)
{
	#pragma HLS DATAFLOW
	
	data_t temp;

	*id = MODULE_ID;

	args_t arg_out = args[0];
	args_t arg_in = args[1];

	for (int i = 0; i < BLOCK_SIZE_DT; ++i) {
		#pragma HLS PIPELINE
		temp = *(mem_in + i + (arg_in / sizeof(data_t)));
		*(mem_out + i + (arg_out / sizeof(data_t))) = temp;
	}
}

void fred_hwacc_2(args_t *id, args_t args[ARGS_SIZE], volatile data_t *mem_in, volatile data_t *mem_out)
{
	#pragma HLS DATAFLOW
	
	data_t a;
	data_t b;

	*id = MODULE_ID;

	args_t arg_out = args[0];
	args_t arg_in_1 = args[1];
	args_t arg_in_2 = args[2];

	for (int i = 0; i < BLOCK_SIZE_DT; ++i) {
		#pragma HLS PIPELINE
		a = *(mem_in + i + (arg_in_1 / sizeof(data_t)));
		b = *(mem_in + i + (arg_in_2 / sizeof(data_t)));
		*(mem_out + i + (arg_out / sizeof(data_t))) = a + b;
	}
}
