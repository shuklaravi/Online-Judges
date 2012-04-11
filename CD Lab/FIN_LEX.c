

	//	Aim: Lexical Analyzer
	//	Author: SAMir SOLanki [SAMSOL]

//	#include<conio.h>
	#include<string.h>
	#include<ctype.h>
	#include<stdio.h>

    class Lex_Ana
    {
        public :
		int i,j,k,ti,oprfl,delfl,keyfl,Litfl,cLitfl,ptfl,tfl,mxIdeni,Liti,mxIdenj,mxOpri,mxOprj,mxDeli,Erri;
		int uqIdi,uqOpi,uqDei,defOpi,defKeyi,cLiti;
		char mStr[50],mxIden[20][20],mxOpr[20][20],mxDel[20],tmpStr[50];
		char defOprStr[20][20],defOpr[15],defDel[15],defKey[20][20];
		char uqOpr[20][20],uqIden[20][20],uqIdfl[20],uqOpfl[20],uqDefl[20],uqDel[20];
		char Opr[20][20],invalTok[20][20],Con[20][20],Iden[20][20],
		     Key[20][20],inTok[20],Lit[20][20],Err[20][20],cLit[20][20];
                int Opri,invToki,Coni,Ideni,Keyi,Deli,inToki;

                Lex_Ana(char *str)
                {
                    strcpy(mStr,str);

                    //Defined Keywords					
                    defKeyi=13;
                    strcpy(defKey[0],"int");
                    strcpy(defKey[1],"float");
                    strcpy(defKey[2],"double");
                    strcpy(defKey[3],"for");
                    strcpy(defKey[4],"if");
                    strcpy(defKey[5],"else");
                    strcpy(defKey[6],"while");
                    strcpy(defKey[7],"do");
                    strcpy(defKey[8],"return");
                    strcpy(defKey[9],"char");
                    strcpy(defKey[10],"break");
                    strcpy(defKey[11],"goto");
                    strcpy(defKey[12],"void");

                    //Defined Operators    
                    defOpi=18;                    
                    strcpy(defOprStr[0],"+");
                    strcpy(defOprStr[1],"-");
                    strcpy(defOprStr[2],"*");
                    strcpy(defOprStr[3],"/");
                    strcpy(defOprStr[4],"%");
                    strcpy(defOprStr[5],"=");
                    strcpy(defOprStr[6],"<");
                    strcpy(defOprStr[7],">");
                    strcpy(defOprStr[8],"<=");
                    strcpy(defOprStr[9],">=");
                    strcpy(defOprStr[10],"==");
                    strcpy(defOprStr[11],"=+");
                    strcpy(defOprStr[12],"=-");
                    strcpy(defOprStr[13],"=*");
                    strcpy(defOprStr[14],"=/");
                    strcpy(defOprStr[15],"=%");   
                    strcpy(defOprStr[16],"++");
                    strcpy(defOprStr[17],"--");
                    strcpy(defOpr,"+-/*%=<>");
		    strcpy(defDel,";,:{}[]()");
		}

		int IsMxIden(char ch)
		{
		    return((IsIden(ch)||IsFloat(ch))?1:0);
		}

		int IsIden(char ch)
		{
			return((isalpha(ch)||ch=='_')?1:0);
		}

		int IsFloat(char ch)
		{
			return((isdigit(ch)||ch=='.')?1:0);
		}

                int IsOpr(char ch)
                {
                    oprfl=0;
                    for(ti=0;ti<strlen(defOpr)&&!oprfl;ti++)
                    {
                        if(ch==defOpr[ti])
                        {
                            oprfl=1;                            
                        }
                    }
                    return oprfl;
                }

                int IsDel(char ch)
                {
                    delfl=0;
                    for(ti=0;ti<strlen(defDel)&&!delfl;ti++)
                    {
                        if(ch==defDel[ti])
                        {
                            delfl=1;                            
                        }
                    }
                    return delfl;
                }

                int IsKey(char *str)
                {
                    keyfl=0;
                    for(ti=0;ti<defKeyi&&!keyfl;ti++)
                    {
                        if(!strcmp(defKey[ti],str))
                        {
                            keyfl=1;                            
                        }
                    }
                    return keyfl;
                }


                void Find_Lex()
                {
		    i=0;
		    cLiti=0;
		    Liti=0;
		    Erri=0;
                    mxIdeni=0;
                    mxIdenj=0;
                    mxOpri=0;
                    mxOprj=0;
                    mxDeli=0;
                    inToki=0;
                    while(mStr[i]!='\0')
                    {
			if(IsMxIden(mStr[i]))
                        {
			    while(IsMxIden(mStr[i]))
                            {
                                mxIden[mxIdeni][mxIdenj++]=mStr[i++];
				if(!IsMxIden(mStr[i]))
                                {
                                    mxIden[mxIdeni++][mxIdenj]='\0';
                                    mxIdenj=0;
                                }
                            }
			}
			else if(mStr[i]=='"')
			{
				Litfl=1;
				k=0;
				tmpStr[k++]=mStr[i];
				for(j=i+1;j<strlen(mStr)&&Litfl;j++)
				{
					tmpStr[k++]=mStr[j];
					if(mStr[j]=='"')
					{
						tmpStr[k]='\0';
						strcpy(Lit[Liti++],tmpStr);
						Litfl=0;
						i=j+1;
					}
				}
				if(Litfl)
				{
					strcpy(Err[Erri++],"Invalid Use of \"");
					i++;
				}
			}
			else if(mStr[i]=='\'')
			{
				cLitfl=0;
				k=0;
				tmpStr[k++]=mStr[i];
				for(j=i+1;j<strlen(mStr)&&!cLitfl;j++)
				{
					tmpStr[k++]=mStr[j];
					if(mStr[j]=='\'')
					{
						tmpStr[k]='\0';
						if(strlen(tmpStr)!=3)
						{
							strcpy(Err[Erri++],"Invalid Use of \'");
							cLitfl=1;
							i++;
						}
						else
						{
							strcpy(cLit[cLiti++],tmpStr);
							cLitfl=1;
							i=j+1;
						}
					}
				}
				if(!cLitfl)
				{
					strcpy(Err[Erri++],"Invalid Use of \'");
					cLitfl=1;
					i++;
				}
			}
			else if(IsOpr(mStr[i]))
                        {
                            while(IsOpr(mStr[i]))
                            {
                                mxOpr[mxOpri][mxOprj++]=mStr[i++];
                                if(!IsOpr(mStr[i]))
                                {
                                    mxOpr[mxOpri++][mxOprj]='\0';
                                    mxOprj=0;
                                }
                            }
                        }
                        else if(IsDel(mStr[i]))
                        {
                            while(IsDel(mStr[i]))
                            {
                                mxDel[mxDeli++]=mStr[i++];                                
                            }
			    mxDel[mxDeli]='\0';
                        }
                        else if(mStr[i]!=' ')
                        {
                            inTok[inToki++]=mStr[i++];   
                            inTok[inToki]='\0';
                        }
                        else
                        {
                            i++;
                        }
                    }                          
                }

                void Rem_Dup()
                {
                    uqIdi=0;
                    uqDei=0;
                    uqOpi=0;
                    for(i=0;i<20;i++)
                    {
                        uqOpfl[i]=0; 
                        uqIdfl[i]=0;
                        uqDefl[i]=0;
                    }
                    for(i=1;i<mxIdeni+1;i++)
                    {
                        if(uqIdfl[i-1]==0)
                        { 
                            strcpy(uqIden[uqIdi++],mxIden[i-1]);
                            for(j=i;j<mxIdeni;j++)
                            {                                
                                if(!strcmp(mxIden[j],mxIden[i-1]))                                
                                {                                    
                                    uqIdfl[j]=1;
                                }
                            }
                        }
                    }
                    for(i=1;i<mxOpri+1;i++)
                    {
                        if(uqOpfl[i-1]==0)
                        { 
                            strcpy(uqOpr[uqOpi++],mxOpr[i-1]);
                            for(j=i;j<mxOpri;j++)
                            {                                
                                if(!strcmp(mxOpr[j],mxOpr[i-1]))                                
                                {                                    
                                    uqOpfl[j]=1;
                                }
                            }
                        }
                    }
                    for(i=1;i<mxDeli+1;i++)
                    {
                        if(uqDefl[i-1]==0)
                        { 
                            uqDel[uqDei++]=mxDel[i-1];  
			    uqDel[uqDei]='\0';
                            for(j=i;j<mxDeli;j++)
                            {                                
                                if(mxDel[j]==mxDel[i-1])                                
                                {                                    
                                    uqDefl[j]=1;
                                }
                            }
                        }
                    }                 
                }

                void Sep_Val()
                {
                    Opri=0;                 
		    invToki=0;
		    Ideni=0;
		    Coni=0;
		    Keyi=0;
		    for(i=0;i<uqIdi;i++)
		    {
			if(IsIden(uqIden[i][0]))
			{
			    if(IsKey(uqIden[i]))
			    {
				strcpy(Key[Keyi++],uqIden[i]);
			    }
			    else
			    {
				ptfl=1;
				for(j=0;j<strlen(uqIden[i])&&ptfl;j++)
				{
					if(uqIden[i][j]=='.')
					{
						strcpy(invalTok[invToki++],uqIden[i]);
						ptfl=0;
					}
				}
				if(ptfl)
				{
					strcpy(Iden[Ideni++],uqIden[i]);
				}
			    }
			}
			else
			{
			    tfl=1;
			    ptfl=0;
			    for(j=0;j<strlen(uqIden[i])&&tfl;j++)
			    {
				if(IsIden(uqIden[i][j]))
				{
				    strcpy(invalTok[invToki++],uqIden[i]);
				    tfl=0;
				}
				else if(uqIden[i][j]=='.')
				{
					if(ptfl)
					{
						strcpy(invalTok[invToki++],uqIden[i]);
						tfl=0;
					}
					if(!ptfl)
					{
						ptfl=1;
					}
				}
			    }
			    if(tfl)
			    {
				strcpy(Con[Coni++],uqIden[i]);
			    }
			}
                    }
                    for(i=0;i<uqOpi;i++)
                    {
                        tfl=1;
                        for(j=0;j<defOpi&&tfl;j++)
                        {
                            if(!strcmp(uqOpr[i],defOprStr[j]))
                            {   
                                strcpy(Opr[Opri++],uqOpr[i]);
                                tfl=0;
                            }
                        }
                        if(tfl)
                        {
                            strcpy(invalTok[invToki++],uqOpr[i]);
                        }
                    }
                }

                void Display()
                {
		    printf("\n\n\t: Lexical Analysis Report :\n\n\n\t%c Input String: %s\n\n\n",272,mStr);
		    printf("\t%c Total Identifiers: %d\n\n",272,Ideni);
                    for(i=0;i<Ideni;i++)
                    {
                        printf("\t\t");
                        puts(Iden[i]);                        
                    }
		    printf("\n\t%c Total Constants: %d\n\n",272,Coni);
		    for(i=0;i<Coni;i++)
		    {
			printf("\t\t");
			puts(Con[i]);
		    }
		    printf("\n\t%c Total Literals: %d\n\n",272,Liti+cLiti);
		    for(i=0;i<Liti;i++)
		    {
                        printf("\t\t");
			puts(Lit[i]);
		    }
		    for(i=0;i<cLiti;i++)
		    {
			printf("\t\t");
			puts(cLit[i]);
		    }
		    printf("\n\t%c Total Keywords: %d\n\n",272,Keyi);
                    for(i=0;i<Keyi;i++)
                    {
                        printf("\t\t");
                        puts(Key[i]);                        
                    }
		    printf("\n\t%c Total Operators: %d\n\n",272,Opri);
                    for(i=0;i<Opri;i++)
                    {
                        printf("\t\t");
                        puts(Opr[i]);                        
                    }
		    printf("\n\t%c Total Delimeters: %d\n\n",272,uqDei);
                    if(uqDei)
                    {
                        printf("\t\t");
                        puts(uqDel);                                            
                    }
		    printf("\n\t%c Total Invalid Tokens: %d\n\n",272,invToki+inToki);
                    for(i=0;i<invToki;i++)
                    {
                        printf("\t\t");
                        puts(invalTok[i]);                        
		    }
		    if(inToki)
		    {
			for(i=0;i<strlen(inTok);i++)
			{
			    printf("\t\t");
			    printf("%c\n",inTok[i]);
			}
		    }
		    printf("\n\t%c Invalid Used Tokens: %d\n\n",272,Erri);
		    for(i=0;i<Erri;i++)
		    {
			printf("\t\t");
			puts(Err[i]);
		    }
                }       

    };

    void main()
    {
	clrscr();
	char mstr[50];
        printf("\n\n\tEnter String: ");
	gets(mstr);
        Lex_Ana oblex(mstr);
        oblex.Find_Lex();
        oblex.Rem_Dup();
        oblex.Sep_Val();
        oblex.Display();        
        getch();
    }
