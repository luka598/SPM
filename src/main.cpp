#include <config.hpp>
#include <iostream>

int main() {
  SPM::config::Config conf = SPM::config::readConfigFile("SPM.toml");
  std::cout << conf << std::endl;
  return 0;
}
