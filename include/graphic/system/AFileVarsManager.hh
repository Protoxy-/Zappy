#ifndef AFILEVARSMANAGER_HH_
# define AFILEVARSMANAGER_HH_

# include "System.hh"

class   AFileVarsManager
{
protected:
  std::map<std::string, std::vector<int> *>  _vars;
  std::string                                _path;
  std::string                                _defPath;
  int                                        _change;
public:
  AFileVarsManager();
  ~AFileVarsManager();

  void	load(std::string const &);
  void	load();
  void	save();
  void  reset();

  void  setChange(int change);
  int   getChange() const;

  int   checkPos(std::string const &);

  void  set(std::string const &name, int pos, int);
  void  set(std::string const &name, int);

  void  set(std::string const &, CordRect const &);


  int   get(std::string const &name, int pos) const;
  int   get(std::string const &name);
};

#endif // !AFILEVARSMANAGER_HH_
