#include <iostream>
#include <string>
#include <getopt.h>
#include "Traceroute.h"

#define no_argument            0
#define required_argument      1

void print_help(const char *program_name) {
    std::cout << "Usage: " << program_name << " <hostname> [options]\n"
              << "Options:\n"
              << "  -h, --help           Show this help message and exit\n"
              << "  -m, --max-hops N     Set the max number of hops (default: 30)\n"
              << "  -t, --timeout N      Set the timeout in seconds (default: 1)\n"
              << "  -f, --start-ttl N    Set the initial TTL value (default: 1)\n"
              << "  -p, --port N         Set the destination port (default: 33434)" << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_help(argv[0]);
        return 1;
    }

    int max_hops = 30;
    int timeout = 1;
    int start_ttl = 1;
    int port = 33434;

    int option_index = 0;
    int c;

    const char *short_options = "hm:t:f:p:";

    const option long_options[] = {
            {"help",      no_argument,       nullptr, 'h'},
            {"max-hops",  required_argument, nullptr, 'm'},
            {"timeout",   required_argument, nullptr, 't'},
            {"start-ttl", required_argument, nullptr, 'f'},
            {"port",      required_argument, nullptr, 'p'},
            {nullptr, 0,                     nullptr, 0}
    };

    while ((c = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1) {
        switch (c) {
            case 'h':
                print_help(argv[0]);
                return 0;
            case 'm':
                max_hops = std::stoi(optarg);
                break;
            case 't':
                timeout = std::stoi(optarg);
                break;
            case 'f':
                start_ttl = std::stoi(optarg);
                break;
            case 'p':
                port = std::stoi(optarg);
                break;
            default:
                print_help(argv[0]);
                return 1;
        }
    }

    if (optind >= argc) {
        std::cerr << "Error: hostname or ip is required\n";
        print_help(argv[0]);
        return 1;
    }

    std::string destination_address = argv[optind];

    Traceroute traceroute;
    traceroute.run(destination_address, max_hops, timeout, start_ttl, port);

    return 0;
}