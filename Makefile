CFLAGS = -I "C:\wxAPI\include" -I "C:\wxAPI\lib\gcc1020_x64_dll\mswu" -L "C:\wxAPI\lib\gcc1020_x64_dll" -l wxbase31u -l wxmsw31u_core
a.exe:
	g++ *.cpp -o wxWigitApp $(CFLAGS)
clean:
	-del wxWigitApp
	-rm wxWigitApp