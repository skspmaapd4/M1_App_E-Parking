#include <parking.h>
/* adds a data of vehicle */
struct vehicle * add ( int t, int num, int row, int col )
{
    struct vehicle *v ;
    int r ;

    v = ( struct vehicle * ) malloc ( sizeof ( struct vehicle ) ) ;

    v -> type = t ;
    v -> row = row ;
    v -> col = col ;

	  if ( t == CAR )
      carcount++ ;
    else
    	scootercount++ ;

    vehcount++ ;
	  parkinfo[row][col] = num ;
     v->at = datetime();
	  insertrecord(num,t,row,col,datetime());
	   backupw(t);
	  r = randint();
	  if(r < 5 )
      {
          printf("\a");
          printf("\a");
          finesheet(num,t,row,col,datetime());

      }

    return v ;
}
struct vehicle * addonstart ( int t, int num, int row, int col )
{
    struct vehicle *v ;
    int r ;

    v = ( struct vehicle * ) malloc ( sizeof ( struct vehicle ) ) ;

    v -> type = t ;
    v -> row = row ;
    v -> col = col ;

	  if ( t == CAR )
      carcount++ ;
    else
    	scootercount++ ;

    vehcount++ ;
	  parkinfo[row][col] = num ;
     //v->at = datetime();
	  //insertrecord(num,t,row,col,datetime());
	//   backupw(t);
	 // r = randint();
	 // if(r < 5 )
      /*{
          printf("\a");
          printf("\a");
          finesheet(num,t,row,col,datetime());
      }*/

    return v ;
}

/* deletes the data of the specified
   car from the array, if found */
void del ( struct vehicle *v )
{
  int c ;

	//for ( c = v -> col ; c < 9 ; c++ )
	 // parkinfo[v -> row][c] = parkinfo[v -> row][c+1] ;

	parkinfo[v -> row][v -> col] = 0 ;

	if ( v -> type == CAR )
    carcount-- ;
  else
    scootercount-- ;

	vehcount-- ;
	backupw();
}

/* get the row-col position for the vehicle to be parked */
void getfreerowcol ( int type, int *arr )
{
  int r, c, fromrow = 0, torow = 2 ;

  if ( type == SCOOTER )
  {
    fromrow += 2 ;
    torow += 2 ;
  }

	for ( r = fromrow ; r < torow ; r++ )
	{
		for ( c = 0 ; c < 10 ; c++ )
		{
			if ( parkinfo[r][c] == 0 )
			{
				arr[0] = r ;
				arr[1] = c ;
        return ;
			}
		}
	}

	if ( r == 2 || r == 4 )
	{
   	arr[0] = -1 ;
    arr[1] = -1 ;
  }
}

/* get the row-col position for the vehicle with specified number */
void getrcbyinfo ( int type, int num, int *arr )
{
  int r, c, fromrow = 0, torow = 2 ;

  if ( type == SCOOTER )
	{
    fromrow += 2 ;
    torow += 2 ;
	}

	for ( r = fromrow ; r < torow ; r++ )
	{
		for ( c = 0 ; c < 10 ; c++ )
		{
			if ( parkinfo[r][c] == num )
			{
				arr[0] = r ;
				arr[1] = c ;
        return ;
			}
		}
	}

	if ( r == 2 || r == 4 )
	{
		arr[0] = -1 ;
		arr[1] = -1 ;
	}
}

/* displays list of vehicles parked */
void display( )
{
  int r, c ;

  printf ( "Cars ->\n" ) ;

  for ( r = 0 ; r < 4 ; r++ )
  {
    if ( r == 2 )
		  printf ( "Scooters ->\n" ) ;

    for ( c = 0 ; c < 10 ; c++ )
      printf ( "%d\t", parkinfo[r][c] ) ;
    printf ( "\n" ) ;
	}
}

