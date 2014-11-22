#ifndef TYPES_H
#define TYPES_H

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
  enum Stat_Type {BOMB_NUM, BOMB_POWER, SPEED, LIFE};
}

#endif // TYPES_H
