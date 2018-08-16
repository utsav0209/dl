#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAXLEN 20
/* 6 for field name "uname", 1 for "=" */
#define EXTRA1 6
/* 5 for field name "pass", 1 for "=" */
#define EXTRA2 5
#define MAXINPUT MAXLEN+EXTRA2+2
/* 1 for added line break, 1 for trailing NUL */
#define MAXINPUT2 MAXLEN+EXTRA2+2


void unencode(char *src, char *last, char *dest1,char *dest2)
{
  char *x;
 for(; *x!='&'; src++, dest1++){
   if(*src == '+')
     *dest1 = ' ';
   else if(*src == '%') {
     int code;
     if(sscanf(src+1, "%2x", &code) != 1) 
      code = '?';
    *dest1 = code;
     src +=2; 
   }
   else if(*src == '&'){
      break;
   }     
   else{
     x=dest1;
     *dest1 = *src;
   }
  } 
 
 src+=EXTRA2+1;
 
 for(; src != last ; src++, dest2++){
   if(*src == '+')
     *dest2 = ' ';
   else if(*src == '%') {
     int code;
     if(sscanf(src+1, "%2x", &code) != 1) code = '?';
     *dest2 = code;
     src +=2; 
   }
  else if(*src == '&'){
      break;
   }     
   else{

       *dest2 = *src;
   }
}

}

int main(void)
{

  char *lenstr;
  char input[2*MAXINPUT], data[2][MAXINPUT]={{'\0'},{'\0'}};
  long len;

  printf("%s%c%c\n",
  "Content-Type:text/html;charset=iso-8859-1",13,10);
  printf("<TITLE>Response</TITLE>\n");
  lenstr = getenv("CONTENT_LENGTH");

  if(lenstr == NULL || sscanf(lenstr,"%ld",&len)!=1 || len > 2*MAXLEN+EXTRA1+EXTRA2)
  {  
    printf("<P>Error in invocation - wrong FORM probably.");
    
  }else{

    fgets(input, len+1, stdin);
    unencode(input+EXTRA1, input+len, data[0],data[1]);
    if(!strcmp(data[0],"utsav") && !strcmp(data[1],"varia"))
      printf("<P> You Have LoggedIn! :) </p>");
    else
      printf("<p> Sorry Wrong Credentials :( </p>");
  }
  return 0;
}