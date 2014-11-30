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

namespace Direction
{
    enum Type {UP, DOWN, RIGHT, LEFT, STAY};
}
extern QPoint cell_xy[(13*3 - 2)*(10*3)];
#endif // TYPES_H
