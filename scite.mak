MyProg.exe		: 	MyProg.o nodes.o transform.o sprites.o algorithm.o graphics.o 
	gcc -Wl,-s -o MyProg.exe MyProg.o nodes.o transform.o sprites.o algorithm.o graphics.o 
			
MyProg.o		:	MyProg.cpp graphics.h nodes.h transform.h sprites.h algorithm.h
	gcc -c -fpermissive -fconserve-space MyProg.cpp
	
transform.o		:	 transform.cpp transform.h
	gcc -c -fpermissive -fconserve-space transform.cpp	

nodes.o		:	 nodes.cpp nodes.h
	gcc -c -fpermissive -fconserve-space nodes.cpp
	
sprites.o		:	 sprites.cpp sprites.h
	gcc -c -fpermissive -fconserve-space sprites.cpp	
	
algorithm.o		:	 algorithm.cpp algorithm.h
	gcc -c -fpermissive -fconserve-space algorithm.cpp		

graphics.o		:	 graphics.cpp graphics.h
	gcc -c -fpermissive -fconserve-space graphics.cpp
