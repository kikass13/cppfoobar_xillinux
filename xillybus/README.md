demo apps from xillibus xilinx (appcompiler.tar.gz: http://xillybus.com/downloads/appcompiler.tar.gz)

documentation and description: http://xillybus.com/downloads/doc/xillybus_getting_started_linux.pdf


 # stream

 > g++ streamread.c -o streamread; g++ streamwrite.c -o streamwrite

 > ./streamread /dev/xillybus_read_8
 
 > ./streamwrite /dev/xillybus_write_8


 # memory

 > g++ memread.c -o memread; g++ memwrite.c -o memwrite

 > ./memwrite /dev/xillybus_mem_8 3 170

 > ./memread /dev/xillybus_mem_8 3
