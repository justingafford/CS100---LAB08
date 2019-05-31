#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <vector>
#include <string>
#include "command.hpp"
using namespace std;

class Menu {
    private:
        int history_index; // Indexes which command was last executed, accounting for undo and redo functions
        std::vector<Command*> history; // Holds all the commands that have been executed until now
    public:
        Menu() : history_index(-1) {
			
        };
        
        string execute() {
	          if (history_index == -1) {
		            return "0";
	          }
	          return to_string(history.at(history_index)->execute());
        };
	
        std::string stringify() {
		  if (history_index == -1) {
		            return "0";
	          }
		  else {
	          	return history.at(history_index)->stringify();
		  }
	};
	
        bool initialized() {
	          if (history_index == -1) {
		            return false;
	          }
	          return true;
        };

        void add_command(Command* cmd) {
	    if(history_index == -1) {
	        history.push_back(cmd);
		history_index = 0;
	    }
	    else if( history_index == history.size() - 1) {
		history.push_back(cmd);
		++history_index;
	    }
	    else {
		history.at(history_index + 1) = cmd;
		++history_index;
	    }
       	};

       Command* get_command() {
	    return history.at(history_index);
       };

       void undo() {
	         if (history_index > 0) {
		     --history_index;
		 }
	         
	};
	
      	void redo() {
	        if (history_index < history.size() - 1) {
		    history_index++;
	        }
	        
      	};
};
#endif
