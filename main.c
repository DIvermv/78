#include "head.h"

int main (int argc, char *argv[])
{
    struct fields ships_fields;
     char  opponent_addr[256];
     int sock_id;
	
 /*    strcpy(opponent_addr,"");
     if(argc>1)
	for(int i=1;i<argc;i++)
	{
		printf("%s\n",argv[i]);
		if(!strcmp(argv[i],"-help")){
		 // printf("%s\n","Помощь спешит!");
		  printf("%s\n","ключ -addr <IP адрес оппонента> (формат 192.168.2.138)");
		return 0;
		}
		if(!strcmp(argv[i],"-addr"))
			//if(!check_valid_addr[strcmp(argv[i+1]))
			{ strcpy(opponent_addr,argv[i+1]);
		 //         printf("%s %s\n",argv[i+1],"IP адрес не соответсвует формату 192.168.2.138");

			}


	}

   // sleep(2);
   sock_id=connect_est (opponent_addr);
*/
   //инициализируем окно ncurses
      initscr();
      start_color();
      keypad (stdscr, TRUE);

  // ships_fields=reposition(ships_fields);// расставили корабли на своем поле
   window(ships_fields);
    //battle(ships_fields,sock_id);
     int *g;//одномерный массив для того, чтобы принять координаты
       g = wait_click(1);//принимаем координаты
   // battle(ships_fields);

    endwin();// разрушаем окно ncurses
    printf("%d\n%d",g[0],g[1]);//выводим координаты (проверял как работает функция Wait_Click)
return 0;
}
