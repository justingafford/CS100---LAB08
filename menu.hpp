#ifndef __MENU_HPP__
#define __MENU_HPP__

#include "command.hpp"

class Menu {
	private:
        int history_index;
		std::vector<Command*> history;

    public:
		Menu() { 
        }

		std::string execute() {
		}

        std::string stringify() {
        }

		bool initialized() {
		}

		void add_command(Command* cmd) {
		}

		Command* get_command() {
		}

		void undo() {
		}

		void redo() {
		}
};

#endif
