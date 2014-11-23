#ifndef TYPES_H
#define TYPES_H
#include <QPoint>

namespace SceneType
{
    enum Type { INIT, CHOICECHARACTER, INGAME, ENDGAME, LOGO };
}

namespace CharacterType
{
  enum Type { LIAR, RICH, ALCHOHOLIC };
}

namespace Team
{
  enum Type { POSTECH, KAIST };
}

namespace ItemType
{
  enum Type {BOMB_NUM, BOMB_POWER, SPEED, LIFE};
}


extern QPoint cell_xy[130];
#endif // TYPES_H
