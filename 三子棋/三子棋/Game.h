#pragma once
#define ROW 3
#define COL 3
#include <stdio.h>
#include<time.h>
#include<stdlib.h>

void ChuShiHua(char qipan[][COL], int row, int col);

void DaYin(char qipan[][COL], int row, int col);

void WanJa(char qipan[][COL], int row, int col);

int Win(char qipan[][COL], int row, int col);
 
void DianNao(char qipan[][COL], int row, int col);
