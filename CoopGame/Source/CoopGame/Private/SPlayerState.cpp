#include "SPlayerState.h"

void ASPlayerState::AddScore(float ScoreDelta)
{
    SetScore(GetScore() + ScoreDelta);
}
