#include "PredefinedMovement.h"

PredefinedMovement::PredefinedMovement() : Movement()
{

}
PredefinedMovement::~PredefinedMovement() = default;
void PredefinedMovement::DefineContinuousMovement(directions direction)
{
    if (IsDirectionAllowed(direction))
    {
        SetMovementVector(direction)
    }
    else
    {
        SetMovementVector(vectorZero);
    }
}