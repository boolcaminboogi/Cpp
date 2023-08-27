#pragma once
#include "Canvas.h"
#include "Monster.h"
#include <windows.h>
#include "Matrix.h"
#include "VariousMonsters.h"

#define MAXMONS 10

class MonsterWorld {
    Matrix world;
    int xMax, yMax, nMon, nMove;
    Monster* pMon[MAXMONS];       // ���� ��ü �迭�� ����� ũ��� ����
    Canvas canvas;
    int& Map(int x, int y) { return world.elem(x, y); }        // ���� ���� �׸��� �����ϱ� ���� �Լ�. map[y][x]�� Map(x,y)�� ��Ȯ�� ����
    bool isDone() { return countItems() == 0; }

    int countItems() {          // ���� �ʿ� �����ִ� ������ �� ��ȯ
        int nItems = 0;
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++)
                if (Map(x, y) > 0) nItems++;
        return nItems;
    }

    void print() {                 // ���� ���� ���      ĵ���� �ʱ�ȭ, ������ ��ġ�� ��, ���� ��ġ�� ������, 30�࿡�� ĵ���� ���, ���� ��º� ���� ���
        canvas.clear();
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++)
                if (Map(x, y) > 0)canvas.draw(x, y, "��");
        for (int i = 0; i < nMon; i++)
            pMon[i]->draw(canvas);
        canvas.print("[ Dynamic World ]");

        cerr << "��ü �̵� Ƚ�� = " << nMove << endl;
        cerr << "���� ������ �� = " << countItems() << endl;
        for (int i = 0; i < nMon; i++)
            pMon[i]->print();
    }

public:
    MonsterWorld(int w, int h) : world(h, w), canvas(w, h), xMax(w), yMax(h) {       // ó������ ���� ��� ĭ�� �������� ����
        nMon = 0;
        nMove = 0;
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++) Map(x, y) = 1;
    }
    ~MonsterWorld() {      // MonsterWorld�� �Ҹ���
        for (int i = 0; i < nMon; i++)
            delete pMon[i];
    }

    void add(Monster* m) {
        if (nMon < MAXMONS) pMon[nMon++] = m;        // ���� ���͸� �߰��ϴ� �Լ�
    }

    void play(int maxwalk, int wait) {      // ���Լ�. �̵��� �ִ� ��� �ѵ��� �ݺ��� ���� �ð��� �Ű������� ����
        print();
        cerr << "���͸� ��������...";
        getchar();
        for (int i = 0; i < maxwalk; i++) {
            for (int k = 0; k < nMon; k++) {
                ((Zombie*)pMon[0])->move(world.Data(), xMax, yMax);
                ((Vampire*)pMon[1])->move(world.Data(), xMax, yMax);
                ((KChost*)pMon[2])->move(world.Data(), xMax, yMax);
                ((Jiangshi*)pMon[3])->move(world.Data(), xMax, yMax);
                ((Human*)pMon[4])->move(world.Data(), xMax, yMax);
                //((Jiangshi*)pMon[5])->move(world.Data(), xMax, yMax);                
                //((Anyang*)pMon[6])->move(world.Data(), xMax, yMax);
                //((Smombi*)pMon[2])->move(world.Data(), xMax, yMax);

            }
            nMove++;
            print();
            if (isDone()) break;
            Sleep(wait);
        }
    }
};
