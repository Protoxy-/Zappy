#ifndef CONFIGMANAGER_HH_
# define CONFIGMANAGER_HH_

# include "System.hh"
# include "system/AFileVarsManager.hh"

class ConfigManager : public AFileVarsManager
{

public:
  ConfigManager();
  ~ConfigManager();
};

#endif // !CONFIGMANAGER_H_
