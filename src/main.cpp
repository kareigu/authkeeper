#include <iostream>
#include <string>
#include "logger.hpp"
#include "command_list.hpp"
#include "keylist.hpp"
#include "utils.hpp"
#include "command_parser.hpp"
#include "config.hpp"

int main() {
    clear();
    print_header();

    Config* config = new Config();
    logger::print(config->editor);

    Keylist* keylist = new Keylist();

    CommandList* command_list = new CommandList(keylist);
    
    CommandParser* command_parser = new CommandParser(command_list);
    command_parser->parse_command("exit");

    return 0;
}


