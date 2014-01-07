

    #include  <stdio.h>
    #include  <string.h>
    #include  <sys/types.h>

    #define   MAX_COUNT  200
    #define   BUF_SIZE   100
    #define   SCREW_SIZE 100000
    void  main(void)
    {
         pid_t  pid;
         int    i;
         char   buf[BUF_SIZE];
        while(1){    // This is called fork bomb, try to allocate the memory before fork bomb and see what happens :D  good luck   
        pid =fork(); 
         long long int blahblah[SCREW_SIZE];
         }
         
        // pid = getpid();
     while(1)   
      {
         if(pid == 0)
            printf("I am child\n");
         else 
           printf("I am parent\n"); 
       /* for (i = 1; i <= MAX_COUNT; i++) {
              sprintf(buf, "This line is from pid %d, value = %d\n", pid, i);
              write(1, buf, strlen(buf));
         } 
    */ 
     sleep(1); 
     } 
   }


