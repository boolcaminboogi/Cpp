#pragma once
#include "Canvas.h"
#include "Matrix.h"
#include "Point.h"

class Monster {

protected:
    string name, icon;      // 몬스터 이름과 화면 출력용 아이콘
    int x, y;
    int nItem;        // 현재 위치와 먹은 아이템 수
    int nEnergy = 100;
    Point q, p;             // 이전 위치 q, 현재 위치 p
    int nSleep;             // 쉬어야 하는 횟수
    double dist;            // 쉬고 난 다음 움직인 거리
    double total;           // 총 움직인 거리

    void clip(int maxx, int maxy) {         // 현위치가 맵 밖이면 다시 안쪽으로 옮김
        p(maxx, maxy);
     /* if (x < 0) x = 0;
        if (x >= maxx)x = maxx - 1;
        if (y < 0) y = 0;
        if (y >= maxy) y = maxy - 1;*/
    }

    void eat(int** map) {           //맴의 현재 위치에 아이템이 있으면 아이템을 먹고 맵의 내용과 먹은 아이템 수 갱신
        if (map[p.y][p.x] == 1) {
            map[p.y][p.x] = 0;
            nItem++;
            nEnergy += 8;         // 몬스터가 아이템을 먹을 때 마다 에너지가 8 오른다.
        }
        else if (nEnergy > 0)
            nEnergy--;
        dist += (double)(p - q);
        total += (double)(p - q);
        q = p;
        if (dist > 20) {
            dist = 0;
            nSleep = 10;
        }                                    
      /*if (map[y][x] == 1) {
            map[y][x] = 0;
            nItem++;
            nEnergy += 8;         // 몬스터가 아이템을 먹을 때 마다 에너지가 8 오른다.
        }
        else if (nEnergy > 0)
            nEnergy--;*/
        /*else if (nEnergy == 0)
        {
            cout << "몬스터가 죽었습니다. 인간 승리" << endl;
            exit(0);
        }*/
    }

    bool isSleep() {
        if (nSleep > 0) {
            nSleep--;
            return true;
        }
        else return false;
    }

public:
    Monster(string n = "나괴물", string i = "※", int px = 0, int py = 0)
        : name(n), icon(i), nItem(0), nEnergy(100), p(x, y), q(x, y), nSleep(0), dist(0.0), total(0.0) {}
    virtual ~Monster() { cout << icon << nItem << "거리 : " << total << endl; }       // 몬스터의 소멸자. 이름과 아이콘, 그리고 사라진다는 메시지 출력

    void draw(Canvas &canvas) { canvas.draw(p,q, icon); }          // 몬스터를 캔버스에 그리는 함수

    virtual void move(int** map, int maxx, int maxy) {
        if (!isSleep()) {
            int num = rand() % 9 + 1;
            p += Point(num % 3 - 1, num / 3 - 1);
            /*
            switch (rand() % 8) {           // 몬스터를 무작위로 이동시킴
            case 0: p[1]--; break;
            case 1: p[0]++; p[1]--; break;
            case 2: p[0]++; break;
            case 3: p[0]++; p[1]++; break;
            case 4: p[1]++; break;
            case 5: p[0]--; p[1]++; break;
            case 6: p[0]--; break;
            case 7: p[0]--; p[1]--; break;
            }*/
            clip(maxx, maxy);
            eat(map);           // 아이템이 남아있으면 먹음
        }
    }
    void print() { cout << "\t" << name << icon << ":" << nItem << "\t\t" << "E : " << nEnergy << "\t\t" << nSleep << endl; }
};