int main( )
{
	int choice, type, number, row = 0, col = 0 ;
	int i, tarr[2] ;
	int finish = 1 ;
	backupr();



  system ( "cls" ) ;

	/* displays menu and calls corresponding functions */
	while ( finish )
	{
    system ( "cls" ) ;

		printf ( "\nCar Parking\n" ) ;
		printf ( "1. Arrival of a vehicle\n" ) ;
		printf ( "2. Total no. of vehicles parked\n" ) ;
		printf ( "3. Total no. of cars parked\n" ) ;
		printf ( "4. Total no. of scooters parked\n" ) ;
		printf ( "5. Display order in which vehicles are parked\n" ) ;
		printf ( "6. Departure of vehicle\n" ) ;
		printf ( "7. Chek History\n" ) ;
		printf ( "8. Exit\n" ) ;

		scanf ( "%d", &choice ) ;

		switch ( choice )
		{
			case 1 :
          system ( "cls" ) ;
				  printf ( "\nAdd: \n" ) ;

          type = 0 ;

          /* check for vehicle type */
          while ( type != CAR && type != SCOOTER )
          {
					  printf ( "Enter vehicle type (1 for Car / 2 for Scooter ): \n" ) ;
            scanf ( "%d", &type ) ;
	          if ( type != CAR && type != SCOOTER )
						  printf ( "\nInvalid vehicle type.\n" ) ;
          }

				  printf ( "Enter vehicle number: " ) ;
				  scanf ( "%d", &number ) ;

				  /* add cars' data */
				  if ( type == CAR || type == SCOOTER )
				  {
					  getfreerowcol ( type, tarr ) ;

					  if ( tarr[0] != -1 && tarr[1] != -1 )
					  {
						  row = tarr[0] ;
						  col = tarr[1] ;

              if ( type == CAR )
                car[row][col] =  add ( type, number, row, col ) ;
              else
							  scooter[row - 2][col] = add ( type, number, row, col ) ; ;
            }
					  else
            {
              if ( type == CAR )
                printf ( "\nNo parking slot free to park a car\n" ) ;
              else
                printf ( "\nNo parking slot free to park a scooter\n" ) ;
            }
          }
				  else
				  {
            printf ( "Invalid type\n" ) ;
					  break ;
          }

          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
				  break ;

      case 2 :
          system ( "cls" ) ;
				  printf ( "Total vehicles parked: %d\n", vehcount ) ;
          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
				  break ;

			case 3 :
          system ( "cls" ) ;
				  printf ( "Total cars parked: %d\n", carcount ) ;
          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
				  break ;

			case 4 :
          system ( "cls" ) ;
				  printf ( "Total scooters parked: %d\n", scootercount ) ;
          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
				  break ;

			case 5 :
          system ( "cls" ) ;
				  printf ( "Display\n" ) ;
				  display( ) ;
          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
				  break ;

			case 6 :      //problem area ................................................
          system ( "cls" ) ;
				  printf ( "Departure\n" ) ;
          type = 0 ;
          /* check for vehicle type */
          while ( type != CAR && type != SCOOTER )
          {
					  printf ( "Enter vehicle type (1 for Car / 2 for Scooter ): \n" ) ;
            scanf ( "%d", &type ) ;
	          if ( type != CAR && type != SCOOTER )
						  printf ( "\nInvalid vehicle type.\n" ) ;
          }
				  printf ( "Enter number: "  ) ;
				  scanf ( "%d", &number ) ;

  				if ( type == CAR || type == SCOOTER )
	  			{


		  			getrcbyinfo ( type, number, tarr ) ;
			  		if ( tarr[0] != -1 && tarr[1] != -1 )
				  	{
				  	    insertrecord2(number,datetime());
				  	    get_arrival_time(number);
              col = tarr [1] ;
              /* if the vehicle is car */
              if ( type == CAR )
              {
                row = tarr [0] ;
	              del ( car [row][col] ) ;

				                    for ( i = col ; i < 9 ; i++ )
							  {
								  car[row][i] = car[row][i + 1] ;
								 // changecol ( car[row][col] ) ;
							  }
                free ( car[row][i] ) ;

					  car[row][i] = NULL ;
              }
						  /* if a vehicle is scooter */
						  else
              {
                row = tarr[0] - 2 ;
							  if ( ! ( row < 0 ) )
							  {
								  del ( scooter[row][col] ) ;
								  for ( i = col ; i < 9 ; i++ )
								  {
									  scooter[row][i] = scooter[row][i + 1] ;
									  //changecol ( scooter[row][col] ) ;
								  }
								  scooter[row][i] = NULL ;
                }
              }
            }
					  else
            {
              if ( type == CAR )
							  printf ( "\nInvalid car number, or a car with such number has not been parked here.\n" ) ;
              else
                printf ( "\nInvalid scooter number, or a scooter with such number has not been parked here.\n" ) ;
            }
          }
          printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
				  break ;

			case 8 :

          system ( "cls" ) ;
          for ( row = 0 ; row < 2 ; row++ )
          {
            for ( col = 0 ; col < 10 ; col++ )
            {
              if ( car[row][col] -> num != 0 )
                free ( car[row][col] ) ;
              if ( scooter[row][col] -> num != 0 )
							  free ( scooter[row+2][col] ) ;
            }
          }
				  finish = 0 ;




				   getch();
				  break ;

            case 7 :
              system ( "cls" ) ;
     int opt ;
		printf ( "RECORD TABLES\n" ) ;
  			 printf ( "Press 1 for Arrival history\n" ) ;
                         printf ( "Press 2 for Departure history\n" ) ;
                                printf ( "Press 3 for Fine Sheet\n" ) ;
     			scanf ( "%d", &opt ) ;
           historyrec(opt);
 printf ( "\nPress any key to continue..." ) ;
          getch( ) ;
                break ;
    }
	}
  return 0;
}