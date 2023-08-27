#pragma once
#include "Canvas.h"
#include "Matrix.h"
#include "Point.h"

class Monster {

protected:
    string name, icon;      // ���� �̸��� ȭ�� ��¿� ������
    int x, y;
    int nItem;        // ���� ��ġ�� ���� ������ ��
    int nEnergy = 100;
    Point q, p;             // ���� ��ġ q, ���� ��ġ p
    int nSleep;             // ����� �ϴ� Ƚ��
    double dist;            // ���� �� ���� ������ �Ÿ�
    double total;           // �� ������ �Ÿ�

    void clip(int maxx, int maxy) {         // ����ġ�� �� ���̸� �ٽ� �������� �ű�
        p(maxx, maxy);
     /* if (x < 0) x = 0;
        if (x >= maxx)x = maxx - 1;
        if (y < 0) y = 0;
        if (y >= maxy) y = maxy - 1;*/
    }

    void eat(int** map) {           //���� ���� ��ġ�� �������� ������ �������� �԰� ���� ����� ���� ������ �� ����
        if (map[p.y][p.x] == 1) {
            map[p.y][p.x] = 0;
            nItem++;
            nEnergy += 8;         // ���Ͱ� �������� ���� �� ���� �������� 8 ������.
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
            nEnergy += 8;         // ���Ͱ� �������� ���� �� ���� �������� 8 ������.
        }
        else if (nEnergy > 0)
            nEnergy--;*/
        /*else if (nEnergy == 0)
        {
            cout << "���Ͱ� �׾����ϴ�. �ΰ� �¸�" << endl;
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
    Monster(string n = "������", string i = "��", int px = 0, int py = 0)
        : name(n), icon(i), nItem(0), nEnergy(100), p(x, y), q(x, y), nSleep(0), dist(0.0), total(0.0) {}
    virtual ~Monster() { cout << icon << nItem << "�Ÿ� : " << total << endl; }       // ������ �Ҹ���. �̸��� ������, �׸��� ������ٴ� �޽��� ���

    void draw(Canvas &canvas) { canvas.draw(p,q, icon); }          // ���͸� ĵ������ �׸��� �Լ�

    virtual void move(int** map, int maxx, int maxy) {
        if (!isSleep()) {
            int num = rand() % 9 + 1;
            p += Point(num % 3 - 1, num / 3 - 1);
            /*
            switch (rand() % 8) {           // ���͸� �������� �̵���Ŵ
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
            eat(map);           // �������� ���������� ����
        }
    }
    void print() { cout << "\t" << name << icon << ":" << nItem << "\t\t" << "E : " << nEnergy << "\t\t" << nSleep << endl; }
};
