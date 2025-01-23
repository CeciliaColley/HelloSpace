#include "PredefinedMovement.h"

PredefinedMovement::PredefinedMovement() : Movement()
{

}
PredefinedMovement::~PredefinedMovement() = default;
void PredefinedMovement::DefineMovement(directions direction)
{
    if (IsDirectionAllowed(direction))
    {
        SetMovementVector(DirectionToVector(direction));
    }
    else
    {
        SetMovementVector(vectorZero);
    }
}