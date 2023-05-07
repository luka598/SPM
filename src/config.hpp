#include <string>
#include <vector>

namespace SPM::config{
    struct Dependency {
        std::string name;
        std::string src;
        std::string version;
    };

    struct Package {
        std::string name;
        std::string version;
        // std::vector<Dependency> dependecies;
    };

    struct Config {
        Package package;
        std::vector<Dependency> Dependencies;
    };
    
    Config readConfig();
}
