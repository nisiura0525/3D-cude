/*
#include"libOne.h"
//���_�ʒu�̍\����
struct POS {  //���_�̍\����
    float x, y, z;
};
int createStar() {
    const int num = 10;
    struct SHAPE_VERTEX vertices[num];
    angleMode(DEGREES);
    float deg = 360 / num;
    for (int i = 0;i < num;i++) {
        float radius = 0.5f + 0.5f * (i % 2);
        vertices[i].x = sin(deg * i) * radius;
        vertices[i].y = cos(deg * i) * radius;
    }
    return createShape(vertices, num);
}
//�Q�[�����C��
void gmain() {
    window(1000, 1000);
    float deg = 0;
    int idx = createStar();
    angleMode(DEGREES);
    clear(200);
    while (notQuit) {
        mathAxis(1.2);
        fill(255, 200, 227);
        strokeWeight(4);
        shape(idx, width / 2, height / 2, deg, 300);
    }
}
*/