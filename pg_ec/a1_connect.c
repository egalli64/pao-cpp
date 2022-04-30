/* Processed by ecpg (14.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "a1_connect.pgc"
/*
 * a1_connect.pgc / c
 *
 * Connecting to PostgreSQL in C
 *
 * 1) precompile -> ecpg a1_connect.pgc
 * 2) compile    -> gcc -I"C:\Program Files\PostgreSQL\14\include" -c a1_connect.c
 * 3) link       -> gcc -o a1 a1_connect.o -L"C:\Program Files\PostgreSQL\14\lib" -lecpg
 */

#include <stdio.h>

/* exec sql begin declare section */

     
     
     


#line 15 "a1_connect.pgc"
 static const char * target = "tcp:postgresql://localhost:5432/hron" ;
 
#line 16 "a1_connect.pgc"
 static const char * user = "hron" ;
 
#line 17 "a1_connect.pgc"
 static const char * password = "password" ;
/* exec sql end declare section */
#line 19 "a1_connect.pgc"


int main() {
	printf("Connecting ... ");

	{ ECPGconnect(__LINE__, 0, target , user , password , NULL, 0); }
#line 24 "a1_connect.pgc"

//	EXEC SQL CONNECT TO tcp:postgresql://localhost:5432/hron USER hron/password;

	if(sqlca.sqlcode == 0) {
		printf("done!\n");
	} else {
		printf("error %s\n", sqlca.sqlerrm.sqlerrmc);
	}

	{ ECPGdisconnect(__LINE__, "CURRENT");}
#line 33 "a1_connect.pgc"

}
