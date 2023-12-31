#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>
#include<conio.h>
static char z[100];
//defining a function for encrypting
void encrypt(char *a,char b[100])
{
    int l,r;
    l=strlen(b);

    char d[128];
    for(int i=0;i<l;i++)
    {
        r=127-(int)b[i];

        strcpy(d,"");
        for(int j=0;j<r;j++)
        {
            strcat(d,"#");

        }
        strcat(d,"_");
        strcat(a,d);
    }

}
//defining a function for decrypting
void decrypt(char b[16229])
{
    int l,i=0,j=0,m=0;

    l=strlen(b);

    while(b[i]!='\0')
    {
        while(b[i]!='_')
        {
            j++;
            i++;
        }

        i++;

        z[m]=(char)(127-j);
        m++;
        j=0;
    }
    z[m]='\0';
}

int main()
{
    printf("_______________________________________________________________________________________________________________________________________\n");
    char username[20],password[20],a,b[16229],filename[20],g,ab[16229],r[100],fl[20],pass[2590],ba[16229];
    int c,i=0,s=0,mk=0,l=0,j=0,k,rc,s1=0;
    FILE *f,*f1,*f2;
    l1 : printf("========================================================FOR SIGN UP PLEASE ENTER u=====================================================\n");
    printf("========================================================FOR SIGN IN PLEASE ENTER i=====================================================\n");
    scanf("%c",&a);
    system("cls");
    //for sign up
    if (a =='u')
    {
            printf("================================================================SIGN UP================================================================");
            printf("\n");
            printf("---------------------------------------------------------------------------------------------------------------------------------------");
            printf("\n\n");
            printf(" YOUR PASSWORD MUST ATLEAST CONTAIN:\n");
            printf("    *MINIMUM 8 CHARACTERS\n");
            printf("    *ONE UPPERCASE CHARACTER\n");
            printf("    *ONE DIGIT OR ONE SPECIAL CHARACTER");
            printf("\n\n");
            printf("---------------------------------------------------------------------------------------------------------------------------------------\n");

            f1=fopen("no of users.txt","r");
            fscanf(f1,"%d",&c);
            fclose(f1);
            f=fopen("up.txt","r");
            scanf("%*c");
            printf("THE TOTAL NUMBER OF USERS TILL DATE:%d",c);
            printf("\n\n");

            //for entering your username
            while(s==0)
            {
                i=0;
                mk=0;

                printf("ENTER YOUR USERNAME:");

                scanf("%[^\n]s",username);
                scanf("%*c");
                if(c==0)
                {
                    s=1;
                }

                else

                {

                    while((i<2*c))
                    {
                        fscanf(f,"%s",b);

                        if((strcmp(username,b)==0)&&(i%2==0))
                        {
                            printf("---------------------------------------------------------------------------------------------------------------------------------------");
                            printf("the username already exists\n");
                            printf("Try another username\n");
                            printf("---------------------------------------------------------------------------------------------------------------------------------------");
                            break;
                        }

                        else
                        {
                            mk++;

                        }
                        i++;

                    }
                    rewind(f);

                }

                if(mk==(2*c))
                {
                    s=1;

                }

            }

            s=0;
            int u=0,l=0,o=0;
            char d[100],f3[50];

            //for entering and checking criteria of password
            while(s==0)
            {
                    printf("ENTER YOUR PASSWORD:");
                    scanf("%[^\n]s",password);
                    scanf("%*c");
                    for(i=0;password[i]!='\0';i++)
                    {   l+=1;
                        if (isupper(password[i]))
                        {
                            u=1;
                        }
                        else if(islower(password[i]))
                        {
                            continue;
                        }
                        else
                        {
                            o=1;
                        }

                    }
                    if((u==1)&&(o==1)&&(l>=8))
                    {
                        system("cls");
                        printf("===========================================================ACCOUNT CREATED=============================================================\n");
                        s=1;
                        encrypt(pass,password);
                        f=fopen("up.txt","a");
                        fprintf(f,"%s\n",username);
                        fprintf(f,"%s\n",pass);
                        fclose(f);
                        c+=1;
                        f1=fopen("no of users.txt","w");
                        fprintf(f1,"%d",c);
                        fclose(f1);

                        f2=fopen("filenames.txt","r");

                        //file name storage
                        while(s1==0)
                        {
                            printf("Enter filename:");
                            scanf("%s",filename);
                            scanf("%*c");
                            i=0;
                            mk=0;

                            if((c-1)==0)
                            {
                                s1=1;
                            }

                            else
                            {
                                while(i<2*(c-1))
                                {
                                    fscanf(f2,"%s",b);
                                    if((strcmp(filename,b)==0)&&((i%2)!=0))
                                    {
                                        printf("The file name already used by another user\n");
                                        printf("Try another file name\n");
                                        break;
                                    }
                                    else
                                    {
                                        mk++;
                                    }
                                    i++;

                                }
                                rewind(f2);
                            }


                            if(mk==2*(c-1))
                            {
                                s1=1;
                            }

                        }
                        fclose(f2);
                        f2=fopen("filenames.txt","a");
                        fprintf(f2,"%s\n",username);
                        fprintf(f2,"%s\n",filename);
                        fclose(f2);
                        f=fopen(filename,"w");
                        printf("PLEASE ENTER y IF YOU WANT TO ENTER DATA OR n TO EXIT:");
                        scanf("%c",&g);
                        if(g=='y')
                        {
                                printf("PLEASE ENTER YOUR DATA:\n");
                                scanf("%*c%[^\n]s",d);

                                encrypt(ab,d);
                                fprintf(f,"%s",ab);

                                fclose(f);
                                printf("\n\n->->->->->->->->->->->->->->->->->->->->->->->->->->->THANK YOU FOR USING OUR PROGRAM<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-");
                                printf("\n");

                        }
                        else if(g=='n')
                        {
                                printf("\n\n->->->->->->->->->->->->->->->->->->->->->->->->->->->THANK YOU FOR USING OUR PROGRAM<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-");
                                printf("\n");
                                exit(0);
                        }

                    }
                    if ((l<8)||(u==0)||(o==0))
                    {
                        printf("THE PASSWORD ISNT STRONG ENOUGH");
                        printf("\n");
                    }
                    if(l<8)
                    {
                        printf("The password should contion minimum 8 characters\n");
                    }
                    if(u==0)
                    {
                        printf("The password should contain atleast one uppercase character\n");
                    }
                    if(o==0)
                    {
                        printf("The password should contain atleast one digit or special character\n");
                    }
            }


    }

    //for sign in
    else if(a=='i')
    {
        for(j=0;j<5;j++)
        {
            printf("___________________________________________________\n");
            printf("Enter your username : ");
            scanf("%s",username);
            printf("___________________________________________________\n");
            printf("Enter your password : ");

            rc=0;
            for(i=0;rc!=1;i++)
            {
                password[i]=getch();
                if(password[i]=='\r')
                {
                    password[i]='\0';
                    rc=1;
                }

                else
                {
                    printf("*");
                }
            }


            char b[2590],d[100];
            f=fopen("up.txt","r");

            int x=0,y=0,ll,ii;

            f1=fopen("no of users.txt","r");
            fscanf(f1,"%d",&c);
            for(i=0;i<2*c;i++)
            {
                fscanf(f,"%s",b);
                if(i%2==0)
                {

                    if(strcmp(username,b)==0)
                    {
                        x=1;
                    }

                }

                else
                {
                    ll=strlen(b);
                    decrypt(b);

                    if(strcmp(password,z)==0)
                    {
                        y=1;
                    }
                }

            }
            fclose(f1);

            if((x==1) && (y==1))
            {
                printf("\n");
                printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<");
                printf("\n\t\t\t\t\t\t\tLOGIN SUCCESSFUL\t\t\t\t\t\t\t\n");
                printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>");
                printf("\n");
                fclose(f);
                printf("\n");
                printf("PLEASE ENTER y IF YOU WANT TO ENTER DATA OR n TO READ THE FILE:");
                scanf("%*c%c",&g);
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                f2=fopen("filenames.txt","r");
                //checking the file name
                while(s1==0)
                        {
                            printf("Enter filename:");
                            scanf("%s",filename);
                            scanf("%*c");
                            i=0;
                            mk=0;
                            while(i<2*c)
                                {
                                    fscanf(f2,"%s",b);
                                    if((strcmp(username,b)==0)&&((i%2)==0))
                                    {
                                        fscanf(f2,"%s",b);
                                        if(strcmp(filename,b)!=0)
                                        {
                                            printf("THIS IS NOT YOUR FILE\n");
                                            printf("PLEASE ENTER YOUR CORRECT FILE NAME\n");
                                            break;
                                        }

                                        else
                                        {
                                            s1=1;
                                            break;
                                        }
                                    }
                                    i++;
                                }
                                rewind(f2);
                        }

                //entering data into the file
                if(g=='y')
                {
                        f=fopen(filename,"a");
                        printf("PLEASE ENTER YOUR DATA:\n");
                        scanf("%[^\n]s",d);
                        scanf("%*c");
                        encrypt(ab,d);
                        fputs(ab,f);
                        fclose(f);
                        printf("\n\n->->->->->->->->->->->->->->->->->->->->->->->->->->->THANK YOU FOR USING OUR PROGRAM<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-\n");

                }
                //reading data from the file
                else if(g=='n')
                {
                        f=fopen(filename,"r");
                        fscanf(f,"%[^\n]s",ab);
                        decrypt(ab);
                        printf("%s",z);
                        printf("\n\n->->->->->->->->->->->->->->->->->->->->->->->->->->->THANK YOU FOR USING OUR PROGRAM<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-<-\n");
                }
                break;
            }
            else
            {
                printf("\n_____________________________________________");
                printf("\n");
                printf("\n---------------------------------------------------------------------------------------------------------------------------------------\n");
                printf("EITHER USERNAME OR PASSWORD INCORRECT\n");
                printf("\n");
                printf("PLEASE TRY AGAIN\n");
                printf("---------------------------------------------------------------------------------------------------------------------------------------\n");
                continue;
            }

        }

        if(j==5)
        {
            exit(0);
        }
    }
    else
    {
        system("cls");
        printf("ENTER VALID CHOICE\n");
        goto l1;
    }

}
