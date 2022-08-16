#pragma once
#include "Object.h"

class Bullet : public Object
{
private:
	int Index;
	Texture* enim;
	float damage;
public:
	virtual void Start()override;
	virtual int Update()override;
	virtual void Render()override;
	virtual void Release()override;
public:
	void SetIndex(int _Index) { Index = _Index; }
	void setDamage(float _damage) { damage = _damage; }
	float getDamage() { return damage; }
public:
	Bullet();
	virtual ~Bullet();
};

