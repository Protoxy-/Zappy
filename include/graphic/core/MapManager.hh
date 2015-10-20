#ifndef MAPMANAGER_HH_
# define MAPMANAGER_HH_

# include "System.hh"
# include "object/ObjIncludes.hh"
# include "core/AObjModule.hh"

class             MapManager : public AObjModule
{
  std::list<AObjEnv*>     *_env;
  std::list<AObjEffect*>  *_effect;
  std::list<AObjItem*>    *_item;
  std::list<AObjPlayer*>  *_player;

public:
  MapManager(const AObjModule &);
  ~MapManager();

  void  generateEnv();
  void  addEnv(AObjEnv *);
  void  addEffect(AObjEffect *);
  void  addItem(AObjItem *);
  void  addItem(int, int, int);
  void  delItem(int, int, int);
  void  addPlayer(AObjPlayer *);
  void  delPlayer(int);

  std::list<AObjEnv*>    *getEnv() const;
  std::list<AObjEffect*> *getEffect() const;
  std::list<AObjItem*>   *getItem() const;
  int                     getItemNb(int, int, int) const;
  int                     getItemNbAll(int) const;

  std::list<AObjPlayer*> *getPlayer() const;

  AObjPlayer             *getPlayer(int) const;
  std::vector<int> const &getPlayerIds(int, int) const;
  int                     getPlayerNbTeam(std::string const &) const;

  void  update();

  void  updateEnv();
  void  updateEffect();
  void  updateItem();
  void  updatePlayer();
};
#endif // !MAPMANAGER_HH_
