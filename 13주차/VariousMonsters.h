#pragma once
#include "Monster.h"
#include "Human.h"

class Zombie : public Monster {

public:
	Zombie(string n = "허접좀비", string i = "§", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Zombie() { cout << "Zombie"; }
};

class Vampire : public Monster {

public:
	Vampire(string n = "뱀파이어", string i = "†", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Vampire() { cout << "Vampire"; }

	void move(int** map, int maxx, int maxy) {
		if (!isSleep()) {
			int dir = rand() % 4;
			if (dir == 0) p[0]--;
			else if (dir == 1) p[0]++;
			else if (dir == 2) p[1]--;
			else p[1]--;
			clip(maxx, maxy);
			eat(map);
		}
	}
};
/*
class Smombi : public Monster {

public:
	Smombi(string n = "스몸비", string i = "★", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Smombi() { cout << "Smombi"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 4;
		if (dir == 0) {
			x++; y++;
		}
		else if (dir == 1) {
			x++; y--;
		}
		else if (dir == 2) {
			x--; y++;
		}
		else {
			x--; y--;
		}
		clip(maxx, maxy);
		eat(map);
	}
};*/

class KChost : public Monster {		//아무데나 나타남

public:
	KChost(string n = "처녀귀신", string i = "＠", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~KChost() { cout << "KChost"; }

	void move(int** map, int maxx, int maxy) {
		if (!isSleep()) {
			p = Point(rand() % maxx, rand() % maxy);
			clip(maxx, maxy);
			eat(map);
		}
	}
};

class Jiangshi : public Monster {
	bool bHori;
public:
	Jiangshi(string n = "가로가로", string i = "↔", int x = 0, int y = 0, bool bH = true)
		: Monster(n, i, x, y) {}
	~Jiangshi() { cout << "Jiangshi"; }

	void move(int** map, int maxx, int maxy) {
		if (!isSleep()) {
			int dir = rand() % 2;
			int jump = rand() % 2 + 1;
			if (bHori)
				p[0] += ((dir == 0) ? -jump : jump);
			else 
				p[1] += ((dir == 0) ? -jump : jump);
			clip(maxx, maxy);
			eat(map);
		}
		
	}
};
/*
class Anyang : public Monster {

public:
	Anyang(string n = "안양검은발", string i = "♣", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Anyang() { cout << "Anyang"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 4;
		if (dir == 0) x += 2;
		else if (dir == 1) x -= 2;
		else if (dir == 2) y += 2;
		else y -= 2;
		clip(maxx, maxy);
		eat(map);
	}
};*/