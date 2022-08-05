#pragma once
#include "Headers.h"

class CollisionManager
{
public:
	static bool RectCollision(Transform _Current, Transform _Target)
	{
		Vector3 CurrentEndPoint = _Current.Position + _Current.Scale;
		Vector3 TargetEndPoint = _Target.Position + _Target.Scale;

		if (_Current.Position.x < TargetEndPoint.x &&
			_Target.Position.x < CurrentEndPoint.x &&
			_Current.Position.y < TargetEndPoint.y &&
			_Current.Position.y < CurrentEndPoint.y)
			return true;

		return false;
	}
};