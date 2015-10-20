#ifndef SYSTEM_HH_
#define SYSTEM_HH_

# include <SFML/Audio.hpp>
# include <SFML/Graphics.hpp>
# include <SFML/System.hpp>
# include <SFML/Window.hpp>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>

#include <sys/time.h>
#include <time.h>
#include <unistd.h>

#include "system/FileSerializer.hh"
#include "system/Exception.hh"
#include "system/CordRect.hh"

#define TILE          96
#define ZOOMRATIO     5

#define LAYER_REFRESH 10
#define FPS           30

#endif
