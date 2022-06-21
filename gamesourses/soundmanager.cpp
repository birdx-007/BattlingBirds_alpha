#include "gameheaders/soundmanager.h"

SoundManager::SoundManager(QObject *parent)
{
    Q_UNUSED(parent);
}

void SoundManager::Init()
{
    this->ShootEffect.setSource(QUrl("qrc:/sfx/res/shoot.wav"));
    this->ShootEffect.setLoopCount(0);
    this->ShootEffect.setVolume(effectvolume);
    this->SpellEffect.setSource(QUrl("qrc:/sfx/res/spell.wav"));
    this->SpellEffect.setLoopCount(0);
    this->SpellEffect.setVolume(effectvolume);
    this->HitEffect.setSource(QUrl("qrc:/sfx/res/hit.wav"));
    this->HitEffect.setLoopCount(0);
    this->HitEffect.setVolume(effectvolume);
    this->HitEffect_lowhp.setSource(QUrl("qrc:/sfx/res/hit1.wav"));
    this->HitEffect_lowhp.setLoopCount(0);
    this->HitEffect_lowhp.setVolume(effectvolume);
    this->Pig_DeadEffect.setSource(QUrl("qrc:/sfx/res/pig_dead.wav"));
    this->Pig_DeadEffect.setLoopCount(0);
    this->Pig_DeadEffect.setVolume(effectvolume);
    this->MissEffect.setSource(QUrl("qrc:/sfx/res/miss.wav"));
    this->MissEffect.setLoopCount(0);
    this->MissEffect.setVolume(effectvolume);
    this->ClearEffect.setSource(QUrl("qrc:/sfx/res/clear.wav"));
    this->ClearEffect.setLoopCount(0);
    this->ClearEffect.setVolume(effectvolume);
    this->FailEffect.setSource(QUrl("qrc:/sfx/res/fail.wav"));
    this->FailEffect.setLoopCount(0);
    this->FailEffect.setVolume(effectvolume);
}
