#pragma once
#include "Headers.h"

class Object
{
public:
	Object();
	virtual ~Object();
public:
	virtual void Initialize() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;
protected:
	Transform m_tInfo;
public:
	Vector3 GetPosition() { return m_tInfo.Position; }
	Vector3 GetScale() { return m_tInfo.Scale; }
	int GetRotate() { return m_tInfo.Rotate; }

	void SetPosition(Vector3 _vPos) { m_tInfo.Position = _vPos; }
	void SetScale(Vector3 _vScale) { m_tInfo.Scale = _vScale; }
	void SetRotate(int _vRotate) { m_tInfo.Rotate = _vRotate; }
};

