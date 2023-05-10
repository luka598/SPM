#include <ostream>
#include <string>
#include <vector>

namespace SPM::config {
struct Dependency {
  std::string name;
  std::string src;
  std::string version;
};

struct Project {
  std::string name;
  std::string version;
  std::vector<Dependency> dependecies;
};

struct Config {
  Project project;
};

std::ostream &operator<<(std::ostream &os, const Config &conf);

Config readConfigFile(std::string file);
} // namespace SPM::config
