#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "command.hpp"
using namespace std;

class Menu {
    private:
        int history_index; // Indexes which command was last executed, accounting for undo and redo functions
        std::vector<Command*> history; // Holds all the commands that have been executed until now
    public:
        Menu() : history_index(0) {
			
        };
        
        void Menu::execute() {
	          if (history.at(history_index) == NULL) {
		            cout << 0 << endl;;
		            return;
	          }
	          cout << history.at(history_index)->execute() << endl;
        }
        std::string stringify() {
		  if (history.at(history_index) == NULL) {
		            cout << 0 << endl;;
		            return;
	          }
	          cout << history.at(history_index)->stringify() << endl;
	}
        bool Menu::initialized() {
	          if (history_index == 0) {
		            return false;
	          }
	          return true;
        }

        void Menu::add_command(Command* cmd) {
	          vector<Command*>::iterator it = history.begin();
	          int counter = history_index + 1;

	          if (history.empty()) {
		            history.push_back(NULL);
		            history.push_back(cmd);
		            ++history_index;
	          }
	          else {
		             if (history_index == history.size() - 1) {
			               history.push_back(cmd);
			               ++history_index;
		             }
		             else {
			               while (counter != 0) {
				                  ++it;
				                  --counter;
			               }
			               history.at(history_index + 1) = cmd;
			               ++history_index;
		             }
	          }
       }

       Command* Menu::get_command() {
	         return history.at(history_index);
       }

       void Menu::undo() {
	         if (history_index == 0) {
		           return;
		 }
	         --history_index;
	}

      void Menu::redo() {
	        if (history_index == history.size() - 1) {
		          return;
	        }
	        history_index++;
      }
};
#endif
