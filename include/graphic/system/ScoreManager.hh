#ifndef SCOREMANAGER_HH_
# define SCOREMANAGER_HH_

# include "System.hh"
# include "system/AFileVarsManager.hh"

class     ScoreManager : public AFileVarsManager
{
public:
  ScoreManager();
  ~ScoreManager();

  std::map<std::string, std::vector<int> *>   const &getList();
  void                                               addScore(std::string const &, int);
};

#endif // !SCOREMANAGER_HH_
