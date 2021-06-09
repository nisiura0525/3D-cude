
//�����̂̉�]

#include"libOne.h"
//���_�ʒu�̍\����
struct POS {  //���_�̍\����
    float x, y, z;
};
//�Q�[�����C��
void gmain() {
    window(1000, 1000);
    const int num = 8; 
    struct POS op[num] = { //�ŏ��̒��_�̒l�@�����l
        -1,1,-1,
        -1,-1,-1,
        1,-1,-1,
        1,1,-1,
        -1,1,1,
        -1,-1,1,
        1,-1,1,
        1,1,1,
    };
    struct POS p[num]; //�ŏ���op�������Ă��Ă��̒l��
    float deg = 0;     //�ς��Ă������Ƃœ������Ă���
    angleMode(DEGREES);
    int state = 0;
    int flug = 0;
    while (notQuit) {
        clear(200);
        if (flug == 0) {
            deg += 5;
        }
        float s = sin(deg);
        float c = cos(deg);
        if (deg > 360) {
            deg = 0;
           ++state %= 2;
        }
        if (isTrigger(KEY_SPACE)) {
            ++flug;
            flug %= 2;
        }
        for (int i = 0;i < num;i++) {
            if (state == 0) {
                p[i].x = op[i].x * c + op[i].z * -s; 
                p[i].y = op[i].y;
                p[i].z = op[i].x * s + op[i].z * c;
            }
            //�ŏ�������W��1�w�肵�Ă�����
            //���̍��W��sin�Ecos���g���ĉ�]�����Ă���
            //�K���ɑł������W����]�����邱�Ƃ��ł���
            
            else if(state == 1) {
                p[i].y = op[i].y * c + op[i].z * -s;
                p[i].x = op[i].x;
                p[i].z = op[i].y * s + op[i].z * c;
            }
            
           
            //p[i].z = op[i].z + s; //�y�i���s�j�̉^�����傫���ق�X,Y�̍��W���������Ȃ�
            p[i].z += 5;

            p[i].x /= p[i].z;
            p[i].y /= p[i].z;
        }  
        mathAxis(0.5);
        stroke(200, 255, 255);
        strokeWeight(10);
        for (int i = 0;i < 4;i++) {
            int  v = (i + 1) % 4;
            mathLine(p[i].x, p[i].y, p[v].x, p[v].y);
            mathLine(p[i + 4].x, p[i + 4].y, p[v + 4].x, p[v + 4].y);
            
            mathLine(p[i].x, p[i].y, p[i+ 4].x, p[i + 4].y);
        }
       

    }
}

/*
#include"libOne.h"
//���_�ʒu�̍\����
struct POS {
    float x, y, z;
};
//�Q�[�����C��
void gmain() {
    window(1000, 1000);
    //���_�̐�
    const int num = 8;
    //���̒��_�ʒu�i���s�����ێ�����Ă���j
    struct POS op[num] = {
        -1,1,-1,
        -1,-1,-1,
        1,-1,-1,
        1,1,-1,
        -1,1,1,
        -1,-1,1,
        1,-1,1,
        1,1,1,
    };
    //�ύX��̒��_�ʒu�̓��ꕨ�i���[�v���邽�тɕω�����j
    struct POS p[num];
    //���̒��_�ʒu����]������p�x
    float deg = 0;
    angleMode(DEGREES);
    //����state��0�̎�Y���A1�̎�X����]����
    int state = 0;
    //���C�����[�v
    while (notQuit) {
        //���炩����sin,cos���v�Z���Ă���
        float s = sin(deg);
        float c = cos(deg);
        deg++;
        //state�̕ύX
        if (deg > 360) {
            deg = 0;
            ++state %= 2;
        }
        //�z��op�̍��W��ϊ����Ĕz��p�ɏ�������
        // ( �z��op�̈ʒu�͕ς��Ȃ� )
        for (int i = 0; i < num; i++) {
            //��]
            if (state == 0) {
                p[i].x = op[i].x * c + op[i].z * -s;
                p[i].y = op[i].y;
                p[i].z = op[i].x * s + op[i].z * c;
            }
            else {
                p[i].x = op[i].x;
                p[i].y = op[i].y * c + op[i].z * -s;
                p[i].z = op[i].y * s + op[i].z * c;
            }
            //���Ɉړ�
            p[i].z += 5;
            //�����̍��W������������
            p[i].x /= p[i].z;
            p[i].y /= p[i].z;
        }
        //���_�ʒu����Ō��ї����̂ɂ���
        clear(0);
        mathAxis(0.5);//�N���A�F�Ɠ����Ŏ��͌����Ȃ����K�v�Ȗ���
        stroke(160, 200, 255);
        strokeWeight(10);
        for (int i = 0; i < 4; i++) {
            int j = (i + 1) % 4;
            //��O�̎l�p�`�̐�
            mathLine(p[i].x, p[i].y, p[j].x, p[j].y);
            //���̎l�p�`�̐�
            mathLine(p[i+4].x, p[i+4].y, p[j+4].x, p[j+4].y);
            //�O������Ԑ�
            mathLine(p[i].x, p[i].y, p[i+4].x, p[i+4].y);
        }
    }
}
*/
