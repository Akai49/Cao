#pragma once
#define ROW 3
#define	COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ����
void InitQipan(char qipan[ROW][COL], int row, int col);
void DisplayQipan(char qipan[ROW][COL], int row, int col);
void PlayerGo(char qipan[ROW][COL], int row, int col);
void ComputerGo(char qipan[ROW][COL], int row, int col);

//�����Ϸ���
//���Ӯ - ��*��
//����Ӯ - ��#��
//ƽ��   - ��Q��
//����   - ��R'
char IsWin(char qipan[ROW][COL], int row, int col);