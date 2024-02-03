senet: senet.cpp
	g++ senet.cpp ncurses_tools.cpp -o bin/senetme -Wall -Werror -g -lncurses

dicesticks: dicesticks.cpp
	g++ dicesticks.cpp -o bin/stickme -Wall -Werror -g
