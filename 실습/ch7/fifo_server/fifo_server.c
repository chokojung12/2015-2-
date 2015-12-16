#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
 
 #define FIFO_READ   "fifo_c"
 #define FIFO_WRITE  "fifo_s"
  
  int main()
  {
      int fp_w;
          int fp_r;
	   
	       int i = 0;
	        
		    umask(0000); //ÆÀ ±Çѿ¡ ´ë ¸Žºũ
		     
		         // mkfifo¸¦ À¿ë¼­ FIFOÆÀ; »ýÙ
			     // FIFO_READ´ÂŬ¶óðÎºÎÍµ¥ÀÅ¸¦ À±â§Ç¼­
			         if (mkfifo(FIFO_READ, 0666) != 0)
				     {
				           perror("mkfifo failure");
					       }
					       // FIFO_WRITE´ÂŬ¶óðÎµ¥ÀÅ¸¦ ¾²±â§Ç¼­ »çÇ´Ù
					           if (mkfifo(FIFO_WRITE, 0666) != 0)
						       {
						             perror("mkfifo failure");
							         }
								  
								      if( (fp_r = open(FIFO_READ, 02)) < 0)
								          {
									          perror("open error : ");
										          exit(0);
											      }
											       
											           if((fp_w = open(FIFO_WRITE, 02)) < 0)
												       {
												               perror("open error : ");
													               exit(0);
														           }
															    
															        while(read(fp_r, (void *)&i, sizeof(int)) > 0)
																    {
																            printf("Ŭ¶óðÎºÎÍµ¥ÀÅ À= %d\n", i);
																	            i = i*2;
																		            write(fp_w, (void *)&i, sizeof(int));
																			        }
																				    exit(1);
																				    }
																				    
