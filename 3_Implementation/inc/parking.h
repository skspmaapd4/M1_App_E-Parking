/* Vehicle parking program */

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define CAR 1
#define SCOOTER 2
#include <stdlib.h>
#ifndef __PARKING_H__
#define __PARKING_H__

/* to store vehicle number, and its
   row-col position in an array */
struct vehicle{
	int num ;
	int row ;
	int col ;
  int type ;
  struct tm *at;
} ;
struct vehicle *car[2][10] ;
	struct vehicle *scooter[2][10] ;
int parkinfo[4][10] ;  /* a 2-D array to store number of vehicle parked */
int vehcount ;  /* to store total count of vehicles */
int carcount ;	/* stores total count of cars */
int scootercount ;  /* stores total count of scooters */
/* creates a 2-D array of car and scooter class */
void display( ) ;
void changecol ( struct vehicle * ) ;
struct vehicle * add ( int, int, int, int ) ;
void del ( struct vehicle * ) ;
void getfreerowcol ( int, int * ) ;
void getrcbyinfo ( int, int, int * ) ;
void show() ;
int randint();
int backupw();
int backupr();
struct vehicle * addonstart ( int, int, int, int ) ;
void total_bill(int ,struct tm *ct1,struct tm *ct2);
void get_arrival_time(int);
/* decrements the col. number by one
   this fun. is called when the data is
   shifted one place to left */
void changecol ( struct vehicle *v )
{
	v -> col--;
}

struct tm* datetime();
int insertrecord(int veh,int type,int row,int col, struct tm *ct );
int insertrecord2(int veh, struct tm *ct );
void get_arrival_time(int num);
int randint();
void finesheet(int veh,int type,int row,int col, struct tm *ct);
struct vehicle * add ( int t, int num, int row, int col );
struct vehicle * addonstart ( int t, int num, int row, int col );
void getrcbyinfo ( int type, int num, int *arr );
void display( )
#endif  /* #define __PARKING_H__ */