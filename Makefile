
CXX_FLAGS := -O2 -DNDEBUG -Wall -g -march=core2 -std=c++11
CXX       := g++
INSTALL_DIR := ./
export CXX
export CXX_FLAGS

all: finalTimer timer

finalTimer: 
	qmake timerGUI/finalTimer.pro -o timerGUI/Makefile
	$(MAKE) -C timerGUI
	#mv timerGUI/finalTimer $(INSTALL_DIR)

timer:
	$(MAKE) -C dispatcher
	mv dispatcher/timer $(INSTALL_DIR)

clean: 
	rm timerGUI/*.o
	rm timerGUI/Makefile
	rm timerGUI/moc*
