    #include <iomanip>
    #include <iostream>   
    #include <cstdlib>  
    #include <ctime> 
    #include <conio.h> 
    #include <cstring> 
    
    #include <windows.h>
    
    using namespace std;
	
	#include "struct.cpp"
	#include "source.cpp"
	#include "ui.cpp"

	 
    int main() 
	{   
	
	   srand(time(0));
	   
	   strcpy(USER[0].login,"ADMIN");
	   
	   strcpy(USER[0].password,"ADMIN_STUD");
	   	
	    int pos = 0;
	    int log = load_login_pass();
	    bool acces = false;
	    if(log == 0){
	    	log = 1;
		}
	    
	    acces = login_pass(log,&pos,acces);
	    
	  
	   	
	   
	    if(acces){
		
	    
	    FILE *fp;
	    
	    fp=fopen("conf.ini","r+");
	    
	    fscanf( fp, "%s", &FNS);
	    fscanf( fp, "%s", &FNL);
	    
	    fclose(fp);
	    
	 	int n  = load();
	 	  
		 
		   
		  while(1)
		  {
		  	
		  	switch( meniu() )
		  	{
		  		
		  		case 49 :  insert(&n); system("pause"); break; 
		  		case 50 :  show(n); system("pause"); break; 
		  		case 51 : {
		  			
		  				switch(meniu_editare()){
		  					case 49: edit_nume(n); break;
		  					case 50: edit_ani(n); break;
		  					case 51: edit_grupa(n);break;
		  					case 52: edit_note(n);break;
						 
				
					  
				 		}
				  }
		  		case 52 :   save(n) ; system("pause"); break; 
		  		case 53 :  n=load() ; system("pause"); break; 
		  		case 54 : {
				  if(strcmp(USER[pos].login,"ADMIN") == 0){
				  	insert_user(&log);
					system("pause"); break;
				  }	
				  else {
				  	system("cls");
				  	cout<<"NU aveti permisiune!!!"<<USER[pos].login<<endl;
				  	system("pause"); break;
				  }
				  }
		  		case 55 : save_user(log); system("pause"); break;
		  		
		  		case 27 : save(n);save_user(log) ;exit(0);
			}
		  	
		  }
		  
		  
		  
		  
		  }
		  

		  
		  
	   return 0;   
    }
    
    
    
    	  
	 
     
