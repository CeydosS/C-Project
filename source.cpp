

	
	void line1()
	{
			cout<<(char)201<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)203<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)203<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)203<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205	<<(char)203<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)203<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)187<<endl;	   	
		   	
	
	}
	void line2()
	{
	cout<<(char)204<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)206<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)206<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)206<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)206<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)206<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)185<<endl;
	
	}
	
	void line3()
	{
			cout<<(char)200<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)202<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)202<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)202<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)202<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)202<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)205<<(char)188<<endl;

	}
	
	int load_login_pass()
	{
	  FILE *fp;
	  fp = fopen("UTILIZATORI_LOGIN.txt","r+b");
	     
	   
	  int log = fread( USER , sizeof(user), 200, fp);
	   
	   fclose(fp);
	   	
	   	
	   	return log;
	}
	
	void save_user(int logindex)
	{
	  FILE *fp;
	  fp = fopen("UTILIZATORI_LOGIN.txt","r+b");
	     
	   
	  int log = fwrite( USER , sizeof(user), logindex, fp);
	
	   fclose(fp);
	   	
	   	
	}
	
	void insert_user(int *logindex){
		
		
		do{
			system("cls");
			cout<<*logindex<<endl;
			cout<<"\tLogin :: ";
			cin>>USER[*logindex].login;
			cout<<endl;
			cout<<"\tPassword :: ";
			cin>>USER[*logindex].password;
			(*logindex)++;
			cout<<" ESC - exit,  any key ...."<<endl;
			
		}while( _getch() != 27 );
	}
	
	
	

	bool login_pass(int log,int *position,bool acces){
		char passwordlocal[100];
		char loginfile[256];
		
		
		int Key , o=0 ;
		int tryes = 0;
		
     bool k=true;
     cout<<"\n\n\t Enter login ::";
     cin>>loginfile;
     for(int i = 0;i<log;i++){
     	if(strcmp(USER[i].login,loginfile) == 0){
     		acces = true;
     		*position = i;
		 } 
	 }
	 if(!acces){
	 	system("cls");
	 	cout<<"\n\n\tUtilizator inexistent ";
	 }

     if(acces){
	 
     cout<<"\n\n\t Enter password ::";
     while(k && tryes<=3)
     {
     	
       Key = _getch(); 
         if(Key == 13)
         {
            passwordlocal[o]=0;
            
            if(strcmp(USER[*position].password,passwordlocal) == 0){
            	k = false;
            	acces = true;
			}
            
            
             else
             {
                system("cls");
        cout<<"\n\n\t Password Error !"<<endl;
        system("pause");
          system("cls");
          cout<<"\n\n\t Enter password ::";
          tryes++;
          
          o=0;
 		}
 		}
  	else if(Key == 8)
           {
              if( o>0 )
   {
    cout<<"\b \b";
            o--;
   } 
           }
           else if(Key == 27)
           { 
              exit(0);
           }
   	else
  {
     if( Key != 32)
     {
       passwordlocal[o]=Key;  
                cout<<"*";
                o++;
     }
  }
     }
	
	
	}
	
	if(tryes <= 3){
		return acces;
	}
	else{
		cout<<"Ati depasit nr de incercari ";
		system("pause");
		exit(0);
	}
		
	
	
	}
	
	 void insert(int *n) 
	 {
	    do
		{  
		 system("cls");
	   	 cout<<" Student ["<<(*n)+1<<"]"<<endl;
	   	 
	   	 cout<<" Enter nume  :: "; cin>>S[*n].nume;
	   	 cout<<" Enter prenume  :: "; cin>>S[*n].prenume;
	   	 cout<<" Enter ani   :: "; cin>>S[*n].ani;
	   	 cout<<" Enter grupa   :: "; cin>>S[*n].grupa;
	   	 
	    
	   
	     do
	     {
	     	
		 
	      cout<<" Enter nota ["<<S[*n].NrNOTE+1<<"]   :: "; cin>>  S[*n].NOTE[ S[*n].NrNOTE ].NOTA  ;
	      
	         S[*n].media += S[*n].NOTE[  S[*n].NrNOTE  ].NOTA; 
	      
	      S[*n].NrNOTE++;
	    
		   cout<<"   --   NOTE   --   ESC - exit,  any key ...."<<endl;
		
		 }while( _getch() != 27 );
		 
		  
		    S[*n].media  =  S[*n].media / S[*n].NrNOTE;
		 
		 
	    
	     (*n)++;
		 
		   cout<<" ESC - exit,  any key ...."<<endl;
		   
		 }while( _getch() != 27 );
	 }
	 
	 void show(int n)
	 {
	 	int a;
	 	
	 	int x=2, in=0, sf=x;
	 	bool EXIT=0;
	 	
	   if( n > 0 )
	   {
        
while(1)		
{	system("cls");

	line1();cout<<(char)186<<setw(5)<<"ID"<<(char)186<<setw(15)<<"NUME"<<(char)186<<setw(15)<<"PRENUME"<<(char)186<<setw(15)<<"GRUPA"<<(char)186<<setw(10)<<"ANI"<<(char)186<<setw(10)<<"MEDIA"<<(char)186<<endl;line2();
	a = 0;
	for(int i = in; i < sf ; i++)
	{
		
	 	cout<<(char)186<<setw(5)<<i+1
		    <<(char)186<<setw(15)<<S[i].nume
		    <<(char)186<<setw(15)<<S[i].prenume
		    <<(char)186<<setw(15)<<S[i].grupa
			<<(char)186<<setw(10)<<S[i].ani
			<<(char)186<<setw(10)<<S[i].media<<(char)186<<endl;
			
		
		
		if(a<1){
		a++; line2();	
		}
		
	}
	line3();
	switch(_getch())
	{
		case 43 : in+=x; sf+=x; if( sf > n ){ in=n-2; sf=n; } break;
		case 45 : in-=x; sf-=x; if( in < 0 ){ in=0;   sf=x; } break;
		case 27 : EXIT=true;  
	}
	
	if( EXIT ) break;
}	
	
	
	
	   
	    } else
		{ 
		 system("cls");
		 cout<<" Nu sunt studenti pentru afisare"<<endl;	
		 }
	 }
	 
	
	
	void save(int n)
	{
	  FILE *fp;
	   
	  if(  (fp = fopen(FNS,"w+b") ) == NULL )
	  {
	  	 cout<<" Error:: W+B "<<endl; 
	  	 system("pause");
	  	 return;
	  }  
	  
	  fwrite( S , sizeof(stud), n, fp);
	   
	   fclose(fp);
	   	
	}
	
	int load()
	{
	  FILE *fp;
	   
	  if(  (fp = fopen(FNL,"r+b") ) == NULL )
	  {
	  	 cout<<" Error:: r+B "<<endl; 
	  	 system("pause");
	  	 return 0;
	  }  
	  
	  int n = fread( S , sizeof(stud), 1000, fp);
	   
	   fclose(fp);
	   	
	   	
	   	return n;
	}
	 
	void edit_nume(int n){
		system("cls");
		int aux;
		int nr;
		for(int i = 0;i<n;i++){
			cout<<i+1<<". "<<S[i].nume<<"  "<<S[i].prenume<<endl;
		}
		cout<<"Enter id student :: ";
		cin>>nr;
		nr--;
	
		system("cls");
		cout<<S[nr].nume<<"  "<<S[nr].prenume<<endl;
		cout<<"1.Edit nume"<<endl;
		cout<<"2.Edit prenume"<<endl;
		aux = _getch();
		if(aux == '1'){
			
				system("cls");
				cout<<"Enter new nume :: ";
				cin>>S[nr].nume;
				
			}
			
		else{
				system("cls");
				cout<<"Enter new prenume :: ";
				cin>>S[nr].prenume;
			
				
			}
			
			
		}
		
		
		void edit_ani(int n){
			system("cls");
	
		int nr;
		for(int i = 0;i<n;i++){
			cout<<i+1<<". "<<S[i].nume<<"  "<<S[i].prenume<<endl;
		}
		cout<<"Enter id student :: ";
		cin>>nr;
		nr--;
		system("cls");
		cout<<S[nr].nume<<"  "<<S[nr].prenume<<"  "<<S[nr].ani<<" ani "<<endl;
		cout<<"Enter new age::";
		cin>>S[nr].ani;
		
		}
		
		void edit_grupa(int n){
			system("cls");
	
		int nr;
		for(int i = 0;i<n;i++){
			cout<<i+1<<". "<<S[i].nume<<"  "<<S[i].prenume<<endl;
		}
		cout<<"Enter id student :: ";
		cin>>nr;
		nr--;
		system("cls");
		cout<<S[nr].nume<<"  "<<S[nr].prenume<<"  "<<" grupa "<<S[nr].grupa<<endl;
		cout<<"Enter new grupa::";
		cin>>S[nr].grupa;
		
		}
		void edit(int nr){
			int index;
			for(int i = 0;i<S[nr].NrNOTE;i++){
					if(S[nr].NOTE[i].NOTA == 0) continue;
					cout<<i+1<<". "<<S[nr].NOTE[i].NOTA<<endl;
				}
			cout<<"Enter nr notei :: ";
			cin>>index;
			index--;
			
			system("cls");
			cout<<"Enter new nota :: ";
			cin>>S[nr].NOTE[index].NOTA;
			S[nr].media = 0;
			for(int i = 0;i<S[nr].NrNOTE;i++){
				S[nr].media += S[nr].NOTE[i].NOTA;
			
			}
		
			S[nr].media = S[nr].media / S[nr].NrNOTE;
			
			
			
		}
		
			void delete_note(int nr){
			system("cls");
			int index;
			for(int i = 0;i<S[nr].NrNOTE;i++){
					if(S[nr].NOTE[i].NOTA == NULL) continue;
					cout<<i+1<<". "<<S[nr].NOTE[i].NOTA<<endl;
			}
			
			cout<<"Enter id nota :: ";
			
			cin>>index;
			index--;

			S[nr].NOTE[index].NOTA = NULL;
			S[nr].NrNOTE--;
			S[nr].media = 0;
			if(S[nr].NrNOTE>1){
				
			
			for(int i = 0;i<S[nr].NrNOTE;i++){
				S[nr].media += S[nr].NOTE[i].NOTA;
			
			}
			S[nr].media = S[nr].media / S[nr].NrNOTE;
			}
			else S[nr].media = S[nr].NOTE[0].NOTA;
		}
		void add_note(int nr){
			system("cls");
			cout<<"Enter new nota :: ";
			cin>>S[nr].NOTE[S[nr].NrNOTE++].NOTA;
			
			S[nr].media = 0;
			for(int i = 0;i<S[nr].NrNOTE;i++){
				S[nr].media += S[nr].NOTE[i].NOTA;
			
			}
			S[nr].media = S[nr].media / S[nr].NrNOTE;
			
		}
		
		
		
		
		
	
		void edit_note(int n){
		system("cls");
	
		int nr;
		for(int i = 0;i<n;i++){
			cout<<i+1<<". "<<S[i].nume<<"  "<<S[i].prenume<<endl;
		}
		cout<<"Enter id student :: ";
		cin>>nr;
		nr--;
		system("cls");
		cout<<S[nr].nume<<"  "<<S[nr].prenume<<endl;
		
		cout<<"1.Edit nota"<<endl;
		cout<<"2.Add nota"<<endl;
		cout<<"3.Delete nota"<<endl;
		cout<<S[nr].media;
		int index;
		switch(_getch()){
			case 49:edit(nr);break;
			case 50:add_note(nr);break;
			case 51:delete_note(nr);break;
				
			
		}
		}
		
		
		
	
		
		
		
		
	 
	 
	 
	 
	 
	 
