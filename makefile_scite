MyProg.exe		: 	MyProg.o nodes.o transform.o sprites.o fuzzylogic.o algorithm.o graphics.o 
	g++ -Wl,-s -o MyProg.exe MyProg.o nodes.o transform.o sprites.o fuzzylogic.o algorithm.o graphics.o 
			
MyProg.o		:	MyProg.cpp graphics.h nodes.h transform.h sprites.h fuzzylogic.h algorithm.h
	g++ -c -fpermissive -fconserve-space MyProg.cpp
	
transform.o		:	 transform.cpp transform.h
	g++ -c -fpermissive -fconserve-space transform.cpp	

nodes.o		:	 nodes.cpp nodes.h
	g++ -c -fpermissive -fconserve-space nodes.cpp
	
sprites.o		:	 sprites.cpp sprites.h
	g++ -c -fpermissive -fconserve-space sprites.cpp	
	
fuzzylogic.o	:	 fuzzylogic.cpp fuzzylogic.h
	g++ -c -fpermissive -fconserve-space fuzzylogic.cpp		
	
algorithm.o		:	 algorithm.cpp algorithm.h
	g++ -c -fpermissive -fconserve-space algorithm.cpp		

graphics.o		:	 graphics.cpp graphics.h
	g++ -c -fpermissive -fconserve-space graphics.cpp
