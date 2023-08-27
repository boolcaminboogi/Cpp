#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>
#include "Human.h"

void main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;

	MonsterWorld game(w, h);

	game.add(new Zombie("����������", "��", rand() % w, rand() % h));
	game.add(new Vampire("�����̾�¯", "��", rand() % w, rand() % h));
	game.add(new KChost("��¼�ٱͽ�", "��", rand() % w, rand() % h));
	game.add(new Jiangshi("���ΰ���", "��", rand() % w, rand() % h, true));
	game.add(new Human("���η�", "��", rand() % w, rand() %h ));
	//game.add(new Jiangshi("���Ծ����", "��", rand() % w, rand() % h, false));
	//game.add(new Smombi("������", "/", rand() % w, rand() % h));
	//game.add(new Anyang("�Ⱦ������", "��", rand() % w, rand() % h));
	game.play(500, 100);		// �ִ� 500�� �ݺ�, �ݺ����� 10msec ��ٸ����� ��
	printf("--------��������------------------------\n");
}