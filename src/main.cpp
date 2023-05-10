#include <iostream>
#include <config.hpp>

int main(int argc, char** argv)
{
 //    if (argc < 2){
	// 	std::cout << "Invalid arguments" << std::endl;
	// 	return 1;
	// }
	// toml::table tbl;
 //    try
 //    {
 //        tbl = toml::parse_file(argv[1]);
 //        if (auto a = tbl["a"].value<int>()){
 //            std::cout << "a: " << a.value() << "\n"; 
 //        } else {
 //            std::cout << "No a" << std::endl;
 //        }
 //    }
 //    catch (const toml::parse_error& err)
 //    {
 //        std::cerr << "Parsing failed:\n" << err << "\n";
 //        return 1;
 //    }
	//
  SPM::config::Config conf =  SPM::config::readConfigFile("SPM.toml");
  std::cout << conf << std::endl;
   return 0;
}
