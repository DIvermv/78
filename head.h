#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <curses.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct fields{
	char my_field[10][10];
	char opponent_field[10][10];
	char status[256];
};

int connect_est (char *ip_port);                    //возвращает дескриптор, порт 8679

struct fields reposition(struct fields field); // возвращает заполненную структуру

int window (struct fields field);             //отрисовывает окна
int *  wait_click(int win_number );// 0 - для своего окна, 1 - для окна противника
int battle(struct fields field,int sock_oppenent);              // возвращает исход боя

#endif
