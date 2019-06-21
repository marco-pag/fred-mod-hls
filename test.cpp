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

#include <iostream>
#include "slots.hpp"
#include "fred_hwacc.hpp"

// DDR memory (512 MB)
data_t mem[(512 * 1024 * 1024) / sizeof(data_t)];

void init_vect(unsigned int base_idx, int value)
{
	for (unsigned int i = 0; i < BLOCK_SIZE_DT; ++i) {
		mem[base_idx + i] = value + i;
	}
}

void print_vect(unsigned int base_idx, unsigned int size)
{
	for (int i = 0; i < size; ++i) {
		std::cout << mem[base_idx + i] << "\t";
	}
	std::cout << std::endl;
}

int main()
{
	unsigned int a_idx;
	unsigned int b_idx;
	unsigned int c_idx;

	unsigned int offset;

	args_t id_out;
	args_t args[ARGS_SIZE];

	offset = BLOCK_SIZE_DT + 100;

	a_idx = 0;
	b_idx = a_idx + offset;
	c_idx = b_idx + offset;

	init_vect(a_idx, 0);
	init_vect(b_idx, 0);

	// Set hw accelerator args
	// The base address is the memory array start address
	args[2] = (args_t)( ((uint64_t)&mem[a_idx]) - ((uint64_t)&mem[0]) );
	args[1] = (args_t)( ((uint64_t)&mem[b_idx]) - ((uint64_t)&mem[0]) );
	args[0] = (args_t)( ((uint64_t)&mem[c_idx]) - ((uint64_t)&mem[0]) );

	slot_0(&id_out, args, mem, mem);;

	print_vect(c_idx, 10);

	return 0;
}

