#ifndef FILESERIALIZER_HH_
# define FILESERIALIZER_HH_

# include <map>
# include <vector>
# include <string>
# include <iostream>
# include <fstream>
# include <sstream>
# include <stdlib.h>

# include "system/Exception.hh"

std::map<std::string, std::vector<int> *> const &loadVarsFile(std::string const &);
void  saveVarsFile(std::string const &, std::map<std::string, std::vector<int> *> const &);

#endif // !FILESERIALIZER_HH_
