#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
 
 #define FIFO_WRITE  "fifo_c"
 #define FIFO_READ   "fifo_s"
  
  int main()
  {
      int fp_w;
          int fp_r;
	   
	       int i = 1; 
	        
		    if((fp_r = open(FIFO_READ, O_RDWR)) < 0) 
		        {    
			        perror("open error : ");
				        exit(0);
					    }    
					        if((fp_w = open(FIFO_WRITE, O_RDWR)) < 0) 
						    {    
						            perror("open error : ");
							            exit(0);
								        }    
									 
									 while(1)
									     {    
									             sleep(1);
										             write(fp_w, (void *)&i, sizeof(int));
											             read(fp_r, (void *)&i, sizeof(int));
												             printf("¼­¹öºÎÍµ¥ÀÅ À= %d\n", i);
													         }    
														     exit(1);
														     } 

														     
