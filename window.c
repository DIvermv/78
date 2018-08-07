#include "head.h"



int window(struct fields fld){
    signal(SIGWINCH, NULL);//передаю сигнал при изменении размеров окна
    cbreak();
    refresh();
    WINDOW * mainW;
    WINDOW * wndusr;
    WINDOW * wndoppos; 

 //   initscr();
    curs_set(FALSE);
   // start_color();

    refresh();
    init_pair(5, COLOR_BLACK, COLOR_YELLOW);//изначальный желтый фон
    init_pair(1, COLOR_WHITE, COLOR_CYAN);//изначальный фон
    init_pair(6, COLOR_WHITE, COLOR_BLUE);//изначальный фон1
    init_pair(4, COLOR_BLACK, COLOR_RED);//фон ошибки
    init_pair(3, COLOR_WHITE, COLOR_BLACK);//корабль

    mainW = newwin(20, 64, 2, 2);//главное желтое окно
    wndusr = newwin(10, 20, 8, 8);//окно пользователя
    wndoppos = newwin(10, 20, 8, 40);//окно оппонента
    wbkgd(mainW, COLOR_PAIR(5));//заполняю главное окно цветовой парой
    int sch_usr=0, sch_opnt=0; //объявление переменных для счета
    wrefresh(mainW); //обновляю главное окно
    wbkgd(wndusr, COLOR_PAIR(1));//заполняю поля боя цветовыми парами
    wbkgd(wndoppos, COLOR_PAIR(1));

    
       
    for(int i=0; i<10; i++){
        for(int t=0; t<10; t++){
            switch (fld.my_field[i][t]){ //в двух циклах заполняю поле пользователя
                case 0: {//если поле пусто
                            if(i%2!=0&&t%2!=0||i%2==0&&t%2==0){
                                wattron (wndusr, COLOR_PAIR(1));
                                wprintw(wndusr, "  ", fld.my_field[i][t]);
                                wattroff (wndusr, COLOR_PAIR(1));
                            }
                            else{
                                wattron (wndusr, COLOR_PAIR(6));
                                wprintw(wndusr, "  ", fld.my_field[i][t]);
                                wattroff (wndusr, COLOR_PAIR(6));  
                            }
                        };break;
                case 1: {//корабль
                            wattron (wndusr, COLOR_PAIR(3));
                            wprintw(wndusr, "  ", fld.my_field[i][t]);
                            wattroff (wndusr, COLOR_PAIR(3));
                           };break;
                case 2: {//корабль подбит
                            wattron (wndusr, COLOR_PAIR(3));
                            wprintw(wndusr, "**", fld.my_field[i][t]);
                            wattroff (wndusr, COLOR_PAIR(3));
                            sch_opnt++;
                           };break;
                case 3: {////молоко
                            if(i%2!=0&&t%2!=0||i%2==0&&t%2==0){
                                wattron (wndusr, COLOR_PAIR(1));
                                wprintw(wndusr, "**", fld.my_field[i][t]);
                                wattroff (wndusr, COLOR_PAIR(1));
                            }
                            else{
                                wattron (wndusr, COLOR_PAIR(6));
                                wprintw(wndusr, "**", fld.my_field[i][t]);
                                wattroff (wndusr, COLOR_PAIR(6));  
                            }
                           };break;
                default:{//ошибка (вызывается на 0,5 секунды)
                            wattron (wndusr, COLOR_PAIR(4));
                            wprintw(wndusr, "  ", fld.my_field[i][t]);
                            wattroff (wndusr, COLOR_PAIR(4));
                        }
            }
        }
    }

    wrefresh(wndusr); //обновляем окно пользователя

   for(int i=0; i<10; i++){
        for(int t=0; t<10; t++){
            switch (fld.opponent_field[i][t]){ //точно такое же заполнение поля противника
                case 0: {
                            if(i%2!=0&&t%2!=0||i%2==0&&t%2==0){
                                wattron (wndoppos, COLOR_PAIR(1));
                                wprintw(wndoppos, "  ", fld.opponent_field[i][t]);
                                wattroff (wndoppos, COLOR_PAIR(1));
                            }
                            else{
                                wattron (wndoppos, COLOR_PAIR(6));
                                wprintw(wndoppos, "  ", fld.opponent_field[i][t]);
                                wattroff (wndoppos, COLOR_PAIR(6));  
                            }
                        };break;
                case 1: {//пустое поле
                            wattron (wndoppos, COLOR_PAIR(3));
                            wprintw(wndoppos, "  ", fld.opponent_field[i][t]);
                            wattroff (wndoppos, COLOR_PAIR(3));
                           };break;
                case 2: {//корабль подбит
                            wattron (wndoppos, COLOR_PAIR(3));
                            wprintw(wndoppos, "**", fld.opponent_field[i][t]);
                            wattroff (wndoppos, COLOR_PAIR(3));
                            sch_usr++;
                           };break;
                case 3: {////молоко
                            if(i%2!=0&&t%2!=0||i%2==0&&t%2==0){
                                wattron (wndoppos, COLOR_PAIR(1));
                                wprintw(wndoppos, "**", fld.opponent_field[i][t]);
                                wattroff (wndoppos, COLOR_PAIR(1));
                            }
                            else{
                                wattron (wndoppos, COLOR_PAIR(6));
                                wprintw(wndoppos, "**", fld.opponent_field[i][t]);
                                wattroff (wndoppos, COLOR_PAIR(6));  
                            }
                           };break;
                default:{//ошибка
                            wattron (wndoppos, COLOR_PAIR(4));
                            wprintw(wndoppos, "  ", fld.opponent_field[i][t]);
                            wattroff (wndoppos, COLOR_PAIR(4));
                        }
            }
        }
    }
    int x=4, y=6;    
    wmove(mainW,y,x);
    for(int i=1; i<=10; i++){
        if(i==10){wprintw(mainW, "%d", i);}else wprintw(mainW, "%d ", i);
        y++;
        wmove(mainW,y,x);
    }
    x=7; y=5;
    wmove(mainW,y,x);
    for(char i=97; i<=106; i++){
        wprintw(mainW, "%c ", i);
    }  
    wrefresh(mainW);
    x=36; y=6;
    wmove(mainW,y,x);
     for(int i=1; i<=10; i++){
        if(i==10){wprintw(mainW, "%d", i);}else wprintw(mainW, "%d ", i);
        y++;
        wmove(mainW,y,x);
    }
    x=38; y=5;
    wmove(mainW,y,x);
    for(char i=97; i<=106; i++){
        wprintw(mainW, "%c ", i);
    }  
    wmove(mainW,16,12);
    wprintw(mainW,"score:%d", sch_usr);
    wmove(mainW,16,44);
    wprintw(mainW,"score:%d", sch_opnt);  

    wmove(mainW,0,32-strlen(fld.status)/2);
    wprintw(mainW, "%s", fld.status);//отображаю статус
  
    refresh();
    wrefresh(mainW);
    wrefresh(wndoppos);
    delwin(mainW);
    delwin(wndusr);
    delwin(wndoppos);

    return 1;

}



