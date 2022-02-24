CFLAGS = -I "C:\wxAPI\include" -I "C:\wxAPI\lib\gcc1020_x64_dll\mswu" -L "C:\wxAPI\lib\gcc1020_x64_dll" -l wxbase31u -l wxmsw31u_core
a.exe:
	g++ *.cpp -o gui $(CFLAGS)
clean:
	-del gui
	-rm gui