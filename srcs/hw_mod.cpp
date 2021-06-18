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

#include "hw_mod.hpp"

void hw_mod(id_ht *id, args_ht args[ARGS_SIZE], volatile data_ht *mem_in, volatile data_ht *mem_out)
{
	data_ht temp;

	*id = MODULE_ID;

	data_ht *data_out = (data_ht *)&mem_out[args[0] / sizeof (data_ht)];
	data_ht *data_in = (data_ht *)&mem_in[args[1] / sizeof (data_ht)];

	for (int i = 0; i < BLOCK_SIZE_DHT; ++i) {
		temp = data_in[i];
		data_out[i] = temp;
	}
}
