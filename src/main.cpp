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

    CommandList* command_list = new CommandList(keylist, config);
    
    CommandParser* command_parser = new CommandParser(command_list);

    while (true) {
        std::string input;
        std::cout << config->symbol << " ";
        std::cin >> input;
        clear();
        print_header();
        command_parser->parse_command(input);
    }
    
    return 0;
}
