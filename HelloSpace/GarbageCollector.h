#pragma once

class GarbageCollector
{
private:
public:
	GarbageCollector();
	~GarbageCollector();
	void CollectInactiveGameObjects();
};
