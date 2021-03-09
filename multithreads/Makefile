BLACK = "\\033[30;1m"
RED  =  "\\033[31;1m"
GREEN = "\\033[32;1m"
YELLOW = "\\033[33;1m"
BLUE  = "\\033[34;1m"
PURPLE = "\\033[35;1m"
CYAN  = "\\033[36;1m"
WHITE = "\\033[37;1m"

TAIL = "\\033[0m"

LOCAL_BIN_DIR = /usr/local/bin
LOCAL_LIB_DIR = /usr/local/lib

main : main.cpp
	@g++ -o main main.cpp -lpthread -lboost_thread-mt -lboost_system
	@echo $(GREEN)Building target $@$(TAIL)

install : main
	@cp main /usr/local/bin
	@echo $(YELLOW)Installing main to /usr/local/bin$(TAIL)


.PHONY: clean uninstall
clean:
	@-rm main
	@echo $(RED)Cleaning...$(TAIL)

uninstall:
	@-rm /usr/local/bin/main
	@echo $(RED)Uninstalling main from /usr/local/bin$(TAIL)