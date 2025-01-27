#include "PredefinedMovement.h"

PredefinedMovement::PredefinedMovement() : Movement() { }
PredefinedMovement::~PredefinedMovement() = default;
void PredefinedMovement::DefineMovement(directions direction)
{
    if (DirectionIsAllowed(direction))
    {
        SetMovementVector(DirectionToVector(direction));
    }
    else
    {
        SetMovementVector(vectorZero);
    }
}