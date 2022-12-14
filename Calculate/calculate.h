#include "artifact.h"
#include "character.h"
#include "enemy.h"
#include "environment.h"
#include "origin.h"
#include "weapon.h"
// #include "logger.h"
#ifndef CALCULATE_H
#define CALCULATE_H

namespace genShinImpact
{
  class calculate : public character, enemy, environment, weapon, artifact//, logger
  {
  public:
    calculate();
    ~calculate();
    tAllAttr mAttacker;
    tAllAttr mSuffer;
    tAllAttr mWeapon;
    tAllAttr mArtifact;
    tAllAttr mEnvironment;

    void resetAll();
    void loadAll();

    float calDamage(float rate, eReactType reactType, TextType mainAttr, eCalType calType, eDamageType damageType, eElementType elementType);

    float attrChange(TextType aim, float maxAim, float rate, float minSrc, TextType src, float maxSrc);

  protected:
    float calHp();
    float calAtk();
    float calDef();
    float calCritRate();
    float calCritDmg();
    float calElementalMastery();

    float calDefFactor();
    float calLevelFactor();
    float calMainFactor(TextType mainAttr);
    float calCritFactor(eCalType calType);
    float calReactFactor(eReactType reactType, float elementalMastery);
    float calResFactor(eDamageType damageType, eElementType elementType);
    float calBonus(eDamageType damageType, eElementType elementType);
    float calIndepMult(eDamageType damageType, eElementType elementType);
    float calExtraRate(eDamageType damageType, eElementType elementType);

    void loadAttacker();
    void loadSuffer();
    void loadWeapon();
    void loadArtifact();
    void loadEnvironment();

  private:
  };
} // namespace genShinImpact

#endif
