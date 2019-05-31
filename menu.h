#include "command.hpp"

class Menu 
{
    private:
        int history_index; 
        std::vector<Command*> history; 
    public:
        Menu() 
        {
            history_index = -1;
        }
        std::string execute() 
        {
            if(history.size() == 0)
                return;
                
            return to_string(root->evaluate());
        }
        std::string stringify() 
        {
            return to_string(root->stringify());
        }
    
        bool initialized() 
        {
            if(history.size() != 0)
                return true;
            
            return false;
        }
    
        void add_command(Command* cmd) 
        {
            history.push_back(cmd);
        }
        Command* get_command() 
        {
            return history.at(history_index);
        }
    
        void undo() 
        {
            if(history_index != 0)
            {
                return history.at(history_index-1);
            }
        }
    
        void redo() 
        {
            if(history.size()>history_index)
            {
                return history.at(history_index+1);
            }
        }
};
