#include <config.hpp>

#define TOML_EXCEPTIONS 0 
#include <external/toml.hpp>
#include <string>
#include <vector>
#include <log.hpp>

namespace SPM::config{
    Config readConfigFile(std::string file){
        Log::Logger log;
        Config conf = Config{{}, {}};
        toml::parse_result result = toml::parse_file(file);
        if (!result){
            log << "Parsing failed: \n" << result.error() << Log::ERROR;
        }
        return conf;
    };
}
