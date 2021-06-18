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

#include <iostream>
#include "hw_task.hpp"
#include "hw_mod.hpp"

// Memory array (128 MB)
data_ht mem[(128 * 1024 * 1024) / sizeof(data_ht)];

int main()
{
	id_ht id_out;
	args_ht args[ARGS_SIZE];

	data_ht *block_out = &mem[0];
	data_ht *block_in = &mem[BLOCK_SIZE_DHT];

	// Initialize input block
	for (int i = 0; i < BLOCK_SIZE_DHT; ++i) {
		block_in[i] = i + 100;
	}

	// Set args pointing to the input and output images using
	// the memory array start address as the base address
	args[0] = 0 * sizeof (data_ht);
	args[1] = BLOCK_SIZE_DHT * sizeof (data_ht);

	hw_task_0(&id_out, args, mem, mem);

	// Check output
	for (int i = 0; i < BLOCK_SIZE_DHT; ++i) {
		if (block_out[i] != block_in[i]) {
			std::cout << "Block mismatch at index: " << i << std::endl;
			return -1;
		}
	}

	std::cout << "Block match, all done"<< std::endl;

	return 0;
}

