CXX_FLAGS := -O2 -DNDEBUG -Wall -g -march=core2 -std=c++11
CXX       := g++
INSTALL_DIR := ./
export CXX
export CXX_FLAGS

.PHONY: finalTimer
finalTimer: 
	qmake timerGUI/finalTimer.pro -o timerGUI/Makefile
	$(MAKE) -C timerGUI
	rm ./timerGUI/moc*
	rm ./timerGUI/*.o
	rm ./timerGUI/Makefile
	mv timerGUI/finalTimer $(INSTALL_DIR)
