#include <config.hpp>
#include <optional>

#define TOML_EXCEPTIONS 0 
#include <external/toml.hpp>
#include <string>
#include <vector>
#include <log.hpp>

namespace SPM::config{
    Config readConfigFile(std::string file){
        Log::Logger log;
        Config conf = Config{{}};
        toml::parse_result result = toml::parse_file(file);
        if (!result){
            log << "Parsing failed: \n" << result.error() << Log::ERROR;
        }
        toml::table data = result.table();

        // Read project
        auto project_opt = data["project"].as_table();
        if (!project_opt) log << "Project variable is not found or isn't a table." << Log::ERROR;
        auto project = *project_opt;
        // Read project.name
        auto project_name = project["name"].value<std::string>();
        if (!project_name) log << "project.name is not defined or isn't a string" << Log::ERROR;
        conf.project.name = project_name.value();
        // Read project.version
        auto project_version = project["version"].value<std::string>();
        if (!project_version) log << "project.version is not defined or isn't a string" << Log::ERROR;
        conf.project.version = project_version.value();
        // Read project.dependencies
        auto project_dependencies = project["dependencies"].as_array();
        if (!project_dependencies) log << "project.dependencies is not defined or isn't an array" << Log::ERROR;
        for (const auto &node : *project_dependencies) {
            Dependency dep{};

            // Read dependency as table
            auto dependency = node.as_table();
            if (!dependency) log << "project.dependencies.x isn't a table" << Log::ERROR;

            //Read dependency name
            auto dep_name = dependency->at_path("name").value<std::string>();
            if (!dep_name) log << "project.dependencies.x.name is not defined or isn't a string" << Log::ERROR;
            dep.name = dep_name.value();
            // Read dependency version
            auto dep_version = dependency->at_path("version").value<std::string>();
            if (!dep_version) log << "project.dependencies.x.version is not defined or isn't a string" << Log::ERROR;
            dep.version = dep_version.value();
            //Read dependency src
            auto dep_src = dependency->at_path("src").value<std::string>();
            if (!dep_src) log << "project.dependencies.x.src is not defined or isn't a string" << Log::ERROR;
            dep.src = dep_src.value();
            conf.project.dependecies.push_back(dep);
        }
        return conf;
    };

    std::ostream& operator<<(std::ostream& os, const Config &conf){
        os << "Config{ " << conf.project.name << ", " << conf.project.version << ", ";
        os << "Dependencies{ ";
        for (const auto &dep : conf.project.dependecies) {
            os << "{ " << dep.name << ", " << dep.version << ", " << dep.src << " } ";
        }
        os << "} }";
        return os;
    }
}
