# fred-mod-hls
HLS stub for Fred-Linux HW-tasks.

- Configure args and data size according to the platform and the design.

```C
#define DATA_WIDTH 128
#define ARGS_WIDTH 64
```

- Run the synthesis. 

```C
vivado_hls -f build.tcl
```

