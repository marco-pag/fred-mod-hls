
# HW-task
set num_slots 4
set name "hw_task_memcpy"

open_project $name
# HW-task files
add_files srcs/hw_task.cpp
add_files srcs/hw_mod.cpp

set i 0
while {$i < $num_slots} {
  set_top hw_task_$i
  open_solution "solution_$i"
  set_part {xczu9eg-ffvb1156-2-i} -tool vivado
  # 64-bit AXI-M address capability
  config_interface -m_axi_addr64
  create_clock -period 10 -name default
  csynth_design
  export_design -format ip_catalog -description "${name}_${i}" -display_name "${name}_${i}"
  incr i
}

close_project
exit

