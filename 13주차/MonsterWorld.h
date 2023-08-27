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
    Monster* pMon[MAXMONS];       // 몬스터 객체 배열도 충분한 크기로 선언
    Canvas canvas;
    int& Map(int x, int y) { return world.elem(x, y); }        // 몬스터 맵의 항목을 접근하기 위한 함수. map[y][x]는 Map(x,y)와 정확히 동일
    bool isDone() { return countItems() == 0; }

    int countItems() {          // 몬스터 맵에 남아있는 아이템 수 반환
        int nItems = 0;
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++)
                if (Map(x, y) > 0) nItems++;
        return nItems;
    }

    void print() {                 // 현재 상태 출력      캔버스 초기화, 아이템 위치에 ㅁ, 몬스터 위치에 아이콘, 30행에서 캔버스 출력, 상태 출력부 내용 출력
        canvas.clear();
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++)
                if (Map(x, y) > 0)canvas.draw(x, y, "■");
        for (int i = 0; i < nMon; i++)
            pMon[i]->draw(canvas);
        canvas.print("[ Dynamic World ]");

        cerr << "전체 이동 횟수 = " << nMove << endl;
        cerr << "남은 아이템 수 = " << countItems() << endl;
        for (int i = 0; i < nMon; i++)
            pMon[i]->print();
    }

public:
    MonsterWorld(int w, int h) : world(h, w), canvas(w, h), xMax(w), yMax(h) {       // 처음에는 맵의 모든 칸에 아이템을 놓음
        nMon = 0;
        nMove = 0;
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++) Map(x, y) = 1;
    }
    ~MonsterWorld() {      // MonsterWorld의 소멸자
        for (int i = 0; i < nMon; i++)
            delete pMon[i];
    }

    void add(Monster* m) {
        if (nMon < MAXMONS) pMon[nMon++] = m;        // 세상에 몬스터를 추가하는 함수
    }

    void play(int maxwalk, int wait) {      // 주함수. 이동의 최대 허용 한도와 반복시 지연 시간을 매개변수로 받음
        print();
        cerr << "엔터를 누르세요...";
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
