#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>
#include "Human.h"

void main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;

	MonsterWorld game(w, h);

	game.add(new Zombie("허접한좀비", "§", rand() % w, rand() % h));
	game.add(new Vampire("뱀파이어짱", "†", rand() % w, rand() % h));
	game.add(new KChost("어쩌다귀신", "＠", rand() % w, rand() % h));
	game.add(new Jiangshi("가로가로", "↔", rand() % w, rand() % h, true));
	game.add(new Human("신인류", "⊙", rand() % w, rand() %h ));
	//game.add(new Jiangshi("못먹어도세로", "↕", rand() % w, rand() % h, false));
	//game.add(new Smombi("스몸비", "/", rand() % w, rand() % h));
	//game.add(new Anyang("안양검은발", "♣", rand() % w, rand() % h));
	game.play(500, 100);		// 최대 500번 반복, 반복마다 10msec 기다리도록 함
	printf("--------게임종료------------------------\n");
}