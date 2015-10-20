# include "system/FileSerializer.hh"

std::map<std::string, std::vector<int> *> const &loadVarsFile(std::string const &path)
{
  std::map<std::string, std::vector<int> *>  *_vars = new std::map<std::string, std::vector<int> *>;

  std::ifstream	fd(path.c_str());
  std::string	  line;
  std::string   name;
  std::string   val;
  std::vector<int>  *param;
  int           i;

  if (fd.is_open())
  {
    while (getline(fd, line))
    {
      param = new std::vector<int>;
      i = line.find(":");
      name = line.substr(0, i++);
      while (line[i])
      {
        if (line[i] != ',' && line[i] != ';')
          val += line[i];
          else
          {
            param->push_back(atoi(val.c_str()));
            val = "";
          }
          i++;
        }
        _vars->insert(std::make_pair(name, param));
      }

  }
  else
  {
    throw errFile("Can't open:" + path);
  }
  fd.close();
  return (*_vars);
}



void saveVarsFile(std::string const &path, std::map<std::string, std::vector<int> *> const &_vars)
{
  std::stringstream                                          line;
  std::map<std::string, std::vector<int> *>::const_iterator        it;
  unsigned int                                               i;
  std::ofstream	fd(path.c_str(), std::ofstream::trunc);


  for (it = _vars.begin(); it != _vars.end(); it++)
  {
    line.str("");
    line << it->first << ':';
    for (i = 0; i < it->second->size(); i++)
    {
      line << (*it->second)[i];
      if (i != it->second->size() - 1)
        line << ',';
      }
      fd << line.str() << ";\n";
    }
    fd.close();
}
