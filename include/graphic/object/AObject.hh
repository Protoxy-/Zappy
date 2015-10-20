#ifndef AOBJECT_HH_
#define AOBJECT_HH_

# include "System.hh"
# include "core/AObjModule.hh"

class         AObject : public AObjModule
{
protected:
  sf::Sprite   _sprt;
  sf::Color    _color;
  sf::Color    _colorBase;
  CordRect     _pos;
  CordRect     _iso;
  CordRect     _disp;
  float        _scl;
  CordRect     _rot;
  CordRect     _img;
  CordRect     _imgCtr;

  CordRect     _solid;
  int          _collType;

  bool         _actif;
  int          _type;
  int          _lastType;
  int          _depth;
  int          _layer;
  bool         _anim;
  int          _animPos;
  int          _animSpeed;
  int          _stp;

public:
  AObject(AObjModule const &, int);
  virtual ~AObject();

  virtual void update();
  virtual void render();

  void         updateBase();
  void         renderBase();

  void         initDefaultValue();

  void         convertToIsometric();
  void         convertToLayer();
  bool         convertToDisplay();



  sf::Sprite const &getSprite() const;
  CordRect  const &getPos() const;
  CordRect  const &getRot() const;
  float        getScale() const;
  CordRect  const &getSolid() const;
  int          getCollType() const;
  int          getType() const;
  int          getDepth() const;
  int          getLayer() const;
  bool         getAnim() const;
  int          getAnimPos() const;
  int          getAnimSpeed() const;

  void         setType(int) const;
  void         setPos(int, int);
  void         setPos(int, int, int);
  void         setRot(int, int, int);
  void         setScale(float);
  void         setSolid(CordRect const &);
  void         setAnim(bool);
  void         setAnimPos(int);
  void         setAnimSpeed(int);
};

#endif
